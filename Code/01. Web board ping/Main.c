///////////////////////////////////////////////////////////////////////////
//  Product/Project : Web board ping                                     //
///////////////////////////////////////////////////////////////////////////
//
//  File Name    : Main.c
//  Version      : 1.0
//  Description  : Connect the uBoard to the internet with the "Web board"
//  Author       : Jim Clermonts
//  Target       : dsPIC33FJ64GP802
//  Compiler     : MPLAB C Compiler for PIC24 and dsPIC v3.25 in LITE mode
//  IDE          : MPLAB X IDE Beta4.0
//  Programmer   : uBRD bootloader
//  Last Updated : 09-06-2011
//
//  Copyright (c) Staronic 2011.
//  All rights are reserved. Reproduction in whole or in part is
//  prohibited without the written consent of the copyright owner.
///////////////////////////////////////////////////////////////////////////
#include    "Delay.h"
#include    "Peripherals.h"
#include    "stdio.h"
#include    "string.h"
#include    "uBRD.h"
#include    "W5100.h"

//Configuration-for-programmer--------------------------
_FBS(RBS_NO_RAM & BSS_NO_FLASH & BWRP_WRPROTECT_OFF);               // No boot ram, flash, write protection
_FSS(RSS_NO_RAM & SWRP_WRPROTECT_OFF);                              // No protected sections
_FGS(GSS_OFF
& GCP_OFF & GWRP_OFF);                                              // No code protection
_FOSCSEL(FNOSC_FRCPLL & IESO_OFF);                                  // FRC Oscillator with PLL, no two-speed oscillator
_FOSC(FCKSM_CSDCMD & IOL1WAY_OFF & OSCIOFNC_ON  & POSCMD_NONE);     // Clock Switching and Fail Safe Clock Monitor is disabled
                                                                    // Multiple I/O reconfigurations admitted                                                                  // OSC2 Pin is digital I/O														                      // Primaire Oscillator Mode: none
_FWDT(FWDTEN_OFF & WINDIS_OFF);                                     // Watchdog Timer off
_FPOR(ALTI2C_ON & FPWRT_PWR64);                                     // 64 ms power-up timer
_FICD(JTAGEN_OFF & ICS_PGD2);                                       // JTAG program port off
//------------------------------------------------------
// Ethernet Setup
unsigned char mac_addr[] = {0x00, 0x16, 0x36, 0xDE, 0x58, 0xF6};
unsigned char ip_addr[] = {192, 168, 1, 130};
unsigned char sub_mask[] = {255, 255, 255, 0};
unsigned char gtw_addr[] = {192, 168, 1, 1};

unsigned char startup[60] = "uBoard                                  "
        "Web board ping";

int main(void) {
    Init();
    Init_shift();
    Erase_VU();
    Init_pin_SPI();
    Init_SPI();
    Init_mcp();
    Init_LCD();
    W5100_Init(gtw_addr,mac_addr,sub_mask,ip_addr);
    T_SPI_CS;
    SPI_CS = 1;
    Write_LCD(startup);
    
    while (1) {
    /*
     *  Ping the uBoard:
     *  On a Windows PC: Start, CMD,
     *  ping 192.168.1.130
     *  
     */

    }
}
