//headers files
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include"logger.h"
#include"header.h"
#include "bus.h"
#include "ticket.h"

using namespace std;
Bus::Bus()
{
        strcpy(busNo, "");
        maxSeats = TOTALSEATS;
        bookedSeats = BOOKEDSEATS;
        busFare = FARE;
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(sourceTime, "");
        strcpy(destinationTime, "");
	LOG_INFO("\nDefault constructor invoked..");
}

//Getters
char Bus::*getBusNo()
    {
        return busNo;
    }

    char Bus:: *getSource()
    {
        return source;
    }
    char Bus:: *getDestination()
    {
        return destination;
    }
    char Bus::*getSourceTime()
    {
        return sourceTime;
    }
    char Bus::*getDestinationTime()
    {
        return destinationTime;
    }
    int Bus:: getBookedSeats()
    {
        return bookedSeats;
    }
    int Bus:: getMaxSeats()
    {
        return maxSeats;
    }
    double Bus:: getBusFare()
    {
        return busFare;
    }
 // SETTERS
    void Bus::setBookedSeats()
    {
        bookedSeats=bookedSeats + 1;
    }
    void Bus::setCancelTicket()
    {
       bookedSeats=bookedSeats - 1;
    }
    void Bus:: setSource(char *s)
    {
        if (s && s[0])
            strcpy(source, s);
    }
    void Bus:: setDestination(char *d)
    {
        if (d && d[0])
            strcpy(destination, d);
    }
    void Bus:: setSourceTime(char *s)
    {
        if (s && s[0])
            strcpy(sourceTime, s);
    }
   void  Bus::setDestinationTime(char *d)
    {
        if (d && d[0])
            strcpy(destinationTime, d);
    }
void Bus:: setBusFare(double f)
    {
        if (f)
            busFare = f;
    }

/*******************************************************************
Function name    :  Add bus
Description      :  This function will create a bus of class bus
Parameters       :  No parameters
Return type      :  No return type
*********************************************************************/

// ADD BUS
void Bus::addBus()
{
    fstream bus;
    system("clear");
    cout<<"\n--------ADD BUS---------\n";
    cout << "\nEnter Bus Number: ";
    //cin>>busNo;
    cin.ignore();
    cin.getline(busNo,SIZE);
    cout << "\nEnter Source:-> ";
    //cin>>source;
    cin.getline(source,BUFFER_SIZE);
    cout << "\nEnter Destination:-> ";
    //cin>>destination;
    cin.getline(destination,BUFFER_SIZE);
    cout << "\nEnter Source Time:-> ";
    //cin>>sourceTime;
    cin.getline(sourceTime,BUFFER_SIZE);
    cout << "\nEnter Destination Time:-> ";
    //cin>>destinationTime;
    cin.getline(destinationTime,BUFFER_SIZE);
    cout << "\nEnter Bus Fare:-> ";
    cin>>busFare;
    cout << "\nBus Added Successfully...!!\n";
    cout<<"\nPress enter to continue..\n";
    getchar();
    bus.open("buses.txt", ios::out | ios::app);
    //bus<<busNo<<","<<source<<","<<destination<<","<<sourceTime<<","<<destinationTime<<","<<busFare<<endl;
    bus.write((char *)this, sizeof(*this));
    bus.close();
    LOG_INFO("\nADDED THE BUS");
}
/*******************************************************************
Function name    :  showAllBus
Description      :  This function is to view all buses of class bus
Parameters       :  No parameters
Return type      :  No return type
*********************************************************************/

// SHOW BUS DETAILS
void Bus::showBusDetails()
{
    cout<<"\n\n\n-------------BUS--------------";
    cout << "\n\nBus No:-> " << getBusNo();
    cout << "\nSource:-> " << getSource();
    cout << "\nDestination:-> " << getDestination();
    cout << "\nTime:-> " << getSourceTime() << " - " << getDestinationTime();
    cout << "\nTotal Seats:-> " << getMaxSeats();
    cout << "\nSeats Remaining:-> " << (getMaxSeats() - getBookedSeats());
    cout << fixed << setprecision(2);
    cout << "\nBus Fare:-> "<< getBusFare();
    cout<<"\nPress enter to continue..\n";
    getchar();
    LOG_INFO("SHOW BUS DETAILS");
}
/*******************************************************************
Function name    :  view bus details
Description      :  This function is to view bus details of class bus
Parameters       :  No parameters
Return type      :  No return type
*********************************************************************/

// VIEW ALL BUS INFO
void Bus::showAllBus()
{
    system("clear");
    fstream bus;
    bus.open("buses.txt", ios::in | ios::app | ios::binary);
    if (!bus){
        cout << "\n\tFile Not Found...!!!\n";
        getchar();
    }
    else
    {
        cout<<"\n-----------BUSES-----------";
        bus.read((char *)this, sizeof(*this));
        //bus>>busNo>>source>>destination>>sourceTime>>destinationTime>>maxSeats>>bookedSeats>>busFare;
        while (!bus.eof())
        {
		showBusDetails();
            //bus>>busNo>>source>>destination>>sourceTime>>destinationTime>>maxSeats>>bookedSeats>>busFare;
            bus.read((char *)this, sizeof(*this));
        }
        bus.close();
    }
    LOG_INFO("\nVIEW ALL BUS INFO");
}
/*******************************************************************
Function name    :  Show all bus
Description      :  This function is for show all bus of class bus
Parameters       :  No parameters
Return type      :  No return type
*********************************************************************/

