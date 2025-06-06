# Arduino Maze-Solving Robot (Left-Hand Rule with IR Sensors)

This Arduino-based robot navigates mazes using the **left-hand rule** algorithm. It relies on four IR sensors for path detection and wall sensing, and it plays familiar theme music to indicate system states. On startup, the robot plays the Mario theme. If a wall is detected in front, it stops and plays the Pac-Man theme
Video of our maze solver robot: https://drive.google.com/drive/folders/13RjZS8ftY8RHCtmR9AqnznO9eq2iwcZu?usp=drive_link

## Features

- Maze-solving using the left-hand rule
- Four IR sensors:
  - Left, center, and right for path detection
  - Front sensor for wall detection
- Motor control with L298N dual H-bridge driver
- Buzzer plays:
  - **Mario theme** on startup
  - **Pac-Man theme** when a wall is detected
- LEDs indicate left and right turns

## How It Works

The robot makes decisions based on the readings from the IR sensors:

- If the front (wall) sensor detects an obstacle, the robot stops and plays a warning tune.
- If the left sensor detects a path, the robot turns left (prioritizing left-hand rule).
- If the center sensor detects a path, it moves forward.
- If the right sensor detects a path, it turns right.
- If no path is detected, it performs a U-turn.

This behavior follows the **left-hand rule**, commonly used to solve simply connected mazes.

## Hardware Requirements

- Arduino Uno R3
- L298N Motor Driver
- 2 DC Motors with wheels
- Chassis and caster wheel
- 4 IR Arduino Sensors
- Buzzer
- Power source (battery or solar-based)
- Breadboard and jumper wires
- 2 leds

## Pin Configuration

| Component             | Arduino Pin |
|-----------------------|-------------|
| Left IR Sensor        | 13          |
| Center IR Sensor      | 11          |
| Right IR Sensor       | 12          |
| Wall IR Sensor        | 8           |
| Motor IN1 (left)      | 2           |
| Motor IN2 (left)      | 3           |
| Motor IN3 (right)     | 4           |
| Motor IN4 (right)     | 5           |
| Motor ENA (PWM left)  | 9           |
| Motor ENB (PWM right) | 10          |
| Buzzer                | A1          |
| Left Turn LED         | 7           |
| Right Turn LED        | 6           |

## Music Files

Ensure the following files are in your project folder:

- `mario_theme.h` — defines `playMarioTheme(pin)`
- `PacmanTheme.h` — defines `playPacmanTheme(pin)`
- `pitches.h` — defines musical note frequencies

These files are used with the `tone()` function to generate sound through the buzzer.

## Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/maze-solving-robot.git
   cd maze-solving-robot
