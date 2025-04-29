//
// Created by robb on 8/24/23.
//

#include "ImpMisc.h"

bool ImpMisc::StringToBool(char *str)
{
    std::string result = str;
    if (result == "TRUE" || result == "true")
        return true;
    else
        return false;
}

char *ImpMisc::BoolToString(bool stat, bool lower)
{
    ImpMisc ibm;

    if (stat)
    {
        std::string result;
        if (!lower)
            result = "TRUE";
        else
            result = "true";
        return ibm.StringToChar(result);
    }
    else
    {
        std::string result;
        if (!lower)
            result = "FALSE";
        else
            result = "false";
        return ibm.StringToChar(result);
    }
}

std::string ImpMisc::IntToString(int str)
{
    std::string result;
    std::stringstream ss;
    ss << str;
    result.append(ss.str());
    return result;
}

int ImpMisc::CharToInt(char a[])
{
    int c, sign = 0, offset, n;

    if (a[0] == '-')
    {							// Handle negative integers
        sign = -1;
    }

    if (sign == -1)
    {							// Set starting position to convert
        offset = 1;
    }
    else
    {
        offset = 0;
    }

    n = 0;

    for (c = offset; a[c] != '\0'; c++)
    {
        n = n * 10 + a[c] - '0';
    }

    if (sign == -1)
    {
        n = -n;
    }

    return n;
}

int ImpMisc::StringToInt(std::string str)
{
    char a[sizeof(str) + 1];
    //strcpy_s(a, str.c_str());
    strcpy(a, str.c_str());
    int result = CharToInt(a);
    return result;
}

char *ImpMisc::StringToChar(std::string str)
{
    //char* result = strcpy_s((char*)malloc(str.length() + 1), str.c_str());
    char* result = &str[0];
    return result;
}

std::string ImpMisc::GetEnv( const std::string & var ) {
    const char * val = std::getenv( var.c_str() );
    if ( val == nullptr ) { // invalid to assign nullptr to std::string
        return "";
    }
    else {
        return val;
    }
}

std::string ImpMisc::MakeFullFileName(std::string path, std::string sep, std::string fileName)
{
    std::string result = path + sep + fileName;
    return result;
}

DataNode ImpMisc::StringToDataNode(std::string data)
{
    DataNode dn = StringToDataNode(data, "=");
    return dn;
}
DataNode ImpMisc::StringToDataNode(std::string data, std::string token)
{
    DataNode dn;
    size_t pos = std::string::npos;
    bool searching = true;
    do
    {
        pos = data.find(token);
        dn._Key = data.substr(0,pos);
        if (std::string::npos != pos)
        {
            dn._Value = data.substr(pos + token.size());
            searching = false;
        }
    } while (searching);

    return dn;
}
std::string ImpMisc::DataNodeToString(DataNode data)
{
    std::string output = DataNodeToString(data, "=");
    return output;
}
std::string ImpMisc::DataNodeToString(DataNode data, std::string token)
{
    std::string output;
    output = data._Key + token + data._Value;
    return output;
}