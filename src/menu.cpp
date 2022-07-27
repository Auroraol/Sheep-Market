#include "../include/menu.h"
#include "../include/fontcolor.h"

//  Menu Type
static std::map<std::string, std::string> menuType{
    {"MAIN", "\
+==============+================+===============+========+\n\
| 1.User Login | 2.User Sign Up | 3.Admin Login | 4.Exit |\n\
+==============+================+===============+========+\n"},
    {"ADMIN", "\
+=========+==========+==========+=========+==========+=======+========+\n\
| 1.Goods | 2.Search | 3.Orders | 4.Users | 5.Delete | 6.Ban | 7.Back |\n\
+=========+==========+==========+=========+==========+=======+========+\n"},
    {"USER", "\
+=========+==========+==============+========+\n\
| 1.Buyer | 2.Seller | 3.Infomation | 4.Back |\n\
+=========+==========+==============+========+\n"},
    {"BUYER", "\
+=========+=======+==========+=========+===============+========+\n\
| 1.Goods | 2.Buy | 3.Search | 4.Order | 5.Information | 6.Back |\n\
+=========+=======+==========+=========+===============+========+\n"},
    {"SELLER", "\
+========+=========+==========+=======+=========+========+\n\
| 1.Sell | 2.Goods | 3.Modify | 4.Ban | 5.Order | 6.Back |\n\
+========+=========+==========+=======+=========+========+\n"},
    {"INFO", "\
+===============+==========+==========+========+\n\
| 1.Information | 2.Modify | 3.Top Up | 4.Back |\n\
+===============+==========+==========+========+\n"},
    {"MODIFY", "\
+============+===========+===========+========+\n\
| 1.Password | 2.Contact | 3.Address | 4.Back |\n\
+============+===========+===========+========+\n"},
    {"GOOD", "\
+========+=========+===============+========+\n\
| 1.Name | 2.Price | 3.Description | 4.Back |\n\
+========+=========+===============+========+\n"}};

int mainMenu(std::string type)
{
    if (type == "ADMIN" || type == "BUYER")
    {
        dark_blue_print("\t\t\t\tMenu\n");
    }
    else if (type == "MAIN")
    {
        dark_blue_print("\t\t\t   Menu\n");
        // blue_print("\t\t\t   Menu\n");
    }
    else
        dark_blue_print("\t\t    Menu\n");
    black_print(menuType[type]);
    interaction();
    return 0;
}

// TODO
void interaction()
{
    using std::cin;
    using std::cout;
    using std::endl;

    char ch;
    cout << "Please choose opration: ";
    cin >> ch;
    while (ch != '4')
    {
        while (cin.get() != '\n')
            continue;
        switch (ch)
        {
        case '1':
            cout << "1";
            break;
        case '2':
            cout << "2";
            break;
        case '3':
            cout << "3";
            break;
        }
        cout << "Please choose opration: ";
        cin >> ch;
    }
}