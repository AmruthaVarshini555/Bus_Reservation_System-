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

        if (check = FALSE)
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