
//code from Ganesh Solapure  
//components used : 1arduino nano, 3LEDs, 1Push button

//including libraries
//I/O definitions for AVR microcontroller
#include <avr/io.h>  
//support for configuring and handling interrupts
#include <avr/interrupt.h>

// Define pins connected to LEDs and button for arduino nano
#define LED1_PIN PB0 // LED1 is connected to pin PB0 i.e. Digital pin 8
#define LED2_PIN PB1 // LED2 is connected to pin PB1 i.e. Digital pin 9
#define LED3_PIN PB2 // LED3 is connected to pin PB2 i.e. Digital pin 10
#define BUTTON_PIN PD2 //Button is connected to pin PD2 i.e. Digital pin 2, external interrupt pin INT0

//defining initial value for a LED status on/off
volatile uint8_t led_state = 0;

void setup() {
    //Setting LED pins PB0, PB1, PB2 as output by writing 1 to their bits in DDRB i.e. Data Direction Register for port B
    DDRB |= (1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN);

    //Seting button pin PD2 as input by writing 0 to its bit in DDRD i.e.Data Direction Register for port D
    DDRD &= ~(1 << BUTTON_PIN);

    //enable pull-up resistor on button pin PD2 seting 1 to its bit in PORTD
    PORTD |= (1 << BUTTON_PIN);

    //configureing external interrupt on INT0 as PD2 to trigger on a falling edge when button pressed
    //ISC01 = 1 & ISC00 = 0 i.e falling edge
    EICRA |= (1 << ISC01);

    //enable external interrupt INT0 by setting its bit in EIMSK
    EIMSK |= (1 << INT0);

    //enable global interrupts by setting I-bit in status register
    sei();
}

ISR(INT0_vect) {
    //debounce mechanism using a delay of 200 milliseconds
    //to ensures button press is registered only once even if it flickers connection for 200ms
    _delay_ms(200);

    //Checking if button is pressed and appling logic LOW due to pull-up resistor
    if (!(PIND & (1 << BUTTON_PIN))) {

        //Increment LED state and checking remainder for 4 conditions
        led_state = (led_state + 1) % 4;

        //Turn off all LEDs by clearing corresponding bits in PORTB
        PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN));  //condition 1

        //Turn on appropriate LED based state calculated
        if (led_state == 1) {
            PORTB |= (1 << LED1_PIN); // Turn on LED1 at PB0  \\  condition 2

        } else if (led_state == 2) {
            PORTB |= (1 << LED2_PIN); // Turn on LED2 at PB1  \\  condition 3

        } else if (led_state == 3) {
            PORTB |= (1 << LED3_PIN); // Turn on LED3 at PB2  \\  condition 4
        }
    }
}

int main() {
    //to initialize loop run setup code once
    setup();

    //enter an infinite loop of main program logic is handled by interrupt
    while (1) {
    //ISR handles LED changes continuously
    }

    return 0;
}
