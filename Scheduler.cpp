//--------------------------------------------------------------------------------------
//  Scheduler.cpp
//  OSProject
//
//  Created by Siddhika Ghaisas on 10/27/18.
//  Copyright © 2018 Siddhika Ghaisas. All rights reserved.
//--------------------------------------------------------------------------------------


#include <stdio.h>
#include <iostream>
#include "Scheduler.h"
#include "ProcessQueue.h"
#include "Process.h"
#include "defines.h"

/*-------------------------------------------------------------------------------------
 Function Name : SJFScheduler::schedule
 Description   : Schedule processes from waitingqueue using SJF Scheduler
 Input         : ProcessQueue waitingQueue
 Output        : print waiting and turnaround times for process
 --------------------------------------------------------------------------------------*/
void SJFScheduler::schedule(ProcessQueue waitingQueue)
{
    try
    {
        //This scheduler schedules process by it's burst time
        //Processes with lease burst times are scheduled first
        ProcessQueue readyQueue;
        Node* waitingProcess = waitingQueue.getHeadOfQueue();
        while(waitingProcess != NULL)
        {
            readyQueue.addToQueue(waitingProcess->data);
            waitingProcess = waitingProcess->next;
        }
        
        //Sort the readyQueue as per the burst time
        readyQueue.sortQueue(BURST_TIME);
        
        Node* temp = readyQueue.getHeadOfQueue();
        int turnaroundTime = 0;
        //int waitingTime = 0;
        int currentTime = 0;
        
        if(temp != NULL)
        {
            //First process in the queue always has the turnaround time as
            //its actual burst time and zero waiting time, as it's the first process
            temp->data.setTurnAroundTime(temp->data.getBurstTime());
            temp->data.setWaitingTime(0);
            currentTime = temp->data.getBurstTime();
            //Let's move on to next process
            temp = temp->next;
            
            while(temp!=NULL)
            {
                temp->data.setWaitingTime(currentTime - temp->data.getArrivalTime());
                turnaroundTime = currentTime+temp->data.getBurstTime();
                temp->data.setTurnAroundTime(turnaroundTime);
                currentTime += temp->data.getBurstTime();
                temp = temp->next;
            }
            readyQueue.printQueue();
        }
        else
        {
            throw (NULL_POINTER_EXCEPTION);
        }
    }
    catch(int err)
    {
        std::cout<<"Null pointer encountered"<<std::endl;
    }
}

/*-------------------------------------------------------------------------------------
 Function Name : FCFSScheduler::schedule
 Description   : Schedule processes from waitingqueue using FCFS Scheduler
 Input         : ProcessQueue waitingQueue
 Output        : print waiting and turnaround times for process
 --------------------------------------------------------------------------------------*/
void FCFSScheduler::schedule(ProcessQueue waitingQueue)
{
    try
    {
        //This scheduler schedules process by it's arrival time
        //Processes with earlieat arrival times are scheduled first
        ProcessQueue readyQueue;
        Node* waitingProcess = waitingQueue.getHeadOfQueue();
        while(waitingProcess != NULL)
        {
            readyQueue.addToQueue(waitingProcess->data);
            waitingProcess = waitingProcess->next;
        }
        
        //Sort the readyQueue as per the burst time
        readyQueue.sortQueue(ARRIVAL_TIME);
        
        Node* temp = readyQueue.getHeadOfQueue();
        
        if(temp != NULL)
        {
            int turnaroundTime = 0;
            //int waitingTime = 0;
            int currentTime = 0;
            
            //First process in the queue always has the turnaround time as
            //its actual burst time and zero waiting time, as it's the first process
            temp->data.setTurnAroundTime(temp->data.getBurstTime());
            temp->data.setWaitingTime(0);
            currentTime = temp->data.getBurstTime();
            //Let's move on to next process
            temp = temp->next;
            
            while(temp!=NULL)
            {
                temp->data.setWaitingTime(currentTime - temp->data.getArrivalTime());
                turnaroundTime = currentTime +temp->data.getBurstTime();
                temp->data.setTurnAroundTime(turnaroundTime);
                currentTime += temp->data.getBurstTime();
                temp = temp->next;
            }
            readyQueue.printQueue();
        }
        else
        {
            throw NULL_POINTER_EXCEPTION;
        }
        
    }
    catch (int err)
    {
        std::cout<<"Null pointer encountered"<<std::endl;
    }
}

/*-------------------------------------------------------------------------------------
 Function Name : PriorityScheduler::schedule
 Description   : Schedule processes from waitingqueue using priority Scheduler
 Input         : ProcessQueue waitingQueue
 Output        : print waiting and turnaround times for process
 --------------------------------------------------------------------------------------*/
