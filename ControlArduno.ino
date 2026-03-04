const int lampuPin = 13; // Pin LED bawaan Arduino

void setup() {
  Serial.begin(9600); // Harus sama dengan ESP yaitu 9600
  pinMode(lampuPin, OUTPUT);
  digitalWrite(lampuPin, LOW); // Awalnya mati
  
  // Debugging setup
  Serial.println("--- Arduino Siap ---");
  Serial.println("Menunggu perintah dari ESP8266...");
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read(); // Baca perintah dari ESP
    
    // Debugging data masuk
    Serial.print("Data masuk: ");
    Serial.println(data);
    
    if (data == '1') {
      digitalWrite(lampuPin, HIGH); // Nyalakan lampu
      Serial.println("Status: Lampu NYALA");
    } else if (data == '0') {
      digitalWrite(lampuPin, LOW);  // Matikan lampu
      Serial.println("Status: Lampu MATI");
    } else {
      // Jika ada data aneh yang masuk, kita tahu
      Serial.println("Status: Perintah tidak dikenal");
    }
  }
}