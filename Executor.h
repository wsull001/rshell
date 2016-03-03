#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <sys/wait.h>
#include <cstdlib>
#include <string.h>
#include "Command.h"
#include "ExecutorBase.h"
using namespace std;

class Executor : public ExecutorBase {
    public:
    Executor() {};
    virtual ~Executor() {};
    int run_cmd (Command* cmd) {
        char** args = cmd->getArgs();
        
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } 
        
        if (strcmp(args[0], "test") == 0) {
            if (args[1] && (strcmp(args[1], "-f") == 0)) {
                if (args[2] && (strcmp(args[2], "/test") == 0)) {
                    cout << "lemme freak!!" << endl;          
                }
            }
            if (args[1] && (strcmp(args[1], "-d") == 0)) {
                //FIXME: STILL NEED TO DO THIS PART
            }
            else { //default is to do the -e
                //FIXME: STILL NEED TO DO THIS PART
            }
            return 0;
        }
        
        int procID, status;
        
        procID = fork();
        
        if (procID == 0) {
            int t = execvp(args[0], args);
            exit(t);
        }
        wait(&status);
        
        return status;
    
    };
};

#endif
