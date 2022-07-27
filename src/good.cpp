#include "../include/good.h"
#include "../include/info.h"
#include "../include/fontcolor.h"
#include "../include/init.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

static Good goods[MAX_GOOD]; // all goods
static int totalGood = 0;
static const char *filePath = "../build/data/good.txt";
static const char *header = "|ID         |Name       |Price      |Date       |Seller     |State      |";
static const char *divide = "+-----------+-----------+-----------+-----------+-----------+-----------+";
static const char *stateName[] = {"Selling", "Sold", "Banned"};

void pullGoods()
{
    using namespace std;
    ifstream fin;
    fin.open(filePath);
    // 读 存储数据格式: ID ,名称, 价格, 上架时间, 卖家id, 商品状态
    if (!fin.is_open())
    {
        cerr << "Can't open" << filePath << "file for output.\n";
    }
    char line[1024];
    //从文件中提取“行”
    while (fin.getline(line, sizeof(line)))
    {
        //从“行”中提取“单词”
        stringstream word(line);
        word << goods[totalGood].id << goods[totalGood].name << goods[totalGood].price << goods[totalGood].seller_id
             << goods[totalGood].state << goods[totalGood].date
             << goods[totalGood].description << endl;
        totalGood++;
    }

    fin.close();
}

void pushGoods()
{
    using namespace std;
    ofstream fout;
    fout.open(filePath);
    if (!fout.is_open())
    {
        cerr << "Can't open" << filePath << "file for input.\n";
        fout.close();
    }
    for (int i = 0; i < totalGood; i++)
    {
        fout << goods[i].id << goods[i].name << goods[i].price << goods[i].seller_id
             << goods[i].state << goods[i].date << goods[i].description
             << std::endl;
    }

    fout.close();
}

Good *getGood(int idex) { return goods + idex; }

void goodInfo(int i)
{
    using std::cout;
    using std::endl;
    cout << "ID:            | " << goods[i].id << endl;
    cout << "Name:          | " << goods[i].id << endl;
    cout << "Description:   | " << goods[i].id << endl;
    cout << "Date:          | " << goods[i].id << endl;
    cout << "Price:         | " << goods[i].id << endl;
    cout << "Seller:        | " << goods[i].id << endl;
    cout << "State:         | " << goods[i].id << endl;
}

static void showGood(int i)
{
    using std::cout;
    using std::endl;
    cout << goods[i].id << "\t\t" << goods[i].name << "\t\t" << goods[i].price
         << "\t\t" << goods[i].date << "\t\t" << goods[i].seller_id
         << "\t\t" << stateName[goods[i].state] << endl;
}

void showGoods()
{
    for (int i = 0; i < totalGood; i++)
    {
        print_header(divide, header);
        showGood(i);
    }
    print_divide(divide);
}

void searchGoodName(const char *name, const char *sta)
{
    if (!name)
        return;
    int flag = true;
    for (int i = 0; i < totalGood; i++)
    {
        if (std::strstr(name, goods[i].name))
        {
            if (flag == true)
            {
                print_header(divide, header);
            }
            if (stateName[goods[i].state] == "Selling")
                showGood(i);
            else if (stateName[goods[i].state] == "Sold")
                showGood(i);
            else if (stateName[goods[i].state] == "Banned")
                showGood(i);
            else if (sta == nullptr)
                showGood(i);
            flag = false;
        }
        if (i == totalGood)
            print_divide(divide);
        else
        {
            print_divide(divide);
            yellow_print("Not found do you want to search the goods! To return to the initial interface");
            print_divide(divide);
        }
    }
}

int searchGoodID(const char *id, const char *sta)
{
    for (int i = 0; i < totalGood; i++)
    {
        if (strcmp(id, goods[i].id) == 0)
            return i;
    }
    return -1;
}

int deleteGood(const char *id)
{
    using namespace std;
    int res = searchGoodID(id);
    if (res == -1)
        return 0;
    cout << "Are you sure you want to remove this commodity?\n";
    print_divide(divide);
    goodInfo(res);
    print_divide(divide);
    cout << "\nPlease select (y/n): ";
    char ch;
    cin >> ch;
    if (ch == 'y')
    {
        goods[res].state = BANNED;
        cout << endl;
        successMessage();
    }

    return 1;
}
