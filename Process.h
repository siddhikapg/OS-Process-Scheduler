//--------------------------------------------------------------------------------------
//  Process.h
//  OSProject
//
//  Created by Siddhika Ghaisas on 10/27/18.
//  Copyright © 2018 Siddhika Ghaisas. All rights reserved.
//--------------------------------------------------------------------------------------

#ifndef Process_h
#define Process_h

class Process
{
private:
    int processID;
    int arrivalTime;
    int burstTime;
    int priority;
    int turnAroundTime;
    int waitingTime;
    
public:
    Process();
    Process(int pid, int arrTime, int burst, int priority);
    int getProcessID();
    int getArrivalTime();
    int getBurstTime();
    int getPriority();
    void setTurnAroundTime(int turnTime);
    void setWaitingTime(int waitTime);
    void setBurstTime(int burst);
    void setArrivalTime(int arrival);
    void setPriority(int priority);
    void setProcessID(int pid);
    int getTurnAroundTime();
    int getWaitingTime();
    bool operator==(const Process& other);
    ~Process();
};

#endif /* Process_h */
