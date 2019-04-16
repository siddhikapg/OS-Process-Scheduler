//--------------------------------------------------------------------------------------
//  Utility.h
//  OSProject
//
//  Created by Siddhika Ghaisas on 11/8/18.
//  Copyright © 2018 Siddhika Ghaisas. All rights reserved.
//
//--------------------------------------------------------------------------------------

#ifndef Utility_h
#define Utility_h

#include "ProcessQueue.h"
#include <stdio.h>
#include <fstream>

/*-------------------------------------------------------------------------------------
 Function Name : populateQueueFromFile
 Description   :
 Input         : ProcessQueue& readyqueue
 Output        : ProcessQueue& readyqueue , as the readyqueue is poulated with the
                 process data from the input file
--------------------------------------------------------------------------------------*/
extern void populateQueueFromFile(ProcessQueue& readyqueue)
{
    //Open the file from given path
    std::ifstream ifs;
    ifs.open("pdata1.txt", std::ifstream::in);
    std::string line;
    while(!ifs.eof())
    {
        Process P1;
        std::getline(ifs, line);
        //Parse the line and fill a process object
        char* token = strtok(strdup(line.c_str()), ",");
        P1.setProcessID(atoi(token));
        token = strtok(NULL, ",");
        P1.setArrivalTime(atoi(token));
        token = strtok(NULL, ",");
        P1.setBurstTime(atoi(token));
        token = strtok(NULL, ",");
        P1.setPriority(atoi(token));
        readyqueue.addToQueue(P1);

    }
    ifs.close();
}

#endif /* Utility_h */
