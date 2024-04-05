#include "check_system.h"
#include "check_config.h"


CodeCheckSystem::CodeCheckSystem()
{
    check_pass_list = std::vector<CheckPassBase*>();
    initPass();
}

CodeCheckSystem::~CodeCheckSystem()
{
    destroyPass();
}

void CodeCheckSystem::run()
{
    
    for(auto module_name: check_config::MODULE_NAMES)
    {
        // 测试文件
        const char file_names[][30] = { "test.cpp" };
        for(auto file_name: file_names)
        {
            char file_path[100] = {};
            sprintf(file_path, "%s/%s/%s", check_config::PROJECT_PATH, module_name, file_name);
            checkFile(file_path);
        }
    }
}

void CodeCheckSystem::initPass()
{

}

void CodeCheckSystem::destroyPass()
{
    
}

void CodeCheckSystem::checkFile(std::string file_name)
{
    bool is_show_errors = false;

    CXIndex cur_index = clang_createIndex(true, false);

    fs::path input_path(file_name);
    if (!fs::exists(input_path))
    {
        std::cerr << input_path << " is not exist" << std::endl;
        return;
    }

    std::vector<const char*>  arguments = {{"-x",
                                           "c++",
                                           "-std=c++11",
                                           "-D__REFLECTION_PARSER__",
                                           "-DNDEBUG",
                                           "-D__clang__",
                                           "-w",
                                           "-MG",
                                           "-M",
                                           "-ferror-limit=0",
                                           "-o clangLog.txt"}};
    auto translation_unit = clang_createTranslationUnitFromSourceFile(
        cur_index, file_name.c_str(), static_cast<int>(arguments.size()), arguments.data(), 0, nullptr);
    auto cursor = clang_getTranslationUnitCursor(translation_unit);
    Utils::debugAst(Cursor(cursor), 0);

 }
