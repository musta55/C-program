#include <iostream>
using namespace std;

const int P = 5, R = 3;

bool isSafe(int processes[], int available[], int maxNeed[][R],
            int allocation[][R])
{
     int need[P][R];

    for (int i = 0; i < P; i++)
          for (int j = 0; j < R; j++)
               need[i][j] = maxNeed[i][j] - allocation[i][j];

     bool finish[P] = {0};
     int safeSeq[P], work[R];

     
     for (int i = 0; i < R; i++)
          work[i] = available[i];

     int count = 0;
     while (count < P)
     {
          bool found = false;
          for (int p = 0; p < P; p++)
          {
               if (finish[p] == 0)
               {
                   
                    int j;
                    for (j = 0; j < R; j++)
                         if (need[p][j] > work[j])
                              break;
                    if (j == R)
                    { 
                         for (int k = 0; k < R; k++)
                              work[k] += allocation[p][k];
                         safeSeq[count++] = p;

                         finish[p] = 1;

                         found = true;
                    }
               }
          }
          if (found == false)
          {
               cout << "System is not safe";
               return false;
          }
     }
     cout << "System is  safe.\nThe sequence is: ";
     for (int i = 0; i < P; i++)
          cout << safeSeq[i] << " ";

     return true;
}

int main()
{
     int processes[] = {0, 1, 2, 3, 4};
     int available[] = {3, 3, 2};
     int maxNeed[][R] = {{7, 5, 3},
                         {3, 2, 2},
                         {9, 0, 2},
                         {4, 2, 2},
                         {5, 3, 3}};

     int allocation[][R] = {{0, 1, 0},
                            {2, 0, 0},
                            {3, 0, 2},
                            {2, 1, 1},
                            {0, 0, 2}};

    
     isSafe(processes, available, maxNeed, allocation);

     return 0;
}
