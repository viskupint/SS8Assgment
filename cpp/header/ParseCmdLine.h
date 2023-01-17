
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
    virtual bool CheckAndRemoveExtraSlash() = 0;
    virtual bool IsCurrentDirectory(string directory) =0 ;
    virtual bool IsRootDirectory() = 0;
    virtual bool IsPreviousDirectory(string directory) = 0;
    virtual string ExecuteCommand() = 0;
    
    

};

#endif

