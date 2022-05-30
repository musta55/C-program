#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
int i,j=0,m=0,count=0;
char orgname[50],abrevname[10];


printf("Enter The  Name:");
gets(orgname);
for(i=0;i<strlen(orgname);i++)
{
abrevname[m]=orgname[j];
if(orgname[i]==' ')
{
	count++;
	if(count<=2)
	{
			abrevname[m+1]='.';
		
	}


m=m+2;
j=i;
//abrevname[m]=orgname[j];

if(count==2)
{
	for(int k=j+1;k<strlen(orgname);k++)
	{
			abrevname[m++]=orgname[k];
		
	}
}

j++;
}
}
abrevname[m]='\0';


printf("\nThe Abbrevation is :");
puts(abrevname);
getch();
return 0;
}
