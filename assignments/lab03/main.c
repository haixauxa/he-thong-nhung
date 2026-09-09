#include <stdint.h>

#define RCC_APB2ENR   (*(volatile uint32_t *)(0x40021018))

#define GPIOA_CRL     (*(volatile uint32_t *)(0x40010800))
#define GPIOA_CRH     (*(volatile uint32_t *)(0x40010804))
#define GPIOA_IDR     (*(volatile uint32_t *)(0x40010808))
#define GPIOA_ODR     (*(volatile uint32_t *)(0x4001080C))

int main(void)
{
    // Bật clock GPIOA
    RCC_APB2ENR |= (1 << 2);

    // PA0 - PA7: Input Pull-up
    GPIOA_CRL = 0x88888888;

    // PA8 - PA15: Output Push-Pull, 50 MHz
    GPIOA_CRH = 0x33333333;

    // Bật pull-up cho PA0 - PA7
    GPIOA_ODR |= 0xFF;

    while (1)
    {
        // Đọc 8 nút, đảo dữ liệu rồi xuất ra 8 LED
        GPIOA_ODR = ((~GPIOA_IDR) & 0xFF) << 8;
    }
}
