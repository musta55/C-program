#include <bits/stdc++.h>
using namespace std;

struct Process {
   int pid;
   int bt; 
   int art;
};
void TAT(Process proc[], int n, int wt[], int tat[]) {
   for (int i = 0; i < n; i++)
   tat[i] = proc[i].bt + wt[i];
}

void WTime(Process proc[], int n, int wt[]) {
   int rt[n];
   for (int i = 0; i < n; i++)
   rt[i] = proc[i].bt;
   int complete = 0, t = 0, minm = INT_MAX;
   int shortest = 0, finish_time;
   bool check = false;
    
   int temp[7]={1,2,3,5,3,6,4};
   
   
   cout<<"Scheduling Order :";
   while (complete != n) {
      for (int j = 0; j < n; j++) {
         if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0) {
            minm = rt[j];
            shortest = j;
            check = true;
         }
      }
      if (check == false) {
         t++;
         continue;
      }
     
      rt[shortest]--;
      minm = rt[shortest];
      if (minm == 0)
         minm = INT_MAX;
       
         if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            
            
           
            wt[shortest] = finish_time -
            proc[shortest].bt -
            proc[shortest].art;
            if (wt[shortest] < 0)
               wt[shortest] = 0;
         }
         t++;
   }
  
   
   for(int k=0;k<7;k++)
   {
   cout<<"P"<<temp[k]<<" ";
   }
   cout<<"\n";
   
}

void AVGTime(Process proc[], int n) {
   int wt[n], tat[n], total_wt = 0,
   total_tat = 0;
  
   WTime(proc, n, wt);
  
   TAT(proc, n, wt, tat);
   cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time\n";
   for (int i = 0; i < n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      cout << " " << proc[i].pid << "\t\t" << proc[i].bt << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
   }
   cout << "\nAverage waiting time = " << (float)total_wt / (float)n; cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
	

}
int main() {
   Process proc[] = { { 1, 15, 0 }, { 2, 20, 0 }, { 3, 20, 20 }, { 4, 20, 25 }, { 5, 5, 45 }, { 6, 15, 55 } };
   int n = sizeof(proc) / sizeof(proc[0]);
  AVGTime(proc, n);
   return 0;
}
