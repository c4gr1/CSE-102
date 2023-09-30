#include <stdio.h>
#include <math.h>
#define PI 3.14

int take_value();	/* Function for the controlling the user's menu decision */
float take_input();	/* Function for the controlling the user's calculation inputs */
/*----------------------------------*/
int select_shape(); /* Function that takes the user's shape choice */
int select_calc();	/* Function that takes the user's calculation choices */
int calculate(int (),int ()); /* Function that calculate the user's choices */
/*----------------------------------*/
int calc_triangle(int s);	/* Function for triangle calculations */
int check_triangle(float a,float b,float c); /* Function for controlling triangle if is valid or not */
void triangle_area(float a,float b,float c);	
void triangle_perimeter(float a,float b,float c);
/*----------------------------------*/
int calc_quadrilateral(int s);	/* Function for quadrilateral calculations */
void quad_area(float a,float b,float c,float d);
void quad_perimeter(float a,float b,float c,float d);
/*----------------------------------*/
int calc_circle(int s);	/* Function for circle calculations */
void circle_area(float a);
void circle_perimeter(float a);
/*----------------------------------*/
int calc_pyramid(int s);	/* Function for pyramid calculations */
void pyramid_area(float a,float b);
void pyramid_perimeter(float a);
void pyramid_volume(float a,float b);
/*----------------------------------*/
int calc_cylinder(int s);	/* Function for cylinder calculations */
void cylinder_area(float a,float b);
void cylinder_perimeter(float a);
void cylinder_volume(float a,float b);
/*----------------------------------------------------------*/

enum Shapes{Triangle=1,Quadrilateral,Circle,Pyramid,Cylinder}; /* Enum types for shapes */
enum Calculators{Area=1,Perimeter,Volume};	/* Enum types for calculations */

/*----------------------------------------------------------*/

int main(){
	
	int f;	/* Variable for holding function into infinite loop */
		
	printf("Welcome to the geometric calculator !\n\n");

	do{
	f=calculate(select_shape,select_calc);
	}while(f!=0);	/* If user select 0 program is going to terminate */
	
}

/*----------------------------------------------------------*/

int select_shape(){

	int a;	/* Variable for user's shape selection */

	printf("Select a shape to calculate:\n");
	printf("----------------------------\n");
	printf("1. Triangle\n");
	printf("2. Quadrilateral\n");
	printf("3. Circle\n");
	printf("4. Pyramid\n");
	printf("5. Cylinder\n");
	printf("0. Exit\n");
	printf("----------------------------\n");		
	printf("Input : ");
	
	a=take_value();

	return a;

}

/*----------------------------------------------------------*/

int select_calc(){

	int a;	/* Variable for user's calculation selection */
	do{
	printf("\nSelect calculator:\n");
	printf("----------------------------\n");
	printf("1. Area\n");
	printf("2. Perimeter\n");
	printf("3. Volume\n");
	printf("0. Exit\n");
	printf("----------------------------\n");
	printf("Input : ");
	
	a=take_value();	
	}while(a<0 || a>3);
		
	return a;			
}

/*----------------------------------------------------------*/

int calculate(int a(),int b()){

	int shape,calculate;	/* Variables for holding the value of functions */
	
		shape=a();
		
	if(shape!=0){	/* Limitation for code if user select 0 */
		calculate=b();
			if(calculate==0)		
				return 0;
				
			else{
			
				switch(shape){
	
				case Triangle : calc_triangle(calculate); break;
				
				case Quadrilateral : calc_quadrilateral(calculate); break;
	
				case Circle : calc_circle(calculate); break;
				
				case Pyramid : calc_pyramid(calculate); break;
				
				case Cylinder : calc_cylinder(calculate); break;
	
						}
			
				}	
		}
	
	return shape;
		
}

/*----------------------------------------------------------*/

int calc_triangle(int s){

	float a,b,c,d;	/* Variables for calculations (d for controlling the trianle if valid or not)*/
	
	switch(s){
	
		case Area:	do{
					printf("\nPlease enter three sides of triangle:\n");
					a=take_input();
					b=take_input();
					c=take_input();
					d=check_triangle(a,b,c); 
					if(d==0) printf("\nERROR ! Please enter a valid triangle\n"); }while(d==0);
					triangle_area(a,b,c);
					break;
		
		case Perimeter: do{
						printf("\nPlease enter three sides of triangle:\n");
						a=take_input();
						b=take_input();
						c=take_input();	
						d=check_triangle(a,b,c);
	                    if(d==0) printf("\nERROR ! Please enter a valid triangle\n"); }while(d==0);
						triangle_perimeter(a,b,c);
						break;
		
		case Volume:	printf("\nERROR ! You cannot calculate the volume of a triangle.");
						printf("Please try again\n\n");
					 	break;
		
		
	}
		
}

