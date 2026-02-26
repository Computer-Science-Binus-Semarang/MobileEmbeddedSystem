// Menentukan pin LED
const int ledPin = 13;

void setup() {
  // Memulai komunikasi Serial dengan kecepatan 9600 bps
  Serial.begin(9600);
  
  // Mengatur pin digital sebagai OUTPUT
  pinMode(ledPin, OUTPUT);
  
  Serial.println("Sistem Dimulai...");
}

void loop() {
  // Menyalakan LED
  digitalWrite(ledPin, HIGH);
  Serial.println("LED Menyala (ON)"); // Mengirim pesan ke Serial Monitor
  delay(1000); // Tunggu 1 detik (1000 milidetik)

  // Mematikan LED
  digitalWrite(ledPin, LOW);
  Serial.println("LED Mati (OFF)");  // Mengirim pesan ke Serial Monitor
  delay(1000); // Tunggu 1 detik
}