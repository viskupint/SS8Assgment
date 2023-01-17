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
    if (args.size() == 0)
    {
        cout<< "No arguments supplied in command line"<<endl;
        return false;
    }

    cd=args[0];
    
    if (cd.find("cd")== string::npos){

        cout<<" Error: no cd command found in the given arguments";
        return false;
    }
        

    if ( args.size()>=2 ){
        currentDir = args[1];

    }
    else{
        cout<< "no current direcotry"<<endl;
        return false;
    }
        
    
    if ( args.size() == 3 ) {
        newDir = args[2];
    }
    else{
        cout<< " No new path added in command line" << endl;
        return false;
    }

    //  regex newPath("(/)*[a-zA-Z_][a-zA-Z_0-9\\-./]+");

    // if (regex_match(newDir,newPath)){
    //     return true;
    // }
    // else{
    //     return false;
    // }

   
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

/// @brief Find and remove extra slashes in command line
/// @return true, if found extra slashes in new path
bool CChangeDirectory::CheckAndRemoveExtraSlash()
{
    
    auto iter = newDir.begin();
    while( iter != newDir.end() )
    {
        if( *iter == '/' && iter+1 != newDir.end() && *(iter+1) == '/' )
        {
            newDir.erase(iter);
            
            iter = newDir.begin();
        }
        else
            iter++;
    }
    args[2] = newDir;
    return true;
}

/// @brief Is the new path current directory
/// @return true if current directory. Otherwise false
bool CChangeDirectory::IsCurrentDirectory(string directory)
{
    
    if (directory.compare(".") == 0 ){
        return true;
    }
    return false;
}

/// @brief find whether the new path is root folder
/// @return true if root folder, otherwise false
bool CChangeDirectory::IsRootDirectory()
{
    
    if (args[2].compare("/")==0){
        return true;
    }
    return false;
}

/// @brief find whether the new path is previous folder
/// @return true if previous folder, otherwise false
bool CChangeDirectory::IsPreviousDirectory(string directory)
{
       
    if (directory.compare("..")==0){
        return true;
    }
    return false;

}

/// @brief reconsturct the new path arguments
void CChangeDirectory::SplitNewPath()
{
   char *str = const_cast<char*>(args[2].c_str());
   char *token=strtok(str,"/");
   newPath.clear();
    regex path("[a-zA-Z_][a-zA-Z_0-9]+");
   while (token != NULL){
    if ( regex_match(token,path)){
        newPath.push_back(token);
    }
    else{
        if (IsCurrentDirectory(token) || IsPreviousDirectory(token))
        {
            newPath.push_back(token);
        }
    }
    token = strtok(NULL,"/");
   }

}

/// @brief restructure the current path arguments
void CChangeDirectory::SplitCurrentPath()
{
    char *str = const_cast<char*>(args[1].c_str());
   char *token=strtok(str,"/");
   currentPath.clear();

   while (token != NULL){
    currentPath.push_back(token);
    token = strtok(NULL,"/");
   }

}

/// @brief Excute the "cd" command with command lin arguments
/// @return return result of "cd" comamand
string CChangeDirectory::ExecuteCommand()
{
    if (!ValidateCmdLineArguments()){
        return "No such file or directory";
    }

    CheckAndRemoveExtraSlash();

    if (IsCurrentDirectory(args[2])){
        return args[1];
    }

    if (IsRootDirectory()){
        return "/";
    }

    string path;
    SplitCurrentPath();

    if (IsPreviousDirectory(args[2])){
                
        if (currentPath.size()-1 == 0){
            return "/";
        }
        for (auto index=0; index < currentPath.size()-1; index++){
            path += "/"+currentPath[index];
        }

        return path;
    }

    SplitNewPath();

    
    // built the fresh current directory
    for (auto index=0; index < newPath.size(); index++){
        if (IsCurrentDirectory(newPath[index])){
            for (auto index=0; index < currentPath.size(); index++){
                path += "/"+currentPath[index];
            }
            return path;
        }
        else if (IsPreviousDirectory(newPath[index])){

            if (currentPath.size() == 0){
                return "/";
            }
            else {
               currentPath.erase(currentPath.end());
            }
            
        }
        else {
            for (auto iter=0;iter < currentPath.size();iter++){
                auto folder = currentPath[iter].find(newPath[index]); 
                if ( folder != string::npos){
                    path +="/"+newPath[index];
                    break;
                }
                else{
                                      
                    currentPath.push_back(newPath[index]);
                    break;
                   
                }
            }
            
                    
        }
    }

    if (!path.empty()){
        return path;
    }

    for (auto index=0; index < currentPath.size(); index++){
        path += "/"+currentPath[index];
    }
    return path;
}