
#include <stdio.h>
#include <string.h>
 
struct Marks {
   
   int   roll;
	char  name[20];
   float physics,chemistry,maths;
};
 
int main( ) {

   struct Marks Marks[5];      
       
 

 float percentage,tot;
 char name[20];
 
 for(int i=1;i<=5;i++)
 {
 	printf("Enter name of student %d :",i);
 	gets(Marks[i].name);
 	
 	
 	printf("Enter roll of student %d :",i);
 	scanf("%d",&Marks[i].roll);
 
 	
 		printf("Enter physics Marks of student %d :",i);
 	scanf("%f",&Marks[i].physics);
 
 	
 		printf("Enter chemistryMarks of student %d :",i);
	 scanf("%f",&	Marks[i].chemistry);

 		printf("Enter Maath morks of student %d :",i);
 	scanf("%f",&Marks[i].maths);
 
 	
 	tot=Marks[i].chemistry+Marks[i].physics+Marks[i].maths;
 	percentage=(tot*100)/300;
 	
 	
 	printf("Percentage Marks of student %d is %f\n",i,percentage);
 	
 	
 	
 }
  

   return 0;
}
