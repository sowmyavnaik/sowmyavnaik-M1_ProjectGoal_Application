/**
 * @file calendar_func.h
 * @author Sowmya (you@domain.com)
 * @brief Calendar application
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __calendar_func_H__
#define __calendar_func_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct {
  int day;
  int month;
  int year;
  char note[255];
} Note;

int LeapYear( int year ); 
    /**
     * @brief 
     * 
     * @param year 
     * @return int 
     */

int leapYears( int year ); 
/**
 * @brief 
 * 
 * @param y 
 * @param m 
 * @param d 
 * @return int 
 */

int todayOf( int y, int m, int d); 
/**
 * @brief 
 * 
 * @param y 
 * @param m 
 * @param d 
 * @return long 
 */

long days( int y, int m, int d);
/**
 * @brief 
 * 
 * @param y 
 * @param m 
 */

int getDayNumber(int d,int m,int y);
/**
 * @brief Get the Name object
 * 
 * @param day 
 * @return char* 
 */

#endif  