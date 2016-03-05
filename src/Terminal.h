#ifndef TERMINAL_H
#define TERMINAL_H
#include "Terminal.h"
#include "Command.h"
#include "CmdFramer.h"
#include "Executor.h"
#include "ExecutorBase.h"
#include <iostream>
#include <unistd.h>
using namespace std;

class Terminal {
    private:
        char user[40];
        char host[40];
    public:
        Terminal() {
            for (int i = 0; i < 40; i++) {
                user[i] = 0;
                host[i] = 0;
            }
            gethostname(host, 40); //gets network host
            getlogin_r(user, 40); //gets username
        };
        
        void run() {
            
            ExecutorBase* executor = new Executor();
            Cmd_Framer framer;
            while (true) {
                Command* cmd;
                cout << user << "@" << host << "$ ";
                string line;
                getline(cin, line);
                istringstream strin(line);
                cmd = framer.frame(strin);
                if (cmd != NULL) {
                    cmd->execute(executor);
                }
                delete cmd;
            }
        };
    
    
};

#endif
