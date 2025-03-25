/**
 * @file main.cpp
 * @brief Main simulation of LTE RRC protocol exchange
 *
 * Simulates the complete RRC connection lifecycle between UE and Network:
 * 1. RRC Connection Request
 * 2. RRC Connection Setup
 * 3. RRC Connection Complete
 * 4. RRC Release
 */


#include <iostream>
#include <thread>
#include "UeRrc.hpp"
#include "NetworkRrc.hpp"
// #include <pcap.h>

int main() {


    UeRrc ue;
    NetworkRrc network;

    std::cout << "=== LTE RRC Simulator ===\n";

    // UE initiates connection
    std::thread ueThread([&]() {
        ue.sendRrcConnectionRequest();
    });

    // Network handles request
    std::thread networkThread([&]() {
        network.receiveRrcConnectionRequest();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        network.sendRrcConnectionSetup();
    });

    ueThread.join();
    networkThread.join();

    // UE processes setup
    ue.receiveRrcConnectionSetup();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // UE sends completion, network receives
    ue.sendRrcConnectionComplete();
    network.receiveRrcConnectionComplete();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    network.sendRrcRelease();
    ue.receiveRrcRelease();

    std::cout << "\nSimulation complete. Check Logs/ for details.\n";
    return 0;


    //    char errbuf[PCAP_ERRBUF_SIZE];
//    pcap_if_t* all_devices;
//
//    if (pcap_findalldevs(&all_devices, errbuf) == -1)
//    {
//        std::cerr << "npcap not found!" << errbuf << std::endl;
//    }
//    else
//    {
//        std::cout << "npcap installed successfully" << std::endl;
//        pcap_freealldevs(all_devices);
//    }

}