#include "common/precompiled.h"
#include "pass/check_pass_base.h"

class CodeCheckSystem
{

public:
    CodeCheckSystem();
    ~CodeCheckSystem();

    void run();

private:
    std::vector<CheckPassBase*> check_pass_list;

private:
    void initPass();
    void destroyPass();

    void checkFile(std::string file_name);
};