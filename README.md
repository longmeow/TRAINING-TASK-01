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

We use **TShark** - a network protocol analyzer, CLI version of Wireshark to capture packets transmitted. Read the TShark's [instruction](https://www.wireshark.org/docs/man-pages/tshark.html) for more details.

`tshark -T fields -e ip.version -e ip.src -e ip.dst -e ip.len -e ip.hdr_len -e ip.id -e ip.proto -e ip.ttl -e ip.flags -e ip.frag_offset -e ip.checksum -e tcp.dstport -E separator=, -E header=y -c <Num_of_packets>  > <File_Name>.csv`

Using this command, we've just captured some "useful" headers. Add `-e <option>` in the command line for more info of captured packet. All `<option>` will be found [here](https://www.wireshark.org/docs/dfref/).
