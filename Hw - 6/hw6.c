#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

/*-------------------------------------------------*/

#define row 30
#define column 15

/*-------------------------------------------------*/

enum shapes{w1,w2,s,p1,p2,f,x}; /* w1 for printing . - w2 for printing : - s for printing space
								   p1 for printing player 1 - p2 for printing player 2 - f for
								   printing finish lane - x for printing penalty point
								 */

/*-------------------------------------------------*/

void blue(); /* Function for printing blue */
void yellow(); /* Function for printing yellow */
void red();	/* Function for printing red */
void green();	/* Function for printing green */
void reset();	/* Function for reseting the previous colour */
void printmap(int arr[column][row]);	/* Function that prints the current map */
void map_icons(int a[column][row]);	/* Function that fills the array with enum shapes */
int dice(); /* Function for tossing dice */
int startgame(); /* Function that decides who gonna start the game */
void conditions(int a[column][row],int s1,int s2);  /* Function that keeps the conditions for array
													when player turns around map	  														
													*/

/*-------------------------------------------------*/

int main(){
		
	int a[column][row];	/* Defining the array */
	int i;	/* Variable for loop */
	int who;	/* Variable that keeps the return value of startgame function */
	int s1=1,s2=3,m,n;	/* s1 and s2 keeps total dice value for player 1-2 and m,n for current dice value */
	
	srand(time (NULL)); /* Necessary for the different numbers when we call dice function every opening */
	
	map_icons(a);	/* Adds the enum shapes to array  */
	printmap(a);	/* Prints the map */
	who=startgame();	/* Decides which player starts */


	do{
	
	map_icons(a); /* When programme turns back do while loop we have to fill array again */
	a[1][1]=s;	/* Necessery for the not printing the previous p1 and p2 point */
	a[3][3]=s;
	
	if(who==1){	/* If player 1 starts */
	
	yellow();	
	printf("PLAYER 1... press ENTER to dice");
	getchar();	/* for waiting the user until user press enter */
	m=dice();
	printf("DICE: %d\n",m);	/*  Result of the dice function value */
	s1=s1+m;	/* Summary of total dice */
	reset();
	
	if(s1==14 || s1==34 || s1==55){ /* Penalty points conditions */
	
		s1=s1-2; 	/* When player comes penalty point user must be go 2 steps back */
		yellow();
		printf("Penalty for player 1...\n");
		reset();
	
	}
	
	
	if(s1>=79) {conditions(a,s1,s2);	/* Win conditions for winner */
				printf("\n\n\n\n");
				yellow();
				printf("***Player 1 won the game...***\n\n");
				reset();
				printmap(a); 
				break;}
	
	blue();
	printf("PLAYER 2... press ENTER to dice");
	getchar();	/* for waiting the user until user press enter */
	n=dice();
	printf("DICE: %d\n",n);	/*  Result of the dice function value */
	s2=s2+n;	/* Summary of total dice */
	reset();
	
	if(s2==10 || s2==18|| s2==28 || s2==33 || s2==42|| s2==50){ /* Penalty points conditions */
		
		s2=s2-2;
		blue();
		printf("Penalty for player 2...\n");
		reset();
		
	}
	
	if(s2>=64) {conditions(a,s1,s2);	/* Win conditions for winner */
			printf("\n\n\n\n");
			blue();
			printf("***Player 2 won the game...***\n\n");
			printmap(a);
			reset();
			break;}
	
	}
	
	else if(who==2){ /* If player 2 starts */
	
	blue();
	printf("PLAYER 2... press ENTER to dice");
	getchar();	/* for waiting the user until user press enter */
	n=dice();
	printf("DICE: %d\n",n);	/*  Result of the dice function value */
	s2=s2+n;	/* Summary of total dice */
	reset();
	
	if(s2==10 || s2==18|| s2==28 || s2==33 || s2==42|| s2==50){/* Penalty points conditions */ 
	
	s2=s2-2;
	blue();
	printf("Penalty for player 2...\n");
	reset();
	
	}
	
	if(s2>=64) {conditions(a,s1,s2);	/* Win conditions for winner */
			printf("\n\n\n\n");
			blue();
			printf("***Player 2 won the game...***\n\n");
	 		printmap(a);
	 		reset();
	 		break;}
	
	yellow();
	printf("PLAYER 1... press ENTER to dice");
	getchar();	/* for waiting the user until user press enter */
	m=dice();
	printf("DICE: %d\n",m);	/*  Result of the dice function value */
	s1=s1+m;	/* Summary of total dice */
	reset();
	
	if(s1==14 || s1==34 || s1==55){ /* Penalty points conditions */
	
		s1=s1-2;
		yellow();
		printf("Penalty for player 1...\n");
		reset();
		
	}
	
	if(s1>=79) {conditions(a,s1,s2);	/* Win conditions for winner */
				printf("\n\n\n\n");
				yellow();
				printf("***Player 1 won the game...***\n\n");
				reset();
				printmap(a); 
				break;}
	
	}
	
	conditions(a,s1,s2);	/* For players turning around map */
	printmap(a);	/* Printing map */
	
			
}while(s1<79 && s2<64);	/* Conditions for ending loop */

}

