#include "../include/user.h"
#include "../include/info.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>

const char *const User::filePath = "../build/data/user.txt";
static const char *header = "|ID         |Name       |Contact    |Address    |Balance    |";
static const char *divide = "+-----------+-----------+-----------+-----------+-----------+";

User::User(/* args */)
{
    userData dat = {};
    m_dummyHead = new userNode(dat);
}

User::~User()
{
    delete m_dummyHead;
}

// 1.录入信息\n
void User::addtail(userData data)
{
    userNode *addNode = new userNode(data);
    userNode *cur = m_dummyHead;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = addNode;
}

// // 2.修改学生信息\n";
// // void change();

// // 3.查找学生信息\n";
// int studentSystem::search(const std::string &name)
// {
//     linkedNode *cur = dummyHead;
//     while (cur)
//     {
//         if (cur->data.name == name)
//         {
//             std::cout << "姓名:" << cur->data.name;
//             std::cout << " 年龄:" << cur->data.age;
//             std::cout << " 性别:" << cur->data.sex;
//             std::cout << " 电话:" << cur->data.phone;
//             return 1;
//         }
//         cur = cur->next;
//     }
//     std::cout << "没有该学生的信息\n";
//     return 0;
// }

// // 4.删除学生信息\n";
// void studentSystem::deleteStudent(const std::string &na)
// {
//     if (search(na) == 0)
//         std::cout << "该学生的不存在";
//     linkedNode *cur = dummyHead;
//     while (cur->next)
//     {
//         if (cur->next->data.name == na)
//             break;
//         cur = cur->next;
//     }
//     linkedNode *temp = cur->next;
//     cur->next = cur->next->next;
//     delete temp;
// }

// 5.显示信息\n"
const void User::show() const
{
    using namespace std;
    userNode *cur = m_dummyHead;
    while (cur->next)
    {
        using std::cout;
        cout << "ID:        | " << cur->next->data.id << endl;
        cout << "Name:      | " << cur->next->data.passwd << endl;
        cout << "Contact:   | " << cur->next->data.contact << endl;
        cout << "Address:   | " << cur->next->data.address << endl;
        cout << "Balance:   | " << cur->next->data.balance << endl;
        cur = cur->next;
    }
}

//文件读操作 //读到链表
void User::readInfoFromFile()
{
    using namespace std;
    ifstream fin;
    fin.open(filePath);
    // 读 存储数据格式: ID ,小明, 密码, 电话, 地址, 余额
    if (!fin.is_open())
    {
        cerr << "Can't open" << filePath << "file for output.\n";
    }
    char line[1024];
    userData dat;
    //从文件中提取“行”
    while (fin.getline(line, sizeof(line)))
    {
        //从“行”中提取“单词”
        stringstream word(line);
        // 以,为分隔符
        vector<string> data;
        string tmp;
        while (word >> tmp)
        {
            data.push_back(tmp);
            if (cin.get() == '\n')
                break;
        }
        strcpy(dat.id, data[0].c_str()); // 当定义一个结构体，里面包含字符数组 必须用strcpy赋值
        strcpy(dat.name, data[1].c_str());
        strcpy(dat.passwd, data[2].c_str());
        strcpy(dat.contact, data[3].c_str());
        strcpy(dat.address, data[4].c_str());
        dat.balance = stoi(data[5]);

        // 增加到 链表尾
        // TODO
    }

    fin.close();
}

//文件写操作 写到文件
void User::writeInfoToFlie()
{
    using namespace std;
    ofstream fout;
    fout.open(filePath);
    if (!fout.is_open())
    {
        cerr << "Can't open" << filePath << "file for input.\n";
        fout.close();
    }
    userNode *cur = m_dummyHead;
    while (cur->next)
    {
        fout << cur->next->data.id << "," << cur->next->data.passwd << ","
             << cur->next->data.contact << "," << cur->next->data.address
             << "," << cur->next->data.balance << endl;
        cur = cur->next;
    }

    fout.close();
}

const void User::printUser() const
{
    using namespace std;
    userNode *cur = m_dummyHead;
    int flag = 1;
    while (cur->next)
    {
        if (flag == 1)
        {
            print_header(divide, header);
            flag = 0;
        }
        cout << "\t\t" << cur->next->data.id << "\t\t" << cur->next->data.passwd << "\t\t"
             << cur->next->data.contact << "\t\t" << cur->next->data.address
             << "\t\t" << cur->next->data.balance << endl;
        cur = cur->next;
    }
    print_divide(divide);
}
