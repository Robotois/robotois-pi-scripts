/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: yovany
 *
 * Created on March 27, 2017, 3:32 PM
 */

#include <cstdlib>
#include <chrono>
#include <thread>
#include <bcm2835.h>
#include <stdio.h>

#include "DigitalIO/DigitalIO.h"

using namespace std;

#define RESET_BUTTON RPI_V2_GPIO_P1_07 // 3.3v Logic IO
#define WEBSERVER_RESET 0x01
#define RASPBERRY_SHUTDOWN 0x02

void bcm_init();
void bcm_end();
uint8_t getResetMode(DigitalIO *button);

/*
 * 
 */
int main(int argc, char** argv) {
    bcm_init();
    DigitalIO *button = new DigitalIO(RESET_BUTTON,AS_INPUT);
    uint8_t resetMode = 0x00;
    while(true){
        if(button->read()){
            resetMode = getResetMode(button);
//            printf("Reset Mode: %d",getResetMode(button));
            switch(resetMode){
                case WEBSERVER_RESET:
                    printf("Restarting the webserverpi application...\n");
                    system("sudo forever restart --killsignal=SIGTERM /home/pi/Robotois/webserverpi/index.js");
                    break;
                case RASPBERRY_SHUTDOWN:
                    printf("Raspberry PI going to shutdown... hasta la vista baby!!\n");
                    system("sudo shutdown -h now");
                    break;
                default: // - False alarm
                    break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    bcm_end();
    return 0;
}

uint8_t getResetMode(DigitalIO *button){
    uint8_t resetMode = 0x00;
    auto startTime = std::chrono::high_resolution_clock::now();            
    printf("Reset Button pressed!!: %d\n",button->read());
    uint16_t millis = 0;
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        auto elapsedTime = std::chrono::high_resolution_clock::now() - startTime;
        millis = std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime).count();

        // -- If the button is pressed for more than 2 secs
        if(button->read()){  
            if(millis >= 2000 and millis < 5000){
                resetMode = WEBSERVER_RESET;
            }

            if(millis >= 5000){
                resetMode = RASPBERRY_SHUTDOWN;
                break;
            }
        }else{ // - Button was released
            break;
        }
    }
    return resetMode;
}

void bcm_init(){
    if (!bcm2835_init()){
        printf("BCM2835 Error!!...\n");
        exit(1);
    }    
}

void bcm_end(){
    bcm2835_close();    
}