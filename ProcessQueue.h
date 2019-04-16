//--------------------------------------------------------------------------------------
//  ProcessQueue.h
//  OSProject
//
//  Created by Siddhika Ghaisas on 10/27/18.
//  Copyright © 2018 Siddhika Ghaisas. All rights reserved.
//--------------------------------------------------------------------------------------

#ifndef ProcessQueue_h
#define ProcessQueue_h

#include <stdio.h>
#include "Process.h"


struct Node
{
    Process data;
    Node* next;
    Node* prev;
};
class ProcessQueue
{
private:
    Node* head;
    Node* tail;
    
public:
    ProcessQueue();
    void addToQueue(Process var);
    void deleteFromQueue(Process var);
    void printQueue();
    void sortQueue(int criteria);
    void mergeSort(Node** head, int criteria);
    Node* sortByArrivalTime(Node* half1, Node* half2);
    Node* sortByBurstTime(Node* half1, Node* half2);
    Node* sortByPriority(Node* half1, Node* half2);
    void splitForSort(Node* source, Node** front,Node** back);
    Node* getHeadOfQueue();
    void setHeadOfQueue(Node* headPtr);
    int getLength();
    float getAvgWaitingTime();
    float getAvgTurnaroundTime();
    ~ProcessQueue();
};


#endif /* ProcessQueue_h */
