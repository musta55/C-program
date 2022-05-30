#include <bits/stdc++.h>

using namespace std;



struct process
{
int at,burst,pr,pid;
};

process proc[100];



bool comp(process a,process b)
{
if(a.at == b.at)
{
return a.pr<b.pr;
}
else
{
    return a.at<b.at;
}
}


void get_wt_time(int waittime[],process proc[],int n)
{
int service[50];

service[0] = proc[0].at;
waittime[0]=0;


for(int i=1;i<n;i++)
{
service[i]=proc[i-1].burst+service[i-1];

waittime[i]=service[i]-proc[i].at;

    if(waittime[i]<0)
    {
    waittime[i]=0;
    }
}

}

void get_tat_time(int turnaroundtime[],int waittime[],int n)
{

for(int i=0;i<n;i++)
{
    turnaroundtime[i]=proc[i].burst+waittime[i];
}

}

void findgc(process proc[],int n)
{

int waittime[50],turnaroundtime[50];

double wavg=0,tavg=0;


get_wt_time(waittime,proc, n);

get_tat_time(turnaroundtime,waittime, n);

int starttime[50],completetime[50];

starttime[0] = proc[0].at;
completetime[0]=starttime[0]+turnaroundtime[0];


for(int i=1;i<n;i++)
    {
        starttime[i]=completetime[i-1];
        completetime[i]=starttime[i]+turnaroundtime[i]-waittime[i];
    }



for(int i=0;i<n;i++)
    {
        wavg += waittime[i];
        tavg += turnaroundtime[i];
}

    cout<<"Average waiting time is : ";
    cout<<wavg/(float)n<<endl;
    cout<<"average turnaround time : ";
    cout<<tavg/(float)n<<endl;

}

int main()
{
int n;
cout<<"Enter number of process :" <<endl;
cin>>n;


for(int i=0;i<n;i++)
{
    cin>>proc[i].at>>proc[i].burst>>proc[i].pr>>proc[i].pid;
    }


    sort(proc,proc+n,comp);
     cout<< "Process Schedule :\n";
    for (int  i = 0 ; i <  n; i++)
        {cout << proc[i].pid <<" " ;}


    findgc(proc, n);

    return 0;
}
