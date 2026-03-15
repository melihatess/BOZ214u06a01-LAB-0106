const int trigPin = 9;
const int echoPin = 10;

// LED pinlerini tanımlıyoruz
const int led1 = 4; // 40 cm'den yakınsa yanar
const int led2 = 5; // 30 cm'den yakınsa yanar
const int led3 = 6; // 20 cm'den yakınsa yanar
const int led4 = 7; // 10 cm'den yakınsa yanar

long sure;
int mesafe;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  
  // LED pinlerini çıkış olarak ayarlıyoruz
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  Serial.begin(9600);       
  Serial.println("Park Sensoru Basliyor...");
}

void loop() {
  // Sensörden ses dalgası gönderimi
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Yansıyan dalganın süresini ölç ve mesafeye çevir
  sure = pulseIn(echoPin, HIGH);
  mesafe = sure * 0.034 / 2;
  
  // Mesafeyi Seri Monitör'e yazdır
  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");
  
  // --- Kademeli LED Kontrolü ---
  
  // 40 cm'nin altındaysa 1. LED yansın
  if (mesafe < 40) digitalWrite(led1, HIGH); 
  else digitalWrite(led1, LOW);

  // 30 cm'nin altındaysa 2. LED yansın
  if (mesafe < 30) digitalWrite(led2, HIGH); 
  else digitalWrite(led2, LOW);

  // 20 cm'nin altındaysa 3. LED yansın
  if (mesafe < 20) digitalWrite(led3, HIGH); 
  else digitalWrite(led3, LOW);

  // 10 cm'nin altındaysa 4. LED yansın
  if (mesafe < 10) digitalWrite(led4, HIGH); 
  else digitalWrite(led4, LOW);
  
  delay(100); // Sistemin kararlı çalışması için kısa bekleme
}