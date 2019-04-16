//--------------------------------------------------------------------------------------
//  Process.cpp
//  OSProject
//
//  Created by Siddhika Ghaisas on 10/27/18.
//  Copyright © 2018 Siddhika Ghaisas. All rights reserved.
//
//--------------------------------------------------------------------------------------

#include <stdio.h>
#include "Process.h"
#include <iostream>
using namespace std;

/*-------------------------------------------------------------------------------------
 Function Name : Process
 Description   : Default Constructor
 Input         :
 Output        :
 --------------------------------------------------------------------------------------*/
Process::Process()
{
    processID=0;
    arrivalTime=0;
    burstTime=0;
    priority=0;
    turnAroundTime = 0;
    waitingTime = 0;
}

/*-------------------------------------------------------------------------------------
 Function Name : Process
 Description   : Parametrized Constructor
 Input         :
 Output        :
 --------------------------------------------------------------------------------------*/
Process::Process(int pid, int arrTime, int burst, int priority)
{
    this->processID = pid;
    this->arrivalTime = arrTime;
    this->burstTime = burst;
    this->priority = priority;
    this->turnAroundTime = 0;
    this->waitingTime = 0;
}

/*-------------------------------------------------------------------------------------
 Function Name : getProcessID
 Description   : returns the ID of process
 Input         :
 Output        : Process ID as integer
 --------------------------------------------------------------------------------------*/
int Process::getProcessID()
{
    return processID;
}

/*-------------------------------------------------------------------------------------
 Function Name : getArrivalTime
 Description   : returns the arrival time of the process
 Input         :
 Output        : integer arrival time
 --------------------------------------------------------------------------------------*/
int Process::getArrivalTime()
{
    return arrivalTime;
}

/*-------------------------------------------------------------------------------------
 Function Name : getBurstTime
 Description   : returns the burst time of the process
 Input         :
 Output        : integer burst time
 --------------------------------------------------------------------------------------*/
int Process::getBurstTime()
{
    return burstTime;
}

/*-------------------------------------------------------------------------------------
 Function Name : getPriority
 Description   : returns the priority of the process
 Input         :
 Output        : integer  priority
 --------------------------------------------------------------------------------------*/
int Process::getPriority()
{
    return priority;
}

/*-------------------------------------------------------------------------------------
 Function Name : setTurnAroundTime
 Description   : Set the value of turnaround time of the process
 Input         : int turnTime
 Output        :
 --------------------------------------------------------------------------------------*/
void Process::setTurnAroundTime(int turnTime)
{
    turnAroundTime = turnTime;
}

/*-------------------------------------------------------------------------------------
 Function Name : setWaitingTime
 Description   : set the value of waiting time of the process
 Input         : int waitTime
 Output        :
 --------------------------------------------------------------------------------------*/
void Process::setWaitingTime(int waitTime)
{
    waitingTime = waitTime;
}

/*-------------------------------------------------------------------------------------
 Function Name : setBurstTime
 Description   : set the value of burst time of the process
 Input         : int burst
 Output        :
 --------------------------------------------------------------------------------------*/
void Process::setBurstTime(int burst)
{
    burstTime = burst;
}

/*-------------------------------------------------------------------------------------
 Function Name : setArrivalTime
 Description   : set the arrival time of the process while reading from input file
 Input         : int arrival
 Output        :
 --------------------------------------------------------------------------------------*/
void Process::setArrivalTime(int arrival)
{
    arrivalTime = arrival;
}

/*-------------------------------------------------------------------------------------
 Function Name : setPriority
 Description   : set the priority of the process while reading from input file
 Input         : int pri
 Output        :
 --------------------------------------------------------------------------------------*/
void Process::setPriority(int pri)
{
    priority = pri;
}

/*-------------------------------------------------------------------------------------
 Function Name : setProcessID
 Description   : set the process ID while reading from the input file
 Input         : int pid
 Output        :
 --------------------------------------------------------------------------------------*/
void Process::setProcessID(int pid)
{
    processID = pid;
}

/*-------------------------------------------------------------------------------------
 Function Name : getTurnAroundTime
 Description   : returns turnaround time of the process
 Input         :
 Output        : int Process ID
 --------------------------------------------------------------------------------------*/
int Process::getTurnAroundTime()
{
    return turnAroundTime;
}

/*-------------------------------------------------------------------------------------
 Function Name : getWaitingTime
 Description   : returns waiting time of the process
 Input         :
 Output        : integer waiting time
 --------------------------------------------------------------------------------------*/
int Process::getWaitingTime()
{
    return waitingTime;
}

/*-------------------------------------------------------------------------------------
 Function Name : operator==
 Description   : overloaded comparison operator
 Input         : const Process& other
 Output        :
 --------------------------------------------------------------------------------------*/
bool Process::operator==(const Process& other)
{
    bool retVal = false;
    if(this->processID == other.processID)
    {
        retVal = true;
    }
    return retVal;
}

/*-------------------------------------------------------------------------------------
 Function Name : ~Process()
 Description   : destructor
 Input         : 
 Output        :
 --------------------------------------------------------------------------------------*/
Process::~Process()
{
    
}

