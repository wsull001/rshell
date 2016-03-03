#ifndef PAREN_COMMAND_H
#define PAREN_COMMAND_H

#include "Command.h"
using namespace std;

class ParenCommand : public Command {
    private:
        Command* base; //the first command that will be executed in the parentheses
    public:
        ParenCommand() : Command() {
            base = NULL;
        }

        ParenCommand(Command* cmd) : Command() {
            base = cmd;
        }

        ~ParenCommand() {
            if (base) 
                delete base;
        };

        void setBase(Command* cmd) {
            base = cmd;
        };


        virtual int execute(ExecutorBase* exec, int type = -1, int success = -1) {
            int t = 0;
            if (type == -1 || type == 0) {
                t = base->execute(exec);
            }
            else if (type == 1) { //run if works type
                if (success == 1) {
                    t = base->execute(exec);
                } else {
                    t = 1;
                }
            } else if (type == 2) { //run if doesn't work type
                if (success == 0) {
                    t = base->execute(exec);
                } else {
                    t = 0;
                }
            }

            int suc = (t==0) ? 1 : 0;

            if (this->success) {
                t = this->success->execute(exec, 1, suc);
            } else if (failure) {
                t = failure->execute(exec, 2, suc);
            else if (next) {
                t = next->execute(exec);
            }


            return t;
        }


};





#endif
