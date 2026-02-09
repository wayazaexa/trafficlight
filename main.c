#include <avr/io.h>
#include <util/delay.h>

#define BIT_SET(a, b) (a |= (1U << b))
#define BIT_CLEAR(a, b) (a &= ~(1U << b))

void trafficlight() {
    while (1) {
        BIT_SET(PORTB, 0); // Red light for 5 sec
        _delay_ms(5000);
        BIT_CLEAR(PORTB, 0); // Red light off
        BIT_SET(PORTB, 1); // Yellow light for 2 sec
        _delay_ms(2000);
        BIT_CLEAR(PORTB, 1); // Yellow light off
        BIT_SET(PORTB, 2); // Green light for 5 sec
        _delay_ms(5000);
        BIT_CLEAR(PORTB, 2); // Green light off
        BIT_SET(PORTB, 1); // Yellow light for 2 sec
        _delay_ms(2000);
        BIT_CLEAR(PORTB, 1); // Yellow light off
    }
}

int main(void) {
    DDRB |= (1U << 2) | (1U << 1) | 1U;
    trafficlight();
    return 0;
}
