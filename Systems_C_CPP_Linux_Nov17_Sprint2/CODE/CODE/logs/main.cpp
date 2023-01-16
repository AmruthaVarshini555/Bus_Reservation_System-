#include<iostream>
using namespace std;
#include"ticket.h"
#include"admin.h"
#include"logger.h"
int main(){
        int num;
        char name[10],pswd[10];
        cout<<"Bus Reservation System";

        cout<<"\nEnter ticket number: ";
        cin>>num;
        ticket(num);
        //LOG_INFO(" Ticket number is %d\n",ticket(12323434));
        //LOG_INFO("Ticket number invalid...: %d ",ticket(0));

        cout<<"\nEnter admin username: ";
        cin>>name;
        userName(name);
        cout<<"\nEnter password: ";
        cin>>pswd;
        userPswd(pswd);
        //LOG_INFO("\nEnter admin username: ",userName("name"));
        return 0;
}