#include <stdio.h>
#include <stdlib.h>
#include "util.h"

/******************************************************************************************************************/

void generate_sequence(int xs, int currentlen, int seqlen, int *seq){	/*Function that creates sequence */
	
	if(currentlen==0) { /* initializing the sequence's first index */
	
		seq[currentlen]=xs;
		
		currentlen++; /* for next index */
		
		seqlen--; 	/* Condition for exit loop */
		
		generate_sequence(xs,currentlen,seqlen,seq);
	
	}
	
	if(seqlen!=0){	
		
		if(xs%2==0){/* If the number is even */
		
		xs=xs/2;	/* we divide the number 2*/
		
		seq[currentlen]=xs;	
		
		currentlen++;
		
		seqlen--;

		generate_sequence(xs,currentlen,seqlen,seq); /*calling function again until reaches the limit */
		
		}
	
		else if(xs%2==1){	/* If the number is even */
		
		xs=3*xs+1;	/* we multiply the number with 3 and add 1 */
		
		seq[currentlen]=xs; 
		
		currentlen++;
		
		seqlen--;
		
		generate_sequence(xs,currentlen,seqlen,seq);
				
		}

	}

}

/******************************************************************************************************************/

void check_loop_iterative(void (*f)(), int xs, int seqlen, int *loop,int *looplen){

	int currentlen=0;	/* for array first index(0) initializing the variable */
	int *seq;	/* Array that keeps the sequence */
	int i,j;	/* variables for loops */
	int n;	/* temp variable for looplen */
	int ls,le;	/* variables for first and last indexes of loop sequence  */
	int z;	/* for checking the return valuo of function */
	static int flag = 0;	/* variable for printing sequence only once */

	seq=(int *) malloc((seqlen)*sizeof(int));	/* defining sequence array with dynamic allocation meethod */
			
	generate_sequence(xs,currentlen,seqlen,seq);	/* calling to function for creating sequence */
	
	n=*looplen;	/* saving the looplen value  */
			
	*looplen=*looplen-1;	/* decreasing the value for recursive function */
	
	if(flag==0) {	/* Printing the sequence */
			
		for(i=0;i<seqlen;i++) {
	
		if(i==0) printf("\n{%d, ",seq[i]);
	
		else if(i==seqlen-1) printf("%d}\n",seq[i]);
	
		else printf("%d, ",seq[i]);}
			
	}
			
	flag=1;	/* After this time sequence wont print again */
													
	if(n!=1) {	/* Checking the loop */
		
		printf("\nChecking if there is loop with lenght of %d...",n);
		
		z=has_loop(seq,seqlen,n,&ls,&le);
		
		if(z==1) {	/* If loop founds we prints its informations */
	
		printf("\n\n\nLoop detected with a lenght of %d.",n);
		printf("\nIndexes of the loop's first occurance: %d (first digit), %d (last digit)",ls,le);
		*looplen=n;
		
		for(j=0;j<n;j++) loop[j]=seq[ls+j];	/* arranging the loop array */
		
		}
		
		else check_loop_iterative(generate_sequence,xs,seqlen,loop,looplen);	/* recursive goes on */
	
	
	}
	
	if(n==1) *looplen=0;	/* exit condition */
		
}

/******************************************************************************************************************/

int has_loop(int *arr, int n, int looplen, int *ls, int *le){

	int one=0,two=0,four=0;	/* sum of indexes one :if loop finishes with 1 etc..*/
	int t,s,v;	/* variables for finding loop lenght */
	int k,b;	/* variable for array lenght */
	int p;	/* temp variable for looplen */
	
	for(b=n-1;b>=0;b--) {
	if(arr[b]==1) {one++;}	/* if loops finishes with 1 */
	else if(arr[b]==2)	{two++;}	/* if loops finishes with 2 */
	else if(arr[b]==4)	{four++;}	/* if loops finishes with 4 */
	
	}
	
	if(arr[n-1]==1){	/* if loops finishes with 1 */
	if(one%2==0) {		/* if number of 1's is even */
	
	t=(one*3)/2;
	
		if(t==looplen) {	/* if looplengt equals current variable */
		
		for(k=0;k<=n-1;k++)	{
				
			if(arr[k]==4) {	/* finding the last and first index */
					*ls=k;
					*le=k+t-1;
					break;
		
				}
		}
		
		p=1; return p;}	/* returns 1 if there is a loop  */
	
	}
	
	else if(one%2==1) {/* if number of 1's is even */
	
	t=(one*3)/2;
	
		if(t-1==looplen) {/* if looplengt equals current variable */
	
		for(k=0;k<=n-1;k++){	/* finding the last and first index */
			if(arr[k]==4) {
					*ls=k+3;
					*le=k+3+t-2;
					break;
		}
				}p=1; return p;}
	
	}
	
	else {p=0; return p;}}
	
	
	else if(arr[n-1]==2){/* if loops finishes with 2 */
	if(two%2==0) {
	two=two-2;
	
	s=(two*3)/2;
	
		if(s==looplen) {/* if looplengt equals current variable */
		
		for(k=0;k<=n-1;k++){		
			if(arr[k]==1) {
					*ls=k+3;
					*le=k+3+s-1;
					break;
		}
				}p=1; return p;}
	
	}
	
	else if(two%2==1) {
	
	s=(two*3)/2;
	
		if(s-1==looplen) {
		
		for(k=0;k<=n-1;k++){		
			if(arr[k]==1) {
					*ls=k;
					*le=k+s-2;
					break;
		}			
				}p=1; return p;}
	
	}
	
	else {p=0; return p;}}

	else if(arr[n-1]==4){ /* if loops finishes with 4 */
	if(four%2==0) {
	four=four-2;
	v=(four*3)/2;
	
		if(v==looplen) {/* if looplengt equals current variable */
		
		for(k=0;k<=n-1;k++)	{	
			if(arr[k]==2) {
					*ls=k+3;
					*le=k+3+v-1;
					break;
		}			
				}p=1; return p;}
	
	}
	
	else if(four%2==1) {
	
	v=(four*3)/2;
	
		if(v-1==looplen) {/* if looplengt equals current variable */
		
		for(k=0;k<=n-1;k++){
			if(arr[k]==2) {
					*ls=k;
					*le=k+v-2;
					break;
		}			
				}p=1; return p;}}
	
	}
	
	else {
	
	p=0; return p;}
	
	

	
}

/******************************************************************************************************************/	

void hist_of_firstdigits(void (*f)(), int xs, int seqlen, int *h, int digit){

	int currentlen=0;	/* variable for array index */
	int *seq;	/* array for sequence */
	int *temp;	/* array for number indexes */
	int k;
	int i;
		
	seq=(int *) malloc((seqlen)*sizeof(int));	/* dynamic memory allocation */
	temp=(int *) malloc((seqlen)*sizeof(int));

	generate_sequence(xs,currentlen,seqlen,seq);
		
	for(i=0;i<seqlen;i++) {first_digit(seq,temp,i);}	/* initializig the temp array */
	
		
	if(digit!=seqlen){	/* recursive histogram check loop*/
	
			k=temp[digit];
			 
			h[k-1]=h[k-1]+1;
			 			 
		hist_of_firstdigits(generate_sequence,xs,seqlen,h,digit+1);
		
	}
}

/******************************************************************************************************************/

void first_digit(int *arr,int *temp ,int n){

	while(arr[n]>=10){	/* if number is greater than 10 we have to divide 10 until smaller than 10 */
	
		arr[n]= arr[n]/10;

			
	}
	
	temp[n]=arr[n];

}

