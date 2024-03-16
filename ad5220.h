// @File		AD5220.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		16/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//

#ifndef AD5220_H
#define AD5220_H

#define AD5220_SCK PORTCbits.RC0
#define AD5220_DIN PORTCbits.RC1
#define AD5220_CS PORTCbits.RC3

#define AD5220_SCK_TRIS TRISCbits.RC0
#define AD5220_DIN_TRIS TRISCbits.RC1
#define AD5220_CS_TRIS TRISCbits.RC3

void AD5220_Write(unsigned int count, unsigned char din)
{
    AD5220_CS = 0;
    
    for(unsigned int i = 0; i < count; i++)
    {        
        AD5220_DIN = din;
        
        __asm__ __volatile__("nop");
        AD5220_SCK = 1;       
        __asm__ __volatile__("nop");
        AD5220_SCK = 0;
        __asm__ __volatile__("nop");    
    }
    
    AD5220_CS = 1;
}

void AD5220_Init(void)
{
    AD5220_SCK_TRIS = 0;
    AD5220_DIN_TRIS = 0;
    AD5220_CS_TRIS = 0;
    
    AD5220_CS = 1;
}

#endif 
