//
// Created by robb on 8/24/23.
//

#include "ImpConfigData.h"

bool ImpConfigData::Contains(std::string key)
{
    if (_dataMap.find(key) == _dataMap.end())
        return false;
    else
        return true;
}

void ImpConfigData::Add(std::string key, std::string value)
{
    if (!Contains(key))
        _dataMap.insert(std::map<std::string,std::string>::value_type(key,value));
    else
        Update(key, value);
}

std::string ImpConfigData::Get(std::string key)
{
    std::string result;
    std::map<std::string, std::string>::iterator it = _dataMap.find(key);
    if (it != _dataMap.end())
        result = it->second;
    else
        result = "Error: key '" + key + "' not found.";
    return result;
}

void ImpConfigData::Update(std::string key, std::string value)
{
    std::map<std::string, std::string>::iterator it = _dataMap.find(key);
    if (it != _dataMap.end())
        it->second = value;
}

void ImpConfigData::Remove(std::string key)
{
    if (!Contains(key))
        return;
    std::map<std::string, std::string>::iterator it = _dataMap.find(key);
    _dataMap.erase(it);
}

void ImpConfigData::Save()
{
    Save(_dmFileName);
}

void ImpConfigData::Save(std::string fileName)
{
    std::map<std::string, std::string>::iterator iter;
    std::vector<std::string> buffer;

    for (iter = _dataMap.begin(); iter != _dataMap.end(); ++iter)
    {
        DataNode dn;
        dn._Key = iter->first;
        dn._Value = iter->second;
        std::string line = ibHelp.DataNodeToString(dn);
        buffer.push_back(line);
    }
    ibIO.WriteData(buffer, fileName);
}

std::vector<std::string> ImpConfigData::ListDS(std::string fileName)
{
    std::map<std::string, std::string>::iterator iter;
    std::vector<std::string> buffer;

    for (iter = _dataMap.begin(); iter != _dataMap.end(); ++iter)
    {
        DataNode dn;
        dn._Key = iter->first;
        dn._Value = iter->second;
        std::string line = ibHelp.DataNodeToString(dn);
        buffer.push_back(line);
    }
    return buffer;
}

void ImpConfigData::Load()
{
    Load(_dmFileName);
}

void ImpConfigData::Load(std::string fileName)
{
    std::vector<std::string> tmpFile;
    tmpFile = ibIO.ReadData(fileName);
    for (size_t i = 0; i < tmpFile.size(); i++)
    {
        DataNode dn = ibHelp.StringToDataNode(tmpFile[i]);
        Add(dn._Key, dn._Value);
    }
}

int ImpConfigData::Count()
{
    int mapsize = (int)_dataMap.size();
    return mapsize;
}
void ImpConfigData::Clear()
{
    _dataMap.clear();
}

void ImpConfigData::SetFileName(std::string fn)
{
    _dmFileName = fn;
}
std::string ImpConfigData::GetFileName()
{
    return _dmFileName;
}
