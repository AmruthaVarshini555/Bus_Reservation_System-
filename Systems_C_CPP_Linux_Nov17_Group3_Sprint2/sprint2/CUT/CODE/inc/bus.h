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
    Bus Bus(); //default constructor
   
    // METHODS
    void addBus();
    void showAllBus();
    void showBusDetails();
    void viewBusDetails();
    void deleteBus();
    void editBus();
    // GETTERS
    char *getBusNo();
    char *getSource();
    char *getDestination();
    char *getSourceTime();
    char *getDestinationTime();
    int getBookedSeats();
    int getMaxSeats();
    double getBusFare();
    
    // SETTERS
    void setBookedSeats();
    void setCancelTicket();
    void setSource(char *s);
    void setDestination(char *d);
    void setSourceTime(char *s);
    void setDestinationTime(char *d)
    void setBusFare(double f);
    
    ~Bus(){
        LOG_INFO("\nBus Destructor invoked");
    }
private:
    int maxSeats, bookedSeats;
    double busFare;
    char busNo[SIZE], source[BUFFER_SIZE], destination[BUFFER_SIZE], sourceTime[BUFFER_SIZE], destinationTime[BUFFER_SIZE];    
};
#endif //__BUS_H__
