# Report
## Introduction 
-   Clock with digital output is the project application that allows user to see time in digital format so user will understand the present time with this application .
## Research
-   This application is researched from various sources (like you tube , google and research papers ) and  then I have  modified into successful working model application with multiple header files and multiple c files  but simulation part is still under process till yet now .
### Features
-   It is a clock with digital output hence shows discrete values of time .
-   When get rebooted , output will not change .
### Who
-   Everyone who wants to have a eye track on time .
### What
-   Time with digital output showing system.
### Why
-   Curious about carrier in embedded system . 
### When 
-   When you understand the importance of time management and start to be accountable for your time.
### Where
-   This can be  used by the user in day to day life where they can track their time and  generate better results in life .
### How
-   By using Atmega328p microcontroller for controlling and we program it and then we have to load firmware in elf or hex format in simulation software called  SimulIDE .
### SWOT ANALYSIS
![SWOT](https://user-images.githubusercontent.com/101577287/163710077-f63ac154-ca86-4134-9f5e-decfdda4df89.png)

## Detail requirements
## High Level Requirements
| ID | Description | Category | Status | 
| ----- | ----- | ------- | ---------|
| HR001 | Proper knowledge of ATmega328p with Hands on experience with SIMULIDE | Techincal | IMPLEMENTED | 
| HR002 | Proper understanding of components used like resistors , microcontroller etc | Techincal |  IMPLEMENTED  |
| HR003 | Display correct information of time tracking | Techincal |  IMPLEMENTED  |
| HR004 | System configuration and stability analysis | Techincal |  IMPLEMENTED  |
## Low level Requirements
 
| ID | Description | HLR ID | Status (Implemented/Future) |
| ------ | --------- | ------ | ----- |
| LR001 | ELECTRICAL NETWORK ANALYSIS AND FEASIBILITY REQUIREMENT | HR001 |  IMPLEMENTED  |
| LR002 | user go with the option of display should be able to view the TIME| HR002 |  IMPLEMENTED |
| LR003 | Simulation Requirement is must | HR002 | IMPLEMENTED |

## Structural
![Structural](https://user-images.githubusercontent.com/101577287/163916702-e1c77a2b-acfb-48c4-8a4c-8b853cedaa1a.png)
## Behavioural
![BEHAVIOURAL](https://user-images.githubusercontent.com/101577287/163919911-aeba1def-3fef-4937-a6fb-0123efd3cb61.png)
### Block Diagram
![BLOCK DIAGRAM](https://user-images.githubusercontent.com/101577287/163925570-708745b3-8502-44b1-96a4-663a76f90b3c.png)

## Test Plan
## High Level Test Plan

| Test ID| Description | Exp I/P | Exp O/P | Status |
| -------| ----------- | ------- | ------- | ------ |
| H_01 | DEVELOPMENT OF .elf file    | .C file | .elf| Implemented |
| H_02 | Cross Compilation of Files  | Converting .c file into target output | .elf or .hex using win-avr   | Implemented |
| H_03 | Search components in Simulide |  Components  | Assembling     | Implemeted  |
| H_04 | Seven Segment Display   |      Run     | Displayed     | Implemented |

### Low Level Test Plan

| Test ID| Description | Exp I/P | Exp O/P | Status |
| -------| ----------- | ------- | ------- | ------ |
| L_01 | changed output to 00:00  | Reset button | whenever required | Implemented |
| L_02 | changed seconds to 00| reset button | whenever required | FUTURE |




