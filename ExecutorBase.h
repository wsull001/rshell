#ifndef EXECUTOR_BASE_H
#define EXECUTOR_BASE_H
#include <iostream>

class Command;
class ExecutorBase {
    public:
        ExecutorBase() {};
        virtual ~ExecutorBase() {};
        virtual int run_cmd(Command* cmd) {return 0;};
};

#endif