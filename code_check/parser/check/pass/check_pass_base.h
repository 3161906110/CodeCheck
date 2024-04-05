#include "common/precompiled.h"
#include "cursor/cursor.h"

class PassInfo
{
public:
    PassInfo()
    {
        module_name = "";
        file_name = "";

    }
    PassInfo(std::string module_name, std::string file_name): module_name(module_name), file_name(file_name)
    {

    }
public:
    std::string module_name;
    std::string file_name;
};

class PassContext
{

};


class CheckPassBase
{
public:
    CheckPassBase(): cur_pass_info(), cur_context(){}

public:
    void prepare(PassInfo &pass_info);
    bool needCheck(Cursor& root);
    void check(Cursor& root);

private:
    PassContext cur_context;
    PassInfo cur_pass_info;

};