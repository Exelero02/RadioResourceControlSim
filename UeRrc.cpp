#include "UeRrc.hpp"
#include <iostream>

std::string getCurrentTimestamp();

UeRrc::UeRrc() {
    logFile.open("../Logs/ue_rrc_log.txt");
    logFile << "[" << getCurrentTimestamp() << "] UE RRC Layer initialized (State: IDLE)\n";
}

UeRrc::~UeRrc() {
    logFile.close();
}

void UeRrc::sendRrcConnectionRequest() {
    if (state == RrcState::RRC_IDLE) {
        state = RrcState::RRC_CONNECTING;
        logFile << "[" << getCurrentTimestamp() << "] [UE → Network] sent RRCConnectionRequest\n";
        std::cout << "Sent RRCConnectionRequest\n";
    }
}

void UeRrc::receiveRrcConnectionSetup() {
    if (state == RrcState::RRC_CONNECTING) {
        state = RrcState::RRC_CONNECTED;
        logFile << "[" << getCurrentTimestamp() << "] [Network → UE] Received RRCConnectionSetup\n";
        std::cout << "Received RRCConnectionSetup\n";
    }
}

void UeRrc::sendRrcConnectionComplete() {
    if (state == RrcState::RRC_CONNECTED) {
        logFile << "[" << getCurrentTimestamp() << "] [UE → Network] sent RRCConnectionComplete\n";
        logFile.flush();
        std::cout << "Sent RRCConnectionComplete\n";
    }
}
void UeRrc::receiveRrcRelease() {
    if (state == RrcState::RRC_CONNECTED) {
        state = RrcState::RRC_IDLE;
        logFile << "[" << getCurrentTimestamp() << "] [Network → UE] RRC Release received, back to IDLE\n";
        std::cout << "Received RRCRelease\n";
    }
}

[[maybe_unused]] RrcState UeRrc::getState() const {
    return state;
}
