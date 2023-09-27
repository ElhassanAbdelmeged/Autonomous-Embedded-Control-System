# Autonomous Embedded Control System

**Recruitment Task by Cairo University Eco-Racing Team - 2024**

**Organization:** Cairo University Eco-Racing Team

**Task Objective:**

The objective of this recruitment task is to design a communication and control system for an autonomous car prototype. The system should enable a PC to send control commands to the car and receive real-time data updates from the car. The key parameters to control are the car's speed, direction (forward or backward), and wheel angle. Communication between the PC and car will be facilitated using UART.

**Task Overview:**

Design and implement a simplified version of the communication and control system for an autonomous car. The system should receive a data frame via UART-PC communication and interpret this frame to control the car's speed, direction, and wheel orientation.

**Communication Frame Format:**

The UART-PC communication frame should adhere to the following format:
- `XXXAYYBE`
    - `XXX`: Speed of the motor controlling the wheels (0 to 100).
    - `A`: Direction of the motor controlling the wheels (F for Forward, B for Backward).
    - `YY`: Angle of the second motor controlling the wheel angle (0 to 45 degrees).
    - `B`: Direction of the second motor (Right or Left) with the north of the car as the reference.
    - `E`: Indicator of the end of the frame.

**General Assumptions:**

1. For the DC motor: ACW (Anti-Clockwise) indicates forward movement, CW (Clockwise) indicates backward movement.
2. For the stepper motor: Each step represents one degree for simplicity.

**Required:**

You should be able to input the speed, direction, and orientation from your PC/laptop keyboard through a virtual terminal, using the specified communication frame. The motors should adjust accordingly. Additionally, display the speed percentage, wheel angle, and time (starting from 00:00:00 AM) on an LCD screen.


This task evaluates your ability to design and implement embedded-C code efficiently, as well as integrate various components into a cohesive system.

**Schmatics:**

![image](https://github.com/ElhassanAbdelmeged/Autonomous-Embedded-Control-System/assets/88130561/0d0df8d2-3a30-4113-a690-a11b1ec23827)
