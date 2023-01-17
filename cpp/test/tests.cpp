#include "../header/ParseCmdLine.h"
#include "../header/LinuxTerminal.h"
#include  <gtest/gtest.h>
#include <memory>

class CParseCmdLineTest : public testing::Test
{
    
    public:

   unique_ptr<CParseCmdLine> cmdLine;
   unique_ptr<CTerminal> terminal;


    CParseCmdLineTest()
    {
       cmdLine = nullptr;
       terminal = nullptr;
    }

    ~CParseCmdLineTest()
    {
        
    }

    void CreateCmdLinObject()
    {
        terminal = make_unique<CLinuxTerminal>();

        cmdLine = terminal->CreateCmdLineInstance();
    }

    void CreateCmdLinObjectWithArguments(vector<string> argv)
    {
        
        
        terminal = make_unique<CLinuxTerminal>();

        cmdLine = terminal->CreateCmdLineInstance();

        if (cmdLine){
            cmdLine->InsertCmdLineArguments(argv);
        }
    }

    int GetArgumentCount(){

        if ( cmdLine )
        {
            return cmdLine->GetArgumentCount();
        }
        
        return 0;
    }

    bool ValidateCmdLineArguments()
    {
        if (cmdLine){
            return cmdLine->ValidateCmdLineArguments();
        }

        return false;
        
    }

    bool IsCurrentDirectory(string directory)
    {
        if (cmdLine){
            return cmdLine->IsCurrentDirectory(directory);
        }

        return false;

    }

    bool IsRootDirectory()
    {
        if (cmdLine){
            return cmdLine->IsRootDirectory();
        }

        return false;

    }

    bool IsPreviousFolder(string directory)
    {
         if (cmdLine){
            return cmdLine->IsPreviousDirectory(directory);
        }

        return false;

    }

    string ExcuteCommand(){
        if (cmdLine){
            return cmdLine->ExecuteCommand();
        }
        return "Commmand is unsuccessful";
    }

    

};


TEST_F(CParseCmdLineTest,CmdLineStartsEmpty)
{
    CreateCmdLinObject();
    EXPECT_EQ(0,GetArgumentCount());
    
}

TEST_F(CParseCmdLineTest,CmdLineWithArguments)
{
    vector<string> argv;
    argv.push_back("./TestCmdLine");
    argv.push_back("mycd");
    argv.push_back("/abc");
    argv.push_back("/def");

    CreateCmdLinObjectWithArguments(argv);
    EXPECT_EQ(3,GetArgumentCount());
    //EXPECT_EQ(0,GetArgumentCount());
   
}


TEST_F(CParseCmdLineTest,ArgumentsAreValid)
{
    vector<string> argv;
    argv.push_back("./TestCmdLine");
    argv.push_back("mycd");
    argv.push_back("/abc");
    argv.push_back("/def");

    CreateCmdLinObjectWithArguments(argv);
    EXPECT_EQ(true,ValidateCmdLineArguments());
    EXPECT_EQ(false,ValidateCmdLineArguments());
}

TEST_F(CParseCmdLineTest,IsRootFolder)
{
    vector<string> argv;
    argv.push_back("./TestCmdLine");
    argv.push_back("mycd");
    argv.push_back("/abc");
    argv.push_back("/");

    CreateCmdLinObjectWithArguments(argv);
    EXPECT_EQ(true,IsRootDirectory());
}

TEST_F(CParseCmdLineTest,IsCurrentFolder)
{
    vector<string> argv;
    argv.push_back("./TestCmdLine");
    argv.push_back("mycd");
    argv.push_back("/abc");
    argv.push_back(".");

    CreateCmdLinObjectWithArguments(argv);
    EXPECT_EQ(true,IsCurrentDirectory(argv[2]));
}

TEST_F(CParseCmdLineTest,IsPreviousFolder)
{
    vector<string> argv;
    argv.push_back("./TestCmdLine");
    argv.push_back("mycd");
    argv.push_back("/abc");
    argv.push_back("...././.09/101/gh///dfg/../..klm");

    CreateCmdLinObjectWithArguments(argv);
    EXPECT_EQ(true,IsPreviousFolder(argv[2]));
}

TEST_F(CParseCmdLineTest,PrintCurrentDirectory)
{
    vector<string> argv;
    argv.push_back("./TestCmdLine");
    argv.push_back("mycd");
    argv.push_back("/abc");
    argv.push_back("...././.09/101/gh///dfg/../..klm");
    string expectedResult("/abc");

    CreateCmdLinObjectWithArguments(argv);
    EXPECT_STREQ(expectedResult.c_str(),ExcuteCommand().c_str());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}