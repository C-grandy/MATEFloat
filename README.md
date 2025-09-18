# MATEFloat
A PCB and code for a Ranger class MATE 2024 float 
NOTE: This design should not be recreated, for reference only as it has errors 

## PCB
The PCB is based around a Atmel Atmega328p MCU interfacing with a HC-5 Bluetooth module, brushed motor driver IC, and a pressure sensor. The PCB's main purpose is to take commands over bluetooth and then dive to the bottom of a pool, find the depth, and then return to the surface and transmit the data from the pressure sensor. All electrical aspects of this system worked well, but unfortunately due to mechanical design errors the system was never tested in full capacity. 
<img width="1008" height="762" alt="image" src="https://github.com/user-attachments/assets/7c800134-448b-47f7-ad47-cfd6ed69c7f3" />



### Power and Motor driver
The PCB features independent 3.3V and 5V linear regulators to step down a supply from two 9V batteries in parallel. The motor driver, a TI DRV8220DRLR, is powered straight from the 9V supply. The motor driver is interfaced with the MCU using two control pins, each getting proportional control via PWM. 
<img width="506" height="756" alt="image" src="https://github.com/user-attachments/assets/6e7d104e-82fd-4f3b-ae1a-4138d2b201f7" />

### Control and Communications
The system is based around a Atmel Atmega328p as it allowed for both backup software written in Arduino C++ and bare metal C for most use cases. The MCU is interfaced with a HC05 bluetooth module for communication as it was both affordable and easy to communicate to over serial UART. The float also incorporates a analog input for a pressure sensor for depth determination. A simple logic level shifter consisting of two signal MOSFETs were also included as the MCU and bluetooth module operate at different voltage levels. 
<img width="1006" height="762" alt="image" src="https://github.com/user-attachments/assets/801982b5-d774-4020-8476-f8ff3c09d7fa" />

## Code
The system is programmed in AVR bare metal C, incorporating a custom made UART hardware abstraction layer (HAL) for easier to understand code. The code at its current state doesn't fully incorporate sensor readings or transmitting, but simple bluetooth communication is established. 
NOTE: The code is not at a finished state, some features work but there is limited documentation, for reference only. 



