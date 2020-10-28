#include <avr/io.h>

int main()
{
	int a;
	long int j = F_CPU / 50;
	long int i = j;
	for (;;)
	{
		DDRB |= (1 << 3);
		PORTB ^= (1 << 3);
		while (i--);
		i = j;
	}
	return(0);
}
