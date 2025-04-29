//
// Created by robb on 8/24/23.
//

#ifndef IMP_IMPCONFIGDATA_H
#define IMP_IMPCONFIGDATA_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Enums.h"
#include "Structs.h"
#include "ImpIO.h"
#include "ImpMisc.h"

class ImpConfigData {
    private:
        int dataMapID;
        ImpIO ibIO;
        ImpMisc ibHelp;

        std::map<std::string, std::string> _dataMap;
        std::string _dmFileName;
    public:
        bool Contains(std::string key);
        void Add(std::string key, std::string value);
        std::string Get(std::string key);

        void Update(std::string key, std::string value);
        void Remove(std::string key);

        void SetFileName(std::string fn);
        std::string GetFileName();

        void Save();
        void Save(std::string fileName);
        void Load();
        void Load(std::string fileName);

        std::vector<std::string> ListDS(std::string fileName);

        int Count();
        void Clear();
};


#endif //IMP_IMPCONFIGDATA_H
