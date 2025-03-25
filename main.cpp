#include "iostream"
#include "UeRrc.hpp"
#include "NetworkRrc.hpp"
#include <thread>

int main() {
    UeRrc ue;
    NetworkRrc network;

    std::cout << "=== LTE RRC Simulator ===\n";

    // UE initiates connection
    ue.sendRrcConnectionRequest();
    network.receiveRrcConnectionRequest();

    // Network responds
    std::this_thread::sleep_for(std::chrono::seconds(1));
    network.sendRrcConnectionSetup();
    ue.receiveRrcConnectionSetup();

    // UE completes setup
    std::this_thread::sleep_for(std::chrono::seconds(1));
    ue.sendRrcConnectionComplete();
    network.receiveRrcConnectionComplete();

    std::cout << "\nSimulation complete. Check Logs/ for details.\n";
    return 0;
}