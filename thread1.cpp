#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull Oddsum=0;
ull EvenSum=0;

void findOdd(ull start,ull end)
{ 
    for(ull i=start;i<=end;i++)
    {
        if((i&1)==1)Oddsum+=i;
    }

}
void findEven(ull start,ull end)
{
 for(ull i=start;i<=end;i++)
    {
        if((i&1)==0)EvenSum+=i;
    }
}
int main()
{
    ull start=0,end=1900000000;

    std::thread t1(findEven,start,end);
    std::thread t2(findOdd,start,end);
    t1.join();
    t2.join();


    
    // findOdd(start,end);
    // findEven(start,end);

    cout<<"Oddsum :"<<Oddsum<<endl;
    cout<<"EvenSum :"<<EvenSum<<endl;

    return 0;
}