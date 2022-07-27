#include "../include/info.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <iostream>
#include <ctime>
#include <iomanip>

static const char *filepath = "../build/data/id.txt";

void genID(std::string &dest, char type)
{
    using namespace std;
    char buf[1024] = {0};
    ifstream fin(filepath);
    ofstream fout(filepath);
    stringstream word;

    int uid = 0, gid = 0, oid = 0;
    if (fin.is_open())
    {
        while (fin.getline(buf, sizeof(buf)))
        {
            stringstream word(buf);
            word >> uid >> gid >> oid;
        }
    }

    int id;
    switch (type)
    {
    case 'U':
        id = ++uid;
        break;
    case 'G':
        id = ++gid;
        break;
    case 'O':
        id = ++oid;
        break;
    }
    // 新值重新写入文件
    fout << uid << " " << gid << " " << oid;
    // 写入到char *dest
    stringstream ss;
    ss << setw(5) << setfill('0') << id;
    string str;
    ss >> str; //将字符流传给 str
    string s(1, type);
    dest = type + str;

    fout.close();
}

void getDate(std::string &dest)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    dest = std::to_string(1900 + ltm->tm_year) + "-" + std::to_string(ltm->tm_mon) + "-" + std::to_string(ltm->tm_mday);
}