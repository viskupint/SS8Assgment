#include "../header/ParseCmdLine.h"



/// @brief default constructor
CParseCmdLine::CParseCmdLine()
{
    //
}

/// @brief Two aregument constructor
/// @param argc count of command line arguments
/// @param argv list of command line arguements
CParseCmdLine::CParseCmdLine(int argc, char **argv)
{
  for( auto index = 1; index < argc; index++){
    args.push_back(argv[index]);
  }
}

/// @brief detault destructor
CParseCmdLine::~CParseCmdLine()
{
   //
}

