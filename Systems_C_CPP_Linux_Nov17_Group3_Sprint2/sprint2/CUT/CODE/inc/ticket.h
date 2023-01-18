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
    char *getName();
    char *getPnrNo();
    char *getDate();
    // SETTERS
    void setName(char*);
    
    private:
    //data members
    char name[BUFFER_SIZE], pnrNo[SIZE], date[BUFFER_SIZE];
    Bus bus;
 
    ~Ticket(){
        LOG_INFO("\nDestructor of ticket invoked");
    }
};
#endif // __TICKET_H__
