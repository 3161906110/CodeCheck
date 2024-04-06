#include "check/check_system.h"



void test_func(int count, std::string tag, std::string name)
{

}

int main(int argc, char* argv[])
{
    std::string str1 = "123";
    std::string str2 = "123" + str1;
    test_func(1, "123", str1);


    CodeCheckSystem code_check_system = CodeCheckSystem();
    code_check_system.run();
    return 0;
}
