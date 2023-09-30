#include <stdio.h>
#include "util.h"

int find_divisible(int x,int y,int z){

    int i,k;

    if(x>y){    /* Condition for part 1 */
        k=-1;
    }    

    else
 {   
    for(i=x;i<=y;i++){

        if(i%z==0){ /* Calculation of the finding the value of function */
            k=i;
            i=y;
        }

        else{
            k=-1;
        }
    }
 }
    return k;
}

int find_nth_divisible(int n,int f_i,int z){

    int k;

    k=f_i+z*n;  /* Formula for calculating the nth step divisor */

    return k;
}

int validate_identity_number(char identity_number[]){

    int i=0,flag=0; /* Variables for loop and controlling */
    int k,evensum=0,oddsum=0,sum=0,sum1,sum2;   /* Variables for verifying the conditions */

    if(identity_number[11]=='\0')   /* if id has more or less than 11 character  */
        flag++;   
    
    for(i=0;i<11;i++){  /* if id has invalid character */
        identity_number[i]=identity_number[i]-48;
        if(identity_number[i]>10){
            flag--;     
        }    
    }

    flag++;
  
    if(identity_number[0]!=0) /* if id starts with zero */
        flag++;

    for(k=0;k<9;k++){   /* formulas for finding 10th and 11th character of id */

        if(k%2==1)
            evensum=evensum+identity_number[k];

        if(k%2==0)
            oddsum=oddsum+identity_number[k];
    }
    
    sum1=(7*oddsum-evensum)%10;

    if(identity_number[9]==sum1)  
        flag++;
     
    for(i=0;i<10;i++){
        sum=sum+identity_number[i]; 
    }
    
    sum2=sum%10;
    
    if(identity_number[10]==sum2)
        flag++;
    
    for(i=0;i<11;i++)   /* This part for converting int to char id's number */
        identity_number[i]=identity_number[i]+48;

    if(flag==5)
        return 1;

    else
        return 0;
  
}

int create_customer(char identity_number[],int password){

    FILE *file;

    if(file=fopen("customeraccount.txt","w")){
        
        fprintf(file,"%s,%d",identity_number,password); /* for printing to the file user's information */
        
        fclose(file);

    }
    else
        printf("File not founded");

}

int check_login(char identity_number[],int password){

    FILE *file;

    char id[11];
    char comma;
    int pw;
    int i,flag=0;

    if(file=fopen("customeraccount.txt","r")){
        
        fscanf(file,"%[^,]%c%d ",id,&comma,&pw);    /* for reading user's information from file */

        for(i=0;i<11;i++)
            if(identity_number[i]==id[i])
                flag++;
        
        if(flag==11 && pw==password)    /* Veryfying to password and id with user's*/
            return 1;
        else
            return 0;
            
        fclose(file);
    }
    else
        printf("File not founded");

    
}

int withdrawable_amount(float cash_amount){

    int wd,mod;

    mod=(int)cash_amount%10;    /* for calculating the withdrawable amount */
    wd=cash_amount-mod;

    return wd;

}