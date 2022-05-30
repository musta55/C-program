#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long myMod(ll a, ll b, ll m)
{
    long long ret=1;
    for(ll i=0;i<b;i++)
    {
        ret = (ret*a)%m;
    }
    return ret;
}

bool check_primitive(long long q,long long alpha)
{
    if(__gcd(q, alpha)==1)
        return true;
    return false;
}

int main()
{
    long long q, alpha, Xa, Xb, Ya,Yb, Ka, Kb;
    cout<< "Enter the value of q and alpha: ";
    cin>>q>>alpha;
    bool val = check_primitive(q, alpha);
    while(val==false)
    {
        cout<< "q and alpha not primitive\nenter q and alpha again"<<endl;
        cin>>q>>alpha;
        val = check_primitive(q,alpha);
    }
    cout<< "Enter Private key of User A and B: ";
    cin>>Xa>>Xb;
    Ya=myMod(alpha,Xa,q);
    Yb=myMod(alpha,Xb,q);
    cout<< "Public Key of User A: "<<Ya<<endl;
    cout<< "Public Key of User B: "<<Yb<<endl;
    Ka = myMod(Yb,Xa,q);
    Kb = myMod(Ya,Xb,q);
    cout<< "Shared Secret Key from User A: "<<Ka<<endl;
    cout<< "Shared Secret Key from User B: "<<Kb<<endl;
}