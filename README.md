# FIL SERCURITY TRANING TASK - Set up IoT testbed (phase 1)

## Made by NPLing & Longmeow

Thís repo describes a simple testbed (to...//the purpose of this testbed is...)

## Table of Contents
- [Requirements] (#requirements)
- [Overall] (#overall)
- [Setup Instructions] (#setup-instructions)
- [Running guide] (#running-guide)
- [Lisence] (#lisence)

### Requirements

- A Raspberry Pi
- 2 sets of sensors including DS18B20 and MH-Sensor-Series Flying-Fish
- 2 nodeMCU boards ESP8266
- 2 PC/laptop

### Overall

<p align="center"><img src="https://i.imgur.com/uYaw3iP.png" width="836" /></p>

- Raspberry Pi operates as a router with DHCP server, connecting remaining entities in IoT testbed.
- 2 nodeMCU boards send their data collected by sensors to host by network protocol of choice (in particular, we use HTTP).
- Host output received data of each zone to the respective .csv file.
- Another PC use an attack tool (in this case - Slowloris) to perform DoS attack targeting (entities) and observe system behaviors.

### Setup Instructions

#### Raspberry Pi

(Longmeow)

#### ESP8266

(Ling)

#### Attack tool

(Ling)

#### Packet sniffer

(Longmeow)
