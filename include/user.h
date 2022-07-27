#ifndef USER_H_
#define USER_H_

#include "config.h"

struct userData
{
    char id[MAX_LEN];
    char name[MAX_LEN];
    char passwd[MAX_LEN];
    char contact[MAX_LEN];
    char address[MAX_LEN];
    double balance;
};

class User
{
private:
    struct userNode
    {
        userData data;
        userNode *next;
        userNode(userData dat) : data(dat), next(nullptr) {}
    };
    userNode *m_dummyHead;

public:
    User();
    ~User();
    static const char *const filePath;
    void writeInfoToFlie();
    void readInfoFromFile();
    void addtail(userData data);
    const void show() const;
    const void printUser() const;
};

#endif