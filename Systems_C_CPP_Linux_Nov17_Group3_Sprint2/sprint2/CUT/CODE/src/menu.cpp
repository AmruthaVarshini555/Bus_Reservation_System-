#include <iostream>
#include<string>
#include<cstring>
#include<fstream>
#include"menu.h"
#include"bus.h"
#include"ticket.h"
#include"header.h"
#include"logger.h"
using namespace std;

//design function
void Menu::design(){
        int i;
        for(i=0;i<40;i++){
                cout<<"*";
        }
}

//welcome screen
void Menu::welcomeScreen()
{
    Menu menu;
    system("clear");
    menu.design();
    cout<<"\nWelcome to bus reservation system project\n";
    cout<<"\nDeveloped By:- Group 3\n\n";
    menu.design();
    cout<<"\n\nPress enter to continue..\n";
    getchar();
    menu.mainMenu();
}

//main menu
void Menu:: mainMenu()
{
    int choice;
    Menu obj1;
    while(TRUE)
    {
	 system("clear");
        obj1.design();
        cout<<"\n\n\tMAIN MENU\n\n";
        obj1.design();
        cout<<"\n1. Admin\n";
        cout<<"\n2. User\n";
        cout<<"\n3. EXIT\n";
        cout<<"\nEnter your choice";
        cin>>choice;
        switch(choice)
        {
          //main menu have 3 options user and admin exit
          case ADMIN: obj1.adminLogin();
                  break;
          case USER: obj1.userLogin();
                  break;
          case EXIT: exit(EXIT_SUCCESS);
                  break;
          default: cout<<"Invalid choice\n";
                   getchar();
                   obj1.mainMenu();
        }
    }
}

// Admin Login
void Menu:: adminLogin()
{
    system("clear");
    Menu admin;
    int flag=0;
    string adminUsername, adminPassword;
    admin.design();
    cout<<"\n\n\tADMIN LOGIN\n\n";
    admin.design();
    //enter adminusername and password;
    cout<<"\n\nEnter AdminUsername: ";
    cin>>adminUsername;
    cout<<"\nEnter Password: ";
    cin>>adminPassword;
    if(flag<=3)
    {
        if(adminUsername == USERNAME && adminPassword == PASSWORD)
        {
                cout<<"\nLogged in successfully...\n";
                getchar();
                admin.adminMenu();
        }
        else
        {
        cout<<"\nEntered wrong username or password..\n";
        cout<<"\nPlease enter correct password to continue..\n";
        flag++;
        getchar();
        admin.adminLogin();
        }
     }
    else{
            cout<<"Too many attempts..";
            getchar();
            admin.mainMenu();
    }
}

// admin menu functions
void Menu::adminMenu()
{
    int choice;
    Menu m;
    Bus b;
    Ticket t;
    while(TRUE)
    {
        system("clear");
        m.design();
        cout<<"\n\n\t\tADMIN PORTAL\n\n";
        m.design();
        cout<<"\n\t1. Add Bus\n";
        cout<<"\n\t2. View Bus\n";
	cout<<"\n\t3. Edit Bus\n";
        cout<<"\n\t4. Delete Bus\n";
        cout<<"\n\t5. Show All buses\n";
        cout<<"\n\t6. View Bookings\n";
        cout<<"\n\t7. BACK\n";
        cout << "\nEnter your choice:-> ";
        cin >> choice;
        switch(choice)
        {
            case ADDBUS: b.addBus();
                         getchar();
                         break;
            case VIEWBUS: b.viewBusDetails();
                          getchar();
                          break;
            case EDITBUS: b.editBus();
                          getchar();
                          break;
            case DELETEBUS: b.deleteBus();
                            getchar();
                            break;
            case SHOWALLBUS: b.showAllBus();
                             getchar();
                             break;
            case BOOKINGSMENU: m.viewBookingsMenu();
                               getchar();
                               break;
            case BACK: m.mainMenu();
                       getchar();
                        break;
            default : cout<<"Invaild choice\n";
                      getchar();
                      m.adminMenu();
        }
    }
}

