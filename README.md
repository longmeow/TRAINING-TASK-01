# FIL SERCURITY TRANING TASK - Set up IoT testbed (phase 1)

## Made by NPLing & Longmeow

Thís repo describes a simple testbed (to...//the purpose of this testbed is...)

## Table of Contents
1. [Requirements](#requirements)
2. [Overall](#overall)
3. [Setup and Running Guide](#setup-running)

### Requirements
**Hardware**
- A Raspberry Pi
- 2 sets of sensors including DS18B20 and MH-Sensor-Series Flying-Fish
- 2 nodeMCU boards ESP8266
- 2 PC/laptop

**Software**
- Python3
- Adruino IDE (including Onewire, DallasTemperature libraries) and downloaded the ESP8266 card library (You can follow the guide [here](https://www.instructables.com/How-to-Install-ESP8266-Into-Arduino-IDE/))
- Driver CP210x to communication with ESP8266 (you can download from [here](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers))

### Overall

<p align="center"><img src="https://i.imgur.com/uYaw3iP.png" width="836" /></p>

The testbed is depicted in the diagram above:

- Raspberry Pi operates as a router with DHCP server, connecting remaining entities in IoT testbed.
- 2 nodeMCU boards send their data collected by sensors to host by network protocol of choice (in particular, we use HTTP).
- Host output received data of each zone to the respective .csv file.
- Another PC use an attack tool (in this case - Slowloris) to perform DoS attack targeting (entities) and observe system behaviors.

### Setup and Running Guide <a name="setup-running"></a>

#### Raspberry Pi

**SOS:** Guildlines for absolute newbie

You'll need to set your Raspberry Pi as a DHCP sever, also known as Router 🙈 

**Step 1:** Install Raspbian OS on your 200$ brandnew limited Raspberry Pi came with black case and type-C charger, give [it](https://www.raspberrypi.com/documentation/computers/getting-started.html) a try.

**Step 2:** Set you Pi as a router. By following [this](https://www.youtube.com/watch?v=S4E35d91Xss), you'll get your job done easily instead of crying with bugs which cannot be debuged cause you don't have such a knowledge of what you're doing like us before.

#### ESP8266

**SOS:** Brief and simple explanation

After collect the data from 2 sensors, ESP8266 will a creates a localhost server and starts to waiting a request. Everytime a client sends a request to that localhost, ESP8266 runs the desired code, check if client's IP is allowable and then returns the result as an http request.

**Step 1:** Download and save 2 files ***esp8266.ino*** and ***utils.h*** in the same folder.

**Step 2:** Open file ***esp8266.ino***, modify some information such as SSID, password of your wifi, IP address of client.

**Step 3:** Plugging ESP8266 and uploading the sketch.


#### Packet sniffer

We use ***TShark*** - a network protocol analyzer, CLI version of Wireshark to capture packets transmitted. Read the TShark's [instruction](https://www.wireshark.org/docs/man-pages/tshark.html) for more details. To capture packets and save to .csv file:

`tshark -T fields -e ip.version -e ip.src -e ip.dst -e ip.len -e ip.hdr_len -e ip.id -e ip.proto -e ip.ttl -e ip.flags -e ip.frag_offset -e ip.checksum -e ipv6.src -e ipv6.dst -e ipv6.tclass -e ipv6.flow -e ipv6.plen -e ipv6.nxt -e ipv6.hlim -e tcp.srcport  -e tcp.dstport -e udp.srcport -e udp.dstport -E separator=, -E header=y -c <Num_of_packets>  > <File_Name>.csv`

Using this command, we've just captured some "useful" headers (IPv4 & IPv6 & UDP/TCP port). Add `-e <option>` in the command line for more info of captured packet. All `<option>` will be found [here](https://www.wireshark.org/docs/dfref/).

### Attack tool

There is a wide range of attack tool, since using HTTP as protocol, we use ***Slowloris*** - a type of DoS attack tool aim at overwhelm a targeted server by opening and maintaining many simultaneous HTTP. Periodically, it will send HTTP headers, adding to, but never completing the request to keep these connections open. The targeted server will be filled its maximum concurrent connection pool and deny additional connection attempts from clients.

**Install using git clone:** `git clone https://github.com/gkbrk/slowloris.git`

**To start attacking:** 

`cd slowloris`

`python3 slowloris.py targetedserver.com`

Read [Slowloris](https://github.com/gkbrk/slowloris) for more details.
