# LoRa Puck PCB

## About the Project

This is a compact LoRa Puck PCB designed in EasyEDA. The project is made to support long-range wireless communication in places where mobile network coverage may not be available, such as during trekking, camping, hiking, and remote travel.

The board combines an RP2040 microcontroller, SX1262 LoRa transceiver, USB Type-C interface, 3.3V power supply, RF matching components, and supporting passive components in one PCB design.

---

## Features

- Long-range LoRa communication using SX1262
- RP2040 microcontroller
- USB Type-C for power and programming
- 3.3V power supply section
- RF matching network for the LoRa section
- Compact PCB layout
- PCB manufacturing files included

---

## Tools and Components Used

- EasyEDA
- RP2040 microcontroller
- SX1262 LoRa transceiver
- USB Type-C connector
- 3.3V voltage regulator
- Crystal oscillator
- Resistors
- Capacitors
- Inductors
- PCB antenna / RF section

---

## What I Did

- Researched the LoRa communication circuit and component connections.
- Created the schematic in EasyEDA.
- Added the RP2040, SX1262, USB Type-C connector, power circuit, capacitors, resistors, inductors, and other supporting components.
- Connected the power, ground, USB, SPI, control, and LoRa RF signals.
- Assigned footprints for all components.
- Converted the schematic into a PCB layout.
- Placed the components carefully for routing and RF connections.
- Routed the PCB tracks and checked the layout.
- Generated Gerber, drill, BOM, schematic, and PCB image files.

---

## Images
<img width="687" height="482" alt="image" src="https://github.com/user-attachments/assets/d04883a6-1dc0-4831-ac01-14bd9c299ca5" />
<img width="623" height="453" alt="image" src="https://github.com/user-attachments/assets/85d9c086-7d4d-476c-b6bf-a2825f01ed3b" />

<img width="816" height="617" alt="image" src="https://github.com/user-attachments/assets/3d7fec30-5c60-429c-97e2-27ac1d9b99f6" />



## Bill of Materials (BOM)

| Name | Designator | Quantity | Unit Price (USD) | Total Cost (USD) |
|---|---|---:|---:|---:|
| 100nF Capacitor | C1, C2, C13, C14, C15, C16, C17, C18, C19, C20, C21 | 11 | $0.0209 | $0.2299 |
| 470nF Capacitor | C3 | 1 | $0.0150 | $0.0150 |
| 1nF Capacitor | C4, C10, C11 | 3 | $0.0100 | $0.0300 |
| 39pF Capacitor | C5 | 1 | $0.0100 | $0.0100 |
| 3.3pF Capacitor | C6, C7 | 2 | $0.0100 | $0.0200 |
| 47nF Capacitor | C8, C9 | 2 | $0.0100 | $0.0200 |
| 1uF Capacitor | C12, C22 | 2 | $0.0143 | $0.0286 |
| 10uF Capacitor | C23, C24 | 2 | $0.0300 | $0.0600 |
| 100nF Capacitor | C25 | 1 | $0.0209 | $0.0209 |
| 15uH Inductor | L1 | 1 | $0.0500 | $0.0500 |
| 0900FM15D0039001E RF Filter | L2 | 1 | $0.6070 | $0.6070 |
| 9.1nH Inductor | L3 | 1 | $0.0300 | $0.0300 |
| 47nH Inductor | L4 | 1 | $0.0300 | $0.0300 |
| BLM15AX102SN1D Ferrite Bead | L5 | 1 | $0.0105 | $0.0105 |
| 100Ω Resistor | R1 | 1 | $0.0100 | $0.0100 |
| 1kΩ Resistor | R2 | 1 | $0.0100 | $0.0100 |
| 10kΩ Resistor | R3 | 1 | $0.0100 | $0.0100 |
| 27.4Ω Resistor | R4 | 1 | $0.0100 | $0.0100 |
| 22.7Ω Resistor | R5 | 1 | $0.0100 | $0.0100 |
| 5.1kΩ Resistor | R6, R7 | 2 | $0.0100 | $0.0200 |
| PE4259-63 RF Switch | U1 | 1 | $1.0686 | $1.0686 |
| RP2040 Microcontroller | U2 | 1 | $1.0000 | $1.0000 |
| SX1262IMLTRT LoRa Transceiver | U3 | 1 | $3.2219 | $3.2219 |
| AP2112K-3.3TRG1(MS) Voltage Regulator | U4 | 1 | $0.0798 | $0.0798 |
| W25Q128JVSIQ Flash Memory | U5 | 1 | $2.5196 | $2.5196 |
| TYPE-C-16PBS-1MD USB-C Connector | USB1 | 1 | $0.0619 | $0.0619 |
| NX3225SA-32.000M-STD-CSR-1 Crystal | X1 | 1 | $0.9681 | $0.9681 |
| **Total Component Cost (Estimated)** | | **44** | | **$10.15** |
## Project Files

```text
LoRa P
│
├── SCH_Schematic1_2026-09-20.pdf
├── PCB_PCB1_2026-09-20.png
├── BOM_Board1_PCB1_2026-09-20.xlsx
├── Gerber_TopLayer.GTL
├── Gerber_BottomLayer.GBL
├── Gerber_TopSolderMaskLayer.GTS
├── Gerber_BottomSolderMaskLayer.GBS
├── Gerber_TopSilkscreenLayer.GTO
├── Gerber_BoardOutlineLayer.GKO
├── Drill_PTH_Through.DRL
├── Drill_PTH_Through_Via.DRL
└── How-to-order-PCB.txt

