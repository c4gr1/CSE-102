/******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_BLOCK_SIZE 10

/******************************************************/

/*stack struct for each disk*/

struct stack{	

	int *array;	/*array that holds disk size*/
	int currentsize;	/*variable that holds currentsize*/
	int maxsize;	/*variable that holds maxsize*/

};

/******************************************************/

struct stack *init_return(int nod);	/*Function that initializes the stack*/
int init(struct stack *s);	/*Function that controls the stack if stack succesfull or not*/

void push(struct stack *s,int d);	/*function that adds new size the array*/
int pop(struct stack *s);	/*function that takes the top elements of the array*/

void iterative(int num_of_disks, struct stack *s, struct stack *a, struct stack *d);	
/*Function that includes the algorithm  */
/* !!! I used some code blocks here from internet !!!*/

/******************************************************/

int main(){

	int nod;	/*number of disk*/
	int control1,control2,control3;	/*variables that checks the initiliation sitiuation*/
	
	printf("Enter the tower size : ");
	scanf("%d",&nod);

	struct stack *A=init_return(nod);	/*Creating starting disk*/
	control1=init(A);
	
	struct stack *B=init_return(nod);	/*Creating second disk*/
	control2=init(B);
	
	struct stack *C=init_return(nod);	/*Creating the third dsk*/
	control3=init(C);
	
	if(control1==1 && control2==1 && control3==1)	printf("\nInitialization succesfull");
	/*Calling the algorithm*/

	else  printf("\nInitialization not succesfull");
	
	printf("\n\nI IMPLEMENTED THE INIT, INIT_RETURN, PUSH & POP FUNCTIONS BUT I COULDN'T WRITE THE MY OWN ALGORITHM SO I DIDN'T WANT TO SEND HANOI FUNCTION WHICH IS VERY SIMILAR TO INTERNET ");
	
}

/******************************************************/

struct stack* init_return(int nod)
{

	/*If user enters higher than 10,have to create larger array*/
	
	if(nod>10){ 
	
	struct stack* node =  (struct stack*) malloc(nod*sizeof(struct stack)); /*Creating disk*/
    
    node -> array = (int*) malloc(nod * sizeof(int));	
    node-> currentsize = nod ;
    node -> maxsize = -1;
    
    
    return node;}
	
	else
	{
	    
    struct stack* node =  (struct stack*) malloc(sizeof(struct stack));
    
    node -> array = (int*) malloc(STACK_BLOCK_SIZE * sizeof(int));
    node-> currentsize = nod ;
    node -> maxsize = -1;       
    
    
    return node;}
}

/******************************************************/

void push(struct stack* node,int i) 
{ 
	
    
     node->maxsize++; 
 	 node->array[node->maxsize]=i;
 	 
 	
}

/******************************************************/

int pop(struct stack* node) 
{ 
	
	int x;
  
    x = node->array[node->maxsize]; 
 	node->maxsize--;
 	
 	return x;
 
}

/******************************************************/

int init(struct stack *s){

	if(s) return 1;
	else return 0;

}

/******************************************************/
