
#ifndef _PARSECMDLINE_
#define _PARSECMDLINE_

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

class CParseCmdLine
{
    
    protected:
    vector<string> args;

    public:
    CParseCmdLine();
    CParseCmdLine(int argc,char **argv);
    virtual ~CParseCmdLine();

    virtual int GetArgumentCount() = 0;
    virtual bool ValidateCmdLineArguments()=0;
    virtual void InsertCmdLineArguments(vector<string> cmd) = 0;

    

};

#endif

