/*******************************************************************************
  GPIO PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_gpio.h

  Summary:
    GPIO PLIB Header File

  Description:
    This library provides an interface to control and interact with Parallel
    Input/Output controller (GPIO) module.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#ifndef PLIB_GPIO_H
#define PLIB_GPIO_H

#include <device.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data types and constants
// *****************************************************************************
// *****************************************************************************


/*** Macros for OUT7 pin ***/
#define OUT7_Set()               (LATGSET = (1<<15))
#define OUT7_Clear()             (LATGCLR = (1<<15))
#define OUT7_Toggle()            (LATGINV= (1<<15))
#define OUT7_OutputEnable()      (TRISGCLR = (1<<15))
#define OUT7_InputEnable()       (TRISGSET = (1<<15))
#define OUT7_Get()               ((PORTG >> 15) & 0x1)
#define OUT7_PIN                  GPIO_PIN_RG15

/*** Macros for IN5 pin ***/
#define IN5_Set()               (LATESET = (1<<5))
#define IN5_Clear()             (LATECLR = (1<<5))
#define IN5_Toggle()            (LATEINV= (1<<5))
#define IN5_OutputEnable()      (TRISECLR = (1<<5))
#define IN5_InputEnable()       (TRISESET = (1<<5))
#define IN5_Get()               ((PORTE >> 5) & 0x1)
#define IN5_PIN                  GPIO_PIN_RE5

/*** Macros for IN6 pin ***/
#define IN6_Set()               (LATESET = (1<<6))
#define IN6_Clear()             (LATECLR = (1<<6))
#define IN6_Toggle()            (LATEINV= (1<<6))
#define IN6_OutputEnable()      (TRISECLR = (1<<6))
#define IN6_InputEnable()       (TRISESET = (1<<6))
#define IN6_Get()               ((PORTE >> 6) & 0x1)
#define IN6_PIN                  GPIO_PIN_RE6

/*** Macros for IN7 pin ***/
#define IN7_Set()               (LATESET = (1<<7))
#define IN7_Clear()             (LATECLR = (1<<7))
#define IN7_Toggle()            (LATEINV= (1<<7))
#define IN7_OutputEnable()      (TRISECLR = (1<<7))
#define IN7_InputEnable()       (TRISESET = (1<<7))
#define IN7_Get()               ((PORTE >> 7) & 0x1)
#define IN7_PIN                  GPIO_PIN_RE7

/*** Macros for BRAKE1 pin ***/
#define BRAKE1_Set()               (LATCSET = (1<<1))
#define BRAKE1_Clear()             (LATCCLR = (1<<1))
#define BRAKE1_Toggle()            (LATCINV= (1<<1))
#define BRAKE1_OutputEnable()      (TRISCCLR = (1<<1))
#define BRAKE1_InputEnable()       (TRISCSET = (1<<1))
#define BRAKE1_Get()               ((PORTC >> 1) & 0x1)
#define BRAKE1_PIN                  GPIO_PIN_RC1

/*** Macros for BRAKE2 pin ***/
#define BRAKE2_Set()               (LATCSET = (1<<2))
#define BRAKE2_Clear()             (LATCCLR = (1<<2))
#define BRAKE2_Toggle()            (LATCINV= (1<<2))
#define BRAKE2_OutputEnable()      (TRISCCLR = (1<<2))
#define BRAKE2_InputEnable()       (TRISCSET = (1<<2))
#define BRAKE2_Get()               ((PORTC >> 2) & 0x1)
#define BRAKE2_PIN                  GPIO_PIN_RC2

/*** Macros for BRAKE3 pin ***/
#define BRAKE3_Set()               (LATCSET = (1<<3))
#define BRAKE3_Clear()             (LATCCLR = (1<<3))
#define BRAKE3_Toggle()            (LATCINV= (1<<3))
#define BRAKE3_OutputEnable()      (TRISCCLR = (1<<3))
#define BRAKE3_InputEnable()       (TRISCSET = (1<<3))
#define BRAKE3_Get()               ((PORTC >> 3) & 0x1)
#define BRAKE3_PIN                  GPIO_PIN_RC3

/*** Macros for SPI1_IN pin ***/
#define SPI1_IN_Get()               ((PORTC >> 4) & 0x1)
#define SPI1_IN_PIN                  GPIO_PIN_RC4

/*** Macros for U6TX pin ***/
#define U6TX_Get()               ((PORTG >> 6) & 0x1)
#define U6TX_PIN                  GPIO_PIN_RG6

/*** Macros for U3RX pin ***/
#define U3RX_Get()               ((PORTG >> 7) & 0x1)
#define U3RX_PIN                  GPIO_PIN_RG7

/*** Macros for U3TX pin ***/
#define U3TX_Get()               ((PORTG >> 8) & 0x1)
#define U3TX_PIN                  GPIO_PIN_RG8

/*** Macros for U6RX pin ***/
#define U6RX_Get()               ((PORTG >> 9) & 0x1)
#define U6RX_PIN                  GPIO_PIN_RG9

/*** Macros for SPR5 pin ***/
#define SPR5_Set()               (LATASET = (1<<0))
#define SPR5_Clear()             (LATACLR = (1<<0))
#define SPR5_Toggle()            (LATAINV= (1<<0))
#define SPR5_OutputEnable()      (TRISACLR = (1<<0))
#define SPR5_InputEnable()       (TRISASET = (1<<0))
#define SPR5_Get()               ((PORTA >> 0) & 0x1)
#define SPR5_PIN                  GPIO_PIN_RA0

