﻿/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Rosbee.h
* @date Created: 6/15/2015
*
* @author Coen Andriessen
*
* @version 1.1
*
* @section LICENSE
* License: newBSD
*
* Copyright � 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef ROSBEE_H
#define ROSBEE_H

#include <iostream>

class Rosbee
{
public:
    // Constructor of rosbee.
    Rosbee();
    // Destructor of rosbee.
    ~Rosbee();
    // Function to check if the rosbee location is changed.
    bool isLocationChanged();
    // Function to get the rosbee location x.
    int getRosbeeLocationX();
    // Function to get the rosbee location y.
    int getRosbeeLocationY();
    // Function to get the old rosbee location x.
    int getOldRosbeeLocationX();
    // Function to get the old rosbee location y.
    int getOldRosbeeLocationY();
    // Function to set the rosbee location y.
    void setRosbeeLocationY(int y);
    // Function to set the rosbee location x.
    void setRosbeeLocationX(int x);
private:
    int rosbeeLocationX;
    int oldRosbeeLocationX;
    int oldRosbeeLocationY;
    int rosbeeLocationY;
};

#endif // ROSBEE_H
