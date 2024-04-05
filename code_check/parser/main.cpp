#include "check/check_system.h"


int main(int argc, char* argv[])
{
    CodeCheckSystem code_check_system = CodeCheckSystem();
    code_check_system.run();
    return 0;
}
