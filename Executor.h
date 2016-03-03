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
        
        if (strcmp(args[0], "test -e") == 0) {
            cout << "test -e worked!!!!!" << endl;
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
