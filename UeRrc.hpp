#pragma once
#include <string>
#include <fstream>

class UeRrc {
private:
    std::string state = "RRC_IDLE";
    std::ofstream logFile;

public:
    UeRrc();
    ~UeRrc();

    void sendRrcConnectionRequest();
    void receiveRrcConnectionSetup();
    void sendRrcConnectionComplete();
    const std::string& getState() const;
};