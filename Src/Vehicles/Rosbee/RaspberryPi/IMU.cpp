/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file IMU.cpp
* @date Created: 26-6-2015
*
* @author Edwin Koek
* @version 1.0
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
#include "IMU.h"

#define USE_MATH_DEFINES
#include <cmath>

IMU::IMU():
    xgyro{0},
    ygyro{0},
    zgyro{0},
    xacc{0},
    yacc{0},
    zacc{0},
    roll{0},
    pitch{0},
    yaw{0}
{}

void IMU::newReading(float newxgyro,
                     float newygyro,
                     float newzgyro,
                     float newxacc,
                     float newyacc,
                     float newzacc,
                     double dTime){
    xgyro = newxgyro;
    ygyro = newygyro;
    zgyro = newzgyro;
    xacc = newxacc;
    yacc = newyacc;
    zacc = newzacc;

    complementaryFilter(dTime);
    yaw += (zgyro/1000) * dTime;
}

void IMU::complementaryFilter(double dTime){
    float accRoll = atan(xacc /sqrt((yacc * yacc) + (zacc * zacc)));
    float accPitch = atan(yacc/sqrt((xacc * xacc) + (zacc * zacc)));
    roll = (0.98 * (roll + ((xgyro/1000) * dTime))) + (0.02 * accRoll);
    pitch = (0.98 * (roll + ((ygyro/1000) * dTime))) + (0.02 * accPitch);

}

float IMU::getRoll(){
    return (roll * (180/M_PI));
}

float IMU::getPitch(){
    return (pitch * (180/M_PI));
}

float IMU::getYaw(){
    return (yaw * (180/M_PI));
}
