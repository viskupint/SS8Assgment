#include "../header/LinuxTerminal.h"
#include "../header/ChangeDirectory.h"

/// @brief default constructor
CLinuxTerminal::CLinuxTerminal()
{
    //
}

/// @brief default destructor
CLinuxTerminal::~CLinuxTerminal()
{
    //
}

/// @brief create object of Change Directory
/// @param argc count of command line areguments 
/// @param argv contains command line arguments
/// @return instance of CChangeDirectory class
unique_ptr<CParseCmdLine> CLinuxTerminal::CreateCmdLineInstance(int argc, char **argv)
{
    return make_unique<CChangeDirectory>(argc,argv);
}

/// @brief create object of Change Directory
/// @return instance of CChangeDirectory class
unique_ptr<CParseCmdLine> CLinuxTerminal::CreateCmdLineInstance()
{
    return make_unique<CChangeDirectory>();
}