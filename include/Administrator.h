#ifndef ADMINISTRATOR_H_
#define ADMINISTRATOR_H_
#include "config.h"
struct Order
{
    char id[MAX_LEN];
    char good_id[MAX_LEN];
    double price;
    char date[MAX_LEN];
    char seller_id[MAX_LEN];
    char buyer_id[MAX_LEN];
};

class Admin
{
private:
    int totalOrder;

public:
    Admin();
    ~Admin();
    static Order orders[MAX_ORDER]; // 通过结构体数组存储数据
    static const char *const filePath;
    static const char *const header;
    static const char *const divide;
    // 读取外部文件中的所有订单
    void PullOrders();
    // 写入所有订单到外部文件
    void pushOrders();
    // 显示所有订单
    void ShowOrdersLists();
    // 显示某一个订单
    static void showOrder(int i);
    // 增加订单
    int addOrder(Order *order);
    //通过id打印的订单卖家
    void printOrders4Seller(const char *id);
    //通过id打印订单买家
    void printOrders4Buyer(const char *id);
    // 查看用户
    void showUesr();
    // 删除用户
    void deleteUesr();
};

#endif
//   登陆、注销
//   查看、搜索、下架商品
//   查看所有订单
//   查看、删除用户   ---> 通过 id
