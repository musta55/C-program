
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int main()
{
    char str[MAX_SIZE];
    int i, len;
    int freq[26];

   
    printf("Enter any string: ");
    gets(str);

    len = strlen(str);

   
    for(i=0; i<26; i++)
    {
        freq[i] = 0;
    }


   
    for(i=0; i<len; i++)
    {
      
        if(str[i]>='a' && str[i]<='z')
        {
            freq[str[i] - 97]++;
        }
        else if(str[i]>='A' && str[i]<='Z')
        {
            freq[str[i] - 65]++;
        }
    }

  
  int max=-1;
  char c='\0';
    printf("\nFrequency of all characters in the given string: \n");
    for(i=0; i<26; i++)
    {
       
        if(freq[i] != 0)
        {
            printf("'%c' = %d\n", (i + 97), freq[i]);
        }
        if(max<freq[i])
        
        {
        	max=freq[i];
        	c=(i + 97);
        	
		}
        
    }
    
    printf("Highest Occurance is %c on %d times\n",c,max);

    return 0;
}