/*** Macros for INTR1 pin ***/
#define INTR1_Get()               ((PORTE >> 8) & 0x1)
#define INTR1_PIN                  GPIO_PIN_RE8

/*** Macros for SSI_DAT1 pin ***/
#define SSI_DAT1_Set()               (LATESET = (1<<9))
#define SSI_DAT1_Clear()             (LATECLR = (1<<9))
#define SSI_DAT1_Toggle()            (LATEINV= (1<<9))
#define SSI_DAT1_OutputEnable()      (TRISECLR = (1<<9))
#define SSI_DAT1_InputEnable()       (TRISESET = (1<<9))
#define SSI_DAT1_Get()               ((PORTE >> 9) & 0x1)
#define SSI_DAT1_PIN                  GPIO_PIN_RE9

/*** Macros for SSI_CLK1 pin ***/
#define SSI_CLK1_Set()               (LATBSET = (1<<5))
#define SSI_CLK1_Clear()             (LATBCLR = (1<<5))
#define SSI_CLK1_Toggle()            (LATBINV= (1<<5))
#define SSI_CLK1_OutputEnable()      (TRISBCLR = (1<<5))
#define SSI_CLK1_InputEnable()       (TRISBSET = (1<<5))
#define SSI_CLK1_Get()               ((PORTB >> 5) & 0x1)
#define SSI_CLK1_PIN                  GPIO_PIN_RB5

/*** Macros for LED_STATUS pin ***/
#define LED_STATUS_Set()               (LATBSET = (1<<4))
#define LED_STATUS_Clear()             (LATBCLR = (1<<4))
#define LED_STATUS_Toggle()            (LATBINV= (1<<4))
#define LED_STATUS_OutputEnable()      (TRISBCLR = (1<<4))
#define LED_STATUS_InputEnable()       (TRISBSET = (1<<4))
#define LED_STATUS_Get()               ((PORTB >> 4) & 0x1)
#define LED_STATUS_PIN                  GPIO_PIN_RB4

/*** Macros for SPR2 pin ***/
#define SPR2_Get()               ((PORTB >> 3) & 0x1)
#define SPR2_PIN                  GPIO_PIN_RB3

/*** Macros for SPR1 pin ***/
#define SPR1_Get()               ((PORTB >> 2) & 0x1)
#define SPR1_PIN                  GPIO_PIN_RB2

/*** Macros for SCAN5 pin ***/
#define SCAN5_Set()               (LATBSET = (1<<6))
#define SCAN5_Clear()             (LATBCLR = (1<<6))
#define SCAN5_Toggle()            (LATBINV= (1<<6))
#define SCAN5_OutputEnable()      (TRISBCLR = (1<<6))
#define SCAN5_InputEnable()       (TRISBSET = (1<<6))
#define SCAN5_Get()               ((PORTB >> 6) & 0x1)
#define SCAN5_PIN                  GPIO_PIN_RB6

/*** Macros for SPR6 pin ***/
#define SPR6_Set()               (LATBSET = (1<<7))
#define SPR6_Clear()             (LATBCLR = (1<<7))
#define SPR6_Toggle()            (LATBINV= (1<<7))
#define SPR6_OutputEnable()      (TRISBCLR = (1<<7))
#define SPR6_InputEnable()       (TRISBSET = (1<<7))
#define SPR6_Get()               ((PORTB >> 7) & 0x1)
#define SPR6_PIN                  GPIO_PIN_RB7

/*** Macros for SSI_CLK0 pin ***/
#define SSI_CLK0_Set()               (LATASET = (1<<9))
#define SSI_CLK0_Clear()             (LATACLR = (1<<9))
#define SSI_CLK0_Toggle()            (LATAINV= (1<<9))
#define SSI_CLK0_OutputEnable()      (TRISACLR = (1<<9))
#define SSI_CLK0_InputEnable()       (TRISASET = (1<<9))
#define SSI_CLK0_Get()               ((PORTA >> 9) & 0x1)
#define SSI_CLK0_PIN                  GPIO_PIN_RA9

/*** Macros for SSI_DAT0 pin ***/
#define SSI_DAT0_Set()               (LATASET = (1<<10))
#define SSI_DAT0_Clear()             (LATACLR = (1<<10))
#define SSI_DAT0_Toggle()            (LATAINV= (1<<10))
#define SSI_DAT0_OutputEnable()      (TRISACLR = (1<<10))
#define SSI_DAT0_InputEnable()       (TRISASET = (1<<10))
#define SSI_DAT0_Get()               ((PORTA >> 10) & 0x1)
#define SSI_DAT0_PIN                  GPIO_PIN_RA10

/*** Macros for IN8 pin ***/
#define IN8_Set()               (LATBSET = (1<<8))
#define IN8_Clear()             (LATBCLR = (1<<8))
#define IN8_Toggle()            (LATBINV= (1<<8))
#define IN8_OutputEnable()      (TRISBCLR = (1<<8))
#define IN8_InputEnable()       (TRISBSET = (1<<8))
#define IN8_Get()               ((PORTB >> 8) & 0x1)
#define IN8_PIN                  GPIO_PIN_RB8

/*** Macros for IN9 pin ***/
#define IN9_Set()               (LATBSET = (1<<9))
#define IN9_Clear()             (LATBCLR = (1<<9))
#define IN9_Toggle()            (LATBINV= (1<<9))
#define IN9_OutputEnable()      (TRISBCLR = (1<<9))
#define IN9_InputEnable()       (TRISBSET = (1<<9))
#define IN9_Get()               ((PORTB >> 9) & 0x1)
#define IN9_PIN                  GPIO_PIN_RB9

