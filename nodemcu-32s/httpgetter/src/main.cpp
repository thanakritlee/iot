#include <HTTPClient.h>
#include <WiFi.h>

const char* ssid = "ChaVisaPlace_A_2.4Ghz";

void connect() {
  Serial.println("Checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(1000);
  }
  Serial.println("Wifi is connected");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.begin(ssid);

  connect();
}

void loop() {
  // put your main code here, to run repeatedly:
  HTTPClient http;
  http.begin("http://anon-chat.thanakritlee.dev/");
  int httpCode = http.GET();
  // httpCode will be negative on error
  if(httpCode < 0) {
    Serial.printf("Error GET request: %s", http.errorToString(httpCode).c_str());
  } else {
    Serial.println("Successfully run GET request");
  }
  http.end();

  http.begin("http://road-surface-estimator.thanakritlee.dev/");
  httpCode = http.GET();
  // httpCode will be negative on error
  if(httpCode < 0) {
    Serial.printf("Error GET request: %s", http.errorToString(httpCode).c_str());
  } else {
    Serial.println("Successfully run GET request");
  }
  http.end();

  delay(60000);
}