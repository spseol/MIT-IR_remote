#include "stm8s.h"
#include "main.h"
#include "milis.h"

#include <stdio.h>
#include "uart1.h"

void setup(void)
{
#if defined (BTN_PORT) || defined (BTN_PIN)
    GPIO_Init(BTN_PORT, BTN_PIN, GPIO_MODE_IN_FL_NO_IT);
#endif

    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LOOP_PORT, LOOP_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    // nastavení portu a přerušení při sestupné hraně 
    GPIO_Init(IR_PORT, IR_PIN, GPIO_MODE_IN_FL_IT);
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_FALL_ONLY);
    ITC_SetSoftwarePriority(ITC_IRQ_PORTE, ITC_PRIORITYLEVEL_1);

    // taktovani MCU na 16MHz
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
    // časovač TIM2 bude počítat μs
    TIM2_TimeBaseInit(TIM2_PRESCALER_16, 0xFFFF);
    TIM2_Cmd(ENABLE);

    enableInterrupts();

    init_milis();
    init_uart1();
}

volatile uint16_t IR_message = 0;  // číslo, které přišlo z ovladače
volatile uint8_t IR_repeat = 0;   // počet opakování zprávy (přidržení tlačítka)
volatile bool IR_Flag = FALSE;   // vlajka oznamuje, že přišla nová zpráva


int main(void)
{
  
    uint32_t time = 0;

    setup();
    printf("Startujme to!!!\n");

    while (1) {
        if (milis() - time > 33 ) {
            time = milis();
            if (IR_Flag) {
                printf("%04X %5d (x%d)\n", IR_message, IR_message, IR_repeat);
                IR_Flag = FALSE;
            }
        }

    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
