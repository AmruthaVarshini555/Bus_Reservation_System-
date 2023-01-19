//Header file for ticket 
#ifndef __TICKET_H__
#define __TICKET_H__

#include <iostream>
#include"logger.h"
#include"header.h"
#include "bus.h"

// CLASS TICKET
class Ticket
{
public:
    Ticket(){
        LOG_INFO("\nTicket Default Constructor invoked");
    }
    //Member functions
    void generateTicket(char *, Bus);
    void displayTicket();
    void bookTicket();
    void cancelTicket();
    void editTicket();
    void showTicketsByPNR();
    void showTicketsByName();
    void showTicketsByBus();
    void showTicketsBySource();
    void showTicketsByDestination();
    void showAllTickets();
    // GETTERS
    char *getName()
    {
        return name;
    }
    char *getPnrNo()
    {
        return pnrNo;
    }
    char *getDate()
    {
        return date;
    }
     // SETTERS
    void setName(char *n)
    {
        if (n && n[0])
            strcpy(name, n);
    };
    //Default Constructor
    ~Ticket(){
        LOG_INFO("\nDestructor of ticket invoked");
    }
    private:
    //data members
    char name[BUFFER_SIZE], pnrNo[SIZE], date[BUFFER_SIZE];
    Bus bus;
};
#endif // __TICKET_H__
