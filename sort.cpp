#include<stdio.h>
#include<string.h>



using namespace std;

struct employee {
    char name[40];
    char country[40];
    int age;
    int salary;

};



//bool compareSalary(employee b1, employee b2) {
//   if(b1.salary > b2.salary) {
//      return true;
//   } return false;
//}

int main()
{
		freopen("SORT.txt","r",stdin);
    int i,n;
    printf("Enter  the Number of employee:");
    scanf("%d",&n);

    struct employee office[n];
    int temp=0,j=0;
   

    for(i=0;i<n;i++){
        scanf("%s %s %d %d",&office[i].name,&office[i].country,&office[i].age,&office[i].salary);
    }
    
     for (i = 1; i < n; i++)
        for (j = 0; j < n - i; j++)
        {
            if (strcmp(employee[j].salary, employee[j + 1].salary) > 0)
            {
                temp = employee[j];
                employee[j] = employee[j + 1];
                employee[j + 1] = temp;
            }
        }
    
    
    
    
    
    
    
    
  //   sort(office, office + n, compareSalary);
    printf("\n \n \n");
    char matching_country[]="Bangladesh";
    
    
    
    
     for(i=0;i<n;i++){
        
            printf("%s  %s   %d   %d\n",office[i].name,office[i].country,office[i].age,office[i].salary);
     }

}