/*** Macros for IN10 pin ***/
#define IN10_Set()               (LATBSET = (1<<10))
#define IN10_Clear()             (LATBCLR = (1<<10))
#define IN10_Toggle()            (LATBINV= (1<<10))
#define IN10_OutputEnable()      (TRISBCLR = (1<<10))
#define IN10_InputEnable()       (TRISBSET = (1<<10))
#define IN10_Get()               ((PORTB >> 10) & 0x1)
#define IN10_PIN                  GPIO_PIN_RB10

/*** Macros for IN11 pin ***/
#define IN11_Set()               (LATBSET = (1<<11))
#define IN11_Clear()             (LATBCLR = (1<<11))
#define IN11_Toggle()            (LATBINV= (1<<11))
#define IN11_OutputEnable()      (TRISBCLR = (1<<11))
#define IN11_InputEnable()       (TRISBSET = (1<<11))
#define IN11_Get()               ((PORTB >> 11) & 0x1)
#define IN11_PIN                  GPIO_PIN_RB11

/*** Macros for SPR0 pin ***/
#define SPR0_Set()               (LATASET = (1<<1))
#define SPR0_Clear()             (LATACLR = (1<<1))
#define SPR0_Toggle()            (LATAINV= (1<<1))
#define SPR0_OutputEnable()      (TRISACLR = (1<<1))
#define SPR0_InputEnable()       (TRISASET = (1<<1))
#define SPR0_Get()               ((PORTA >> 1) & 0x1)
#define SPR0_PIN                  GPIO_PIN_RA1

/*** Macros for U5TX pin ***/
#define U5TX_Get()               ((PORTF >> 13) & 0x1)
#define U5TX_PIN                  GPIO_PIN_RF13

/*** Macros for U5RX pin ***/
#define U5RX_Get()               ((PORTF >> 12) & 0x1)
#define U5RX_PIN                  GPIO_PIN_RF12

/*** Macros for IN12 pin ***/
#define IN12_Set()               (LATBSET = (1<<12))
#define IN12_Clear()             (LATBCLR = (1<<12))
#define IN12_Toggle()            (LATBINV= (1<<12))
#define IN12_OutputEnable()      (TRISBCLR = (1<<12))
#define IN12_InputEnable()       (TRISBSET = (1<<12))
#define IN12_Get()               ((PORTB >> 12) & 0x1)
#define IN12_PIN                  GPIO_PIN_RB12

/*** Macros for IN13 pin ***/
#define IN13_Set()               (LATBSET = (1<<13))
#define IN13_Clear()             (LATBCLR = (1<<13))
#define IN13_Toggle()            (LATBINV= (1<<13))
#define IN13_OutputEnable()      (TRISBCLR = (1<<13))
#define IN13_InputEnable()       (TRISBSET = (1<<13))
#define IN13_Get()               ((PORTB >> 13) & 0x1)
#define IN13_PIN                  GPIO_PIN_RB13

/*** Macros for IN14 pin ***/
#define IN14_Set()               (LATBSET = (1<<14))
#define IN14_Clear()             (LATBCLR = (1<<14))
#define IN14_Toggle()            (LATBINV= (1<<14))
#define IN14_OutputEnable()      (TRISBCLR = (1<<14))
#define IN14_InputEnable()       (TRISBSET = (1<<14))
#define IN14_Get()               ((PORTB >> 14) & 0x1)
#define IN14_PIN                  GPIO_PIN_RB14

/*** Macros for IN15 pin ***/
#define IN15_Set()               (LATBSET = (1<<15))
#define IN15_Clear()             (LATBCLR = (1<<15))
#define IN15_Toggle()            (LATBINV= (1<<15))
#define IN15_OutputEnable()      (TRISBCLR = (1<<15))
#define IN15_InputEnable()       (TRISBSET = (1<<15))
#define IN15_Get()               ((PORTB >> 15) & 0x1)
#define IN15_PIN                  GPIO_PIN_RB15

/*** Macros for U4RX pin ***/
#define U4RX_Get()               ((PORTD >> 14) & 0x1)
#define U4RX_PIN                  GPIO_PIN_RD14

/*** Macros for U4TX pin ***/
#define U4TX_Get()               ((PORTD >> 15) & 0x1)
#define U4TX_PIN                  GPIO_PIN_RD15

/*** Macros for U2RX pin ***/
#define U2RX_Get()               ((PORTF >> 4) & 0x1)
#define U2RX_PIN                  GPIO_PIN_RF4

/*** Macros for U2TX pin ***/
#define U2TX_Get()               ((PORTF >> 5) & 0x1)
#define U2TX_PIN                  GPIO_PIN_RF5

/*** Macros for SPI_CS0 pin ***/
#define SPI_CS0_Set()               (LATFSET = (1<<3))
#define SPI_CS0_Clear()             (LATFCLR = (1<<3))
#define SPI_CS0_Toggle()            (LATFINV= (1<<3))
#define SPI_CS0_OutputEnable()      (TRISFCLR = (1<<3))
#define SPI_CS0_InputEnable()       (TRISFSET = (1<<3))
#define SPI_CS0_Get()               ((PORTF >> 3) & 0x1)
#define SPI_CS0_PIN                  GPIO_PIN_RF3

/*** Macros for U1RX pin ***/
#define U1RX_Get()               ((PORTF >> 2) & 0x1)
#define U1RX_PIN                  GPIO_PIN_RF2

