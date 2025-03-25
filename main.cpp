#include <iostream>
#include <thread>
#include "UeRrc.hpp"
#include "NetworkRrc.hpp"

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
}