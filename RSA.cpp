#include<bits/stdc++.h>
#include<math.h>
using namespace std;
bool isPrime(long int prime);
long int calculateE(long int t);
long int greatestCommonDivisor(long int e,long int t);
long int calculateD(long int e,long int t);
long int encrypt(long int i,long int e, long int n);
long int decrypt(long int i,long int d,long int n);

int main()
{
    long int p,q,n,t,e,d;
    long int encryptedText[100];
    memset(encryptedText,0,sizeof(encryptedText));

    long int decryptedText[100];
    memset(decryptedText,0,sizeof(decryptedText));

    bool flag;
    string msg;
    
    do
    {
        cout<<" Enter a prime Number: ";
        cin>>p;
        flag=isPrime( p);
        if(flag==false)cout<<"\n Wrong input.Please Enter a Prime Number";

    } while (flag == false);

      do
    {
        cout<<" Enter another prime Number: ";
        cin>>q;
        flag=isPrime( q);
        if(flag==false)cout<<"\n Wrong input.Please Enter a Prime Number";

    } while (flag == false);

    n=p*q;
    t=(p-1)*(q-1);
    e=calculateE(t);
    d=calculateD(e,t);

    cout << "\nRSA public key is (n = " << n << ", e = " << e << ")" << std::endl;
    
     std::cout << "RSA private key is (n = " << n << ", d = " << d << ")" << std::endl;

    cout << "\nEnter Message to be encryped:" <<endl;
    cin.ignore();
    getline(cin,msg);
    cout<<"\nThe message is: "<<msg<<endl;

    //Encryption

    for(long int i=0;i< msg.length();i++)
    {
        encryptedText[i]=encrypt(msg[i],e,n);
    }

    cout<<"\nEncrypted Message is: "<<endl;

     for ( long int i = 0; i < msg.length(); i++ )
    {
        cout<< (char)encryptedText[i] ;
    }

    //Decryption

     for (long int i = 0; i < msg.length(); i++)
    {
        decryptedText[i] = decrypt(encryptedText[i], d, n);
    }
    cout << "\n\nTHE DECRYPTED MESSAGE IS:" << endl;

    for (long int i = 0; i < msg.length(); i++)
    {
        cout<<(char)decryptedText[i] ;
    }
    
    return 0;
}

bool isPrime(long int prime)
{
    long int i,j;
    j=(long int)sqrt((long double)prime);
    for(i=2;i<=j;i++)
    {
        if(prime%i==0)return false;
    }
    return true;
}

long int greatestCommonDivisor(long int e,long int t)
{
    while(e>0)
    {
        long int mytemp;
        mytemp=e;
        e=t%e;
        t=mytemp;
    }
    return t;
}

long int calculateE(long int t)
{
    long int e;
    if(t>17)e=16;
    else{
        e=2;
    }
    for(;e<t;e++)
    {
        if(greatestCommonDivisor(e,t)==1)return e;
    }
    return -1;
}

long int calculateD(long int e,long int t)
{
    long int d;
    long int k=1;
    while(1)
    {
        k+=t;
        if(k%e==0)
        {
            d=(k/e);
            return d;
        }
    }
}
long int encrypt( long int i, long int e, long int n )
{
    long int current, result;
    
    current = i - 97;
    result = 1;
    
    for ( long int j = 0; j < e; j++ )
    {
        result = result * current;
        result = result % n;
    }
    
    return result;
}

long int decrypt(long int i, long int d, long int n)
{
    long int current, result;
    
    current = i;
    result = 1;
    
    for ( long int j = 0; j < d; j++ )
    {
        result = result * current;
        result = result % n;
    }
    
    return result + 97;
}