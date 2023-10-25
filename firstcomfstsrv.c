#include <stdio.h>

// Function to calculate average waiting time
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0; // The first process has a waiting time of 0

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

// Function to calculate average waiting time
float findAverageWaitingTime(int processes[], int n, int bt[]) {
    int wt[n];

    // Find waiting time for all processes
    findWaitingTime(processes, n, bt, wt);

    // Calculate the total waiting time
    int total_wt = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
    }

    // Calculate and return the average waiting time
    return (float)total_wt / n;
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n]; // Process IDs
    int burst_time[n]; // Burst times

    // Input process IDs and burst times
    for (int i = 0; i < n; i++) {
        printf("Enter process %d ID: ", i + 1);
        scanf("%d", &processes[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Calculate and display the average waiting time
    float avg_wt = findAverageWaitingTime(processes, n, burst_time);
    printf("Average Waiting Time: %.2f\n", avg_wt);

    return 0;
}
