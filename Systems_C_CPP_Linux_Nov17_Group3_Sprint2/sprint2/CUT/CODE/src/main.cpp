//Client file
#include <iostream>
#include<string>
#include<cstring>
#include<fstream>
#include"menu.h"
#include"bus.h"
#include"ticket.h"
using namespace std;

int main()
{
    Menu display;
    display.welcomeScreen();
    return 0;
}

void Menu::welcomeScreen()
{
    Menu menu;
    system("clear");
    cout<<"\n\t\t******Welcome to bus reservation system project******\n";
    cout<<"\n\t\t\t\tDeveloped By:- Group 3\n";
    cout<<"\n\tPress enter to continue..";
    getchar();
    menu.mainMenu();
}
//main menu
void Menu:: mainMenu()
{
    int choice;
    Menu obj1;
    while(1)
    {
        system("clear");
	 cout<<"\n-----------MAIN MENU------------";
        cout<<"\n1. Admin\n";
        cout<<"\n2. User\n";
        cout<<"\n3. EXIT\n";
        cout<<"\nEnter your choice";
        cin>>choice;
        switch(choice)
        {
          //main menu have 3 options user and admin exit
          case 1: obj1.adminLogin();
                  break;
          case 2: obj1.userLogin();
                  break;
          case 3: exit(EXIT_SUCCESS);
                  break;
          default: cout<<"Invalid choice";
                   obj1.mainMenu();
        }
    }
}

// Admin Login
void Menu:: adminLogin()
{
    system("clear");
    Menu admin;
    int count=0;
    string adminUsername, adminPassword;
    cout<<"\n-----------ADMIN LOGIN----------";
    //enter adminusername and password;
    cout<<"\nEnter AdminUsername:";
    cin>>adminUsername;
    cout<<"\nEnter Password";
    cin>>adminPassword;
    if(adminUsername == "group3" && adminPassword == "Capg@123")
    {
        admin.adminMenu();
        cout<<"Logged in successfully...";
    }
     else
    {
        cout<<"\nEntered wrong username or password..";
        admin.adminLogin();
    }

}

// admin menu functions
void Menu::adminMenu()
{
    int choice;
    Menu m;
    Bus b;
    Ticket t;
    while(1)
    {
        system("clear");
        cout<<"----------------ADMIN PORTAL-------------";
        cout<<"\n1. Add Bus\n";
        cout<<"\n2. View Bus\n";
        cout<<"\n3. Edit Bus\n";
        cout<<"\n4. Delete Bus\n";
        cout<<"\n5. View Bookings\n";
        cout<<"\n6. BACK\n";
        cout << "\nEnter your choice:-> ";
        cin >> choice;
        switch(choice)
        {
            case 1: b.addBus();
                    break;
            case 2: b.showAllBus() ;
                    break;
            case 3: b.editBus();
		    break;
	    case 4: b.deleteBus();
                    break;
            case 5: m.viewBookingsMenu();
                    break;
            case 6: m.mainMenu();
                    break;
            default : cout<<"Invaild choice";
                      m.adminMenu();
        }
    }
}

//userlogin
void Menu::userLogin(){
    system("clear");
    Menu login;
    int ch,tm;
    string name,username,usrname,password,pswd,line;
    ofstream fileo;
    ifstream filei;
    cout<<"\n---------USER PORTAL--------";
    cout<<"\n\t1. Login";
    cout<<"\n\t2. Register";
    cout<<"\n\t3. Exit";
    cout<<"\nEnter your choice: ";
    cin>>ch;
    while(1){
    switch(ch){
        case 1:
            cout<<"\nEnter username: ";
            cin>>username;
            cout<<"\nEnter password: ";
            cin>>password;
            filei.open("user.txt");
            if(!filei.is_open() && filei.fail())
            {
                cout<<"\nYou are not registerd, please register before login";
                filei.close();
		//continue;
            }
            getline(filei,usrname);
            getline(filei,line);
            getline(filei,pswd);
            if(username==usrname && password==pswd)
            {
                cout<<"\nYour are successfully logged in :)";
                login.userMenu();
                filei.close();
            }
            else{
                cout<<"\nwrong username or password\n please try again..";
                login.userLogin();
            }
            cout<<endl;
            break;
        case 2:
            cout<<"\nEnter your name: ";
            cin.ignore();
            getline(cin,name);
            cout<<"\nCreate username: ";
	    cin>>username;
            tm=0;
            //valid(username);
            if(tm>=3){
                //continue;
            }
            cout<<"\nCreate Password: ";
            cin>>password;
            fileo.open("user.txt");
            fileo<<username<<endl<<name<<endl<<password<<endl;
            cout<<"\nYou are registered succesfully..";
            login.userLogin();
            fileo.close();
            break;
        case 3: login.mainMenu();
                break;
        default: cout<<"\n Invalid choice..";
        	break;

      }
    }
}


void Menu:: valid(string str)
{
    string user;
    int tm;
    ifstream file;
    file.open("user.txt");
    if(!file.is_open() && file.fail())
    {
        return;
    }
    else{
        tm++;
        if(tm==3)
        {
            cout<<"\nThis username already exists\nPlease try again";
	     return;
        }
        cout<<"\nThis username already exists\n Create username: ";
        cin>>user;
        valid(user);
    }
}

//User Menu
void Menu::userMenu()
{
    int choice;
    Ticket t;
    Menu m;
    while(1)
    {
        system("clear");
        cout<<"\n---------USER MENU---------";
        cout<<"\n1. Book Ticket";
        cout<<"\n2. View Ticket";
        cout<<"\n3. Edit Ticket";
        cout<<"\n4. Cancel Ticket";
        cout<<"\n5. EXIT";
        cout<<"\nEnter your choice";
        cin>>choice;
        switch(choice)
        {
            case 1: t.bookTicket();
                    break;
            case 2: t.showTicketsByPNR();
                    break;
            case 3: t.editTicket();
                    break;
            case 4: t.cancelTicket();
                    break;
            case 5: m.mainMenu();
                    break;
            default:
                cout<<"Invaild choice";
                cout<<"\nPress enter to continue..";
		 getchar();
                m.userMenu();
        }
    }
}

//view bookings menu function
void Menu::viewBookingsMenu()
{
    int choice;
    Ticket t;
    Menu m;
    while(1)
    {
        system("clear");
        cout<<"\n----------VIEW BOOKINGS-----------\n";
        cout<<"\n1. By PNR";
        cout<<"\n2. By Name";
        cout<<"\n3. By Bus";
        cout<<"\n4. By Source";
        cout<<"\n5. By Destination";
        cout<<"\n6. All Bookings";
        cout<<"\n7. EXIT";
        cout<<"\nEnter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1: t.showTicketsByPNR();
                    break;
            case 2: t.showTicketsByName();
                    break;
            case 3: t.showTicketsByBus();
                    break;
            case 4: t.showTicketsBySource();
                    break;
            case 5: t.showTicketsByDestination();
                    break;
            case 6: t.showAllTickets();
                    break;
	    case 7: m.adminMenu();
                    break;
            default: cout<<"\nInvaild choice\n";
                     m.viewBookingsMenu();
        }
    }
}
	