#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <sys/wait.h>
#include <cstdlib>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>

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
        
        if (strcmp(args[0], "test") == 0 || strcmp(args[0], "[") == 0) {
            if (args[1] && (strcmp(args[1], "-f") == 0)) { //CHECKS IF FILE IS A REGULAR FILE
                if (args[2]) {
                    struct stat nike;
                    if (stat(args[2], &nike) == 0 && S_ISREG(nike.st_mode)) {
                        cout << "(True)" << endl;
                        return 0;
                    }
                    else {
                        cout << "(False)" << endl;
                        return 1;
                    }
                }
            }

            else if (args[1] && (strcmp(args[1], "-d") == 0)) { //CHECKS IF FILE IS A DIRECTORY
                if (args[2]) {
                    struct stat nike;
                    if (stat(args[2], &nike) == 0 && S_ISDIR(nike.st_mode)) {
                        cout << "(True)" << endl;
                        return 0;
                    }
                    else {
                        cout << "(False)" << endl;
                        return 1;
                    }
                }
            }

            else { //default is to do the -e && CHECKS IF FILE IS DIRECTORY OR REG FILE
                int t = (strcmp(args[1], "-e") == 0) ? 2 : 1;
                if (args[1]) {
                    struct stat nike;
                    if (stat(args[t], &nike) == 0 && S_ISDIR(nike.st_mode)) {
                        cout << "(True)" << endl;
                        return 0;
                    }
                    
                    else if (stat(args[t], &nike) == 0 && S_ISREG(nike.st_mode)) {
                        cout << "(True)" << endl;
                        return 0;
                    }

                    else {
                        cout << "(False)" << endl;
                        return 1;
                    }
                }
                                        
            }
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
