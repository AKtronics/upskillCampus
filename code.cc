#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

int IRpin = 2;
int count = 0;
int val0 = HIGH; 

void setup() {
  pinMode(IRpin, INPUT);
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED allocation failed!");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Count: ");
  display.display();
}

void loop() {
  int val1 = digitalRead(IRpin);

  if (val1 == LOW && val0 == HIGH) {
    count++;
    updateDisplay();
  }

  val0 = val1;

  delay(50); 
}

void updateDisplay() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Count: ");
  display.print(count);
  display.display();
}

