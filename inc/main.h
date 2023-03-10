#ifndef _MAIN_H_
#define _MAIN_H_ 1

#define LOW(BAGR) GPIO_WriteLow(BAGR##_PORT, BAGR##_PIN)
#define HIGH(BAGR) GPIO_WriteHigh(BAGR##_PORT, BAGR##_PIN)
#define REVERSE(BAGR) GPIO_WriteReverse(BAGR##_PORT, BAGR##_PIN)

#define READ(BAGR) GPIO_ReadInputPin(BAGR##_PORT, BAGR##_PIN) 
#define PUSH(BAGR) (GPIO_ReadInputPin(BAGR##_PORT, BAGR##_PIN)==RESET) 


#define IR_PORT GPIOC
#define IR_PIN GPIO_PIN_4
#define LOOP_PORT GPIOD
#define LOOP_PIN GPIO_PIN_3


#ifdef STM8S003
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_0
#define BTN_PORT GPIOB
#define BTN_PIN  GPIO_PIN_7
#endif

#ifdef STM8S103
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_4
#endif

#ifdef STM8S105
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_0
#endif

#ifdef STM8S208
#define LED_PORT GPIOC
#define LED_PIN  GPIO_PIN_5
#define BTN_PORT GPIOE
#define BTN_PIN  GPIO_PIN_4
#endif

// functions
void setup(void);

#endif // !_MAIN_H_