/*** Macros for U1TX pin ***/
#define U1TX_Get()               ((PORTF >> 8) & 0x1)
#define U1TX_PIN                  GPIO_PIN_RF8

/*** Macros for OUT3 pin ***/
#define OUT3_Set()               (LATGSET = (1<<3))
#define OUT3_Clear()             (LATGCLR = (1<<3))
#define OUT3_Toggle()            (LATGINV= (1<<3))
#define OUT3_OutputEnable()      (TRISGCLR = (1<<3))
#define OUT3_InputEnable()       (TRISGSET = (1<<3))
#define OUT3_Get()               ((PORTG >> 3) & 0x1)
#define OUT3_PIN                  GPIO_PIN_RG3

/*** Macros for OUT2 pin ***/
#define OUT2_Set()               (LATGSET = (1<<2))
#define OUT2_Clear()             (LATGCLR = (1<<2))
#define OUT2_Toggle()            (LATGINV= (1<<2))
#define OUT2_OutputEnable()      (TRISGCLR = (1<<2))
#define OUT2_InputEnable()       (TRISGSET = (1<<2))
#define OUT2_Get()               ((PORTG >> 2) & 0x1)
#define OUT2_PIN                  GPIO_PIN_RG2

/*** Macros for SCL2 pin ***/
#define SCL2_Get()               ((PORTA >> 2) & 0x1)
#define SCL2_PIN                  GPIO_PIN_RA2

/*** Macros for SDA2 pin ***/
#define SDA2_Get()               ((PORTA >> 3) & 0x1)
#define SDA2_PIN                  GPIO_PIN_RA3

/*** Macros for SCAN1 pin ***/
#define SCAN1_Set()               (LATASET = (1<<4))
#define SCAN1_Clear()             (LATACLR = (1<<4))
#define SCAN1_Toggle()            (LATAINV= (1<<4))
#define SCAN1_OutputEnable()      (TRISACLR = (1<<4))
#define SCAN1_InputEnable()       (TRISASET = (1<<4))
#define SCAN1_Get()               ((PORTA >> 4) & 0x1)
#define SCAN1_PIN                  GPIO_PIN_RA4

/*** Macros for SCAN2 pin ***/
#define SCAN2_Set()               (LATASET = (1<<5))
#define SCAN2_Clear()             (LATACLR = (1<<5))
#define SCAN2_Toggle()            (LATAINV= (1<<5))
#define SCAN2_OutputEnable()      (TRISACLR = (1<<5))
#define SCAN2_InputEnable()       (TRISASET = (1<<5))
#define SCAN2_Get()               ((PORTA >> 5) & 0x1)
#define SCAN2_PIN                  GPIO_PIN_RA5

/*** Macros for X8_I pin ***/
#define X8_I_Get()               ((PORTC >> 12) & 0x1)
#define X8_I_PIN                  GPIO_PIN_RC12

/*** Macros for X8_O pin ***/
#define X8_O_Get()               ((PORTC >> 15) & 0x1)
#define X8_O_PIN                  GPIO_PIN_RC15

/*** Macros for SPR3 pin ***/
#define SPR3_Set()               (LATASET = (1<<14))
#define SPR3_Clear()             (LATACLR = (1<<14))
#define SPR3_Toggle()            (LATAINV= (1<<14))
#define SPR3_OutputEnable()      (TRISACLR = (1<<14))
#define SPR3_InputEnable()       (TRISASET = (1<<14))
#define SPR3_Get()               ((PORTA >> 14) & 0x1)
#define SPR3_PIN                  GPIO_PIN_RA14

/*** Macros for SPR4 pin ***/
#define SPR4_Set()               (LATASET = (1<<15))
#define SPR4_Clear()             (LATACLR = (1<<15))
#define SPR4_Toggle()            (LATAINV= (1<<15))
#define SPR4_OutputEnable()      (TRISACLR = (1<<15))
#define SPR4_InputEnable()       (TRISASET = (1<<15))
#define SPR4_Get()               ((PORTA >> 15) & 0x1)
#define SPR4_PIN                  GPIO_PIN_RA15

/*** Macros for D7 pin ***/
#define D7_Set()               (LATDSET = (1<<8))
#define D7_Clear()             (LATDCLR = (1<<8))
#define D7_Toggle()            (LATDINV= (1<<8))
#define D7_OutputEnable()      (TRISDCLR = (1<<8))
#define D7_InputEnable()       (TRISDSET = (1<<8))
#define D7_Get()               ((PORTD >> 8) & 0x1)
#define D7_PIN                  GPIO_PIN_RD8

/*** Macros for SPI_CS2 pin ***/
#define SPI_CS2_Set()               (LATDSET = (1<<9))
#define SPI_CS2_Clear()             (LATDCLR = (1<<9))
#define SPI_CS2_Toggle()            (LATDINV= (1<<9))
#define SPI_CS2_OutputEnable()      (TRISDCLR = (1<<9))
#define SPI_CS2_InputEnable()       (TRISDSET = (1<<9))
#define SPI_CS2_Get()               ((PORTD >> 9) & 0x1)
#define SPI_CS2_PIN                  GPIO_PIN_RD9