/*----------------------------------------------------------*/

int check_triangle(float a,float b,float c){

	if(a>=b+c || b>=a+c || c>=a+b) return 0;	/* Conditions for invalid triangle */

	else return 1;
}

/*----------------------------------------------------------*/

void triangle_area(float a,float b,float c){

	float area,s,r;
	
	s=(a+b+c)/2;
	
	r=s*(s-a)*(s-b)*(s-c);

	area=sqrt(r);	/* Using heron formulas for finding the area */
	
	printf("\nArea of TRIANGLE : %.2f\n\n",area);

}

/*----------------------------------------------------------*/

void triangle_perimeter(float a,float b,float c){

	float perimeter;

	perimeter=a+b+c;	/* For finding perimeter*/

	printf("\nPerimeter of TRIANGLE : %.2f\n\n",perimeter);

}

/*----------------------------------------------------------*/

int calc_quadrilateral(int s){

	float a,b,c,d; /* Variables for quadrilateral */

	printf("\nPlease enter four sides of Quadrilateral:\n");
	
	switch(s){
	
		case Area:	a=take_input();
					b=take_input();
					c=take_input();
					d=take_input();
					quad_area(a,b,c,d);
					break;
		
		case Perimeter: a=take_input();
						b=take_input();
						c=take_input();
						d=take_input();	
						quad_perimeter(a,b,c,d); 
						break;
		
		case Volume:	printf("\nERROR ! You cannot calculate the volume of a quadrilateral.");
						printf("Please try again\n\n");
					 	break;
		
		
	}
	
}

/*----------------------------------------------------------*/

void quad_area(float a,float b,float c,float d){

	float s,r,area;
	
	s=(a+b+c+d)/2;
	
	r=(s-a)*(s-b)*(s-c)*(s-d);	
	
	area=sqrt(r); /* Using Brahmagupta's formlua for finding area*/
	
	printf("\nArea of QUADRILATERAL : %.2f \n\n",area);

}

/*----------------------------------------------------------*/

void quad_perimeter(float a,float b,float c,float d){

	float perimeter;
	
	perimeter=a+b+c+d;	/* for calculating perimeter*/
	
	printf("\nPerimeter of QUADRILATERAL : %.2f \n\n",perimeter);

}

/*----------------------------------------------------------*/

int calc_circle(int s){

	float r;	/* Variable for radius of circle */
	
	printf("\nPlease enter the radius of Circle :\n");

	switch(s){
	
		case Area :	r=take_input();
					circle_area(r); break;
	
	    case Perimeter : r=take_input();
	    				 circle_perimeter(r); break;
	    
	    case Volume :	printf("\nERROR ! You cannot calculate the volume of a Circle.");
						printf("Please try again\n\n");
					 	break;
	} 

}

/*----------------------------------------------------------*/

void circle_area(float a){

	float area=PI*a*a;	/* Area formula for circle that R=pi*r*r*/

	printf("\nArea of CIRCLE : %.2f \n\n",area);


}

/*----------------------------------------------------------*/

void circle_perimeter(float a){

	float perimeter=2*PI*a;	/* Perimeter formula for circle that S=2*pi*r */

	printf("\nPerimeter of CIRCLE : %.2f \n\n",perimeter);

}

/*----------------------------------------------------------*/

int calc_pyramid(int s){

	float a,b;	/* Variables for height and side */
	
	switch(s){
	
		case Area :	printf("\nPlease enter the base side and slant height of a Pyramid :\n");
					a=take_input();
					b=take_input();
					pyramid_area(a,b); break;
	
	    case Perimeter : printf("\nPlease enter the base side of a Pyramid :\n");	
	    				 a=take_input();
	    				 pyramid_perimeter(a); break;
	    
	    case Volume :	printf("\nPlease enter the base side and height of a Pyramid :\n");	
	    				a=take_input();
	    				b=take_input();
	    				pyramid_volume(a,b); break;
	}


}

/*----------------------------------------------------------*/

