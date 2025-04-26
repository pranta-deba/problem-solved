// non-preemptive
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int burstTime[n], priority[n], processID[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter burst time and priority for process " << i + 1 << ": ";
        cin >> burstTime[i] >> priority[i];
        processID[i] = i + 1; // process ID starting from 1
    }

    // Sort processes by priority (lower number = higher priority)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (priority[i] > priority[j])
            {
                swap(priority[i], priority[j]);
                swap(burstTime[i], burstTime[j]);
                swap(processID[i], processID[j]);
            }
        }
    }

    int waitingTime[n], turnaroundTime[n];
    waitingTime[0] = 0;
    turnaroundTime[0] = burstTime[0];

    // Calculate waiting time and turnaround time
    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
    }

    double totalWaiting = 0, totalTurnaround = 0;

    cout << "\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << processID[i] << "\t"
             << burstTime[i] << "\t\t"
             << priority[i] << "\t\t"
             << waitingTime[i] << "\t\t"
             << turnaroundTime[i] << endl;

        totalWaiting += waitingTime[i];
        totalTurnaround += turnaroundTime[i];
    }

    cout << "\nAverage Waiting Time: " << totalWaiting / n << endl;
    cout << "Average Turnaround Time: " << totalTurnaround / n << endl;

    return 0;
}