//Show bus details
void Bus::viewBusDetails()
{
    system("clear");
    char bNo[SIZE];
    int check = 0;
    fstream bus;
    cout<<"\n-------------VIEW BUS INFO---------------";
    cout << "\n\tEnter Bus Number:-> ";
    cin.ignore();
    cin.getline(bNo,SIZE);
    //cin>>bNo;
    system("clear");
    cout<<"\n\n-------------BUS INFO------------";
    bus.open("buses.txt", ios::in | ios::app | ios::binary);
    if (bus.fail())
    {
        cout << "\n\tCan't Open File...!!\n";
    }
    else
    {
        //bus>>busNo>>source>>destination>>sourceTime>>destinationTime>>maxSeats>>bookedSeats>>busFare;
        bus.read((char *)this, sizeof(*this));
        while (!bus.eof())
        {
            if (strcmp(getBusNo(), bNo) == 0)
            {
                showBusDetails();
                check = 1;
            }
	    bus.read((char *)this, sizeof(*this));
        }
        if (check == FALSE)
        {
            cout << "\n\tBus Not Found...!!\n";
            cout<<"\nPress enter to continue..";
            getchar();
        }
        bus.close();
    }
    LOG_INFO("\nVIEW BUS INFO");
}

/*******************************************************************
Function name    :  Edit bus
Description      :  This function is used to edit bus of class bus
Parameters       :  No parameters
Return type      :  No return type
*********************************************************************/

// EDIT BUS
void Bus::editBus()
{
    system("clear");
    char bNo[SIZE];
    int check = 0;

    fstream bus, temp;
    cout<<"\n\n\n----------EDIT BUS-----------";
    cout << "\n\tEnter Bus Number:-> ";
    cin.ignore();
    cin.getline(bNo,SIZE);
    //cin>>bNo;
    bus.open("buses.txt", ios::in | ios::app | ios::binary);
    if (bus.fail())
    {
        cout << "\n\tCan't Open File...!!\n";
    }
    else
    {
        temp.open("temp.txt", ios::out | ios::app | ios::binary);

        bus.read((char *)this, sizeof(*this));
        while (!bus.eof())
        {
            if (strcmp(getBusNo(), bNo) == 0)
	    {
                system("clear");
                cout<<"\n-----------EDIT BUS-------------";
                showBusDetails();
                char s[BUFFER_SIZE], d[BUFFER_SIZE], sTime[BUFFER_SIZE], dTime[BUFFER_SIZE];
                double fare;
                cout << "\n\tEnter Source:-> ";
                cin.getline(s, BUFFER_SIZE);
                cout << "\n\tEnter Destination:-> ";
                cin.getline(d,BUFFER_SIZE);
                cout << "\n\tEnter Source Time:-> ";
                cin.getline(sTime,BUFFER_SIZE);
                cout << "\n\tEnter Destination Time:-> ";
                cin.getline(dTime,BUFFER_SIZE);
                cout << "\n\tEnter Bus Fare:-> ";
                cin.ignore();
                cin >> fare;
                setSource(s);
                setDestination(d);
                setSourceTime(sTime);
                setDestinationTime(dTime);
                setBusFare(fare);
                temp.write((char *)this, sizeof(*this));
                check = 1;
            }
            else
            {
                temp.write((char *)this, sizeof(*this));
            }
            bus.read((char *)this, sizeof(*this));
        }

        if (check == FALSE)
        {
            cout << "\n\tBus Updated Successfully...!!\n";
            getchar();
        }
        else
        {
	    cout << "\n\tBus Not Found...!!\n";
            getchar();
        }
        cout<<"\nPress enter to continue..\n";
        getchar();
        bus.close();
        temp.close();
        remove("buses.txt");
        rename("temp.txt", "buses.txt");
    }
    LOG_INFO("\nVIEW BUS");
}
/*******************************************************************
Function name    :  Delete bus
Description      :  This function is used to delete bus of class bus
Parameters       :  No parameters
Return type      :  No return type
*********************************************************************/
// DELETE BUS
void Bus::deleteBus()
{
    system("clear");
    char bNo[SIZE];
    int check = 0;
    fstream bus, temp;
    cout<<"-----------DELETE BUS--------------";
    cout << "\n\tEnter Bus No:-> ";
    cin.ignore();
    cin.getline(bNo,SIZE);
    bus.open("buses.txt", ios::in | ios::app | ios::binary);
    if (bus.fail())
    {
        cout << "\n\tCan't Open File...!!";
    }
    else
    {
        temp.open("temp.txt", ios::out | ios::app | ios::binary);
        bus.read((char *)this, sizeof(*this));
        while (!bus.eof())
        {
            if (strcmp(getBusNo(), bNo) != 0)
            {
                temp.write((char *)this, sizeof(*this));
            }
	else
            {
                check = 1;
            }
            bus.read((char *)this, sizeof(*this));
        }

        if (check == FALSE)
        {
            cout << "\n\tBus Not Found...!!\n";
            getchar();
        }
        else
        {
            cout << "\n\tBus Deleted...!!\n";
            getchar();
        }
        cout<<"\nPress enter to continue..";
        getchar();
        bus.close();
        temp.close();
        remove("buses.txt");
        rename("temp.txt", "buses.txt");
    }
    LOG_INFO("\nDELETE BUS");
}
