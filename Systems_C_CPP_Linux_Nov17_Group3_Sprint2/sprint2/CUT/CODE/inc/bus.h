// Bus header file
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
public:   
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
    
    ~Bus(){
        LOG_INFO("\nBus Destructor invoked");
    }
private: 
    //data members
    int maxSeats, bookedSeats;
    double busFare;
    char busNo[SIZE], source[BUFFER_SIZE], destination[BUFFER_SIZE], sourceTime[BUFFER_SIZE], destinationTime[BUFFER_SIZE];    
};
#endif //__BUS_H__
