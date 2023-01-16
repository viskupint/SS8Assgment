#ifndef _LINUXTERMINAL_
#define _LINUXTERMINAL_

#include "Terminal.h"

class CLinuxTerminal: public CTerminal
{
    public:

    CLinuxTerminal();
    ~CLinuxTerminal();
    unique_ptr<CParseCmdLine> CreateCmdLineInstance(int argc, char **argv);
    unique_ptr<CParseCmdLine> CreateCmdLineInstance();




};





#endif