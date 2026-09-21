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
