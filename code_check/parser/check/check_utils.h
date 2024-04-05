
#pragma once
#include "cursor/cursor.h"

namespace Utils
{

    void toString(const CXString& str, std::string& output);

    bool checkNodeInFile(Cursor& node, std::string file_path);

    void debugAst(Cursor& node, int count);


} // namespace Utils

