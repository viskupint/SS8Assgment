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

        cmdLine->InsertCmdLineArguments(argv);

    }

    

    int GetArgumentCount(){

        if ( cmdLine )
        {
            return cmdLine->GetArgumentCount();
        }
        
        return 0;
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
    EXPECT_EQ(0,GetArgumentCount());
    EXPECT_EQ(3,GetArgumentCount());
}




int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}