//header file for utils
#ifndef __UTILS_H__
#define __UTILS_H__
#include<iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;
//this function for to generate PNR number and it allows the passenger to check or manage their bookings in short time.
string generatePNR(int n)
{
    srand(time(0));
    string pnr;
    int randomNo = rand() % n;
    pnr = "PNR" + to_string(randomNo);
    return pnr;
}

//this function is used to get the date i.e local date
string getCurrentDate()
{
    time_t t = time(NULL);
    tm *tPtr = localtime(&t);
    return to_string(tPtr->tm_mday) + "-" + to_string((tPtr->tm_mon) + 1) + "-" + to_string((tPtr->tm_year) + 1900);
}
#endif // __UTILS_H__
