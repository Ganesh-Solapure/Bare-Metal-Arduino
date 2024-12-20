# LED Pattern Using External Interrupt (Bare-Metal Programming)

This task demonstrates bare-metal programming on an ATmega328P microcontroller to create an LED pattern controlled by an external interrupt. The code is written in C using register-level programming, providing a deeper understanding of microcontroller operations.

connect 3 LEDs and a push button with Arduino (Uno/Nano/Mega/Pro Mini). The set of 3 LEDs will glow one by one when the button is presse

## Overview

The project involves controlling three LEDs and a push button:

* **LEDs:** Connected to specific pins on the microcontroller, glowing in a sequence based on button presses.
* **Push Button:** Configured as an external interrupt input to detect button presses and advance the LED sequence.

The LED sequence progresses as follows:

| Button Press | LED 1 | LED 2 | LED 3 |
|---|---|---|---|
| Initial | OFF | OFF | OFF |
| 1st | ON | OFF | OFF |
| 2nd | OFF | ON | OFF |
| 3rd | OFF | OFF | ON |
| 4th | OFF | OFF | OFF | (Repeat cycle)

## Key Features

* **Bare-Metal Programming:** Code manipulates LEDs and handles interrupts directly using registers, providing a deeper understanding of microcontroller internals.
* **Efficient Interrupt Handling:** Leverages external interrupts for effective LED pattern control.
* **Simple Debouncing:** Implements a timer-based software debouncing mechanism to ensure reliable button input.
* **Well-Structured Code:** Organized for readability and maintainability.

## Hardware Requirements

* **Microcontroller:** Arduino Uno, Nano, Mega, or Pro Mini (ATmega328P-based)
* **Components:**
    * 3 LEDs
    * 1 Push Button
    * Resistors for LEDs and button (if needed)
* **Optional:** Breadboard and connecting wires

## Getting Started

1. Clone this repository and open the project in the Arduino IDE.
2. Connect the hardware according to the following pin assignments (modify if needed):
    * LEDs: PD2, PD3, PD4
    * Button: PD5 (with internal pull-up resistor enabled)
3. Upload the code to your Arduino board.
4. Press the button to observe the LED sequence.

## Code Structure (Highlights)

The code focuses on the following key aspects:

* **Direct Register Manipulation:** Achieves precise control over LED pins and interrupts using ATmega328P registers (DDRD for outputs, EIMSK/GIFR for interrupts).
* **Timer-Based Debouncing:** Implements software debouncing using Timer0 in CTC mode with a 1ms time base, ensuring accurate button presses.
* **Interrupt Service Routine (ISR):** Handles button presses effectively within the ISR, updating the LED state based on the current sequence.
* **State Machine:** Maintains the cyclic state of the LED sequence for efficient pattern control.


## Resources

* ATmega328P Datasheet: (Link to datasheet)

## License

This project is open-source and available under the MIT License. Feel free to use and modify it for educational purposes.

## Contributions

Contributions and suggestions are welcome! Create a pull request or raise an issue to improve the project.
