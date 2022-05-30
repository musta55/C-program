#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, flag = 0, count = 0, done = 0, lock = 0;
    int mark[20];

    int np = 5, nr = 3;
    int seq[np], finish[np];
    int work[nr], r[10];

    int allocation[np][nr] = {{0, 1, 0},
                              {2, 0, 0},
                              {3, 0, 3},
                              {2, 1, 1},
                              {0, 0, 2}};
    int available[nr] = {0, 0, 0};
    int request[np][nr] = {{0, 0, 0},
                           {2, 0, 2},
                           {0, 0, 1},
                           {1, 0, 0},
                           {0, 0, 2}};

    for (int i = 0; i < np; i++)
    {
        finish[i] = true;
    }

    for (int i = 0; i < nr; i++)
    {
        work[i] = available[i]; //Making a copy of available
    }
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            if (allocation[i][j] != 0)
            {
                finish[i] = false;
            }
        }
    }

    while (count != np)
    {
        count++;
        for (int i = 0; i < np; i++)
        {
            if (finish[i] == false)
            {
                for (int j = 0; j < nr; j++)
                {
                    if (request[i][j] > work[j])
                    {
                        flag = 1;
                        break;
                    }
                    flag = 0;
                }
                if (flag == 0)
                {
                    for (int j = 0; j < nr; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    seq[done] = i;
                    done++;
                }
            }
        }
    }
    for (int i = 0; i < np; i++)
    {
        if (finish[i] == false)
        {
            lock = 1;
            break;
        }
    }
    if (lock == 1)
    {
        cout << "The system is in a deadlock situation";
    }
    else
    {
        cout << "The system is in a safe situation";
    }
}