/*-------------------------------------------------*/

void map_icons(int a[column][row]){

	int i;

	for(i=0;i<row;i++)	a[0][i]=w1;	/* loop for 1st row */
	
	for(i=0;i<row;i++){	/* loop for 2st row */
		if(i==1) a[1][i]=p1;
		else if(i==14) a[1][i]=x;
		else if(i==0 || i==29) a[1][i]=w2;
		else a[1][i]=s;
		}
	
	for(i=0;i<row;i++){	/* loop for 3st row */
		if(i==1) a[2][i]=f;
		else if(i==0 || i==29) a[2][i]=w2;
		else if(i==28) a[2][28]=s; 
		else a[2][i]=w1;	
	}
	
	for(i=0;i<row;i++){	/* loop for 4st row */
		if(i==3) a[3][i]=p2;
		else if(i==10 || i==18) a[3][i]=x;
		else if(i==0 || i==2 || i== 27 || i==29) a[3][i]=w2;
		else a[3][i]=s;
		}
		
	for(i=0;i<row;i++){	/* loop for 5st row */
		if(i==3) a[4][i]=f;
		else if(i==0 || i==2 || i== 27 || i==29) a[4][i]=w2;
		else if(i==1 || i==28 || i==26) a[4][i]=s; 
		else a[4][i]=w1;	
	}	

	for(i=0;i<row;i++){		/* loop for 6st row */
		if(i==26) a[5][i]=x;
		else if(i==0 || i==2 || i==4 || i==25 || i== 27 || i==29) a[5][i]=w2;
		else a[5][i]=s;
	}
	
	for(i=0;i<row;i++){		/* loop for 7st row */
		if(i==0 || i==2 || i==4 || i==25 || i== 27 || i==29) a[6][i]=w2;
		else a[6][i]=s;
	}
	
	for(i=0;i<row;i++){		/* loop for 8st row */
		if(i==28) a[7][i]=x;
		else if(i==0 || i==2 || i==4 || i==25 || i== 27 || i==29) a[7][i]=w2;
		else a[7][i]=s;
	}
	
	for(i=0;i<row;i++){		/* loop for 9st row */
		if(i==0 || i==2 || i==4 || i==25 || i== 27 || i==29) a[8][i]=w2;
		else a[8][i]=s;
	}
	
	for(i=0;i<row;i++){		/* loop for 10st row */
		if(i==0 || i==2 || i==4 || i==25 || i== 27 || i==29) a[9][i]=w2;
		else a[9][i]=s;
	}
	
	for(i=0;i<row;i++){		/* loop for 11st row */
		if(i==26) a[10][i]=x;
		else if(i==0 || i==2 || i== 27 || i==29) a[10][i]=w2;
		else if(i==1 || i==3 || i==28) a[10][i]=s; 
		else a[10][i]=w1;	
	}
	
	for(i=0;i<row;i++){		/* loop for 12st row */
		if(i==10 || i==18) a[11][i]=x;
		else if(i==0 || i==2 || i== 27 || i==29) a[11][i]=w2;
		else a[11][i]=s;
		}
		
	for(i=0;i<row;i++){		/* loop for 13st row */
		if(i==0 || i==29) a[12][i]=w2;
		else if(i==1 || i==28) a[12][i]=s; 
		else a[12][i]=w1;	
	}
	
	for(i=0;i<row;i++){		/* loop for 14st row */
		if(i==13) a[13][i]=x;
		else if(i==0 || i==29) a[13][i]=w2;
		else a[13][i]=s;
		}
		
	for(i=0;i<row;i++)	a[14][i]=w1;	/* loop for 15st row */

}

