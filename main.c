#include <avr/io.h>
#include <util/delay.h>

/*
OBS! Detta är *INTE* rekommenderat sätt att göra detta på, men eftersom vi har full kontroll över registren
    och vet att PORTB inte används till något annat så *går det* att göra på detta sätt.
Om vi använt en eller flera andra pinnar på PORTB så hade detta förstört logiken för den/dem.
*/
void trafficlight() {
    BIT_SET(PORTB, 0); // Red light on
    while (1) {
        _delay_ms(5000);
        PORTB = (PORTB << 1); // Red light off, yellow light on
        _delay_ms(2000);
        PORTB = (PORTB << 1); // Yellow light off, green light on
        _delay_ms(5000);
        PORTB = (PORTB >> 1); // Green light off, yellow light on
        _delay_ms(2000);
        PORTB = (PORTB >> 1); // Yellow light off, red light on
    }
}

int main(void) {
    DDRB |= (1U << 2) | (1U << 1) | 1U;
    trafficlight();
    return 0;
}
