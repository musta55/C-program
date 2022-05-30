
#include <stdio.h>
#include <limits.h> 

#define MAX_SIZE 1000    

int main()
{
    int arr[MAX_SIZE],arr2[MAX_SIZE], size, i;
    
   
    int max1, max2,it1=0,it2=0;
 /* Input size of the array */
    printf("Enter size of the array: ");
    scanf("%d", &size);

    for(int k=0;k<size+1;k++)arr2[k]=0;
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    max1 = max2 = INT_MIN;

    for(i=0; i<size; i++)
    {
        if(arr[i] > max1)
        {
            
            max2 = max1;
            it2=it1;
            max1 = arr[i];
            it1=i;
        }
        else if(arr[i] > max2 && arr[i] < max1)
        {
           
            max2 = arr[i];
            it2=i;
        }
    }

    int j;
    
    
    
     for(i=0,j=0; i<size; i++,j++)
    {
       
        if(i==it1)
        {
        	arr2[j]=max2;
        	j++;
        	arr2[j]=max1-max2;
        
		}
		else
		{
			 arr2[j]=arr[i];
			
		}
		
		 
		 
    }
    
    for( i=0;i<=size;i++) printf(" %d ", arr2[i]);

    return 0;
}



