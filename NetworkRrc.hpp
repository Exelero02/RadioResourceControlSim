#pragma once
#include <string>
#include <fstream>

class NetworkRrc {
private:
    std::ofstream logFile;

public:
    NetworkRrc();
    ~NetworkRrc();

    void receiveRrcConnectionRequest();
    void sendRrcConnectionSetup();
    void receiveRrcConnectionComplete();
    void sendRrcRelease();
};