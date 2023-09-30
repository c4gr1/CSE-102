#include <stdio.h>
#include "util.h"


int main() {
    /* Variables for user numerator choices */
    int usernum1,usernum2;
    /* Variables for user denominator choices */
    int userdenom1,userdenom2;
    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A fractional number: 13/7 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    /*---Information part--- */
    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    /*---Addition part---*/
    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*---Subtraction part---*/
    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*---Multiplication part---*/
    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*---Division part---*/
    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*Part of the user choice*/
    printf("\n");
    printf("Enter the first numerator and denominator :");
    scanf("%d %d",&usernum1,&userdenom1);

    printf("Enter the second numerator and denominator :");
    scanf("%d %d",&usernum2,&userdenom2);
    printf("\n");  

    printf("Results of the %d//%d and %d//%d are :\n",usernum1,userdenom1,usernum2,userdenom2);    

    /*---Addition part---*/
    printf("Addition: ");
    fraction_add(usernum1, userdenom1, usernum2, userdenom2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*---Subtraction part---*/
    printf("Subtraction: ");
    fraction_sub(usernum1, userdenom1, usernum2, userdenom2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*---Multiplication part---*/
    printf("Multiplication: ");
    fraction_mul(usernum1, userdenom1, usernum2, userdenom2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*---Division part---*/
    printf("Division: ");
    fraction_div(usernum1, userdenom1, usernum2, userdenom2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

  return(0);

}
