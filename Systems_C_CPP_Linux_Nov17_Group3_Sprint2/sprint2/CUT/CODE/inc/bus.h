#ifndef __BUS_H__
#define __BUS_H__
#include"logger.h"
#include"header.h"
#include <iostream>
#include<cstring>
using namespace std;

// CLASS BUS
class Bus
{
private:
    int maxSeats, bookedSeats;
    double busFare;
    char busNo[SIZE], source[BUFFER_SIZE], destination[BUFFER_SIZE], sourceTime[BUFFER_SIZE], destinationTime[BUFFER_SIZE];

public:
    Bus()
    {
        strcpy(busNo, "");
        maxSeats = TOTALSEATS;
        bookedSeats = BOOKEDSEATS;
        busFare = FARE;
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(sourceTime, "");
        strcpy(destinationTime, "");
        //LOG_INFO("Bus Default constructor invoked");
    }

    // METHODS
    void addBus();
    void showAllBus();
    void showBusDetails();
    void viewBusDetails();
    void deleteBus();
    void editBus();

    // GETTERS
    char *getBusNo()
    {
        return busNo;
    }

    char *getSource()
    {
        return source;
    }
    char *getDestination()
    {
        return destination;
    }
    char *getSourceTime()
    {
        return sourceTime;
    }
    char *getDestinationTime()
    {
        return destinationTime;
    }
    int getBookedSeats()
    {
        return bookedSeats;
    }
    int getMaxSeats()
    {
        return maxSeats;
    }
    double getBusFare()
    {
        return busFare;
    }
// SETTERS
    void setBookedSeats()
    {
        bookedSeats=bookedSeats + 1;
    }
    void setCancelTicket()
    {
       bookedSeats=bookedSeats - 1;
    }
    void setSource(char *s)
    {
        if (s && s[0])
            strcpy(source, s);
    }
    void setDestination(char *d)
    {
        if (d && d[0])
            strcpy(destination, d);
    }
    void setSourceTime(char *s)
    {
        if (s && s[0])
            strcpy(sourceTime, s);
    }
    void setDestinationTime(char *d)
    {
        if (d && d[0])
            strcpy(destinationTime, d);
    }
    void setBusFare(double f)
    {
        if (f)
            busFare = f;
    }
    ~Bus(){
        //LOG_INFO("\nBus Destructor invoked");
    }
};
#endif //__BUS_H__
