#include "requester.h"
#include "secrets.h"

String sendGetRequest(const String& route) {
    String url = API_URL + route;
    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();
    String response = http.getString();
    http.end();
    return response;
}


String sendPutRequest(const String& route, const String& body) {
    String url = API_URL + route;
    HTTPClient http;
    http.begin(url);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("hue-application-key", HUE_APPLICATION_KEY);
    int httpCode = http.PUT(body);
    String response = http.getString();
    http.end();
    return response;
}

