#include <stdio.h>
#include <stdlib.h>

/***************************************************************************/

typedef union{

	char name[50];
	char address[50];
	int phone;

}Person;

typedef union{

	float amount;
	float interestRate;
	int period;

}Loan;

typedef struct{

	Person Customer;
	Loan Loans;
	float credit[3];
	int n_loan;

}BankAccount;

/***************************************************************************/

void menu();	/*Function that prints the menu screen*/
void listCustomers(Person a[50],int k);	/* Function that prints the customers name from struct array */
void addCustomer (BankAccount a[50],Person b[50],int k);	/*Function that adds new customer to file*/
void newLoan (BankAccount a[50]);	/*Function that takes the information for loan and includes the calculation function*/
float calculateLoan(float amount, int period, float interestRate);	/*Function that calculates the loan*/
void getReport(BankAccount a[50],int k); /*Function that keeps the whole personal and their loans information and prints them to screen*/

/***************************************************************************/


int main(){
	
	int number_of_customers=0;	/*Variable that holds to customers*/
	int menu_selection;	/*Variable for menu selection*/
	Person names[50];	/* Union array for 1.selection  */
	BankAccount person[50]; /* Variable for new customers account */
	int i,j;
	
	/*For loop for filling the personal credits variable to counts how many loans customer has*/
	
	for(i=0;i<50;i++)
		for(j=0;j<3;j++) person[i].credit[j]=0;
		
	for(i=0;i<50;i++)
		 person[i].n_loan=0;	
	
	
	/* Menu part for user */
	
	do{
	
	menu();
	scanf("%d%*c",&menu_selection);
	
	
		if(menu_selection==1){
				
			listCustomers(names,number_of_customers);
							
		}

		else if(menu_selection==2){
		
			addCustomer(person,names,number_of_customers);
		
			number_of_customers++;		
				
		}
		
		else if(menu_selection==3){
				
			newLoan(person);
				
		}
		
		else if(menu_selection==4){
		
			getReport(person,number_of_customers);
		
		}
						
	}while(menu_selection!=5);	



}

/***************************************************************************/

void menu(){

	printf("\n=====================================\n");
	printf("Welcome to the Bank Management System\n");
	printf("=====================================\n");
	printf("    1. List All Customers\n");
	printf("    2. Add New Customer\n");
	printf("    3. New Loan Application\n");
	printf("    4. Report Menu\n");
	printf("    5. Exit System\n");
	printf("\nSelect : ");
		
}

/***************************************************************************/

void listCustomers(Person a[50],int k){

	int i;	/*Loop for printing the names in union array*/

	for(i=0;i<k;i++) printf("Customer %d --> %s\n",i+1,a[i].name);

}

/***************************************************************************/

void addCustomer (BankAccount a[50],Person b[50],int k){

	FILE *file;

	file = fopen("customers.txt","a+");	
	
	/* Opening file and taking the customer information for saving  */

	printf("\nEnter the customer's name : ");
	scanf("%[^\n]%*c",b[k].name);
	fprintf(file,"%s ",b[k].name);	   	
				
	printf("\nEnter the customer's Phone : ");
	scanf("%d%*c",&a[k].Customer.phone);
	fprintf(file,"%d ",a[k].Customer.phone);	   	
		
	printf("\nEnter the customer's Adress : ");
	scanf("%[^\n]%*c",a[k].Customer.address);
	fprintf(file,"%s\n",a[k].Customer.address);

		
fclose(file);	

}

/***************************************************************************/

void newLoan (BankAccount a[50]){

	int id;	/*Variable for access to customer information*/
	int p;	/*Variable for period*/
	float k,l;/*Variables for k:amount,l:interestRate*/	
	float result;/*Variable for holding the loan amount*/
	int temp;/*Variable that customers loan quantity */

	printf("\nEnter the Customers ID :");
	scanf("%d",&id);
	
	/* Limititaion for customer to cant take more 3 loans */
	
	if(a[id-1].n_loan==3) printf("\nBank CAN'T give you more credit\n");
	
	else{

	printf("\nEnter the amount: ");
	scanf("%f",&a[id-1].Loans.amount);
	k=a[id-1].Loans.amount;
	
	printf("\nEnter the Interest Rate : ");
	scanf("%f",&a[id-1].Loans.interestRate);
	l=a[id-1].Loans.interestRate/100;
	
	printf("\nEnter the period : ");
	scanf("%d",&a[id-1].Loans.period);
	p=a[id-1].Loans.period;
		
	result=calculateLoan(k,p,l);
	
	printf("\nLoan is %.2f\n",result);
		
	temp=a[id-1].n_loan;
	a[id-1].credit[temp]=result;
	
	a[id-1].n_loan++;	/*Increasing the customers loan number*/
	
	}
	

}

/***************************************************************************/

float calculateLoan(float amount, int period, float interestRate){


/*Loan Formula=Amount*(1+interestRate)^period*/

	if(period==1) return amount*(1+interestRate); 
	
	else return (1+interestRate)*calculateLoan(amount,period-1,interestRate);



}

/***************************************************************************/

void getReport(BankAccount a[50],int k){
		
	char name[50][50];	/* Variable for holding name */
	char surname[50][50];	/* Variable for holding surname */
	int phone[50];	/* Variable for holding phone */
	char address[50][50];	/* Variable for holding address */
	int i=0;	/* Variable for loops */
	int id;	/* Variable for accessing the id */
	float total;	/* Variable for sum of loans */
	int choice;	/* decision variable for 4. selection of menu */
	
	FILE *fp;
	
	fp=fopen("customers.txt","r"); 

	printf("\n1. Customer Detail\n");
	printf("2. Loan Detail\n");
	printf("Choice : ");
	scanf("%d",&choice);
			
	if(choice==1){	
			
	if((fp=fopen("customers.txt","r"))!=NULL){	/* Controlling the file existing situation */
	
	while(!feof(fp)){
			
		fscanf(fp,"%s %s %d %s ",name[i],surname[i],&phone[i],address[i]);
		printf("\nCustomer Id = %d\n",i+1);
		printf("Customer Name = %s %s\n",name[i],surname[i]);
		printf("Customer Phone = %d\n",phone[i]);
		printf("Customer Address = %s\n",address[i]);
		printf("Loans = [%.2f + %.2f +%.2f] => %.2f\n",a[i].credit[0],a[i].credit[1],a[i].credit[2],a[i].credit[0]+a[i].credit[1]+a[i].credit[2]);	
		i++;

		}
		
	fclose(fp);
			
	}
	
	else printf("\nFILE doesn't exist !!!\n");
	
	}
	
	else if(choice==2){
	
	printf("Which user's information do want you see ? ");
	scanf("%d",&id);
	
	total=a[id-1].credit[0]+a[id-1].credit[1]+a[id-1].credit[2];	/* Total loans */
	
	printf("\nTotal Credit Value = %.2f\n",total);
	
	for(i=1;i<=12;i++)	printf("%d Month Installment = %.2f\n",i,total/12);
	
	}

}

/***************************************************************************/
