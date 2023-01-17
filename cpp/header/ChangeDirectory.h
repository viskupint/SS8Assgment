#ifndef _CHANGEDIRECTORY_
#define _CHANGEDIRECTORY_

#include "ParseCmdLine.h"
#include <vector>

class CChangeDirectory : public CParseCmdLine
{
    string cd,currentDir,newDir;
    vector<string> currentPath;
    vector<string> newPath;

    public:
    CChangeDirectory();
    CChangeDirectory(int argc,char **argv);
    ~CChangeDirectory();

    int GetArgumentCount();
    bool ValidateCmdLineArguments();
    void InsertCmdLineArguments(vector<string> cmd);
    bool CheckAndRemoveExtraSlash();
    bool IsCurrentDirectory(string directory);
    bool IsRootDirectory();
    bool IsPreviousDirectory(string directory);
    string ExecuteCommand() ;

    void SplitNewPath();
    void SplitCurrentPath();


};
#endif