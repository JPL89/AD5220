// @File		MAIN.C		 		
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
#include "utils.h"
#include "ad5220.h"

void main(void)
{
    __delay_ms(500);   
    
    Pic18f2520_init();

    AD5220_Init();
    
    AD5220_Write(255,1);

    
    while(1);
    return;
}
