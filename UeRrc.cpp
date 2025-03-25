#include "UeRrc.hpp"
#include <iostream>

UeRrc::UeRrc() {
    logFile.open("C:/Users/ALBERTUS/CLionProjects/Analyzer/Logs/network_rrc_log.txt");
    logFile << "UE RRC Layer initialized (State: " << state << ")\n";
}

UeRrc::~UeRrc() {
    logFile.close();
}

void UeRrc::sendRrcConnectionRequest() {
    if (state == "RRC_IDLE") {
        state = "RRC_CONNECTING";
        logFile << "[UE → Network] RRCConnectionRequest\n";
        std::cout << "Sent RRCConnectionRequest\n";
    }
}

void UeRrc::receiveRrcConnectionSetup() {
    if (state == "RRC_CONNECTING") {
        state = "RRC_CONNECTED";
        logFile << "[Network → UE] RRCConnectionSetup\n";
        std::cout << "Received RRCConnectionSetup\n";
    }
}

void UeRrc::sendRrcConnectionComplete() {
    if (state == "RRC_CONNECTED") {
        logFile << "[UE → Network] RRCConnectionComplete\n";
        logFile.flush();
        std::cout << "Sent RRCConnectionComplete\n";
    }
}

const std::string& UeRrc::getState() const {
    return state;
}