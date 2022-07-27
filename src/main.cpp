#include "../include/fontcolor.h"
#include "../include/menu.h"
#include "../include/init.h"
#include "../include/user.h"
#include "../include/info.h"
#include "../include/user.h"
#include "../include/Administrator.h"

#include <cstring>
using namespace std;

int main()
{
    welcomeMessage();
    successMessage();
    mainMenu("MAIN");

    return 0;
}
