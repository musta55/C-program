
#include<stdio.h>
#include<math.h>

int main(){
 
 int m;
 scanf("%d",&m);
 
 float arr[m],mean,stdDev,dev,min=100000,max=-1,total,sum;
 float  Variance, SD, Differ, Varsum=0;
 for(int i=0;i<m;i++)
 {
 	scanf("%f",&arr[i]);
 	sum+=arr[i];
 }
 mean=sum/(float)m;
 
  for(int i=0;i<m;i++)
 {
 if(max<arr[i])max=arr[i];
 if(min>arr[i])min=arr[i];

}
 
 
 
  for(int i=0;i<m;i++)
 {
      Differ = arr[i] - mean;
     Varsum = Varsum + pow(Differ,2);
   }
  
  Variance = Varsum / (float)m;
  SD = sqrt(Variance);
  
  
   float sum2 = 0;
   for (int i = 0; i < m; i++)
      sum2 = sum2 + abs(arr[i] - mean);
   dev= sum2 / m;
  
  
  
  
  
 total=min+max+SD+mean+dev;
 printf("%f ",total);
 



  return 0;
  
}


