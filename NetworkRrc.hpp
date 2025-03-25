#pragma once
#include <string>
#include <fstream>
#include "PcapLogger.hpp"

class NetworkRrc {
private:
    std::ofstream logFile;
    PcapLogger pcapLogger{"../Logs/network_rrc.pcap"};

public:
    NetworkRrc();
    ~NetworkRrc();

    void receiveRrcConnectionRequest();
    void sendRrcConnectionSetup();
    void receiveRrcConnectionComplete();
    void sendRrcRelease();
};