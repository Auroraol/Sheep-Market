#include "../include/init.h"
#include "iostream"
#include "../include/fontcolor.h"

const char *BANNER = "\
\t         _                                            _        _\n\
\t        | |                                          | |      | |\n\
\t     ___| |__   ___  __   __     _  __ __   __ _ _ __| | _____| |_\n\
\t    / __| '_ \\ / _ \\/ _\\ '_  \\  | '_ ` _ \\ / _` | '__| |/ / _ \\ __|\n\
\t    \\__ \\ | | |  __/  __/ |_) | | | | | | | (_| | |  |   <  __/ |_\n\
\t    |___/_| |_|\\___|\\___| .__/  |_| |_| |_|\\__,_|_|  |_|\\_\\___|\\__|\n\
\t                        | |                                        \n\
\t                        |_|                                        \n\
\t                                                                    \n\
            ";

static const char *BANNER2 = "\
\t     _____ _                       __  __            _        _\n\
\t    / ____| |                     |  \\/  |          | |      | |\n\
\t   | (___ | |__   ___   __  _ _   | \\  / | __ _ _ __| | _____| |_\n\
\t    \\___ \\| '_ \\ / _ \\/ _ \\ '_ \\  | |\\/| |/ _` | '__| |/ / _ \\ __|\n\
\t    ____) | | | |  __/  __/ |_) | | |  | | (_| | |  |   <  __/ |_\n\
\t   |_____/|_| |_|\\___|\\___| .__/  |_|  |_|\\__,_|_|  |_|\\_\\___|\\__|\n\
\t                          | |                                     \n\
\t                          |_|                                     \n\
";

static const char *SUCCESS = "\t\t*** Operation Successful! ***";
static const char *FAILURE = "\t\t*** Operation Failed! ***";
static const char *ILLEGAL = "\t\t*** Illegal Input! ***";
static const char *LOADING = "\t\t*** Loading ... ***";
static const char *EXITING = "\t\t*** Exiting ... ***";

// 打印
void welcomeMessage()
{
    red_print("welcome to");
    blue_print(BANNER2);
    std::cout << std::endl;
}

void successMessage()
{
    green_print(SUCCESS);
}

void failureMessage()
{
    yellow_print(FAILURE);
}

void illegalMessage()
{
    cyan_print(ILLEGAL);
}

void loadingMessage()
{
    purple_print(LOADING);
}

void exitingMessage()
{
    red_print(EXITING);
}
// void invalidMessage()
// {
//     printf("\n%s%s%s\n\n", FRONT_RED, INVALID, RESET);
//     printf("\n%s%sThis Function is Waiting For you to Implement ...%s\n\n",
//            FRONT_RED, BOLD, RESET);
// }