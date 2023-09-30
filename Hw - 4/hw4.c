#include <stdio.h>

void print_file(int a,int b ,int c);
void blue();
void yellow();
void reset();

int main(){
	
	int selection;	/* Variable for user selection */
	int coef1,coef2,coef3;	/* Variables for coefficients */
	
	do{ /* Menu Part */
	
	printf("\nSelect an operation...\n");
	printf("1. -> Enter the coefficients.\n");
	printf("2. -> Draw the graph.\n");
	printf("3. -> Print the graph into a .txt file \n");
	printf("4. -> EXIT.\n\n");
	printf("Choice: ");
	scanf("%d",&selection);
	
	if(selection<1 || selection>4) printf("Invalid selection \n"); /* Limitations for menu */
	
	if(selection==1){
	
	printf("\nPlease enter the coefficient for the following equation x=a*(y*y) + b*y +c \n\n");
	
	printf("a: ");
	scanf("%d",&coef1);
	printf("b: ");
	scanf("%d",&coef2);
	printf("c: ");
	scanf("%d",&coef3);
	
	print_file(coef1,coef2,coef3); /* Sending coefficients to file for writing */
	
	printf("\ncoefficients.txt file has been created.\n\n");
	
	}
	
	if(selection==2){
	
	int a,b,c;
	int i,j;
	
	FILE *fp;
	
	fp = fopen("coefficients.txt","r");
	
		if(fp == NULL) printf("File doesn't exist ! \n");
	
		else {
	
	fscanf(fp,"%d %d %d ",&a,&b,&c);
			
	fclose(fp);
	
	printf("\nCoefficients has been read from the coefficients.txt file. \n");
	printf("Printing the graph of x=%d(y*y) + %d*y + %d\n",a,b,c);
				
	for(i=16;i>=-15;i--){ /* Loops for controlling the coordinate system */
		for(j=-55;j<=55;j++){				
			if(j==a*i*i+b*i+c) {blue(); printf("#"); reset();} /* Conditions for equation */
			else if(i==0){
				if(i==0 && j==-55) printf("<");
				else if(i==0 && j==55) printf(">");
				else printf("-");
			}			
			else if(j==0){ 
				if(i==16 && j==0) printf("^");				
				else printf("|");
			}
			else if(i==-1 && j==-1) {yellow(); printf("0"); reset();}
			else if(j==-1 && i==5)  {yellow(); printf("%d",i); reset();}
			else if(j==-1 && i==-5) {yellow(); printf("\b%d",i); reset();}	
			else if(j==-1 && i<0 && i%5==0)  {yellow(); printf("\b\b%d",i); reset();}
			else if(j==-1 && i>0 && i%5==0)  {yellow(); printf("\b%d",i); reset();}
			else if(i==-1 && j<0 && j%10==0) {yellow(); printf("\b\b%d",j); reset();}
			else if(i==-1 && j>0 && j%10==0) {yellow(); printf("\b%d",j); reset();}		
			else printf(" ");
									 
		}
		
		printf("\n");
		
		}	
		}
	}
	
   if(selection==3){
   
   int a,b,c;
   int i,j;
	
	FILE *fp; /* File for reading to coefficients from coefficients.txt */
	FILE *fp2;	/* File for writing to graphic to graph.txt */
	
	fp = fopen("coefficients.txt","r");
		
	if(fp == NULL) printf("File doesn't exist ! \n");
	
	else {
	
	fp2 = fopen("graph.txt","w");
	
	fscanf(fp,"%d %d %d ",&a,&b,&c);
				
	fclose(fp);
	
	printf("\nCoefficients has been read from the coefficient file.\n");
	printf("The graph of x=%d(y*y) + %d*y + %d has been written to graph.txt file.\n",a,b,c);
   
    for(i=16;i>=-15;i--){ /* Loops for controlling the graphic which sent to file */
		for(j=-55;j<=55;j++){				
			if(j==a*i*i+b*i+c) fprintf(fp2,"#");	
			else if(i==0){
				if(i==0 && j==-55) fprintf(fp2,"<");
				else if(i==0 && j==55) fprintf(fp2,">");
				else fprintf(fp2,"-");
			}			
			else if(j==0){ 
				if(i==16 && j==0) fprintf(fp2,"^");			
				else fprintf(fp2,"|");
			}		
			else fprintf(fp2," ");
									 
		}
		
		fprintf(fp2,"\n");
		
		}
		
	fclose(fp2);
	
  	 }
   }	
			
   }while(selection!=4); /* Condition for the stopping the programme */
	
}

void print_file(int a,int b ,int c){

	FILE *fp;
	
	fp = fopen("coefficients.txt","w");
	
	fprintf(fp,"%d\n%d\n%d ",a,b,c);

	fclose(fp);

}

void blue(){

	printf("\033[0;34m");

}

void yellow(){

	printf("\033[0;33m");

}

void reset(){

printf("\033[0m");

}




