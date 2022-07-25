#include "../include/fontcolor.h"

// input red font
void red_print(std::string out)
{
    std::cout << "\033[1;31m" << out << "\033[0m" << std::endl;
}

// input green font
void green_print(std::string out)
{
    std::cout << "\033[32;1m" << out << "\033[0m" << std::endl;
}

// input black font
void black_print(std::string out)
{
    std::cout << "\033[1;30m" << out << "\033[1m" << std::endl;
}

// input yellow font
void yellow_print(std::string out)
{
    std::cout << "\033[33;1m" << out << "\033[0m" << std::endl;
}

// input blue font
void blue_print(std::string out)
{
    std::cout << "\033[0;34m" << out << "\033[1m" << std::endl;
}

// input purple font
void purple_print(std::string out)
{
    std::cout << "\033[1;35" << out << "\033[0m" << std::endl;
}

// input cyan font
void cyan_print(std::string out)
{
    std::cout << "\033[36m" << out << "\033[0m" << std::endl;
}

void dark_blue_print(std::string out)
{
    std::cout << std::endl;
    std::cout << "\033[0;34m" << out << "\033[1m";
}
