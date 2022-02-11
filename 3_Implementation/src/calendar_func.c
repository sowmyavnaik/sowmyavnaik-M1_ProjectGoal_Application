#include <calendar_func.h>

int LeapYear( int y )
{
    return(y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

int leapYears( int y )
{
    return y/4 - y/100 + y/400;
}

int todayOf( int y, int m, int d) 
{
    return DayOfMonth[m] + d + ((m>2 && LeapYear(y))? 1 : 0);
}

long days( int y, int m, int d)
{
    return 365L * lastYear + leapYears(lastYear) + todayOf(y,m,d);
}
int getDayNumber(int d, int m, int y)
{ 
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}