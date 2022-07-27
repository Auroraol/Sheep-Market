#include "../include/Administrator.h"
#include "../include/info.h"
#include "../include/user.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

const char *const Admin::filePath = "../build/data/order.txt";
const char *const Admin::header = "|ID         |Good       |Price      |Date       |Seller     |Buyer      |"; //订单列表
const char *const Admin::divide = "+-----------+-----------+-----------+-----------+-----------+-----------+";
Order Admin::orders[MAX_ORDER]; // 注意

Admin::Admin()
{
    totalOrder = 0;
}

Admin::~Admin()
{
}

void Admin::PullOrders()
{
    using namespace std;
    ifstream fin;
    fin.open(filePath);
    // 读 存储数据格式: ID ,商品id, 价格, 交易时间, 买家id, 卖家id
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
        word << orders[totalOrder].id << orders[totalOrder].good_id << orders[totalOrder].price
             << orders[totalOrder].date << orders[totalOrder].seller_id
             << orders[totalOrder].buyer_id;
        totalOrder++;
    }
    fin.close();
}

void Admin::pushOrders()
{
    using namespace std;
    ofstream fout;
    fout.open(filePath);
    if (!fout.is_open())
    {
        cerr << "Can't open" << filePath << "file for input.\n";
        fout.close();
    }
    for (int i = 0; i < totalOrder; i++)
    {
        fout << orders[i].id << orders[i].good_id << orders[i].price
             << orders[i].date << orders[i].seller_id
             << orders[i].buyer_id << std::endl;
    }

    fout.close();
}

void Admin::ShowOrdersLists()
{
    print_header(divide, header);
    for (int i = 0; i < totalOrder; i++)
    {
        showOrder(i);
        print_divide(divide);
    }
}

void Admin::showOrder(int i)
{
    std::cout << orders[i].id << orders[i].good_id << orders[i].price
              << orders[i].date << orders[i].seller_id
              << orders[i].buyer_id << std::endl;
}

int Admin::addOrder(Order *order)
{
    if (totalOrder == MAX_ORDER)
        return 0;
    std::string ID = order->id;
    std::string DATA = order->date;
    genID(ID, 'O');
    getDate(DATA);
    orders[totalOrder++] = *order; // 增加订单
    return 1;
}

void Admin::printOrders4Seller(const char *id)
{
    print_header(divide, header);
    for (int i = 0; i < totalOrder; i++)
    {
        if (strcmp(orders[i].seller_id, id) == 0)
        {
            showOrder(i);
            print_divide(divide);
        }
    }
}

void Admin::printOrders4Buyer(const char *id)
{
    print_header(divide, header);
    for (int i = 0; i < totalOrder; i++)
    {
        if (strcmp(orders[i].buyer_id, id) == 0)
        {
            showOrder(i);
            print_divide(divide);
        }
    }
}

void Admin::showUesr()
{
    User user;
    user.readInfoFromFile();
    user.show();
}
