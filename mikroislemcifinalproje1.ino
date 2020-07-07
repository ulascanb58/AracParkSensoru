#define trigPin 11 //Ultrasonik mesafe sensörümüzün trigPin'i.
#define echoPin  12 //Ultrasonik mesafe sensörümüzün echoPin'i.
#define buzzer 10  //Buzzer(piezo)'muzun pini.
#define kirmiziled 7 //Kırmızı ledimizin pini.
#define sariled  6 //Sarı ledimizin pini.
#define yesilled  5 //Yeşil ledimizin pini.

long sure, cm; //Süre ve cm değişkenleri.
 
void setup() {
  //Seri haberleşme başlangıcı 9600 baud rate
  Serial.begin (9600);
  //İnput ve output tanımlanması.
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(kirmiziled, OUTPUT);
  pinMode(sariled, OUTPUT);
  pinMode(yesilled, OUTPUT);
}
 
void loop() {
  // Sensör, 10 veya daha fazla mikrosaniye yüksek bir darbe ile tetiklenir.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // sure değişkeni mikrosaniye olarak gönderilen zaman değişkenidir.
  // bir nesnenin yankısının alınması için ping atıyoruz.
  pinMode(echoPin, INPUT);
  sure = pulseIn(echoPin, HIGH);
 
  // Mesafeyi hesaplamak için mesafe sensöründe bulduğumuz süre ile işlem yapıyoruz.
  cm = sure / 58.2; // Mesafeyi hesaplama formülü. Toplam zaman(ultrasonik mesafe sensöründe sesin git-gel yapması
    
  
  if(cm>150)
  {
    noTone(10);
    digitalWrite(yesilled,HIGH);
    delay(500);
    digitalWrite(yesilled,LOW);
    delay(500);
    digitalWrite(sariled,LOW);
    digitalWrite(kirmiziled,LOW);
    digitalWrite(buzzer,LOW);
  }
  else if(100<cm && cm<150)
  {
    tone(10,400,400);
    digitalWrite(sariled,HIGH);
    delay(920);
    digitalWrite(sariled,LOW);
    delay(920);
    digitalWrite(yesilled,LOW);
    digitalWrite(kirmiziled,LOW);
    digitalWrite(buzzer,LOW);

    
    
  }
  else if(60<cm && cm<100)
  {
    
    tone(10, 425, 425);
    digitalWrite(kirmiziled,HIGH);
    delay(700);
    digitalWrite(kirmiziled,LOW);
    delay(700);
    digitalWrite(sariled,LOW);
    digitalWrite(yesilled,LOW);
    digitalWrite(buzzer,LOW);
   
  }
  else 
  {
    Serial.println("Lutfen dikkat kaza yapacaksiniz!");
    tone(10, 450, 450);
    delay(400);
    digitalWrite(sariled,LOW);
    digitalWrite(kirmiziled,LOW);
    digitalWrite(yesilled,LOW);
    
    
  }
  
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();
  
  delay(250);
}
