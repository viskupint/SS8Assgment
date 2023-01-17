#include "../header/ParseCmdLine.h"
#include "../header/LinuxTerminal.h"


using namespace std; 
int main(int argc, char **argv){

     unique_ptr<CTerminal> terminal = make_unique<CLinuxTerminal>();

     unique_ptr<CParseCmdLine> cmdLine = terminal->CreateCmdLineInstance(argc,argv);

     if (cmdLine){
        cout<< cmdLine->ExecuteCommand();
        
     }
    return 0;
}