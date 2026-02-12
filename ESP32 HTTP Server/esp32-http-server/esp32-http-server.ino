

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <uri/UriBraces.h>
#include <FirebaseESP32.h>

// 1. Credentials
#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""
#define WIFI_CHANNEL 6

#define FIREBASE_HOST "....../" // Without https://
#define FIREBASE_AUTH "........"

// 2. Pin Definitions
const int LED1 = 26;
const int LED2 = 27;

// 3. Firebase Objects
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  // Connect WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, WIFI_CHANNEL);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");

  // Configure Firebase
  config.host = FIREBASE_HOST;
  config.signer.tokens.legacy_token = FIREBASE_AUTH;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  // Optional: Set initial states in Firebase if they don't exist
  Firebase.setBool(fbdo, "/led1", false);
  Firebase.setBool(fbdo, "/led2", false);

  Serial.println("Firebase Connected!");
}

void loop() {
  // Check LED 1 status
  if (Firebase.getBool(fbdo, "/led1")) {
    bool state = fbdo.boolData();
    digitalWrite(LED1, state ? HIGH : LOW);
  } else {
    Serial.println("Error reading LED1: " + fbdo.errorReason());
  }

  // Check LED 2 status
  if (Firebase.getBool(fbdo, "/led2")) {
    bool state = fbdo.boolData();
    digitalWrite(LED2, state ? HIGH : LOW);
  }

  delay(1000); // Polling interval (Streaming is better for production)
}