//userlogin
void Menu::userLogin(){
    system("clear");
    Menu login;
    int ch,tm=0;
    string name,username,usrname,password,pswd,line,fname;
    ofstream fileo;
    ifstream filei;
    login.design();
    cout<<"\n\t\tUSER PORTAL\n\n";
    login.design();
    cout<<"\n\t1. Login";
    cout<<"\n\t2. Register";
    cout<<"\n\t3. Exit";
    cout<<"\nEnter your choice: ";
    cin>>ch;
    while(TRUE){
        switch(ch)
        {
        case LOGIN:
            cout<<"\nEnter username: ";
            cin>>username;
            cout<<"\nEnter password: ";
            cin>>password;
            fname=username+".txt";
            filei.open(fname.c_str());
            if(!filei.is_open() && filei.fail())
            {
                cout<<"\nYou are not registered, please register before login\n\t\t'OR'\n";
                getchar();
                filei.close();
                //continue;
            }
            getline(filei,usrname);
            getline(filei,line);
            getline(filei,pswd);
            if(username==usrname && password==pswd)
            {
		cout<<"\nYou are successfully logged in :)\n";
                getchar();
                login.userMenu();
                filei.close();
            }
            else{
                cout<<"\nwrong username or password please try again..\n";
                getchar();
                login.userLogin();
            }
            cout<<endl;
            break;
        case REGISTER:
            cout<<"\nEnter your name: ";
            cin.ignore();
            getline(cin,name);
            cout<<"\nCreate username: ";
            cin>>username;
           // valid(username);
            if(tm>=3){
                    //continue;
            }
            cout<<"\nCreate Password: ";
            cin>>password;
            fname=username+".txt";
            fileo.open(fname.c_str());
            fileo<<username<<endl<<name<<endl<<password<<endl;
            cout<<"\nYou are registered succesfully.. :)\n";
            getchar();
            login.userLogin();
            fileo.close();
            break;
        case PREVIOUS: login.mainMenu();
                break;
        default:
                cout<<"\n Invalid choice..\n";
                getchar();
                break;

        }
	}
}

void Menu:: valid(string str)
{
    string user,dir;
    int tm=0;
    ifstream file;
    dir=str+".txt";
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
        //cout<<"\nThis username already exists\n Create username: ";
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
        m.design();
        cout<<"\n\n\t\tUSER MENU\n\n";
	m.design();
        cout<<"\n\t1. Book Ticket";
        cout<<"\n\t2. View Ticket";
        cout<<"\n\t3. Edit Ticket";
        cout<<"\n\t4. Cancel Ticket";
        cout<<"\n\t5. EXIT";
        cout<<"\nEnter your choice";
        cin>>choice;
        switch(choice)
        {
            case BOOKTICKET: t.bookTicket();
                             getchar();
                             break;
            case VIEWTICKET: t.showTicketsByPNR();
                             getchar();
                             break;
            case EDITTICKET: t.editTicket();
                             getchar();
                             break;
            case CANCELTICKET: t.cancelTicket();
                               getchar();
                               break;
            case GOBACK: m.mainMenu();
                    break;
            default:
                cout<<"\nInvaild choice..";
                cout<<"\nPress enter to continue..\n";
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
    while(TRUE)
    {
        system("clear");
        m.design();
        cout<<"\n\n\t\tVIEW BOOKINGS\n\n";
        m.design();
        cout<<"\n\t1. By PNR";
        cout<<"\n\t2. By Name";
        cout<<"\n\t3. By Bus";
        cout<<"\n\t4. By Source";
        cout<<"\n\t5. By Destination";
        cout<<"\n\t6. EXIT";
        cout<<"\nEnter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case TICKETBYPNR: t.showTicketsByPNR();
                              getchar();
                                break;
            case TICKETBYNAME: t.showTicketsByName();
                               getchar();
                               break;
            case TICKETBYBUS: t.showTicketsByBus();
                              getchar();
                              break;
            case TICKETBYSOURCE: t.showTicketsBySource();
                                 getchar();
                                 break;
            case TICKETBYDESTINATION: t.showTicketsByDestination();
                                      getchar();
                                      break;
            case MENU: m.adminMenu();
                    break;
            default: cout<<"\nInvaild choice\n";
                     getchar();
                     m.viewBookingsMenu();
        }
   }
}
