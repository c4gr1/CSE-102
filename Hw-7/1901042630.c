#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define len 50  /*for string variables*/

/***********************************************************************/

void play(); /*Function that includes game's functions*/
void pick_word(char table[15][15],char puzzle_word[7][len]); /*Function that picks word from txt file and fills the game table*/
void read_file(char word[len][len]); /*Function that reads the txt file*/
void direction(char word[len],char table[15][15],int cntrl[15][15]); /*Function that sets the word's direction*/
void find_word(char table[15][15],char puzzle_word[7][len]); /*Function that under user's control*/
int check_word(char table[15][15],char user[10],int r,int c,int lenght); /*Function that checks the user's input and shows the point*/
void x_word(char table[15][15],char user[10],int r,int c,int x); /*Function that adds 'x' if the user's input is true*/
int randomize(); /*Function that makes different numbers*/

/***********************************************************************/

int main(){
		
	srand(time(NULL)); /*Function for playing different game variations everytime*/
	play(); /*To call other function we use play function*/
		
}

/***********************************************************************/

void play(){

	char table[15][15]; /*Array for game table*/
	char puzzle_word[7][len];	/*Variable for chosen 7 words from txt file*/
		
	pick_word(table,puzzle_word);	/*Part 1*/
	find_word(table,puzzle_word); 	/*Part 2*/

}

/***********************************************************************/

void pick_word(char table[15][15],char puzzle_word[7][len]){
	
	char word[len][len];	/*Variable for words which in txt file*/
	int cntrl[15][15];	/*Variable that holds the places of the words in temporary array if they exist 1 else 0 etc.*/
	int arr[7];	/*Variable for comparing chosen 7 words each other and retaking new words if same words exist  */
	int i,j,k=0,n,m;	/*i,j>>>for loops , k>>for while loop to check every successful picking different words , n,m>>>variable for holds random numbers*/
	int r,c;
	
	/*This loop select different letters for game table*/
	
	for(r=0;r<15;r++)
		for(c=0;c<15;c++) table[r][c]='a'+rand()%26;
	
	/*This loop for filling control array with 0 */
		
	for(r=0;r<15;r++)
		for(c=0;c<15;c++) cntrl[r][c]=0;	
	
	read_file(word); /*for picking words from txt file*/
	
	/*This loop checks the words if they are same or not and changes thoose*/
		
	while(k<7){
	
		n=randomize();
		arr[k]=n;
		j=k;
		
		for(i=0;i<j;i++)
			if(arr[k]==arr[i]) k--;
		
		k++;	
		
	}

	/*This loop adds words the game table  */
	
	for(i=0;i<7;i++){
		m=arr[i];
		strcpy(puzzle_word[i],word[m]);
		printf("%d. WORD %s",i+1,puzzle_word[i]);
		direction(puzzle_word[i],table,cntrl); /*for adding words with different direction to the table */
		printf("\n");
	} 
	
}

/***********************************************************************/

void read_file(char word[len][len]){

FILE *fp;

	int i=0;
	
	fp = fopen("wordlist.txt","r");
	
	/*Loop for taking words from txt file*/
	
	while(i!=50){
		
	fscanf(fp,"%s",word[i]);
	i++;
	
	}	
	
	fclose(fp);

}

/***********************************************************************/

int randomize(){

	int n;
	
	n = rand()%50; /* returns 1,2,3,....,48,49 */
	
	return n;
	
}

/***********************************************************************/

