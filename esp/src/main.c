#include "main.h"
#include <avr/io.h>

void esp_runtime_config(void)
{
  uart_strx("ATE0\r\n");        // Disable echo
  //tx("AT+CIPMUX=0", 1); // Single-Connection Mode
}

int main() {
    DDRD |= (1 << PD2);
    uart_init();
    esp_runtime_config();
    uart_strx("AT\r\n");
    if (uart_rx() == 'O')
    {
        if (uart_rx() == 'K')
            PORTD |= (1 << PD2);
    }
    
	// ADCSRA |= (1 << ADEN); // enable ADC
	// ADMUX |= (1 << REFS0); // VCC -> voltage reference
	// uart_init();
	// SREG |= (1 << SREG_I); // allow interrupts
	// TIMSK1 |= (1 << OCIE1A); // enable Compare A Match interrupt
	// TCCR1B |= (1 << WGM12); // set CTC mode
	// OCR1A = 2 * F_CPU / (256 * 2) - 1; // 2 sec
	// TCCR1B |= (1 << CS12); // prescaler 256
	for(;;) {
	}
}