#include <Arduino.h>
#include "HT1621_custom.h" // Include the HT1621 library

// Define the HT1621 LCD object
HT1621 lcd;

// Demo counters
int count = 0;

// Pin configuration for the LCD
const int csPin = 13;   // Chip Select pin
const int wrPin = 12;   // Write pin
const int dataPin = 8;  // Data pin
const int backlightPin = 10; // Optional backlight pin

void setup()
{
    // Initialize serial communication
    Serial.begin(115200);
    Serial.println("HT1621 Demo Starting...");

    // Initialize the LCD with the backlight control
    lcd.begin(csPin, wrPin, dataPin, backlightPin);
    lcd.backlight(); // Turn on the backlight

    // Clear the screen
    lcd.clear();

    // Display markers as a part of the startup sequence
    lcd.setMarker(USB);
    delay(500);
    lcd.setMarker(CH51);
    delay(500);
    lcd.setMarker(CH21);
    delay(500);
    lcd.setMarker(STANDBY);
    delay(500);

    Serial.println("Setup complete.");
}

void loop()
{
    // Display temperature simulation
    float simulatedTemperature = (float)count / 10;
    lcd.printCelsius(simulatedTemperature);

    // Print value to the Serial Monitor
    Serial.print("Displayed Temperature: ");
    Serial.print(simulatedTemperature);
    Serial.println(" °C");

    // Increment and reset count for demonstration purposes
    count = (count + 1) % 1000;

    // Wait before updating the display
    delay(200);
}
