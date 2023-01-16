#include "../header/ChangeDirectory.h"


/// @brief default constructor for Change Directory class
CChangeDirectory::CChangeDirectory()
{
    //
}

/// @brief constructor with two arguments
/// @param count no of arguments in the aregument array
/// @param args It contains arguments as string
CChangeDirectory::CChangeDirectory(int count, char **args): CParseCmdLine(count,args)
{
    //
}

CChangeDirectory::~CChangeDirectory()
{

}

/// @brief get the argument count from the args.
/// @return count of arguments
int CChangeDirectory::GetArgumentCount()
{
    if (args.size()>0){
        return args.size();
    }
    return 0;
}

/// @brief validate the command line arguments
/// @return if any invaild arguments, return false otherwise true.
bool CChangeDirectory::ValidateCmdLineArguments()
{

   
    return true;
}

/// @brief Created for unit testing pupose, to insert command line arguments
/// @param cmd holds the command line arguments
void CChangeDirectory::InsertCmdLineArguments(vector<string> cmd)
{
   if (args.empty()){
    args.insert(args.begin(),cmd.begin()+1,cmd.end());
   }
   else{
    cout << "Vector contains agruments already "<<endl;
   }

}