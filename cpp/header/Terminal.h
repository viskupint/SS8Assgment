#ifndef _TERMINAL_
#define _TERMINAL_

#include "ParseCmdLine.h"

class CTerminal
{
    public:

    CTerminal();
    virtual ~CTerminal();
    virtual unique_ptr<CParseCmdLine> CreateCmdLineInstance(int argc, char **argv) = 0;
    virtual unique_ptr<CParseCmdLine> CreateCmdLineInstance() = 0;



};


#endif