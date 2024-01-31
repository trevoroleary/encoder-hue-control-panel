#ifndef REQUESTER_H
#define REQUESTER_H

#include <WiFi.h>
#include <HTTPClient.h>

String sendGetRequest(const String& route);

String sendPutRequest(const String& route, const String& body);

#endif