void PriorityScheduler::schedule(ProcessQueue waitingQueue)
{
    try
    {
        //This scheduler schedules process by it's priority
        //Processes with least numbered priority are scheduled first
        ProcessQueue readyQueue;
        Node* waitingProcess = waitingQueue.getHeadOfQueue();
        while(waitingProcess != NULL)
        {
            readyQueue.addToQueue(waitingProcess->data);
            waitingProcess = waitingProcess->next;
        }
        
        //Sort the readyQueue as per the burst time
        readyQueue.sortQueue(PRIORITY);
        
        Node* temp = readyQueue.getHeadOfQueue();
        if(temp != NULL)
        {
            int turnaroundTime = 0;
            //int waitingTime = 0;
            int currentTime = 0;
            //First process in the queue always has the turnaround time as
            //its actual burst time and zero waiting time, as it's the first process
            temp->data.setTurnAroundTime(temp->data.getBurstTime());
            temp->data.setWaitingTime(0);
            currentTime = temp->data.getBurstTime();
            //Let's move on to next process
            temp = temp->next;
            
            while(temp!=NULL)
            {
                temp->data.setWaitingTime(currentTime - temp->data.getArrivalTime());
                turnaroundTime = currentTime +temp->data.getBurstTime();
                temp->data.setTurnAroundTime(turnaroundTime);
                currentTime += temp->data.getBurstTime();
                temp = temp->next;
            }
            readyQueue.printQueue();
        }
        else
        {
            throw NULL_POINTER_EXCEPTION;
        }
    }
    catch (int err)
    {
        std::cout<<"Null pointer encountered"<<std::endl;
    }
    
}


/*-------------------------------------------------------------------------------------
 Function Name : setQuantum
 Description   : Set the quantum size required for Round robin scheduler
 Input         : quantum size to be set
 Output        :
 --------------------------------------------------------------------------------------*/
void RRScheduler::setQuantum(int quant)
{
    quantum = quant;
}

/*-------------------------------------------------------------------------------------
 Function Name : getQuantum
 Description   : Returns the quantum size required for Round robin scheduler
 Input         :
 Output        : quantum
 --------------------------------------------------------------------------------------*/
int RRScheduler::getQuantum()
{
    return quantum;
}

/*-------------------------------------------------------------------------------------
 Function Name : RRScheduler::schedule
 Description   : Schedule processes from waitingqueue using Round robin Scheduler
 Input         : ProcessQueue waitingQueue
 Output        : print waiting and turnaround times for process
 --------------------------------------------------------------------------------------*/
void RRScheduler::schedule(ProcessQueue waitingQueue)
{
    //The readyqueue that we get as input here, is sorted as per the arrival time
    //however, if 2 processes have same arrival time as each other, their priority
    //considered as a tie-breaking criteria.
    //Compare each node with its next node and arrange them as per priority if
    //they have same arrival time
    
    ProcessQueue readyQueue;
    Node* waitingProcess = waitingQueue.getHeadOfQueue();
    while(waitingProcess != NULL)
    {
        readyQueue.addToQueue(waitingProcess->data);
        waitingProcess = waitingProcess->next;
    }
    
    //Lets start scheduling the updated readyqueue
    Node* temp = readyQueue.getHeadOfQueue();
    
    //This variable keeps a count of processes
    //for which execution is completed. To update count, we keep
    //checking if burst time of the process has reduced to zero zero.
    int count = 0;
    
    //This variable holds the value of cuttent time,
    //For any given process,
    //Waiting Time += current time- it's own turnaroundtime before calculating new
    //TurnAroundtime += cureentTime + quantum

    int currentTime = 0;
    
    int readyQueueLength = readyQueue.getLength();

    while(temp != NULL && count < readyQueueLength)
    {
        //Check if arrival time is less than or equal to the currentTime
        if(temp->data.getArrivalTime() > currentTime)
        {
            bool found = false;
            while(temp != NULL && !found)
            {
                temp = temp->next;
                if(temp != NULL)
                {
                    if(temp->data.getArrivalTime() <= currentTime)
                    found = true;
                }
                else
                {
                    temp = readyQueue.getHeadOfQueue();
                }
            }
        }
        if(temp->data.getBurstTime() > 0)
        {
            if(temp->data.getBurstTime()<= getQuantum())
            {
                if(temp->data.getWaitingTime() == 0)
                {
                    temp->data.setWaitingTime(temp->data.getWaitingTime()+ currentTime -temp->data.getTurnAroundTime()- temp->data.getArrivalTime());
                }
                else
                {
                    temp->data.setWaitingTime(temp->data.getWaitingTime()+ currentTime -temp->data.getTurnAroundTime());
                }
                temp->data.setTurnAroundTime(currentTime+ temp->data.getBurstTime());
                currentTime += temp->data.getBurstTime();
                temp->data.setBurstTime(0);
                count++;
            }
            else
            {
                temp->data.setBurstTime(temp->data.getBurstTime()-getQuantum());
                if(temp->data.getWaitingTime() == 0)
                {
                    temp->data.setWaitingTime(temp->data.getWaitingTime()+ currentTime -temp->data.getTurnAroundTime()- temp->data.getArrivalTime());
                }
                else
                {
                    temp->data.setWaitingTime(temp->data.getWaitingTime()+ currentTime -temp->data.getTurnAroundTime());
                }
                temp->data.setTurnAroundTime(currentTime+ getQuantum());
                currentTime += getQuantum();
            }
        }
        temp = temp->next;
        if(temp == NULL)
            temp = readyQueue.getHeadOfQueue();
    }

    readyQueue.printQueue();
}

