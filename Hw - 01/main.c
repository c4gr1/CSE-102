#include <stdio.h>
#include "util.h"

int main(){

/*----------PART 1-----------*/

    int x,y,z;  /* Variables for part 1 */
    int f_i,flag=-1,control; /* Variables for part 1's function */
    int n; /* Variables for part 1's function */
    char identity_number[20];   /* Variable for part 2 and part 3 */
    int kontrol,kontrol1; /* Variables for part 2 and part 3 to control the functions return value */
    int password;   /* Variable for part 3 */
    float amount; /* Variable for part 3 */

    printf("----PART 1----\n");

    /* User part to enter the variable */
    printf("Enter the first integer: ");
    scanf("%d",&x);
    printf("Enter the second integer: ");
    scanf("%d",&y);
    printf("Enter the divisor: ");  
    scanf("%d",&z);
    
    f_i=find_divisible(x,y,z);
    
    /* Control part for the checking retun value of part 1's functions */
    if(f_i != flag){
         
        printf("The first integer between %d and %d divided by %d is %d\n",x,y,z,f_i);

        printf("Enter the number how many next:");
        scanf("%d",&n);

        control=find_nth_divisible(n,f_i,z);

        if(control>y || control<x){ /* Conditions for part 1  */
            printf("No possible to find %d. divisible between %d and %d divided by %d\n",n+1,x,y,z);
        }
        else{
            printf("The %d. integer between %d and %d divided by %d is %d\n",n+1,x,y,z,control);
        }
    }
    
    else{
        printf("There is not any integer between %d and %d can be divided by %d\n",x,y,z);
    }

/*-------------PART 2-----------------------*/

    /* user part and checking part of return value of function of part 2 */
do{

printf("\n----PART 2----\n");

printf("Enter your identity number:");
scanf("%s",identity_number);
kontrol=validate_identity_number(identity_number);
    if(kontrol==0)
        printf("invalid id no please try again\n");
}
while(kontrol==0);

do{
printf("Enter your 4 digit password:");
scanf("%d",&password);
    if(password<1000 || password>9999)  /* Conditions for finding the valid password */
        printf("invalid password please try again\n");

}
while(password<1000 || password>9999);

create_customer(identity_number,password);

/*-------------PART 3-----------------------*/

printf("\n----PART 3----\n");

/* User part */
printf("Enter your identity number:");
scanf("%s",identity_number);

printf("Enter your password :");
scanf("%d",&password);

kontrol1=check_login(identity_number,password); /* Conditions for function's value */
    if(kontrol1==0)
        printf("Invalid identity number or password\n");
    else
        printf("Login Successful\n");

printf("Enter your withdraw amount:");
scanf("%f",&amount);
printf("Withdrawable amount is: %d",withdrawable_amount(amount));

}