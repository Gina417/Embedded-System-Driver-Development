/*
* This file contains the base address and the definition of the peripheral registers
* for the private peripheral bus (core periphrerals) of the Cortex-M4 microcontroller. 
*/

#ifndef _PPB_H_
#define _PPB_H_

#include <stdint.h>

#include "stm32f407.h"

/* Private peripheral bus base address */
#define PPB_BASEADDR ((uint32_t) 0xE0000000)

/* PPB periphral */
#define SCB_BASEADDR1       (PPB_BASEADDR + 0xE008) // 0xE000E008, System Control Block base address related to ACTLR register
#define SYSTICK_BASEADDR    (PPB_BASEADDR + 0xE010) // 0xE000E010, System Timer base address
#define NVIC_BASEADDR       (PPB_BASEADDR + 0xE100) // 0xE000E100, Nested Vectored Interrupt Controller for (hardware) interrupt base address
#define SCB_BASEADDR2       (PPB_BASEADDR + 0xED00) // 0xE000ED00, System Control Block register base address related to CPUID register
#define MPU_BASEADDR        (PPB_BASEADDR + 0xED90) // 0xE000ED90, Memory Protection Unit base address
#define SWNVIC_BASEADDR     (PPB_BASEADDR + 0xEF00) // 0xE000EF00, Software Nested Vectored Interrupt Controller base address
#define FPU_BASEADDR        (PPB_BASEADDR + 0xEF30) // 0xE000EF30, Floating Point Unit base address

/* NVIC base address definition */
#define NVIC ((NVIC_RegDef_t*) NVIC_BASEADDR)

/* SCB with respect to CPUID base address definition */
#define SCB2 ((SCB2_RegDef_t*) SCB_BASEADDR2)

/* NVIC registers definition */
typedef struct {
    volatile uint32_t ISER[8]; // interrupt set-enable registers, total in 8
    volatile uint32_t ICER[8]; // interrupt clear-enable registers, total in 8
    volatile uint32_t ISPR[8]; // interrupt set-pending registers, total in 8
    volatile uint32_t ICPR[8]; // interrupt clear-pending registers, total in 8
    volatile uint32_t IABR[8]; // interrupt active bit registers, total in 8
    volatile uint8_t  IPR[240]; // interrupt priority registers, total in 240
}NVIC_RegDef_t;

/* SCB registers with respect to CPUID definition */
typedef struct{
    volatile uint32_t CPUID; // CPUID base address
    volatile uint32_t ICSR;  // Interrupt Control and State Register
    volatile uint32_t VTOR;  // Vector Table Offset Register
    volatile uint32_t AIRCR; // Application Interrupt and Reset Control Register
    volatile uint32_t SCR;   // System Control Register
    volatile uint32_t CCR;   // Configuration and Control Register
    volatile uint32_t SHPR[3]; // System Handler Priority Registers, total in 12
    volatile uint32_t SHCSR; // System Handler Control and State Register
    volatile uint32_t CFSR;  // Configurable Fault Status Register
    volatile uint32_t HFSR;  // Hard Fault Status Register
    volatile uint32_t MMFAR; // MemManage Fault Address Register
    volatile uint32_t BFAR;  // Bus Fault Address Register
    volatile uint32_t AFSR;  // Auxiliary Fault Status Register
}SCB2_RegDef_t;

#endif