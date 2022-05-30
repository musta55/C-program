#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long int power(int a,int b,int mod)
 {
  long long int t;
  if(b==1)
  return a;
  t=power(a,b/2,mod);
  if(b%2==0)
   return (t*t)%mod;
  else
   return (((t*t)%mod)*a)%mod;
 }

 bool check_primitive(long long a,long long b)
{
    if(__gcd(a, b)==1)
        return true;
    return false;
}
 int main()
 {
  int n,g,x,a,y,b;  

   bool val = check_primitive(n, g);
    while(val==false)
    {
       printf("Enter the value of n and g : "); 
      scanf("%d%d",&n,&g); 
      val = check_primitive(n,g);
    }
//  public key  n and g  
    
 
// first person will choose the first private key x  
  printf("Enter the value of x for the first person's private key : ");
  scanf("%d",&x);  a=power(g,x,n);    
// second person will choose the second private key y
  printf("Enter the value of y for the second person's private key : ");
  scanf("%d",&y);  b=power(g,y,n);
  printf("Secret key for the first person is : %lld\n",power(b,x,n));
  printf("Secret key for the second person is : %lld\n",power(a,y,n));
  return 0;
 }