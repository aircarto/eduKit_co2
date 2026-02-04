#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

// I2C pins pour le Pico 2 W
#define I2C_SDA 4
#define I2C_SCL 5

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

bool ledState = false;

void drawLed(bool on) {
    display.clearDisplay();

    // Texte
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("eduKit CO2");
    display.println();

    // Dessine une LED (cercle)
    int centerX = SCREEN_WIDTH / 2;
    int centerY = 40;
    int radius = 15;

    if (on) {
        // LED allumée : cercle plein + rayons
        display.fillCircle(centerX, centerY, radius, SSD1306_WHITE);
        // Rayons
        for (int i = 0; i < 8; i++) {
            float angle = i * PI / 4;
            int x1 = centerX + cos(angle) * (radius + 3);
            int y1 = centerY + sin(angle) * (radius + 3);
            int x2 = centerX + cos(angle) * (radius + 8);
            int y2 = centerY + sin(angle) * (radius + 8);
            display.drawLine(x1, y1, x2, y2, SSD1306_WHITE);
        }
        display.setCursor(45, 56);
        display.print("LED: ON");
    } else {
        // LED éteinte : cercle vide
        display.drawCircle(centerX, centerY, radius, SSD1306_WHITE);
        display.setCursor(42, 56);
        display.print("LED: OFF");
    }

    display.display();
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);
    delay(2000);
    Serial.println("Pico 2 W ready!");

    // Initialise I2C avec les pins personnalisés
    Wire.setSDA(I2C_SDA);
    Wire.setSCL(I2C_SCL);
    Wire.begin();

    // Initialise l'écran OLED
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println("Erreur: ecran OLED non trouve!");
        while (true) {
            digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
            delay(100);
        }
    }

    Serial.println("Ecran OLED initialise");
    display.clearDisplay();
    display.display();
}

void loop() {
    ledState = !ledState;

    digitalWrite(LED_BUILTIN, ledState ? HIGH : LOW);
    drawLed(ledState);

    Serial.println(ledState ? "LED ON" : "LED OFF");

    delay(1000);
}
