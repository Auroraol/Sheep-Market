#ifndef _GOOD_H_
#define _GOOD_H_
#include "config.h"

// good state
typedef enum
{
    SELLING,
    SOLD,
    BANNED
} State;

// type definition of good
typedef struct
{
    char id[MAX_LEN];
    char name[MAX_LEN];
    double price;
    char seller_id[MAX_LEN];
    State state;
    char date[MAX_LEN];
    char description[MAX_LEN];
} Good;

// 显示某一商品
static void showGood(int i);

//显示所有商品
void showGoods();

// 搜索商品
int searchGoodName(const char *name);

/**
 * @brief 搜索商品id
 *
 * @param id good id to be searched
 * @param sta good status
 * @return int -1 if failed else index in goods
 */
int searchGoodID(const char *id, const char *sta = nullptr);

/**
 * @brief 商品下架
 *
 * @param id good id to be deleted
 * @param who who does the deletion
 * @return int 0 if failed else 1
 */
int deleteGood(const char *id);

/**
 * @brief pull all good infomation from external file
 *
 */
void pullGoods();

/**
 * @brief push all good information into external file
 *
 */
void pushGoods();

/**
 * @brief Get the Good object
 *
 * @param idex index
 * @return User* pointer to result good
 */

Good *getGood(int idex);

// /**
//  * @brief add Good g to goods
//  *
//  * @param u good to be added
//  * @return int 0 if failed else 1
//  */
// int addGood(Good *g);

// /**
//  * @brief 打印某个商品
//  *
//  */
// void printGoods();

// /**
//  * @brief print search results for buyer
//  *
//  * @param name good name to be searched
//  */
// void searchGoodName4Buyer(const char *name);

// /**
//  * @brief print search results for administrator
//  *
//  * @param name good name to be searched
//  */
// void searchGoodName4Admin(const char *name);

// /**
//  * @brief good information
//  *
//  * @param i good index
//  */
// void goodInfo(int i);

// /**
//  * @brief print goods with seller id
//  *
//  * @param id seller id
//  */
// void printGoods4Seller(const char *id);

// /**
//  * @brief print avaliable goods
//  *
//  * @param id buyer id
//  */
// void printGoods4Buyer(const char *id);

#endif