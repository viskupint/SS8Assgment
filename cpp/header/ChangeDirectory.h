#ifndef _CHANGEDIRECTORY_
#define _CHANGEDIRECTORY_

#include "ParseCmdLine.h"

class CChangeDirectory : public CParseCmdLine
{
    public:
    CChangeDirectory();
    CChangeDirectory(int argc,char **argv);
    ~CChangeDirectory();

    int GetArgumentCount();
    bool ValidateCmdLineArguments();
    void InsertCmdLineArguments(vector<string> cmd);



};
#endif