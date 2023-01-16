#ifndef __LOGGER_H__
#define __LOGGER_H__
#include<iostream>
#define LOG_FMT         "Bus Reservation Sytem ||%s|%s|%-7s|%-15s|%s:%d | "
#define NEWLINE         "\n"
#define INFO_TAG        "INFO"
#define LOG_ARGS(LOG_TAG)  __TIME__,__DATE__,LOG_TAG, __FILE__,__FUNCTION__,__LINE__
#define PRINTFUNCTION(fmt, ...)          do {                                   \
                                                fprintf(stderr,fmt,__VA_ARGS__); \
                                        }while (0)
#define LOG_INFO(message,args...)       PRINTFUNCTION(LOG_FMT message NEWLINE,LOG_ARGS(INFO_TAG),## args)
#endif /*__LOGGER_H__*/