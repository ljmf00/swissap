/*
 * __________  _________ _________
 * \______   \/   _____//   _____/  | BigSource Script
 *  |    |  _/\_____  \ \_____  \   | Project in C/C++ Language
 *  |    |   \/        \/        \  |
 *  |______  /_______  /_______  /  | @author Luís Ferreira
 *         \/        \/        \/   | @license GNU Public License v3
 * Copyright (C) 2016 - Luís Ferreira. All right reserved
 * More information in: https://github.com/ljmf00/ (Github Page)
 */

#ifndef BSSHELP_H_INCLUDED
#define BSSHELP_H_INCLUDED

#include <iostream>
#include "errors.h"

namespace bssCore
{
void help();
void exitCode(int e_code);
}

#include "errors.h"

namespace bssCore
{
void helpMain()
{
    std::cout << "Usage: bss <option(s)> SOURCES\n" << std::endl;
    std::cout << "Options:" << std::endl;
}
void helpSpecific(std::string name)
{
    if(name=="cryptography" || name=="cR")
    {
        std::cout << "\t-c --cryptography" << std::endl
                  << "\t\taes" << std::endl
                  << "\t\t\tdecrypt <key> <keylen> <string>\tAES Decryptation Algoritm (Hexadecimal Block)" << std::endl
                  << "\t\t\tencrypt <key> <keylen> <string>\tAES Encryptation Algoritm (Hexadecimal Block)" << std::endl
                  << "\t\tmd5 <string>\t\t\t\tMD5 Hash Calculation" << std::endl
                  << "\t\tsha1 <string>\t\t\t\tSHA-1 Hash Calculation" << std::endl
                  << "\t\tsha224 <string>\t\t\t\tSHA-224 Hash Calculation" << std::endl
                  << "\t\tsha256 <string>\t\t\t\tSHA-256 Hash Calculation" << std::endl
                  << "\t\tsha384 <string>\t\t\t\tSHA-384 Hash Calculation" << std::endl
                  << "\t\tsha512 <string>\t\t\t\tSHA-512 Hash Calculation" << std::endl
                  << "\t\tsha3 <string> [bits]\t\t\tSHA-3 Hash Calculation" << std::endl;
    }
    else if(name=="win32lib")
    {
        std::cout << "\t-w --win32" << std::endl
                  << "\t\t" << std::endl;
    }
    else if(name=="version")
    {
        std::cout << "\t-v --version\t\t\t\t\tShow app version" << std::endl;
    }
    else if(name=="debug")
    {
        std::cout << "\t-d --debug\t\t\t\t\t Full app debug" << std::endl
                  << "\t\t-e --error <code>\t\t\tDisplay specific error" << std::endl;
    }
    else if(name=="help")
    {
        std::cout << "\t--help [section]\t\t\t\tShow app help" << std::endl;
    }
    else
    {
        exitCode(3);
    }
}
void helpOnce(std::string name)
{
    helpMain();
    helpSpecific(name);
}
void help()
{
    helpMain();
    helpSpecific("cryptography");
    helpSpecific("debug");
    helpSpecific("help");
    helpSpecific("version");
    helpSpecific("win32lib");
}
}

#endif // BSSHELP_H_INCLUDED
