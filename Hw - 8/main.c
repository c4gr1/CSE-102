#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(){

int xs;	/* Variable for starting index */
int seqlen;	/* Variable of the sequence lenght */
int *loop;	/* Variable for loop inside seq array which is in util.c */
int looplen;	/* Variable for checking conditions if there is loop or not */
int n;	/* Variable for loop */
int digit=0;	/* Variable for finding first index of number */	
int *h;	/* Array of histogram */

	h=(int *) calloc(9,sizeof(int));	/*Defining h array with dynamic allocation method*/

	/* User's input part */

	printf("Please enter the sequance lenght: ");
	scanf("%d",&seqlen);
	
	printf("Please enter the first element: ");
	scanf("%d",&xs);
	
	looplen=seqlen/2; /* Max loop lenght can be seqlen/2 */
	
	check_loop_iterative(generate_sequence,xs,seqlen,loop,&looplen); /*for creating sequence and finding loop*/
	
	/*Conditions for loops founding */
	
	if(looplen==0) printf("\nNo loop found\n");
	
	else {printf("\nLoop: ");
		
		for(n=0;n<looplen;n++)  { /* If there is a loop we print*/
	
			if(n==0) printf("{%d, ",loop[n]);
	
			else if(n==looplen-1) printf("%d}\n",loop[n]);
	
			else printf("%d, ",loop[n]);}
			
		}
					
	hist_of_firstdigits(generate_sequence,xs,seqlen,h,digit); /*for finding histogram of loop*/
	
	printf("\nHistogram of the sequence :");
	
	for(n=0;n<9;n++)  {	/* If there is a histogram we print*/
	
		if(n==0) printf("{%d, ",h[n]);
	
		else if(n==8) printf("%d}\n",h[n]);
	
		else printf("%d, ",h[n]);}
		

}
