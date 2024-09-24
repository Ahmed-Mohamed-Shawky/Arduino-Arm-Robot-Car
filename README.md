# Arduino-Based RC Car with Robotic Arm

## Project Overview
This project is an Arduino-controlled RC car with a robotic arm. The car’s movement and the arm's positioning can be controlled via Bluetooth using a mobile app. The system includes:

- Car movement: Forward, backward, left, and right.
- Robotic arm control: Waist, elbow, wrist, and grip controlled via servos and motors.
- Bluetooth control via mobile app.

## Folder Structure
```plaintext
|-- Arduino_Code/       # Contains the Arduino code
|-- Proteus_Simulation/ # Proteus simulation files for circuit testing
|-- Mobile_App/         # Mobile app source and APK build file
```
## Installation

### Prerequisites
- **[Arduino IDE](https://www.arduino.cc/en/software)** for compiling the code and uploading it to the Arduino.
- **[Proteus](https://www.labcenter.com/downloads/)** for running the circuit simulation.
- **[MIT AI2 Companion](https://play.google.com/store/apps/details?id=edu.mit.appinventor.aicompanion3&pcampaignid=web_share)** for running the mobile APP simulation.
- **Android device** for installing the mobile app APK.

## Building Arduino Code
1. **Open the code**: Navigate to the `Arduino_Code` folder and open the `.ino` file in the Arduino IDE.
2. **Select the board**: Go to `Tools` > `Board` and select the appropriate Arduino board (e.g., Arduino Uno).
3. **Compile the code**: Press the checkmark icon (✔️) in the Arduino IDE to compile the code.
4. **Export the compiled binary**:
   - Go to `Sketch` > `Export compiled binary`.
   - A folder named `build` will be created in the same directory as your `.ino` file.
   - Inside this folder, you will find the `.hex` and `.elf` files needed for the Proteus simulation.

## Usage (Hardware)
1. **Upload the Arduino code**: Upload the compiled Arduino code to your board using the Arduino IDE.
2. **Connect to the Bluetooth module**: Pair your mobile device with the Arduino Bluetooth module using the mobile app.
3. **Control the car and arm**: Once connected, you can use the app to send commands and control the RC car and robotic arm via Bluetooth.

### Components List

| Component                    | Quantity |
|------------------------------|----------|
| Arduino Uno                   | 1        |
| L298N Motor Driver            | 2        |
| DC Motors                     | 3        |
| Servo Motors                  | 3        |
| HC-05 Bluetooth Module        | 1        |
| 9V Batteries                  | 2        |
| Battery Holders               | 2        |
| Jumper Wires                  | Multiple |
| Breadboard                    | 1        |
| Wheels (for the car Motors)   | 2        |
| Caster Wheel (for the car front) | 1         |
| Chassis (for the car and arm)  | 1        |
| Robotic Arm Kit (with joints) | 1        |


### Hardware Wiring Connections

| Component               | Arduino Pin        | Description                                   |
|-------------------------|--------------------|-----------------------------------------------|
| **Right Motor**          |                    |                                               |
| IN1 (Direction Control)  | Digital Pin 3      | Controls right motor direction (forward/backward) |
| IN2 (Direction Control)  | Digital Pin 4      | Controls right motor direction (forward/backward) |
| EN1 (Enable)             | Digital Pin 2      | Enables right motor                           |
|-------------------------|--------------------|-----------------------------------------------|
| **Left Motor**           |                    |                                               |
| IN1 (Direction Control)  | Digital Pin 6      | Controls left motor direction (forward/backward) |
| IN2 (Direction Control)  | Digital Pin 5      | Controls left motor direction (forward/backward) |
| EN2 (Enable)             | Digital Pin 7      | Enables left motor                            |
|-------------------------|--------------------|-----------------------------------------------|
| **Waist Motor**          |                    |                                               |
| IN1 (Direction Control)  | Digital Pin 12     | Controls waist motor direction (up/down)      |
| IN2 (Direction Control)  | Digital Pin 11     | Controls waist motor direction (up/down)      |
| EN (Enable)              | Digital Pin 13     | Enables waist motor                           |
|-------------------------|--------------------|-----------------------------------------------|
| **Servo Motors**         |                    |                                               |
| Servo 1 (Elbow)          | Digital Pin 8      | Controls elbow movement                       |
| Servo 2 (Wrist)          | Digital Pin 9      | Controls wrist movement                       |
| Servo 3 (Grip)           | Digital Pin 10     | Controls grip movement                        |
|-------------------------|--------------------|-----------------------------------------------|
| **Bluetooth Module (HC-05)** |               |                                               |
| RX                       | TX (Pin 0)         | UART communication (HC-05 to Arduino)         |
| TX                       | RX (Pin 1)         | UART communication (Arduino to HC-05)         |

### Circuit Diagram
![Proteus Simulation](https://github.com/user-attachments/assets/a4905d28-432d-4bd4-8213-af1551bec8ee)


## Simulation
The Proteus simulation allows you to test the circuit virtually without needing the physical hardware.

### Steps:
1. **Open Proteus**: Open the Proteus project from the `Proteus_Simulation` folder.
2. **Load the .hex file**: Use the `.hex` file generated from the Arduino code compilation.
3. **Run the simulation**: Simulate the system. The Bluetooth communication is modeled as **UART** in the simulation, allowing you to test the RC car and robotic arm’s movement.

## Control Functions

| Command  | Function                | Command  | Function               |
|----------|-------------------------|----------|------------------------|
| F        | Move forward             | B        | Move backward           |
| R        | Turn right               | L        | Turn left               |
| S        | Stop the car             
| 1        | Move waist up            | 2        | Move waist down         |
| 3        | Move elbow up            | 4        | Move elbow down         |
| 5        | Move wrist up            | 6        | Move wrist down         |
| 7        | Move grip up             | 8        | Move grip down          |

## Mobile App

The mobile app, which controls the RC car and robotic arm via Bluetooth, was created using `MIT App Inventor`. A copy of the source code project is available in the `Mobile_App` folder.

### How to Import the Mobile App Project

1. **Go to MIT App Inventor:**
   - Open your web browser and navigate to [MIT App Inventor](https://appinventor.mit.edu).

2. **Sign In:**
   - Sign in using your Google account.

3. **Import the Project:**
   - Once signed in, go to the **Projects** dropdown menu in the top-left corner.
   - Select **Import project (.aia) from my computer**.
   - Browse to the `Mobile_App` folder in this project, locate the `.aia` file, and upload it.

4. **Edit the Mobile App:**
   - Once imported, you can make changes to the app design and functionality in the MIT App Inventor interface.
   - Adjust the Bluetooth settings, UI elements, and control logic as needed.

### Running the App in Simulation

1. **Install MIT AI2 Companion:**
   - Download and install the `**MIT AI2 Companion**` app on your Android device from the Google Play Store.

2. **Connect to MIT App Inventor:**
   - In MIT App Inventor, click on **Connect** at the top menu.
   - Choose **AI Companion** from the dropdown.

3. **Scan the QR Code:**
   - A QR code will be generated in the MIT App Inventor window.
   - Open the AI2 Companion app on your phone and scan the QR code to test the app in real-time.

### Building the App

1. **Build the APK:**
   - After editing, go to the `**Build**` dropdown menu and select **App (save .apk to my computer)**.

2. **Install the APK:**
   - Once the APK is built, transfer it to your Android device and install it.
   - Ensure Bluetooth is enabled on your phone and that it is paired with the Arduino's Bluetooth module.

3. **Connect to Bluetooth:**
   - Open the installed app on your phone and connect to the HC-05 Bluetooth module.

4. **Control the RC Car and Robotic Arm:**
   - Once connected, you can use the mobile app to control the car's movement and robotic arm's positioning.


## Contributing
Contributions are welcome! Please open an issue or submit a pull request for any changes or improvements.

