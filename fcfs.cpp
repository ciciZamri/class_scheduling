// First Come First Serve (FCFS) algorithm

#include <iostream>
using namespace std;

struct Process{
    int ccode;
    int duration;
    int priority;
    int arrival_time;
};

// turn around time = burst time + waiting time
float getAverageTurnAroundTime(Process proc[], int length){
    float waitingTime = 0.0;
    float total = 0.0;
    float average = 0.0;
    for(int i = 0 ; i<length ; i++){
        int burstTime = proc[i].duration;
        total += burstTime + waitingTime;
        waitingTime += burstTime;
    }
    average = total/(float)length;
    return average;
}

float getAverageWaitingTime(Process proc[], int length){
    float average = 0.0;
    float total = 0.0;
    for(int i = 0 ; i<length-1 ; i++){
        total += proc[i].duration;
    }
    average = total/(float)length;
    return average;
}

int main(){
    const int length = 3;
    Process proc[length] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}};

    cout << "Class order from start to end: ";
    for(int i = 0 ; i<length ; i++){
        cout << proc[i].ccode;
        if(i < length-1) cout << " -> ";
    }
    cout << "\nAverage waiting time: " << getAverageWaitingTime(proc, length);
    cout << "\nAverage turnaround time: " << getAverageTurnAroundTime(proc, length);

    return 0;
}