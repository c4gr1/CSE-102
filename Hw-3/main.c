#include <stdio.h>
#include <math.h>

void part1(); /* Functions for every part */
void part2();
void part3();
void part4();

int sum(int n1,int n2,int flag);	/* Functions for part 1 */
int multi(int n1,int n2,int flag);

void write_file(int number);	/* Functions for part 3-4 */
void sort_file();
void print_file();

int isprime(int a);	/* Functions for part 2 */

int main(){

	int menu_selection; /* Selection part for user to use programme */
	
	while(menu_selection!=5){
	
	printf("\nSelect operation\n");
	printf("1. Calculate sum/multiplication between two numbers\n");
	printf("2. Calculate prime numbers\n");
	printf("3. Show number sequence in file\n");
	printf("4. Sort number sequence in file\n");
	printf("-----------TO EXIT SELECT 5--------------\n");

	scanf("%d",&menu_selection);
		
	if(menu_selection == 1) part1();
	
	else if(menu_selection == 2) part2();

	else if(menu_selection == 3) part3();

	else if(menu_selection == 4) part4();
	
	else if(menu_selection == 5) printf("---Task finished---");
	
	else printf("Invalid selection");

	}
}

void part1(){

	int selection,even_or_odd;	/* Variables for user decisions */
	int num1,num2;	/* Variables for calculating user inputs */
	int i,temp,result;	/* Variables for conditions */

	printf("Select operation\n");
	printf("Please enter '0 for sum,'1' for multiplication.\n");
	scanf("%d",&selection);

	if(selection==0 || selection==1){ /* Selection part */
	
	printf("Please enter '0' to work on even numbers, '1' to work on odd numbers.\n");		 	 		scanf("%d",&even_or_odd);
		if(even_or_odd==0 || even_or_odd==1){  /* Selection part */
			printf("Please enter two different number:\n");
			scanf("%d %d",&num1,&num2);
			printf("Number 1: %d \nNumber 2: %d \n",num1,num2);
			printf("Result\n");
			if(num1>num2){		/* Conditions for if num1 higher than num2 */
				temp=num1;
				num1=num2;
				num2=temp;
			}
		}	
		else  printf("Enter correct input");			
	}
	
	switch(selection){ /* for calling to right function according to users decision */
		
		case 0 : result=sum(num1,num2,even_or_odd);
				 write_file(result);	
				 break;

		case 1 : result=multi(num1,num2,even_or_odd);
				 write_file(result);
				 break;	
														
		default : printf("Enter correct input");
			
	}
	
	if(selection==0){	/* conditions for printing the results */
		if(even_or_odd==0){
			for(i=num1+1;i<num2;i++)
				if(i%2==0){			
					if(i+1==num2 || i+2==num2)
						printf("%d = %d",i,sum(num1,num2,even_or_odd));				
					else printf("%d + ",i);
				}
		}				
		else if(even_or_odd==1){ /* conditions for printing the results */
			for(i=num1+1;i<num2;i++)
				if(i%2==1){			
					if(i+1==num2 || i+2==num2)
						printf("%d = %d",i,sum(num1,num2,even_or_odd));				
					else printf("%d + ",i);		
				}				
		}	 	
	 	printf("\nThe result is written to results.txt file.\n");		 		 		
	}
					
	if(selection==1){ /* conditions for printing the results */
		if(even_or_odd==0){
			for(i=num1+1;i<num2;i++)
				if(i%2==0){			
					if(i+1==num2 || i+2==num2)
						printf("%d = %d",i,multi(num1,num2,even_or_odd));				
					else printf("%d * ",i);
				}				
		}
		else if(even_or_odd==1){ /* conditions for printing the results */
			for(i=num1+1;i<num2;i++)
				if(i%2==1){			
					if(i+1==num2 || i+2==num2)
						printf("%d = %d",i,multi(num1,num2,even_or_odd));				
					else printf("%d * ",i);		
				}
		}					
		printf("\nThe result is written to results.txt file.\n");		
	}			
}	

int sum(int n1,int n2,int flag){


	int i,temp,sum=0;
	
	if(flag==0){ /* calculating sum of even numbers */
		for(i=n1+1;i<n2;i++)
			if(i%2==0){			
				sum=sum+i;				
		}	
	}

	if(flag==1){ /* calculating sum of odd numbers */
		for(i=n1+1;i<n2;i++)
			if(i%2==1){			
				sum=sum+i;				
		}							
	}
	
	return sum;
}

int multi(int n1,int n2,int flag){

	int i,sum=1;

	if(flag==0){ /* calculating sum of multiplying of even numbers */
		for(i=n1+1;i<n2;i++)
			if(i%2==0){			
				sum=sum*i;
		}	
	}

	if(flag==1){ /* calculating sum of multiplying of odd numbers */
		for(i=n1+1;i<n2;i++)
			if(i%2==1){			
				sum=sum*i;
		}							
	}
	
	return sum;
}

void part2(){

	int i,num;
		
	printf("Please enter an integer: ");
	scanf("%d",&num);
			
	if(num<2) printf("Enter correct input");
	
	for(i=2;i<num;i++){	/* Controlling the functions return value */
		
		if(isprime(i)!=0) printf("%d is not a prime number,it is divisible by %d.\n",i,isprime(i));
		if(isprime(i)==0) printf("%d is a prime number\n",i);
	}
		
}

int isprime(int a){

	int flag1=0,flag2; /* Variables for controlling conditions */
	int i;
	int root=sqrt(a);
	
	for(i=1;i<=root;i++) /* Loops for number if  prime or not  */
		if(a%i==0)
			flag1++;	
	
	for(i=a;i>1;i--)	/* Loops for finding least divisor of number */
		if(a%i==0)
			flag2=i;							
	
	if(flag1>1) return flag2;
	
	else return 0;  	
	
}

void write_file(int number){

	FILE *fp;
	
	fp = fopen("results.txt","a+");	/* for printing the number in to txt file */
	fprintf(fp,"%d ",number);
		
	fclose(fp);

}

void part3(){

	print_file();

}

void part4(){

	sort_file();

}

void print_file(){

	FILE *fp;
	int number;
		
	 if ((fp=fopen("results.txt", "r")) == NULL) { /* for reading the number from the txt file */
      printf("File not found!\n");
  }

	else{
	
	while(!feof(fp)){
	
	fscanf(fp,"%d ",&number);
	printf("%d ",number);
	}
	
	fclose(fp);
	
	}
}

void sort_file(){
	
}




