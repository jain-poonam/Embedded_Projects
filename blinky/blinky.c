//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2012-2017 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
//
// This is part of revision 2.1.4.178 of the EK-TM4C123GXL Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/tm4c123gh6pm.h"

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//!
//! A very simple example that blinks the on-board LED using direct register
//! access.
//
//*****************************************************************************

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
    while(1);
}
#endif

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************
PortFunctionInit(void)
{
//
        volatile uint32_t ui32Loop;
    // Enable the GPIO port that is used for the on-board LED.
    //
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    //
    // Do a dummy read to insert a few cycles after enabling the peripheral.
    //
    ui32Loop = SYSCTL_RCGC2_R;

    //
    // Enable the GPIO pin for the blue LED (PF2).  Set the direction as output, and
    // enable the GPIO pin for digital function.
//    //
//    GPIO_PORTF_LOCK_R = 0x4C4F434B;
//    GPIO_PORTF_CR_R |= 0x01;
//    GPIO_PORTF_DIR_R |= 0x0E;
//    GPIO_PORTF_DIR_R &= ~0x11;
//    GPIO_PORTF_DEN_R |= 0x1F;
//    GPIO_PORTF_PUR_R |= 0x11;
//
//
//
//}
//
//int main(void)
//{
//
//
//
//    PortFunctionInit();
//
//
//
//
//    //
//    // Loop forever.
//    //
//    while(1)
//    {
//        if((GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0)==0x00)&&(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4)==0x00)){
//
//
//        //
//        // Turn on the LED.
//        //
//          GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,0x04);
//
//        //
//        // Delay for a bit.
//        //
////        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
////        {
////        }
//        }else if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4)==0x00){
//
//
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x02);
//
//        }else if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0)==0x00){
//            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x08);
//
//        }else{
//            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,0x00);
//            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,0x00);
//            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,0x00);
//        }

        GPIO_PORTF_LOCK_R = 0x4C4F434B;
        GPIO_PORTF_CR_R |= 0x01;
        GPIO_PORTF_DIR_R |= 0x04;
        GPIO_PORTF_DIR_R &= ~0x10;
        GPIO_PORTF_DEN_R |= 0x14;
        GPIO_PORTF_PUR_R |= 0x10;



    }

    int main(void)
    {



        PortFunctionInit();

        while(1)
        {
            if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0)!=00){

              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,0x04);


            }else if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0)==00){
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,0x04);
                SysCtlDelay(200000);



                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,0x00);
                SysCtlDelay(200000);

                }


    }
}

