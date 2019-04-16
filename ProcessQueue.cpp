//--------------------------------------------------------------------------------------
//  ProcessQueue.cpp
//  OSProject
//
//  Created by Siddhika Ghaisas on 10/27/18.
//  Copyright © 2018 Siddhika Ghaisas. All rights reserved.
//
//--------------------------------------------------------------------------------------

#include "ProcessQueue.h"
#include "defines.h"
#include <iostream>
using namespace std;

/*-------------------------------------------------------------------------------------
 Function Name : addToQueue
 Description   : Add a process to the  ready / waiting queue
 Input         : Process var
 Output        :
 --------------------------------------------------------------------------------------*/
void ProcessQueue::addToQueue(Process var)
{
    struct Node* tempNode = new Node;
    tempNode->data = var;
    tempNode->next = NULL;
    tempNode->prev = NULL;
    if(head == NULL)
    {
        //Add the process to the head of the queue
        head = tempNode;
        head->prev = NULL;
        head->next = NULL;
        //Since this is the only process in the queue,
        //it will also be the tail node
        tail = tempNode;
        tail->next = NULL;
    }
    else
    {
        //This means queue already has some processes in it
        //Simply add the new process at the current tail
        tail->next = tempNode;
        tempNode->prev = tail;
        //Chane tail to new process node
        tail = tempNode;
        tail->next = NULL;
    }
}

/*-------------------------------------------------------------------------------------
 Function Name : mergeSort
 Description   : Method to sot the process queue.
 Input         : Node** head,int criteria
 Output        : Process queue sorted according to either arrival time, burst time OR
                 priority
 --------------------------------------------------------------------------------------*/
void ProcessQueue::mergeSort(Node** head,int criteria)
{
    Node* headPtr = *head;
    Node* half1;
    Node* half2;
    
    //Check for empty process queue
    if ((headPtr == NULL) || (headPtr->next == NULL))
    {
        return;
    }
    //Split the queue in 2 halves
    splitForSort(headPtr,&half1,&half2);
    
    //Apply mergesort to both halves
    mergeSort(&half1,criteria);
    mergeSort(&half2,criteria);
    
    switch(criteria)
    {
        case ARRIVAL_TIME:
            //Merge the two lists together based on arrival time
            *head = sortByArrivalTime(half1,half2);
            break;
        case BURST_TIME:
            //Merge the two lists together based on burst time
            *head = sortByBurstTime(half1,half2);
            break;
        case PRIORITY:
            //Merge the two lists together based on priority
            *head = sortByPriority(half1, half2);
            break;
    }
}

/*-------------------------------------------------------------------------------------
 Function Name :
 Description   :
 Input         :
 Output        :
 --------------------------------------------------------------------------------------*/
Node* ProcessQueue::sortByArrivalTime(Node* half1, Node* half2)
{
    struct Node* result = NULL;
    
    if (half1 == NULL)
        return(half2);
    else if (half2 ==NULL)
        return(half1);
    
    //Choose either half and repeat the sorting process on it
    if(half1->data.getArrivalTime() <= half2->data.getArrivalTime())
    {
        result = half1;
        result->next = sortByArrivalTime(half1->next, half2);
    }
    else
    {
        result = half2;
        result->next = sortByArrivalTime(half1,half2->next);
    }
    return result;
}

/*-------------------------------------------------------------------------------------
 Function Name : sortByBurstTime
 Description   :
 Input         :
 Output        :
 --------------------------------------------------------------------------------------*/
Node* ProcessQueue::sortByBurstTime(Node* half1, Node* half2)
{
    struct Node* result = NULL;
    
    if (half1 == NULL)
        return(half2);
    else if (half2 ==NULL)
        return(half1);
    
    //Choose either half and repeat the sorting process on it
    if(half1->data.getBurstTime() <= half2->data.getBurstTime())
    {
        result = half1;
        result->next = sortByBurstTime(half1->next, half2);
    }
    else
    {
        result = half2;
        result->next = sortByBurstTime(half1,half2->next);
    }
    return result;
    
}

/*-------------------------------------------------------------------------------------
 Function Name : sortByPriority
 Description   : Sort the process queue according to priority
 Input         : Node* half1, Node* half2
 Output        :
 --------------------------------------------------------------------------------------*/
Node* ProcessQueue::sortByPriority(Node* half1, Node* half2)
{
    struct Node* result = NULL;
    
    if (half1 == NULL)
        return(half2);
    else if (half2 ==NULL)
        return(half1);
    
    //Choose either half and repeat the sorting process on it
    if(half1->data.getPriority() <= half2->data.getPriority())
    {
        result = half1;
        result->next = sortByPriority(half1->next, half2);
    }
    else
    {
        result = half2;
        result->next = sortByPriority(half1,half2->next);
    }
    return result;
}


/*-------------------------------------------------------------------------------------
 Function Name : splitForSort
 Description   : Split the given process queue in two halves
 Input         : Node* source, Node** front,Node** back
 Output        :
 --------------------------------------------------------------------------------------*/
