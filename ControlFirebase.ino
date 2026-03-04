#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define WIFI_SSID "M14 Prabowows"
#define WIFI_PASS "semogabermanfaat"
#define FIREBASE_HOST "" // Ganti sesuai database-mu
#define FIREBASE_AUTH "" 

FirebaseData firebaseData;
FirebaseConfig config;
FirebaseAuth auth;

void setup() {
  Serial.begin(9600); // Harus 9600 agar cocok dengan Arduino
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  
  config.host = FIREBASE_HOST;
  config.signer.tokens.legacy_token = FIREBASE_AUTH;
  Firebase.begin(&config, &auth);
}

void loop() {
  // Cek data dari Firebase
  if (Firebase.getString(firebaseData, "/Lampu")) {
    String status = firebaseData.stringData();
    
    // Kirim perintah ke Arduino lewat Serial
    if (status == "Nyala") {
      Serial.println('1'); // Kirim karakter '1'
    } else if (status == "Mati") {
      Serial.println('0'); // Kirim karakter '0'
    }
  }
  delay(500); // Cek setiap 2 detik
}