/*** Macros for GPIO_RD10 pin ***/
#define GPIO_RD10_Set()               (LATDSET = (1<<10))
#define GPIO_RD10_Clear()             (LATDCLR = (1<<10))
#define GPIO_RD10_Toggle()            (LATDINV= (1<<10))
#define GPIO_RD10_OutputEnable()      (TRISDCLR = (1<<10))
#define GPIO_RD10_InputEnable()       (TRISDSET = (1<<10))
#define GPIO_RD10_Get()               ((PORTD >> 10) & 0x1)
#define GPIO_RD10_PIN                  GPIO_PIN_RD10

/*** Macros for SPI_CS1 pin ***/
#define SPI_CS1_Set()               (LATDSET = (1<<11))
#define SPI_CS1_Clear()             (LATDCLR = (1<<11))
#define SPI_CS1_Toggle()            (LATDINV= (1<<11))
#define SPI_CS1_OutputEnable()      (TRISDCLR = (1<<11))
#define SPI_CS1_InputEnable()       (TRISDSET = (1<<11))
#define SPI_CS1_Get()               ((PORTD >> 11) & 0x1)
#define SPI_CS1_PIN                  GPIO_PIN_RD11

/*** Macros for SPI1_OUT pin ***/
#define SPI1_OUT_Get()               ((PORTD >> 0) & 0x1)
#define SPI1_OUT_PIN                  GPIO_PIN_RD0

/*** Macros for RS_DIS pin ***/
#define RS_DIS_Set()               (LATCSET = (1<<13))
#define RS_DIS_Clear()             (LATCCLR = (1<<13))
#define RS_DIS_Toggle()            (LATCINV= (1<<13))
#define RS_DIS_OutputEnable()      (TRISCCLR = (1<<13))
#define RS_DIS_InputEnable()       (TRISCSET = (1<<13))
#define RS_DIS_Get()               ((PORTC >> 13) & 0x1)
#define RS_DIS_PIN                  GPIO_PIN_RC13

/*** Macros for EN_DIS pin ***/
#define EN_DIS_Set()               (LATCSET = (1<<14))
#define EN_DIS_Clear()             (LATCCLR = (1<<14))
#define EN_DIS_Toggle()            (LATCINV= (1<<14))
#define EN_DIS_OutputEnable()      (TRISCCLR = (1<<14))
#define EN_DIS_InputEnable()       (TRISCSET = (1<<14))
#define EN_DIS_Get()               ((PORTC >> 14) & 0x1)
#define EN_DIS_PIN                  GPIO_PIN_RC14

/*** Macros for D0 pin ***/
#define D0_Set()               (LATDSET = (1<<1))
#define D0_Clear()             (LATDCLR = (1<<1))
#define D0_Toggle()            (LATDINV= (1<<1))
#define D0_OutputEnable()      (TRISDCLR = (1<<1))
#define D0_InputEnable()       (TRISDSET = (1<<1))
#define D0_Get()               ((PORTD >> 1) & 0x1)
#define D0_PIN                  GPIO_PIN_RD1

/*** Macros for D1 pin ***/
#define D1_Set()               (LATDSET = (1<<2))
#define D1_Clear()             (LATDCLR = (1<<2))
#define D1_Toggle()            (LATDINV= (1<<2))
#define D1_OutputEnable()      (TRISDCLR = (1<<2))
#define D1_InputEnable()       (TRISDSET = (1<<2))
#define D1_Get()               ((PORTD >> 2) & 0x1)
#define D1_PIN                  GPIO_PIN_RD2

/*** Macros for D2 pin ***/
#define D2_Set()               (LATDSET = (1<<3))
#define D2_Clear()             (LATDCLR = (1<<3))
#define D2_Toggle()            (LATDINV= (1<<3))
#define D2_OutputEnable()      (TRISDCLR = (1<<3))
#define D2_InputEnable()       (TRISDSET = (1<<3))
#define D2_Get()               ((PORTD >> 3) & 0x1)
#define D2_PIN                  GPIO_PIN_RD3

/*** Macros for SSI_CLK2 pin ***/
#define SSI_CLK2_Set()               (LATDSET = (1<<12))
#define SSI_CLK2_Clear()             (LATDCLR = (1<<12))
#define SSI_CLK2_Toggle()            (LATDINV= (1<<12))
#define SSI_CLK2_OutputEnable()      (TRISDCLR = (1<<12))
#define SSI_CLK2_InputEnable()       (TRISDSET = (1<<12))
#define SSI_CLK2_Get()               ((PORTD >> 12) & 0x1)
#define SSI_CLK2_PIN                  GPIO_PIN_RD12

/*** Macros for SSI_DAT2 pin ***/
#define SSI_DAT2_Set()               (LATDSET = (1<<13))
#define SSI_DAT2_Clear()             (LATDCLR = (1<<13))
#define SSI_DAT2_Toggle()            (LATDINV= (1<<13))
#define SSI_DAT2_OutputEnable()      (TRISDCLR = (1<<13))
#define SSI_DAT2_InputEnable()       (TRISDSET = (1<<13))
#define SSI_DAT2_Get()               ((PORTD >> 13) & 0x1)
#define SSI_DAT2_PIN                  GPIO_PIN_RD13

/*** Macros for D3 pin ***/
#define D3_Set()               (LATDSET = (1<<4))
#define D3_Clear()             (LATDCLR = (1<<4))
#define D3_Toggle()            (LATDINV= (1<<4))
#define D3_OutputEnable()      (TRISDCLR = (1<<4))
#define D3_InputEnable()       (TRISDSET = (1<<4))
#define D3_Get()               ((PORTD >> 4) & 0x1)
#define D3_PIN                  GPIO_PIN_RD4

