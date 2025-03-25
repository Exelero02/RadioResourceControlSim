# LTE RRC Simulator

This project simulates the **Radio Resource Control (RRC)** signaling process in LTE networks. It focuses on simulating communication between **User Equipment (UE)** and **Network** using key RRC messages, including the connection request, connection setup, and connection release procedures. The project is implemented in **C++** and includes data logging using text files and PCAP files for packet capture.

---

## Project Overview

The **LTE RRC Simulator** is a simple simulation of the LTE RRC signaling procedures, with the following key features:

- **UE and Network Interaction**: The simulation mimics the communication process between a UE and the network by sending and receiving RRC messages.
- **Logging**: Logs messages are written to a text file (`...log.txt`), and packet data is also logged using the **PCAP** format for analysis with tools like Wireshark.
- **Multithreading**: The simulation uses multithreading to handle simultaneous interactions between the UE and Network.
- **PCAP Logging**: The project includes an attempt to simulate the capture of RRC signaling messages using PCAP files.

---

## Features

- **UE to Network Communication**: Simulates the transmission of RRC connection requests, connection setup messages, and release procedures.
- **Logging**: Outputs logs to text files for easy tracking and debugging of the simulation process.
- **PCAP Packet Capture**: Implements a basic PCAP logging feature that attempts to capture simulated packets for further analysis using network analysis tools like Wireshark.
- **Multithreading**: The simulation involves asynchronous handling of UE and network interactions using threads.
  
---

## Requirements

- **C++11 or higher** (for threading and modern C++ features)
- **pcap** library (for packet capture logging, optional if PCAP feature is used)
  
Make sure to install **libpcap** on your system if you wish to use the PCAP logging feature.

---



   
