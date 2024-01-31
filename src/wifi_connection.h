// receiver.h

// Include guards to prevent multiple inclusion
#ifndef RECEIVER_H
#define RECEIVER_H

#include <WiFi.h>
#include <WiFiClient.h>

// Define your struct
struct DataPacket {
    uint8_t ramp_rate;
    uint8_t rgb_list[219];
};

void setup_wifi_connection();

#endif // RECEIVER_H