/*** Macros for D4 pin ***/
#define D4_Set()               (LATDSET = (1<<5))
#define D4_Clear()             (LATDCLR = (1<<5))
#define D4_Toggle()            (LATDINV= (1<<5))
#define D4_OutputEnable()      (TRISDCLR = (1<<5))
#define D4_InputEnable()       (TRISDSET = (1<<5))
#define D4_Get()               ((PORTD >> 5) & 0x1)
#define D4_PIN                  GPIO_PIN_RD5

/*** Macros for D5 pin ***/
#define D5_Set()               (LATDSET = (1<<6))
#define D5_Clear()             (LATDCLR = (1<<6))
#define D5_Toggle()            (LATDINV= (1<<6))
#define D5_OutputEnable()      (TRISDCLR = (1<<6))
#define D5_InputEnable()       (TRISDSET = (1<<6))
#define D5_Get()               ((PORTD >> 6) & 0x1)
#define D5_PIN                  GPIO_PIN_RD6

/*** Macros for D6 pin ***/
#define D6_Set()               (LATDSET = (1<<7))
#define D6_Clear()             (LATDCLR = (1<<7))
#define D6_Toggle()            (LATDINV= (1<<7))
#define D6_OutputEnable()      (TRISDCLR = (1<<7))
#define D6_InputEnable()       (TRISDSET = (1<<7))
#define D6_Get()               ((PORTD >> 7) & 0x1)
#define D6_PIN                  GPIO_PIN_RD7

/*** Macros for CAN1_RX pin ***/
#define CAN1_RX_Get()               ((PORTF >> 0) & 0x1)
#define CAN1_RX_PIN                  GPIO_PIN_RF0

/*** Macros for CAN1_TX pin ***/
#define CAN1_TX_Get()               ((PORTF >> 1) & 0x1)
#define CAN1_TX_PIN                  GPIO_PIN_RF1

/*** Macros for OUT1 pin ***/
#define OUT1_Set()               (LATGSET = (1<<1))
#define OUT1_Clear()             (LATGCLR = (1<<1))
#define OUT1_Toggle()            (LATGINV= (1<<1))
#define OUT1_OutputEnable()      (TRISGCLR = (1<<1))
#define OUT1_InputEnable()       (TRISGSET = (1<<1))
#define OUT1_Get()               ((PORTG >> 1) & 0x1)
#define OUT1_PIN                  GPIO_PIN_RG1

/*** Macros for OUT0 pin ***/
#define OUT0_Set()               (LATGSET = (1<<0))
#define OUT0_Clear()             (LATGCLR = (1<<0))
#define OUT0_Toggle()            (LATGINV= (1<<0))
#define OUT0_OutputEnable()      (TRISGCLR = (1<<0))
#define OUT0_InputEnable()       (TRISGSET = (1<<0))
#define OUT0_Get()               ((PORTG >> 0) & 0x1)
#define OUT0_PIN                  GPIO_PIN_RG0

/*** Macros for SCAN3 pin ***/
#define SCAN3_Set()               (LATASET = (1<<6))
#define SCAN3_Clear()             (LATACLR = (1<<6))
#define SCAN3_Toggle()            (LATAINV= (1<<6))
#define SCAN3_OutputEnable()      (TRISACLR = (1<<6))
#define SCAN3_InputEnable()       (TRISASET = (1<<6))
#define SCAN3_Get()               ((PORTA >> 6) & 0x1)
#define SCAN3_PIN                  GPIO_PIN_RA6

/*** Macros for SCAN4 pin ***/
#define SCAN4_Set()               (LATASET = (1<<7))
#define SCAN4_Clear()             (LATACLR = (1<<7))
#define SCAN4_Toggle()            (LATAINV= (1<<7))
#define SCAN4_OutputEnable()      (TRISACLR = (1<<7))
#define SCAN4_InputEnable()       (TRISASET = (1<<7))
#define SCAN4_Get()               ((PORTA >> 7) & 0x1)
#define SCAN4_PIN                  GPIO_PIN_RA7

/*** Macros for IN0 pin ***/
#define IN0_Set()               (LATESET = (1<<0))
#define IN0_Clear()             (LATECLR = (1<<0))
#define IN0_Toggle()            (LATEINV= (1<<0))
#define IN0_OutputEnable()      (TRISECLR = (1<<0))
#define IN0_InputEnable()       (TRISESET = (1<<0))
#define IN0_Get()               ((PORTE >> 0) & 0x1)
#define IN0_PIN                  GPIO_PIN_RE0

/*** Macros for IN1 pin ***/
#define IN1_Set()               (LATESET = (1<<1))
#define IN1_Clear()             (LATECLR = (1<<1))
#define IN1_Toggle()            (LATEINV= (1<<1))
#define IN1_OutputEnable()      (TRISECLR = (1<<1))
#define IN1_InputEnable()       (TRISESET = (1<<1))
#define IN1_Get()               ((PORTE >> 1) & 0x1)
#define IN1_PIN                  GPIO_PIN_RE1

/*** Macros for OUT6 pin ***/
#define OUT6_Set()               (LATGSET = (1<<14))
#define OUT6_Clear()             (LATGCLR = (1<<14))
#define OUT6_Toggle()            (LATGINV= (1<<14))
#define OUT6_OutputEnable()      (TRISGCLR = (1<<14))
#define OUT6_InputEnable()       (TRISGSET = (1<<14))
#define OUT6_Get()               ((PORTG >> 14) & 0x1)
#define OUT6_PIN                  GPIO_PIN_RG14

