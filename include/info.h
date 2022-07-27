#ifndef _INFO_H_
#define _INFO_H_
#include <string>
#include <iostream>
/**
 * @brief 生成一个给定类型ID,让程序结束后再次打开时也能够接着之前的ID生成唯一的新ID，用了一个文件src/data/id.txt来储存当前ID的最大值。
 *
 * @param dest 储存ID的目标字符串
 * @param type ID类型，U-用户，G-商品，O-订单
 */
void genID(std::string &dest, char type);

/**
 * @brief 获取当前日期
 *
 * @param dest 储存日期的目标字符串
 */
void getDate(std::string &dest);

inline void print_header(const char *divide, const char *header)
{
    std::cout << divide << std::endl;
    std::cout << header << std::endl;
    std::cout << divide << std::endl;
}

inline void print_divide(const char *divide)
{
    std::cout << divide << std::endl;
}

#endif