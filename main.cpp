#include <iostream>
#include <unistd.h>
#include "Terminal.h"
#include "Command.h"
#include "CmdFramer.h"
#include "Executor.h"
#include "ExecutorBase.h"
#include "ParenCommand.h"
using namespace std;

void testFunct(char* &p) {
    string f = "hello";
    p = (char*)f.c_str();
}

int main() {
    
    
    Terminal t;
    t.run();
    
    return 0;
}
