// <one line to give the program's name and a brief idea of what it does.>
// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: GPL-2.0-or-later

#ifndef IMPDB_H
#define IMPDB_H

#include <sqlite3.h>
#include <stdexcept>
#include <iostream>

/**
 * @todo write docs
 */
class ImpDB
{
private:
    sqlite3* idb;
    std::string fileName;

public:
    void SetFileName(std::string fn);
};

#endif // IMPDB_H
