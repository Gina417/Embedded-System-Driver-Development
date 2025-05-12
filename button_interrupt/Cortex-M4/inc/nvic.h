#ifndef _NVIC_H_
#define _NVIC_H_

#include "ppb.h"

typedef struct {
    IRQn_t  IRQ_number; // interrupt request number
    uint8_t Gpriority;  // interrupt group priority
    uint8_t Spriority;  // interrupt group priority
}NVIC_Handle_t;

typedef enum {
    GP4_SP0 = 0x300, // 0011 0000 0000 (4 bits for group priority, 0 bits for sub-priority)
    GP3_SP1 = 0x400, // 0100 0000 0000 (3 bits for group priority, 1 bit for sub-priority)
    GP2_SP2 = 0x500, // 0101 0000 0000 (2 bits for group priority, 2 bits for sub-priority)
    GP1_SP3 = 0x600, // 0110 0000 0000 (1 bit for group priority, 3 bits for sub-priority)
    GP0_SP4 = 0x700  // 0111 0000 0000 (0 bits for group priority, 4 bits for sub-priority)
}PriorityGroup_t;

/* Check the validity of the priority*/
static inline uint32_t Is_valid_PriorityGroup(PriorityGroup_t group_type)
{
    return ( (group_type == GP4_SP0) || (group_type == GP3_SP1) || 
             (group_type == GP2_SP2) || (group_type == GP1_SP3) || 
             (group_type == GP0_SP4) );
}

static inline uint32_t Is_valid_PriorityNum(uint32_t priority)
{
    return ( (priority >= 0) && (priority < 16) );
}

void NVIC_IRQ_Enable(NVIC_Handle_t *pNVICHandle);
void NVIC_IRQ_Disable(NVIC_Handle_t *pNVICHandle);

void NVIC_PrioityGroupConfig(PriorityGroup_t group_type);
void NVIC_SetPriority(NVIC_Handle_t *pNVICHandle);

#endif