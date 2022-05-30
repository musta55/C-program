

Skip to content
Using Institute of Information Technology, DU Mail with screen readers
End now Vacation Settings
Enable desktop notifications for Institute of Information Technology, DU Mail.
   OK  No thanks
Meet
Hangouts

1 of 2,904
$
Inbox

Tasmia Zerin
Attachments
9:12 PM (1 hour ago)
to me


~𝔗𝔞𝔰𝔪𝔦𝔞

2 Attachments

Mustahid Hasan <bsse1114@iit.du.ac.bd>
9:12 PM (1 hour ago)
to bsse1128

MUSTAHID


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int P=5, R=3;
    int flag=0;
    int seq[P];
    int done=0;
    int count=0;
    int allocated[P][R]={{ 0, 1, 0 },
                        { 2, 0, 0 },
                        { 3, 0, 3 },
                        { 2, 1, 1 },
                        { 0, 0, 2 }};
    int available[R]={ 0, 0, 0 };
    int request[P][R]={{ 0, 0, 0 },
                        { 2, 0, 2 },
                        { 0, 0, 1 },
                        { 1, 0, 0 },
                        { 0, 0, 2 }};
    int work[R];
    int finish[P];
    for(int i=0;i<P;i++)
    {
        finish[i]=true;
    }
    for(int i=0;i<R;i++)
    {
        work[i]= available[i];
    }
    for(int i=0;i<P;i++)
    {
        for(int j=0;j<R;j++)
        {
            if(allocated[i][j]!=0)
            {
                finish[i]=false;
            }
        }
    }
    while(count!=P|| done!=P)
    {
        count++;
    for(int i=0;i<P;i++)
    {
        if(finish[i]==false)
        {
            for(int j=0;j<R;j++)
            {
            if(request[i][j]>work[j])
            {
                flag=1;
                break;
            }
            flag=0;
            }
        if(flag==0)
        {
            for(int j=0;j<R;j++)
            {
                work[j] += allocated[i][j];
            }
            finish[i]= true;
            seq[done] = i;
            done++;
        }
        }
    }
    }
    for(int i=0;i<P;i++)
    {
        if(finish[i]==false)
        {
            cout<<"The system is in a deadlocked state";
            break;
        }
    }
}
DeadlockDetection.cpp
Displaying bankers.cpp.