#include "unity.h"
#include <calendar_func.h>

void test_LeapYear(void);
void test_leapYears(void);
void test_todayOf(void);
void test_days(void);
void test_getDayNumber(void);

void setUp()
{
}

void tearDown()
{
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_LeapYear);
  RUN_TEST(test_leapYears);
  RUN_TEST(test_todayOf);
  RUN_TEST(test_days);
  RUN_TEST(test_getDayNumber);
  
  return UNITY_END();
}