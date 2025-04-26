#include <iostream>
#include <algorithm>

using namespace std;

void SJF(int processes[], int arrival_time[], int burst_time[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (burst_time[i] > burst_time[j])
            {
                swap(burst_time[i], burst_time[j]);
                swap(arrival_time[i], arrival_time[j]);
                swap(processes[i], processes[j]);
            }
        }
    }

    int waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;
    int current_time = 0;

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";

    for (int i = 0; i < n; i++)
    {
        int wait = current_time - arrival_time[i];
        if (wait < 0)
            wait = 0;
        waiting_time[i] = wait;
        turnaround_time[i] = wait + burst_time[i];

        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];

        cout << processes[i] << "\t\t" << burst_time[i] << "\t\t"
             << waiting_time[i] << "\t\t" << turnaround_time[i] << endl;

        current_time += burst_time[i];
    }

    cout << "\nAverage Waiting Time: " << (float)total_waiting_time / n << endl;
    cout << "Average Turnaround Time: " << (float)total_turnaround_time / n << endl;
}

int main()
{
    int n = 5;
    int processes[] = {1, 2, 3, 4, 5};
    int arrival_time[] = {0, 2, 4, 7, 10};
    int burst_time[] = {6, 8, 7, 3, 4};

    SJF(processes, arrival_time, burst_time, n);

    return 0;
}
