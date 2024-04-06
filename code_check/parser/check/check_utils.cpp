#include "common/precompiled.h"

#include "check_utils.h"

namespace Utils
{
    void toString(const CXString& str, std::string& output)
    {
        auto cstr = clang_getCString(str);

        output = cstr;

        clang_disposeString(str);
    }

    bool checkNodeInFile(Cursor& node, std::string file_path)
    {
        auto kind = node.getKind();
        if (kind == CXCursor_TranslationUnit && node.getSpelling() == file_path)
        {
            return true;
        }
        std::string source_file = node.getSourceFile();
        if (source_file != file_path)
        {
            return false;
        }
        return true;
    }

    void debugAst(Cursor& node, int level)
    {
        for(int i=0; i<level; ++i)
        {
            std::cout << "-";
        }

        std::cout << clang_getCString(clang_getCursorKindSpelling(node.getKind())) << ":   " << node.getSpelling()  << std::endl;
        for(auto& child: node.getChildren())
        {
            debugAst(child, level + 1);
        }
    }
}
    