/*** Macros for OUT4 pin ***/
#define OUT4_Set()               (LATGSET = (1<<12))
#define OUT4_Clear()             (LATGCLR = (1<<12))
#define OUT4_Toggle()            (LATGINV= (1<<12))
#define OUT4_OutputEnable()      (TRISGCLR = (1<<12))
#define OUT4_InputEnable()       (TRISGSET = (1<<12))
#define OUT4_Get()               ((PORTG >> 12) & 0x1)
#define OUT4_PIN                  GPIO_PIN_RG12

/*** Macros for OUT5 pin ***/
#define OUT5_Set()               (LATGSET = (1<<13))
#define OUT5_Clear()             (LATGCLR = (1<<13))
#define OUT5_Toggle()            (LATGINV= (1<<13))
#define OUT5_OutputEnable()      (TRISGCLR = (1<<13))
#define OUT5_InputEnable()       (TRISGSET = (1<<13))
#define OUT5_Get()               ((PORTG >> 13) & 0x1)
#define OUT5_PIN                  GPIO_PIN_RG13

/*** Macros for IN2 pin ***/
#define IN2_Set()               (LATESET = (1<<2))
#define IN2_Clear()             (LATECLR = (1<<2))
#define IN2_Toggle()            (LATEINV= (1<<2))
#define IN2_OutputEnable()      (TRISECLR = (1<<2))
#define IN2_InputEnable()       (TRISESET = (1<<2))
#define IN2_Get()               ((PORTE >> 2) & 0x1)
#define IN2_PIN                  GPIO_PIN_RE2

/*** Macros for IN3 pin ***/
#define IN3_Set()               (LATESET = (1<<3))
#define IN3_Clear()             (LATECLR = (1<<3))
#define IN3_Toggle()            (LATEINV= (1<<3))
#define IN3_OutputEnable()      (TRISECLR = (1<<3))
#define IN3_InputEnable()       (TRISESET = (1<<3))
#define IN3_Get()               ((PORTE >> 3) & 0x1)
#define IN3_PIN                  GPIO_PIN_RE3

/*** Macros for IN4 pin ***/
#define IN4_Set()               (LATESET = (1<<4))
#define IN4_Clear()             (LATECLR = (1<<4))
#define IN4_Toggle()            (LATEINV= (1<<4))
#define IN4_OutputEnable()      (TRISECLR = (1<<4))
#define IN4_InputEnable()       (TRISESET = (1<<4))
#define IN4_Get()               ((PORTE >> 4) & 0x1)
#define IN4_PIN                  GPIO_PIN_RE4


// *****************************************************************************
/* GPIO Port

  Summary:
    Identifies the available GPIO Ports.

  Description:
    This enumeration identifies the available GPIO Ports.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all ports are available on all devices.  Refer to the specific
    device data sheet to determine which ports are supported.
*/

typedef enum
{
    GPIO_PORT_A = 0,
    GPIO_PORT_B = 1,
    GPIO_PORT_C = 2,
    GPIO_PORT_D = 3,
    GPIO_PORT_E = 4,
    GPIO_PORT_F = 5,
    GPIO_PORT_G = 6,
} GPIO_PORT;

// *****************************************************************************
/* GPIO Port Pins

  Summary:
    Identifies the available GPIO port pins.

  Description:
    This enumeration identifies the available GPIO port pins.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all pins are available on all devices.  Refer to the specific
    device data sheet to determine which pins are supported.
*/

typedef enum
{
    GPIO_PIN_RA0 = 0,
    GPIO_PIN_RA1 = 1,
    GPIO_PIN_RA2 = 2,
    GPIO_PIN_RA3 = 3,
    GPIO_PIN_RA4 = 4,
    GPIO_PIN_RA5 = 5,
    GPIO_PIN_RA6 = 6,
    GPIO_PIN_RA7 = 7,
    GPIO_PIN_RA9 = 9,
    GPIO_PIN_RA10 = 10,
    GPIO_PIN_RA14 = 14,
    GPIO_PIN_RA15 = 15,
    GPIO_PIN_RB0 = 16,
    GPIO_PIN_RB1 = 17,
    GPIO_PIN_RB2 = 18,
    GPIO_PIN_RB3 = 19,
    GPIO_PIN_RB4 = 20,
    GPIO_PIN_RB5 = 21,
    GPIO_PIN_RB6 = 22,
    GPIO_PIN_RB7 = 23,
    GPIO_PIN_RB8 = 24,
    GPIO_PIN_RB9 = 25,
    GPIO_PIN_RB10 = 26,
    GPIO_PIN_RB11 = 27,
    GPIO_PIN_RB12 = 28,
    GPIO_PIN_RB13 = 29,
    GPIO_PIN_RB14 = 30,
    GPIO_PIN_RB15 = 31,
    GPIO_PIN_RC1 = 33,
    GPIO_PIN_RC2 = 34,
    GPIO_PIN_RC3 = 35,
    GPIO_PIN_RC4 = 36,
    GPIO_PIN_RC12 = 44,
    GPIO_PIN_RC13 = 45,
    GPIO_PIN_RC14 = 46,
    GPIO_PIN_RC15 = 47,
    GPIO_PIN_RD0 = 48,
    GPIO_PIN_RD1 = 49,
    GPIO_PIN_RD2 = 50,
    GPIO_PIN_RD3 = 51,
    GPIO_PIN_RD4 = 52,
    GPIO_PIN_RD5 = 53,
    GPIO_PIN_RD6 = 54,
    GPIO_PIN_RD7 = 55,
    GPIO_PIN_RD8 = 56,
    GPIO_PIN_RD9 = 57,
    GPIO_PIN_RD10 = 58,
    GPIO_PIN_RD11 = 59,
    GPIO_PIN_RD12 = 60,
    GPIO_PIN_RD13 = 61,
    GPIO_PIN_RD14 = 62,
    GPIO_PIN_RD15 = 63,
    GPIO_PIN_RE0 = 64,
    GPIO_PIN_RE1 = 65,
    GPIO_PIN_RE2 = 66,
    GPIO_PIN_RE3 = 67,
    GPIO_PIN_RE4 = 68,
    GPIO_PIN_RE5 = 69,
    GPIO_PIN_RE6 = 70,
    GPIO_PIN_RE7 = 71,
    GPIO_PIN_RE8 = 72,
    GPIO_PIN_RE9 = 73,
    GPIO_PIN_RF0 = 80,
    GPIO_PIN_RF1 = 81,
    GPIO_PIN_RF2 = 82,
    GPIO_PIN_RF3 = 83,
    GPIO_PIN_RF4 = 84,
    GPIO_PIN_RF5 = 85,
    GPIO_PIN_RF8 = 88,
    GPIO_PIN_RF12 = 92,
    GPIO_PIN_RF13 = 93,
    GPIO_PIN_RG0 = 96,
    GPIO_PIN_RG1 = 97,
    GPIO_PIN_RG2 = 98,
    GPIO_PIN_RG3 = 99,
    GPIO_PIN_RG6 = 102,
    GPIO_PIN_RG7 = 103,
    GPIO_PIN_RG8 = 104,
    GPIO_PIN_RG9 = 105,
    GPIO_PIN_RG12 = 108,
    GPIO_PIN_RG13 = 109,
    GPIO_PIN_RG14 = 110,
    GPIO_PIN_RG15 = 111,

    /* This element should not be used in any of the GPIO APIs.
       It will be used by other modules or application to denote that none of the GPIO Pin is used */
    GPIO_PIN_NONE = -1

} GPIO_PIN;

