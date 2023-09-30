#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main() {

    int selection; /* Variable for the problem selection */
    double pl,pw,sl,sw; /* Variables for problem 1 */
    double x1,x2,x3;  /* Variables for problem 2 */
    int x4,x5; 
    double y1,y2; /* Variables for problem 3 */
    int y3,y4,y5;

    /* Ask for the problem selection (1,2,3) .....  */
    printf("Which problem do you want to solve ? :");
    scanf("%d",&selection);

    /* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
    /* Compare performances and print results */
    if(selection==1){ 
        printf("Enter the pl and pw inputs :\n");
        scanf("%lf %lf %lf %lf",&pl,&pw,&sl,&sw);
        if(dt1a(pl,pw)=='b' && dt1b(pl,pw) == 'b') printf("Result is Setosa");
        if(dt1a(pl,pw)=='o' && dt1b(pl,pw) == 'o') printf("Result is Virginica");
        if(dt1a(pl,pw)=='g' && dt1b(pl,pw) == 'g') printf("Result is Versicolor");
        if(dt1a(pl,pw)=='b' && dt1b(pl,pw) == 'o') printf("Result is Setosa and Virginica");
        if(dt1a(pl,pw)=='b' && dt1b(pl,pw) == 'g') printf("Result is Setosa and Versicolor");
        if(dt1a(pl,pw)=='o' && dt1b(pl,pw) == 'b') printf("Result is Virginica and Setosa");
        if(dt1a(pl,pw)=='o' && dt1b(pl,pw) == 'g') printf("Result is Virginica and Versicolor");
        if(dt1a(pl,pw)=='g' && dt1b(pl,pw) == 'b') printf("Result is Versicolor and Setosa");
        if(dt1a(pl,pw)=='g' && dt1b(pl,pw) == 'o') printf("Result is Versicolor and Virginica");
    
    printf("\n");
    }

    /* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
    /* Compare performances and print results */
    else if(selection==2){
        printf("Enter input values:\n");
        scanf("%lf %lf %lf %d %d",&x1,&x2,&x3,&x4,&x5);
        if(dt2a(x1,x2,x3,x4,x5)==dt2b(x1,x2,x3,x4,x5)) /* If the result are same */
            printf("Result is = %.2lf",(dt2a(x1,x2,x3,x4,x5)+dt2b(x1,x2,x3,x4,x5))/2);
        else if((dt2a(x1,x2,x3,x4,x5)-dt2b(x1,x2,x3,x4,x5))<CLOSE_ENOUGH && (dt2a(x1,x2,x3,x4,x5)-dt2b(x1,x2,x3,x4,x5))>-(CLOSE_ENOUGH)) /* If the results are similar */
            printf("Result is = %.2lf",(dt2a(x1,x2,x3,x4,x5)+dt2b(x1,x2,x3,x4,x5))/2);
        else    /* If the results are different */
            printf("Results are = %.2lf and %.2lf",dt2a(x1,x2,x3,x4,x5),dt2b(x1,x2,x3,x4,x5));            
    
    printf("\n");    
    }
	
    /* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
    /* Compare performances and print results */		
    else if(selection==3){
	
	/* Welcome to the program which calculates 
		the your change percantage of getting loan from bank */
	
        printf("x1:age\nx2:loan amouth\nx3:student(if yes 1 else 0)\nx4:income(low:1,2-normal:3,4-high:5,6)\nx5:month(1-12)");
        printf("\nEnter input values:");
        scanf("%lf %lf %d %d %d",&y1,&y2,&y3,&y4,&y5);
        if(dt3a(y1,y2,y3,y4,y5)==dt3b(y1,y2,y3,y4,y5))  /* If the result are same */
            printf("Result is = %.2lf",(dt3a(y1,y2,y3,y4,y5)+dt3b(y1,y2,y3,y4,y5))/2);
        else if((dt3a(y1,y2,y3,y4,y5)-dt3b(y1,y2,y3,y4,y5))<CLOSE_ENOUGH && (dt3a(y1,y2,y3,y4,y5)-dt3b(y1,y2,y3,y4,y5))>-(CLOSE_ENOUGH)) /* If the results are similar */
            printf("Result is %.2lf",(dt3a(y1,y2,y3,y4,y5)+dt3b(y1,y2,y3,y4,y5))/2);
        else  	/* If the results are different */  	
            printf("Results are = %.2lf and %.2lf",dt3a(y1,y2,y3,y4,y5),dt3b(y1,y2,y3,y4,y5)); 
    
    printf("\n");
    }

    else printf("Invalid selection");	/* Controlling the users mistake */
    
    printf("\n");
    
    return 0;
    
}
