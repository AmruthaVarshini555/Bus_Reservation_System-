#ifndef __MENU_H__
#define __MENU_H__
#include<iostream>
#include<string>
#include"logger.h"
using namespace std;

class Menu
{
    public:
        Menu(){
            //LOG_INFO("\nDefault constructor of mainmenu invoked");
        }
        void design();
        void welcomeScreen();
        void mainMenu();
        void adminLogin();
        void adminMenu();
        void userLogin();
        void valid(string);
        void userMenu();
        void viewBookingsMenu();
        ~Menu(){
            //LOG_INFO("\nDestructor invoked");
        }
};
#endif /* __MENU_H__ */