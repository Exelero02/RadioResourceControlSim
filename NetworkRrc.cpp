#include "NetworkRrc.hpp"
#include <iostream>
#include <filesystem>
#include <ctime>

std::string getCurrentTimestamp() {
    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buf);
}

NetworkRrc::NetworkRrc() {
    logFile.open("../Logs/network_rrc_log.txt");
    logFile << "[" << getCurrentTimestamp() << "] Network RRC Layer initialized\n";
}

NetworkRrc::~NetworkRrc() {
    logFile.flush();
    logFile.close();
}

void NetworkRrc::receiveRrcConnectionRequest() {
    logFile << "[" << getCurrentTimestamp() << "] [UE → Network] Received RRCConnectionRequest\n";
    std::cout << "Received RRCConnectionRequest\n";
}

void NetworkRrc::sendRrcConnectionSetup() {
    logFile << "[" << getCurrentTimestamp() << "] [Network → UE] Sending RRCConnectionSetup\n";
    std::cout << "Sent RRCConnectionSetup\n";
    pcapLogger.logPacket({0x58, 0xA3}, "RRC Connection Setup");
}

void NetworkRrc::receiveRrcConnectionComplete() {
    logFile << "[" << getCurrentTimestamp() << "] [UE → Network] Received RRCConnectionComplete\n";
    std::cout << "Received RRCConnectionComplete\n";
}

void NetworkRrc::sendRrcRelease() {
    logFile << "[" << getCurrentTimestamp() << "] [Network → UE] Sending RRCRelease\n";
    std::cout << "Sent RRCRelease\n";
    pcapLogger.logPacket({0x60, 0x01}, "RRC Release");
}
