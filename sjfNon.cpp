#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    char pname[50];
    int btime;
    int atime;
}a[50];
void insert(int n){
    int i;
    for(i=0;i<n;i++){
        cin>>a[i].pname;
        cin>>a[i].atime;
        cin>>a[i].btime;
    }
}
bool btimeSort(node a,node b){
    return a.btime < b.btime; 
}
bool atimeSort(node a,node b){
    return a.atime < b.atime; 
}
void disp(int n){
    sort(a,a+n,btimeSort);
    sort(a,a+n,atimeSort);
    int ttime=0,i;
    int j,tArray[n];
    
    for(i=0;i<n;i++){
        j=i;
        while(a[j].atime<=ttime&&j!=n){
            j++;
        }
        sort(a+i,a+j,btimeSort);
        tArray[i]=ttime;
        ttime+=a[i].btime;
    }
    tArray[i] = ttime;
    float averageWaitingTime=0;
    float averageResponseTime=0;
    float averageTAT=0;
    cout<<"\n";
    cout<<"P.Name  AT\tBT\tCT\tTAT\tWT\tRT\n";
    for (i=0; i<n; i++){
        cout << a[i].pname << "\t"; 
        cout << a[i].atime << "\t";
        cout << a[i].btime << "\t";
        cout << tArray[i+1] << "\t"; 
        cout << tArray[i]-a[i].atime+a[i].btime << "\t"; 
        averageTAT+=tArray[i]-a[i].atime+a[i].btime;
        cout << tArray[i]-a[i].atime << "\t"; 
        averageWaitingTime+=tArray[i]-a[i].atime;
        cout << tArray[i]-a[i].atime << "\t";  
        averageResponseTime+=tArray[i]-a[i].atime;
        cout <<"\n"; 
    }
    cout<<"\n";
    cout<<"\nProcess Schedule :\n";
    for (i=0; i<n; i++){
        cout <<"P"<< a[i].pname << "   "; 
    }
    
    cout<<"\n";
    cout<<"Average Waiting time: "<<(float)averageWaitingTime/(float)n<<endl;
    cout<<"Average TA time: "<<(float)averageTAT/(float)n<<endl;
}
int main(){
    int nop,choice,i;
    freopen("process.txt","r",stdin);
    cout<<"Enter number of processes\n";
    cin>>nop;
    insert(nop);
    disp(nop);
    return 0;
}
