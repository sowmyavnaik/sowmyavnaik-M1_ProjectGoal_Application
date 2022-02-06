/**
 * 
 * @file calculator.c
 * @author Bharath G ()
 * @brief Example to learn Complex numbers: Add, Subtract, Divide and Multply
 * @version 0.1
 * @date 2022-02-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>  // existing library 
//#include "stdio.h" // Only for user header files

struct complex_number{
    int real;
    int imaginary;
};

/**
 * @brief Adds two complex numbers
 * 
 * @param in_operand1 Operand1 for addition
 * @param in_operand2 Operand2 for addition
 * @return struct complex_number Result of addition
 */
struct complex_number complex_add(struct complex_number in_operand1, struct complex_number in_operand2)
{
    struct complex_number temp;
    temp.real = in_operand1.real + in_operand2.real;
    temp.imaginary = in_operand1.imaginary + in_operand2.imaginary;

    return temp;
}
/**
 * @brief Subtract two complex numbers
 * 
 * @param in_operand1 Operand1 for Subtract
 * @param in_operand2 Operand2 for Subtract
 * @return struct complex_number Result of Subtraction
 */
struct complex_number complex_subtract(struct complex_number in_operand1, struct complex_number in_operand2)
{
    struct complex_number temp;
    //What if real1 = INT_MIN & real2 = INT_MIN
    temp.real = in_operand1.real - in_operand2.real;
    temp.imaginary = in_operand1.imaginary - in_operand2.imaginary;

    return temp;
}

/**
 * @brief Multiply two complex numbers
 * 
 * @param in_operand1 Operand1 for Multiplication
 * @param in_operand2 Operand2 for Multiplication
 * @return struct complex_number Result of Multiplication
 */
struct complex_number complex_multiply(struct complex_number in_operand1, struct complex_number in_operand2)
{
    struct complex_number temp;
    //TODO Correct logic for multiplication of complext numbers
    return temp;
}

enum status{
    error_divide_by_zero,
    success
};
/**
 * @brief Divides two complex numbers
 * 
 * @param in_operand1 Operand1 for Division
 * @param in_operand2 Operand2 for Division
 * @return struct complex_number Result of Division
 */
enum status complex_divide(struct complex_number in_operand1, struct complex_number in_operand2, struct complex_number* out_result_divide)
{
     /*
        A = 10;
        B = 0;
        A/B --> Crash of the program
    */
    if(0 == in_operand1.imaginary || 0 == in_operand2.imaginary)
        return error_divide_by_zero;

    //TODO Correct logic for multiplication of complext numbers
    out_result_divide->real = 1;
    out_result_divide->imaginary = 2;

    return success;
}

int main()
{
    int number11 , number12;
    printf("Enter two numbers\n");
    scanf("%d %d", &number11, &number12);

    struct complex_number cn1 = {number11, number12};

    int number21 , number22;
    printf("Enter two numbers \n");
    scanf("%d %d", &number21, &number22);

    struct complex_number cn2 = {number21, number22};
    struct complex_number result = complex_add(cn1, cn2);

    // What if number11 = INT_MAX
    printf("Sum of 2 complex number is = %d + i %d\n",result.real, result.imaginary);

    enum status operation_divide_status = complex_divide(cn1, cn2, &result);

    printf("Division of two complex number, Ststu = %d\n", operation_divide_status);
    printf("Division of 2 complex number is = %d + i %d\n",result.real, result.imaginary);
  return 0;  
}