void pyramid_area(float a,float b){

	float base_area,lateral_area,total_area; 

	base_area=a*a;	/* base area formula */
	
	lateral_area=2*a*b; /* lateral area formula */
	
	total_area=base_area+lateral_area;	/* total area formula */

	printf("\nBase Surface of a PYRAMID : %.2f \n",base_area);
	
	printf("\nLateral Surface of a PYRAMID : %.2f \n",lateral_area);
	
	printf("\nSurface Area of a PYRAMID : %.2f \n\n",total_area);
	
}

/*----------------------------------------------------------*/

void pyramid_perimeter(float a){


 float perimeter=a*a;	/* for finding perimeter */
 
 printf("\nBase Surface Perimeter of a PYRAMID : %.2f \n\n",perimeter);

}

/*----------------------------------------------------------*/

void pyramid_volume(float a,float b){

	float volume=(a*a*b)/3; /* Volume formula of pyramid */

	printf("\nVolume of a PYRAMID : %.2f \n\n",volume);

}

/*----------------------------------------------------------*/

int calc_cylinder(int s){

	float a,b; /* Variables for cylinder's height and side */
	
	switch(s){
	
		case Area :	printf("\nPlease enter the radius and height of a Cylinder:\n");
					a=take_input();
					b=take_input();
					cylinder_area(a,b); break;
	
	    case Perimeter : printf("\nPlease enter the radius and height of a Cylinder :\n");	
	    				 a=take_input();
	    				 cylinder_perimeter(a); break;
	    
	    case Volume :	printf("\nPlease enter the radius and height of a Cylinder :\n");	
	    				a=take_input();
	    				b=take_input();
	    				cylinder_volume(a,b);	
					 	break;
	}


}

/*----------------------------------------------------------*/

void cylinder_area(float a,float b){

	float base_area,lateral_area,total_area; 
	
	base_area=PI*a*a;	/* base area formula*/
	
	lateral_area=2*PI*a*b;	/* lateral area formula*/
	
	total_area=2*base_area+lateral_area;	/* total area */

	printf("\nBase Surface of a CYLINDER : %.2f \n",base_area);
	
	printf("\nLateral Surface of a CYLINDER : %.2f \n",lateral_area);
	
	printf("\nSurface Area of a CYLINDER : %.2f \n\n",total_area);	

}

/*----------------------------------------------------------*/

void cylinder_perimeter(float a){

	float perimeter=2*PI*a;	/* for calculating perimeter*/
	
	printf("\nBase Surface Perimeter of a CYLINDER : %.2f \n\n",perimeter);
	
}

/*----------------------------------------------------------*/

void cylinder_volume(float a,float b){

	float volume=PI*a*a*b;	/* for calculating cylinder volume */
	
	printf("\nVolume of a CYLINDER : %.2f \n\n",volume);

}

/*----------------------------------------------------------*/

int take_value(){

	int selection,status,temp;	/* selection:user input-temp:for collect garbega value-
	status : check user input */

	status=scanf("%d",&selection);	

	while(status!=1){	/* if user enter invalid input this loop will ask again and again*/
		while((temp=getchar()) != EOF  && temp != '\n'){
		printf("ERROR ! Please enter a valid entry:\n\n");
		status=scanf("%d",&selection);
			}
		}
		
	while(selection<0 || selection>5){	/* Limitation for user to choice correct menu input */
	
	printf("ERROR ! Please enter a valid entry:\n\n");
	status=scanf("%d",&selection);
	
	while(status!=1){
		while((temp=getchar()) != EOF  && temp != '\n'){
		printf("ERROR ! Please enter a valid entry:\n\n");
		status=scanf("%d",&selection);
			}
		}
	
	}

	return selection;	

}

/*----------------------------------------------------------*/

float take_input(){

	float selection,status,temp;

	status=scanf("%f",&selection);

	while(status!=1){
		while((temp=getchar()) != EOF  && temp != '\n'){
		printf("ERROR ! Please enter a valid entry:\n\n");
		status=scanf("%f",&selection);
			}
		}
		
	while(selection<=0){ /* Limitation for user to choice correct calculation input */
	
	printf("ERROR ! Please enter a valid entry:\n\n");
	status=scanf("%f",&selection);
	
	while(status!=1){
		while((temp=getchar()) != EOF  && temp != '\n'){
		printf("ERROR ! Please enter a valid entry:\n\n");
		status=scanf("%f",&selection);
			}
		}
	
	}

	return selection;	

}

/*----------------------------------------------------------*/
