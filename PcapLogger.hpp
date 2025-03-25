#pragma once
#include <pcap.h>
#include <vector>
#include <string>

class PcapLogger {
private:
    pcap_t* pcap_handle;
    pcap_dumper_t* pcap_dumper;
public:
    PcapLogger(const std::string& filename);
    ~PcapLogger();
    void logPacket(const std::vector<uint8_t>& packet, const std::string& comment);
};