#pragma once

#include <string>
#include <fstream>

enum class RrcState {
    RRC_IDLE, RRC_CONNECTING, RRC_CONNECTED
};

class UeRrc {
private:
    RrcState state = RrcState::RRC_IDLE;
    std::ofstream logFile;

public:
    UeRrc();

    ~UeRrc();

    void sendRrcConnectionRequest();

    void receiveRrcConnectionSetup();

    void sendRrcConnectionComplete();

    void receiveRrcRelease();

    [[maybe_unused]] RrcState getState() const;
};