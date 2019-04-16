//--------------------------------------------------------------------------------------
//  main.cpp
//  OSProject
//
//  Created by Siddhika Ghaisas on 10/27/18.
//  Copyright © 2018 Siddhika Ghaisas. All rights reserved.
//
//--------------------------------------------------------------------------------------

#include <iostream>
#include "Process.h"
#include "ProcessQueue.h"
#include "Scheduler.h"
#include "Utility.h"
#include <ctime>

using namespace std;

int main(int argc, const char * argv[]) {

    clock_t begin = clock();
    
    ProcessQueue waitingQueue;
    int quantum = 2;
    
    populateQueueFromFile(waitingQueue);
    int scheduleOption = 0;
    
    cout<<"Enter scheduler type from following :"<<endl;
    cout<<"Enter 1 for First come first serve first"<<endl;
    cout<<"Enter 2 for Shortest job scheduler"<<endl;
    cout<<"Enter 3 for Priority scheduler"<<endl;
    cout<<"Enter 4 for Round robin scheduling"<<endl;
    
    cin>>scheduleOption;
    
    switch(scheduleOption)
    {
        case 1:
        {
            FCFSScheduler* fcfs = new FCFSScheduler;
            fcfs->schedule(waitingQueue);
            break;
        }
        case 2:
        {
            SJFScheduler* sjfScheduler = new SJFScheduler();
            sjfScheduler->schedule(waitingQueue);
            break;
        }
        case 3:
        {
            PriorityScheduler* prScheduler = new PriorityScheduler;
            prScheduler->schedule(waitingQueue);
            break;
        }
        case 4:
        {
            RRScheduler* roundRobinSch = new RRScheduler();
            roundRobinSch->setQuantum(quantum);
            roundRobinSch->schedule(waitingQueue);
            break;
        }
        default:
        {
            cout<<"You have entered a wrong choice"<<endl;
            break;
        }
            
    }
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    return 0;
}