void ProcessQueue::splitForSort(Node* source, Node** front,Node** back)
{
    struct Node* ptr1;
    struct Node* ptr2;
    ptr2 = source;
    ptr1 = source->next;
    
    /* Advance 'ptr1' two nodes, and advance 'ptr2' one node */
    while (ptr1 != NULL)
    {
        ptr1 = ptr1->next;
        if (ptr1 != NULL)
        {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
    }
    
    /* 'ptr2' is before the midpoint in the list, so split it in two
     at that point. */
    *front = source;
    *back = ptr2->next;
    ptr2->next = NULL;
}

/*-------------------------------------------------------------------------------------
 Function Name : deleteFromQueue
 Description   : Delete/remove a process from queue.
 Input         : Process var
 Output        :
 --------------------------------------------------------------------------------------*/
void ProcessQueue::deleteFromQueue(Process var)
{
    Node* temp = head;
    while(temp->next != NULL)
    {
        if(temp!= NULL)
        {
            //This == operator ensure that the complete process data
            //match is checked for equality
            if(temp->data == var)
            {
                //delete this node
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                break;
            }
        }
        
    }
}

/*-------------------------------------------------------------------------------------
 Function Name : sortQueue
 Description   : Sort the process queue according to given criteria between arrival time,
                burst time and priority.
 Input         : int criteria
 Output        :
 --------------------------------------------------------------------------------------*/
void ProcessQueue::sortQueue(int criteria)
{
    switch(criteria)
    {
        case 1:
        {
            //Sort the queue as per arrival time
            mergeSort(&head,1);
        }break;
        case 2:
        {
            //Sort the queue as per burst time
            mergeSort(&head,2);
        }break;
        case 3:
        {
            //Sort the queue as per priority
            mergeSort(&head,3);
        }break;
    }
}

/*-------------------------------------------------------------------------------------
 Function Name : printQueue()
 Description   : Print the waiting and turnround time of each process in the queue
 Input         :
 Output        :
 --------------------------------------------------------------------------------------*/
void ProcessQueue::printQueue()
{
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<"Process ID :"<<temp->data.getProcessID()<<endl;
        cout<<"Process waiting time :"<<temp->data.getWaitingTime()<<endl;
        cout<<"Process turnaround time :"<<temp->data.getTurnAroundTime()<<endl;
        cout<<endl;
        temp= temp->next;
    }
    cout<<"Avergae waiting time :"<<getAvgWaitingTime()<<endl;
    cout<<"Average turnaround time :"<<getAvgTurnaroundTime()<<endl;
}

/*-------------------------------------------------------------------------------------
 Function Name : ProcessQueue()
 Description   : Constructor
 Input         :
 Output        :
 --------------------------------------------------------------------------------------*/
ProcessQueue::ProcessQueue()
{
    head = NULL;
    tail = NULL;
}

/*-------------------------------------------------------------------------------------
 Function Name : ~ProcessQueue()
 Description   : Destructor
 Input         :
 Output        :
 --------------------------------------------------------------------------------------*/
ProcessQueue::~ProcessQueue()
{
    if(head != NULL)
    {
        head = NULL;
    }
    if(tail != NULL)
    {
        tail = NULL;
    }
}

/*-------------------------------------------------------------------------------------
 Function Name : getHeadOfQueue
 Description   : Get the head of the process queue
 Input         :
 Output        :
 --------------------------------------------------------------------------------------*/
Node* ProcessQueue::getHeadOfQueue()
{
    return head;
}

/*-------------------------------------------------------------------------------------
 Function Name : setHeadOfQueue
 Description   : Set the process as head of the queue
 Input         : Node* headPtr
 Output        :
 --------------------------------------------------------------------------------------*/
void ProcessQueue::setHeadOfQueue(Node* headPtr)
{
    head = headPtr;
}
int ProcessQueue::getLength()
{
    int count = 0;
    Node* temp = getHeadOfQueue();
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

/*-------------------------------------------------------------------------------------
 Function Name : getAvgWaitingTime
 Description   : Calculates and return the average waiting time for the processes.
 Input         :
 Output        : Average turnaround time
 --------------------------------------------------------------------------------------*/
float ProcessQueue::getAvgWaitingTime()
{
    float avg = 0.0;
    int length = getLength();
    Node* temp = getHeadOfQueue();
    while(temp != NULL)
    {
        avg+= temp->data.getWaitingTime();
        temp = temp->next;
    }
    return (avg/length);
}

/*-------------------------------------------------------------------------------------
 Function Name : getAvgTurnaroundTime
 Description   : Calculates and returns the average turn around time of the processes.
 Input         :
 Output        : Average turn around time
 --------------------------------------------------------------------------------------*/
float ProcessQueue::getAvgTurnaroundTime()
{
    float avg = 0.0;
    int length = getLength();
    Node* temp = getHeadOfQueue();
    while(temp != NULL)
    {
        avg+= temp->data.getTurnAroundTime();
        temp = temp->next;
    }
    return (avg/length);
}
