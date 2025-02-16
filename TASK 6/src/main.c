#include <ch32v00x.h>
#include <stdio.h>

#define RED_LED     GPIO_Pin_0  // PD0
#define YELLOW_LED  GPIO_Pin_4  // PD1
#define GREEN_LED   GPIO_Pin_2  // PD2
#define BUTTON      GPIO_Pin_3  // PD3
#define BUZZER      GPIO_Pin_1  // PC1

void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 1000; i++) {
        __NOP();  // No operation for precise delay
    }
}

void GPIO_Config() {
    // Enable peripheral clock for Port D and C
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    // Configure LEDs as output
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = RED_LED | YELLOW_LED | GREEN_LED;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStruct);

    // Configure push button as input with pull-up resistor
    GPIO_InitStruct.GPIO_Pin = BUTTON;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOD, &GPIO_InitStruct);

    // Configure buzzer as output
    GPIO_InitStruct.GPIO_Pin = BUZZER;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStruct);
}

int main(void) {
    SystemInit();  // Initialize system
    GPIO_Config(); // Configure GPIO

    while (1) {
        // Green ON for 5 seconds
        GPIO_SetBits(GPIOD, GREEN_LED);
        delay_ms(5000);
        GPIO_ResetBits(GPIOD, GREEN_LED);

        // Yellow ON for 2 seconds
        GPIO_SetBits(GPIOD, YELLOW_LED);
        delay_ms(2000);
        GPIO_ResetBits(GPIOD, YELLOW_LED);

        // Red ON for 5 seconds
        GPIO_SetBits(GPIOD, RED_LED);


        // Check if pedestrian button is pressed
        if (GPIO_ReadInputDataBit(GPIOD, BUTTON) == 0) {
            // Activate buzzer for 3 seconds
            GPIO_SetBits(GPIOC, BUZZER);
            delay_ms(3000);
            GPIO_ResetBits(GPIOC, BUZZER);
        }

        delay_ms(5000);
        GPIO_ResetBits(GPIOD, RED_LED);

        // Yellow ON for 2 seconds
        GPIO_SetBits(GPIOD, YELLOW_LED);
        delay_ms(2000);
        GPIO_ResetBits(GPIOD, YELLOW_LED);
    }
}
