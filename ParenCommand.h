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


        








#endif
