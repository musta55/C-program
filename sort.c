#include<stdio.h>
#include<string.h>



struct employee {
    char name[40];
    char country[40];
    int age;
    int salary;

};



int main()
{
	freopen("SORT.txt","r",stdin);
    int i,n;
    printf("Enter  the Number of employee:");
    scanf("%d",&n);

    struct employee office[n],temp;
    int j=0;
   

    for(i=0;i<n;i++){
        scanf("%s %s %d %d",&office[i].name,&office[i].country,&office[i].age,&office[i].salary);
    }
    
     for (i = 1; i < n; i++)
        for (j = 0; j < n - i; j++)
        {
            if (office[j].salary< office[j + 1].salary)
            {
                temp = office[j];
                office[j] = office[j + 1];
                office[j + 1] = temp;
            }
        }
    
    
  
    
     for(i=0;i<n;i++){
        
            printf("%s  %s   %d   %d\n",office[i].name,office[i].country,office[i].age,office[i].salary);
     }

}
