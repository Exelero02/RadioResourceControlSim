#include "NetworkRrc.hpp"
#include <iostream>
#include <filesystem>

NetworkRrc::NetworkRrc() {
    logFile.open("C:/Users/ALBERTUS/CLionProjects/Analyzer/Logs/network_rrc_log.txt");
    logFile << "Network RRC Layer initialized\n";
}

NetworkRrc::~NetworkRrc() {
    logFile.flush();
    logFile.close();
}

void NetworkRrc::receiveRrcConnectionRequest() {
    logFile << "[UE → Network] Received RRCConnectionRequest\n";
    std::cout << "Received RRCConnectionRequest\n";
}

void NetworkRrc::sendRrcConnectionSetup() {
    logFile << "[Network → UE] Sending RRCConnectionSetup\n";
    std::cout << "Sent RRCConnectionSetup\n";
}


void NetworkRrc::receiveRrcConnectionComplete() {
    logFile << "[UE → Network] Received RRCConnectionComplete\n";
    std::cout << "Received RRCConnectionComplete\n";
}