/*-------------------------------------------------*/

void printmap(int arr[column][row]){

	int i,j;	/* loop for the printing map with conditions */
		
	for(i=0;i<column;i++){
		for(j=0;j<row;j++){
			
			if(arr[i][j]==w1) printf(".");
			else if(arr[i][j]==w2) printf(":");
			else if(arr[i][j]==p1) {yellow(); printf("1"); reset();}
			else if(arr[i][j]==p2) {blue(); printf("2"); reset();}
			else if(arr[i][j]==f) {green(); printf("-"); reset();}
			else if(arr[i][j]==x) {red(); printf("X"); reset();}
			else printf(" ");
									
		}

	printf("\n");
	}



}

/*-------------------------------------------------*/

int dice(){

	int n;
	
	n = rand()%6 + 1; /* returns 1,2,3,4,5,6 */
	
	return n;
	
}

/*-------------------------------------------------*/

int startgame(){

	int p1,p2;	
	
	printf("To start to game, players should dice and decide who is going");
	printf(" to start first according to it...\n");
	
	do{
	
	yellow();
	printf("PLAYER 1... press ENTER to dice");
	getchar();	
	p1=dice();
	printf("DICE: %d\n",p1);
	reset();
	blue();
	printf("PLAYER 2... press ENTER to dice");
	getchar();	
	p2=dice();
	printf("DICE: %d\n",p2);
	reset();
	
	/* Conditions for choosing player */
	
	if(p1>p2) {printf("\n\n*** PLAYER 1 will start the game... ***\n"); return 1;}
	else if(p1<p2) {printf("\n\n*** PLAYER 2 will start the game... ***\n"); return 2;}
	else printf("same dice value please try again\n");
	}while(p1==p2);


}

/*-------------------------------------------------*/

void conditions(int a[15][30],int s1,int s2){

	/* turning conditions for player 1 */
	
	if(s1<29) a[1][s1]=p1;
	else if(s1<41) a[s1-27][28]=p1;  
	else if(s1<68) a[13][68-s1]=p1;
	else if(s1<80) a[81-s1][1]=p1; 
	else a[1][s1-79]=p1;

	/* turning conditions for player 2 */
	
	if(s2<26) a[3][s2]=p2;
	else if(s2<35) a[s2-23][26]=p2;  
	else if(s2<58) a[11][60-s2]=p2;
	else if(s2<66) a[68-s2][3]=p2; 
	else a[3][s2-62]=p2;

}

/*-------------------------------------------------*/

void blue(){

	printf("\033[0;34m");

}

/*-------------------------------------------------*/

void yellow(){

	printf("\033[0;33m");

}

/*-------------------------------------------------*/

void red(){

	printf("\033[0;31m");

}

/*-------------------------------------------------*/

void green(){

	printf("\033[0;32m");

}

/*-------------------------------------------------*/

void reset(){

printf("\033[0m");

}

/*-------------------------------------------------*/
