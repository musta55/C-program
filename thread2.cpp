#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

void fun(int x)
{
    while(x-- >0)cout<<x <<endl;
}

int main()
{
    std::thread t1(fun,11);
    std::thread t2(fun,10);
    t1.join();
    t2.join();

    return 0;
}