//
// Created by robb on 8/24/23.
//

#ifndef IMP_IMPMISC_H
#define IMP_IMPMISC_H

#include <stdio.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <list>
#include <vector>

#include "Enums.h"
#include "Structs.h"

class ImpMisc {
    public:
        // Helpers
        bool StringToBool(char *str);
        char *BoolToString(bool stat, bool lower = false);
        std::string IntToString(int str);
        int CharToInt(char a[]);
        int StringToInt(std::string str);
        char *StringToChar(std::string str);
        std::string GetEnv(const std::string & var);

        std::string MakeFullFileName(std::string path, std::string sep, std::string fileName);

        // Dealing with DataNodes
        DataNode StringToDataNode(std::string data);
        DataNode StringToDataNode(std::string data, std::string token);
        std::string DataNodeToString(DataNode data);
        std::string DataNodeToString(DataNode data, std::string token);
};


#endif //IMP_IMPMISC_H
