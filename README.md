# Voltage Controller Project (Arduino + Proteus)

This repository contains an embedded systems project that simulates an **Arduino Uno based voltage protection circuit** using **Proteus**.  
The system monitors input voltage, displays readings on an LCD, and controls a relay + LED to protect against **over-voltage** and **under-voltage** conditions.

---

## Project Structure
- `VoltageProtection.ino` → Arduino source code
- `VoltageProtection.hex` → Compiled binary for Proteus simulation
- `VoltageProtection.pdsprj` → Proteus schematic/project file
- `docs/` → Documentation, notes, and optional circuit images

---

## Features
- Real-time voltage monitoring via analog input (A0)
- LCD display showing measured voltage and system status
- Relay control for safe switching during abnormal voltage
- LED indicator for fault conditions (over/under voltage)
- Configurable voltage thresholds (default: 180–250 V)

---

## How It Works
1. **Voltage sensing**  
   - AC mains → transformer → step-down → voltage divider → Arduino Analog Pins (A0)  
   - Arduino reads scaled voltage and calculates RMS.

2. **Decision logic**  
   - Normal voltage (180–250 V): Relay ON, LED OFF  
   - Over-voltage (>250 V): Relay OFF, LED ON  
   - Under-voltage (<180 V): Relay OFF, LED ON  

3. **Display**  
   - LCD shows voltage value and system status in real time.

---

## Simulation in Proteus
1. Compile the `.ino` file in Arduino IDE → export `.hex`.  
2. Load `.hex` into the ATmega328P or Arduino Uno model in Proteus.  
3. Connect the circuit (transformer, rectifier, divider, relay, LCD).  
4. Run simulation → observe voltage protection behavior.

---

## Example Circuit (Proteus)


```markdown
![Proteus Circuit](docs/voltage_controller_schematic.png)
