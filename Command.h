#ifndef _COMMAND_H
#define _COMMAND_H

#include <iostream>
#include "ExecutorBase.h"
#include <string.h>
using namespace std;

void printTabs(int t) {
    for (int i = 0; i < t; i++) {
        cout << '\t';
    }
}

class Command {
    private:
        int size;
        char* cmd;
        char** args;
        Command* success;
        Command* failure;
        Command* next;
    public:
        Command(char* command, char** arguments, int size) {
            this->size = size;
            int len = strlen(command);
            //initialize cmd
            cmd = new char[len + 1];
            for (int i = 0; i < len; i++) {
                cmd[i] = command[i];
            }
            cmd[len] = 0;
            
            //initialize args
            args = new char*[size + 1];
            for (int i = 0; i < size; i++) {
                len = strlen(arguments[i]);
                args[i] = new char[len + 1];
                for (int j = 0; j < len; j++) {
                    args[i][j] = arguments[i][j];
                }
                args[i][len] = 0;
            }
            args[size] = 0;
            
            success = failure = next = 0;
        };
        
        //deconstructor for command de-allocates dynamically allocated memory
        ~Command() {
            delete[] cmd;
            for (int i = 0; i < size; i++) {
                delete[] args[i];
            }
            delete[] args;
            if (success != 0) delete success;
            if (failure != 0) delete failure;
            if (next != 0) delete next;
        };
        
        //add a success sub-command
        void addSuccess(Command* suc) {
            success = suc;
        };
        
        
        
        void addFailure(Command* fail) {
            failure = fail;
        };
        
        void addNext(Command* nxt) {
            next = nxt;
        };
        
        //used for testing command framer
        void print(int tabs = 0) {
            printTabs(tabs);
            cout << args[0];
            for (int i = 1; i < size; i++) {
                cout << " " << args[i];
            }
            cout << endl;
            if (next != 0) {
                printTabs(tabs);
                cout << "Next:" << endl;
                next->print(tabs + 1);
            }
            if (success != 0) {
                printTabs(tabs);
                cout << "Success:" << endl;
                success->print(tabs + 1);
            }
            if (failure != 0) {
                printTabs(tabs);
                cout << "Failure:" << endl;
                failure->print(tabs + 1);
            }
        };
        
        char* getCommand() const {
            return cmd;
        };
        
        char** getArgs() const {
            return args;
        };
        
        
        
        int execute(ExecutorBase* exec) {
            int t = exec->run_cmd(this);
            if (t == 0 && success != 0) {
                success->execute(exec);
            }
            else if (t != 0 && failure != 0) {
                failure->execute(exec);
            }
            else if (next != 0) {
                next->execute(exec);
            }
            return t;
            
        };
};
#endif