typedef enum
{
  CN0_PIN = 1 << 0,
  CN1_PIN = 1 << 1,
  CN2_PIN = 1 << 2,
  CN3_PIN = 1 << 3,
  CN4_PIN = 1 << 4,
  CN5_PIN = 1 << 5,
  CN6_PIN = 1 << 6,
  CN7_PIN = 1 << 7,
  CN8_PIN = 1 << 8,
  CN9_PIN = 1 << 9,
  CN10_PIN = 1 << 10,
  CN11_PIN = 1 << 11,
  CN12_PIN = 1 << 12,
  CN13_PIN = 1 << 13,
  CN14_PIN = 1 << 14,
  CN15_PIN = 1 << 15,
  CN16_PIN = 1 << 16,
  CN17_PIN = 1 << 17,
  CN18_PIN = 1 << 18,
  CN19_PIN = 1 << 19,
  CN20_PIN = 1 << 20,
  CN21_PIN = 1 << 21,
}CN_PIN;


void GPIO_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: GPIO Functions which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

uint32_t GPIO_PortRead(GPIO_PORT port);

void GPIO_PortWrite(GPIO_PORT port, uint32_t mask, uint32_t value);

uint32_t GPIO_PortLatchRead ( GPIO_PORT port );

void GPIO_PortSet(GPIO_PORT port, uint32_t mask);

void GPIO_PortClear(GPIO_PORT port, uint32_t mask);

void GPIO_PortToggle(GPIO_PORT port, uint32_t mask);

void GPIO_PortInputEnable(GPIO_PORT port, uint32_t mask);

void GPIO_PortOutputEnable(GPIO_PORT port, uint32_t mask);

// *****************************************************************************
// *****************************************************************************
// Section: GPIO Functions which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

static inline void GPIO_PinWrite(GPIO_PIN pin, bool value)
{
    GPIO_PortWrite((GPIO_PORT)(pin>>4), (uint32_t)(0x1) << (pin & 0xF), (uint32_t)(value) << (pin & 0xF));
}

static inline bool GPIO_PinRead(GPIO_PIN pin)
{
    return (bool)(((GPIO_PortRead((GPIO_PORT)(pin>>4))) >> (pin & 0xF)) & 0x1);
}

static inline bool GPIO_PinLatchRead(GPIO_PIN pin)
{
    return (bool)((GPIO_PortLatchRead((GPIO_PORT)(pin>>4)) >> (pin & 0xF)) & 0x1);
}

static inline void GPIO_PinToggle(GPIO_PIN pin)
{
    GPIO_PortToggle((GPIO_PORT)(pin>>4), 0x1 << (pin & 0xF));
}

static inline void GPIO_PinSet(GPIO_PIN pin)
{
    GPIO_PortSet((GPIO_PORT)(pin>>4), 0x1 << (pin & 0xF));
}

static inline void GPIO_PinClear(GPIO_PIN pin)
{
    GPIO_PortClear((GPIO_PORT)(pin>>4), 0x1 << (pin & 0xF));
}

static inline void GPIO_PinInputEnable(GPIO_PIN pin)
{
    GPIO_PortInputEnable((GPIO_PORT)(pin>>4), 0x1 << (pin & 0xF));
}

static inline void GPIO_PinOutputEnable(GPIO_PIN pin)
{
    GPIO_PortOutputEnable((GPIO_PORT)(pin>>4), 0x1 << (pin & 0xF));
}


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END
#endif // PLIB_GPIO_H
