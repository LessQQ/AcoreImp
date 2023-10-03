//
// Created by robb on 8/24/23.
//

#ifndef IMP_STRUCTS_H
#define IMP_STRUCTS_H

#include <string>
#include "Enums.h"

struct DataNode
{
    std::string _Key;
    std::string _Value;
};

struct iFile
{
    std::string _FileName;
    std::string _FolderName;
    std::string _Sep;
    OSType _ostype;
};

#endif //IMP_STRUCTS_H
