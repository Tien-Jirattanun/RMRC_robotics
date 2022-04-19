const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

#define LED_PIN 14

void setup() {
  // put your setup code here, to run once:
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_PIN, ledChannel);
}

void loop() {
  // put your main code here, to run repeatedly:
  ledcWrite(ledChannel, 255);
  delay(2000);
  ledcWrite(ledChannel, 100);
  delay(2000);
  ledcWrite(ledChannel,0);
  delay(2000);

}
