//--------------------------------------------------------------------------------------
//  Scheduler.h
//  OSProject
//
//  Created by Siddhika Ghaisas on 10/27/18.
//  Copyright © 2018 Siddhika Ghaisas. All rights reserved.
//--------------------------------------------------------------------------------------

#ifndef Scheduler_h
#define Scheduler_h
#include "ProcessQueue.h"

class Scheduler
{
public:
    virtual void schedule(ProcessQueue readyQueue)=0;
};

class SJFScheduler : public Scheduler
{
public:
    void schedule(ProcessQueue readyQueue);
};

class FCFSScheduler : public Scheduler
{
public:
    void schedule(ProcessQueue readyQueue);
};

class PriorityScheduler : public Scheduler
{
public:
    void schedule(ProcessQueue readyQueue);
};

class RRScheduler : public Scheduler
{
private:
    int quantum;
public:
    int getQuantum();
    void setQuantum(int quant);
    void schedule(ProcessQueue readyQueue);

};
#endif /* Scheduler_h */