void direction(char word[len],char table[15][15],int cntrl[15][15]){

	int i,j; /*Variables for loops*/
	int lenght;	/*for find string's lenght*/
	int flag=0;	/*to check game table if the coordinates is empty or not*/
	int k;	/*Holds directions way*/
	int r,c;	/*Holds row and column index*/
	lenght=strlen(word);

	r = rand()%15;
	c = rand()%15;
	k = rand()%8;
	

	switch(k){
			
		case 0 :  if(c+lenght<15)	/*adds words to game puzzle from left to right*/
		{ 
		
		for(i=0;i<lenght;i++) {
			if(cntrl[r][c+i]==0) flag++;} /*Checks the coordinates if is empty or not */
			
		if(flag==lenght){	/*if all spaces are empty...*/
				for(i=0;i<lenght;i++){	 /*adds the words to game table*/
				table[r][c+i]=word[i];				
				cntrl[r][c+i]=1;
				}
		printf("\t row: %2d column: %2d ",r,c);		
		}		
		else direction(word,table,cntrl); /*if all spaces are not convenient for word function retake random number until finds right conditions */				
		}
		else direction(word,table,cntrl);	/*if the words overflow from gametable function retake random number */
		break;
					
		case 1:	if(c-lenght>=0){ /*adds words to game puzzle from right to left*/
		
		for(i=0;i<lenght;i++) {
			if(cntrl[r][c-i]==0) flag++;}
			
		if(flag==lenght){	
				for(i=0;i<lenght;i++){	 
				table[r][c-i]=word[i];				
				cntrl[r][c-i]=1;				
				}
		printf("\t row: %2d column: %2d ",r,c);
		}		
		else direction(word,table,cntrl);			
		}
		else direction(word,table,cntrl);			
		break;
				
		case 2: if(r+lenght<15) /*adds words to game puzzle from up to down*/
		{
		
		for(i=0;i<lenght;i++) {
			if(cntrl[r+i][c]==0) flag++;}
			
		if(flag==lenght){
				for(i=0;i<lenght;i++){	 
				table[r+i][c]=word[i];				
				cntrl[r+i][c]=1;
				}
			printf("\t row: %2d column: %2d ",r,c);	
		}		
		else direction(word,table,cntrl);	
		
		}
		else direction(word,table,cntrl);	
		break;
		
		case 3: if(r-lenght>=0){ /*adds words to game puzzle from down to up*/
		
		for(i=0;i<lenght;i++) {
			if(cntrl[r-i][c]==0) flag++;}
			
		if(flag==lenght){
				for(i=0;i<lenght;i++){	 
				table[r-i][c]=word[i];				
				cntrl[r-i][c]=1;
				}
				printf("\t row: %2d column: %2d ",r,c);
		}
		else direction(word,table,cntrl);	
		
		}
		else direction(word,table,cntrl);	
		break;
		
		case 4 :  if(c+lenght<15 && r+lenght<15) /*adds words to game puzzle diagonal*/
		{ 
		
		for(i=0;i<lenght;i++) {
			if(cntrl[r+i][c+i]==0) flag++;}
			
		if(flag==lenght){
				for(i=0;i<lenght;i++){	 
				table[r+i][c+i]=word[i];				
				cntrl[r+i][c+i]=1;
				}
				printf("\t row: %2d column: %2d ",r,c);
		}		
		else direction(word,table,cntrl);				
			
		}
		else direction(word,table,cntrl);		
		break;	
		
		case 5: if(r-lenght>=0 && c-lenght>=0) /*adds words to game puzzle diagonal*/
		{
		
		for(i=0;i<lenght;i++) {
			if(cntrl[r-i][c-i]==0) flag++;}
			
		if(flag==lenght){
				for(i=0;i<lenght;i++){	 
				table[r-i][c-i]=word[i];				
				cntrl[r-i][c-i]=1;
				}printf("\t row: %2d column: %2d ",r,c);
		}		
		else direction(word,table,cntrl);

		}
		else direction(word,table,cntrl);		
		break;	
		
		case 6: if(r-lenght>=0 && c+lenght<15){ /*adds words to game puzzle diagonal*/
		
		for(i=0;i<lenght;i++) {
			if(cntrl[r-i][c+i]==0) flag++;}
			
		if(flag==lenght){
				for(i=0;i<lenght;i++){	 
				table[r-i][c+i]=word[i];				
				cntrl[r-i][c+i]=1;
				}printf("\t row: %2d column: %2d ",r,c);
		}
		else direction(word,table,cntrl);	

		}
		else direction(word,table,cntrl);		
		break;	
		
		case 7: if(r+lenght<15 && c-lenght>=0){ /*adds words to game puzzle diagonal*/
		
		for(i=0;i<lenght;i++) {
			if(cntrl[r+i][c-i]==0) flag++;}
			
		if(flag==lenght){
				for(i=0;i<lenght;i++){	 
				table[r+i][c-i]=word[i];				
				cntrl[r+i][c-i]=1;
				}printf("\t row: %2d column: %2d ",r,c);
		}
		else direction(word,table,cntrl);	

		}
		else direction(word,table,cntrl);		
		break;
						
	}

}

/***********************************************************************/

void find_word(char table[15][15],char puzzle_word[7][len]){

	int i,j	; /*Variables for loops*/
	int r,c; /*Variables for row,column index*/
	int points=0; /*Variable for user point*/
	int left=3; /*Variable for users mistake*/
	char user[10]; /*Variable for users input */
	int lenght;	/*Variable for finding users input lenght*/
	char quit[10]=":q";	/*Variable for holding terminate command*/
	int x,go; /*go for checking user input if it is word that in txt file*/
	

	/*Loops for users conditions points,mistakes etc.*/

	do{
	
	/*Loop for printing the game table*/
	
	for(r=0;r<15;r++){
		for(c=0;c<15;c++) printf("%2c",table[r][c]);
	printf("\n");
	}
	
	printf("\nEnter WORD and COORDINATES : ");
	
	scanf("%s",user);
	
	lenght=strlen(user);
	
	/*Conditions for checking input if the user wants terminate game*/
	
	if(strcmp(quit,user)!=0) {
	
		scanf("%d %d",&r,&c);

		}
	
	else {
	
	printf("\nGame is over ! Your points : %d\n",points);
	break;
	
	}
	
	go=0;
	
	for(i=0;i<7;i++){ 
	
		if(strcmp(user,puzzle_word[i])==0) go++;
				
		}
		
	if(go==0){
	
	left--;
		
		if(left==0) printf("\nGame is over ! Your points : %d\n",points);
		else printf("\nWRONG CHOICE! YOU HAVE ONLY %d LEFTS.\n\n",left);
	
	}
		
	/*Conditions for comparing user inputs vs game words and coordinates*/
	
	else{
	
	if(user[0]==table[r][c]){ 
		
		x=check_word(table,user,r,c,lenght); /*Function that compares user string vs game words*/
				
		if(x!=0){
		
		x_word(table,user,r,c,x);	/*If users input is true that word changes to x*/
			
		points=points+2;	/*Giving user to 2 points*/
	
		/*Conditions for if user finds all words*/
		
		if(points!=14) 	printf("\nFounded! You got 2 points.Your total points: %d\n\n",points);
		
		else {
						
		for(r=0;r<15;r++){
			for(c=0;c<15;c++) printf("%2c",table[r][c]);
		printf("\n");
				}
			  
			  printf("\nGame is over ! Your points : %d\n\n",points);
			  break;
			}
		}
		
		else{ /*if users enters wrong word or coordinates*/
		
		left--;
		
			if(left==0) printf("\nGame is over ! Your points : %d\n",points);
			else printf("\nWRONG CHOICE! YOU HAVE ONLY %d LEFTS.\n\n",left);}	 	
	}
		
	else{ /*if users enters wrong word or coordinates*/
	
		left--;
		
		if(left==0) printf("\nGame is over ! Your points : %d\n",points);
		else printf("\nWRONG CHOICE! YOU HAVE ONLY %d LEFTS.\n\n",left);}
	 
	 }
	 
	}while(left!=0);
	
	

}

/***********************************************************************/

int check_word(char table[15][15],char user[10],int r,int c,int lenght){
	
	int check=0;
	int i;
	
	/* Loops for finding words coordinate and compares with table letter */
			
		for(i=0;i<lenght;i++)	{
		
			if(user[i]==table[r][c+i])  check++;
	 		 	
		 }
		 
		if (check==lenght) return 1;
		check=0;
		 
		for(i=0;i<lenght;i++) {
		 		 
			if(user[i]==table[r+i][c+i])	check++;
		 	
		 }
		 
		if (check==lenght) return 2;
		check=0;
		 		
		for(i=0;i<lenght;i++) {
		 		 
			if(user[i]==table[r+i][c])  check++;
	 	
		 }
		 
		if (check==lenght) return 3;
		check=0;
		 
		for(i=0;i<lenght;i++) {
		 
			if(user[i]==table[r+i][c-i]) check++;
		 	
		 }
		 
		if (check==lenght) return 4;
		check=0;
		
		for(i=0;i<lenght;i++) {
		 
			if(user[i]==table[r][c-i])	 check++;
  	
		 }
		 
		if (check==lenght) return 5;
		check=0;
		
		for(i=0;i<lenght;i++) {
		 
			if(user[i]==table[r-i][c-i])	check++;
			 		 	
		 }
		 
		if (check==lenght) return 6;
		check=0;
		 
		for(i=0;i<lenght;i++) {
		 
			if(user[i]==table[r-i][c])	check++;
			 		
		 }
		 
		if (check==lenght) return 7;
		check=0;
		
		for(i=0;i<lenght;i++) {	
		 
			if(user[i]==table[r-i][c+i])  check++;
	 			 	
		 }
		 
		if(check==lenght) return 8;
		
		else return 0;	/*If the users input doesnt matches with word*/
		
}

/***********************************************************************/

void x_word(char table[15][15],char user[10],int r,int c,int x){
		
		int lenght=strlen(user);
		int i ;
		
		for(i=0;i<lenght;i++){	/*if user input matches with game words adds x the founded word with right coordinate*/
		
		if(x==1) table[r][c+i]='x';
		else if(x==2) table[r+i][c+i]='x';
		else if(x==3) table[r+i][c]='x';
		else if(x==4) table[r+i][c-i]='x';
		else if(x==5) table[r][c-i]='x';
		else if(x==6)  table[r-i][c-i]='x';
		else if(x==7) table[r-i][c]='x';
		else if(x==8) table[r-i][c+i]='x';
		
	}	

}

/***********************************************************************/

/*CAGRI YILDIZ 1901042630 GEBZE TECHNICAL UNIVERSITY CSE 102 HW 7*/

/***********************************************************************/
