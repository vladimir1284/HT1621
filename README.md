# HT1621 Arduino Library

This is a custom Arduino library for interfacing with the HT1621 LCD controller, tailored for complex segmented displays. The library supports rendering numeric and textual information, along with specialized markers and symbols, on custom boards like the one shown in the provided image.

![WhatsApp Image 2024-12-09 at 12 24 44 PM](https://github.com/user-attachments/assets/49e47768-2e3c-4afd-906b-733b32498530)

## Features

- Full support for the HT1621 LCD driver
- Print numeric and text values
- Built-in handling for markers and symbols (e.g., `VOLUME`, `TREBLE`, `FM`, etc.)
- Customizable backlight control
- Battery level indicators
- Decimal point and colon rendering
- Display modes (clear, update, and toggle markers)
- Precision handling for numeric and floating-point values

## Supported Markers

The library includes predefined markers for specific board symbols:

- **Audio Settings**: `CLASSIC`, `ROCK`, `POP`, `FLAT`, `JAZZ`
- **Inputs**: `AUX`, `DVD`, `CD`, `OPT`, `COA`, `RADIO`
- **Playback Controls**: `PLAY`, `PAUSE`, `FORWARD`, `PREVIOUS`
- **Audio Channels**: `2.1CH`, `5.1CH`
- **Other Symbols**: `USB`, `CLOCK`, `TREBLE`, `MUTE`, `DELAY`, `MS`

For the full list, see the symbol definitions in the source code.

![screen](https://github.com/user-attachments/assets/d10e18f4-f12f-41cb-bdeb-1a9ba0de5217)

## Installation

1. Clone this repository or download the ZIP file.
2. Place the folder in your Arduino `libraries` directory.
3. Restart your Arduino IDE.

## Pinout Information

This project includes the following components and their respective connections to the microcontroller:
![pinout](https://github.com/user-attachments/assets/b4a892cd-8ed3-4e94-a226-9912a4fe7ff3)

### Buttons
Matrix keypad as in the figure.

### Infrared (IR) Receiver
- **IR Signal**: Connected to `IR`

### HT1621 LCD Controller
- **WR (Write)**: Connected to `P4.1`
- **Data**: Connected to `P4.2`
- **CS (Chip Select)**: Connected to `P4.3`

### Power
- **5V**: Supplies power to the board.
- **GND**: Ground connection.

**Important Note:**  
The board's printing **inverts the power pins**. Double-check connections using electrolitic capacitors as ground true, before powering up the system to avoid damage.
![board](https://github.com/user-attachments/assets/79b53761-ee65-48f4-bd4e-3224410f44fd)


## Usage

### Basic Setup

```cpp
#include "HT1621.h"

HT1621 lcd;

void setup() {
    lcd.begin(10, 11, 12); // Connect CS, WR, DATA pins
    lcd.clear();
    lcd.backlight();
}

void loop() {
    lcd.print(123.45, 2); // Display a floating-point number with two decimals
    lcd.setMarker(VOLUME); // Highlight the VOLUME symbol
    lcd.display(); // Refresh the display
    delay(1000);
}
```

### Custom Printing

- Use `lcd.print()` to display numbers or text.
- Use `lcd.setMarker(MARKER)` to highlight specific board markers.
- For advanced usage, see the example sketches in the repository.

### Backlight Control

```cpp
lcd.backlight();    // Turn on backlight
lcd.noBacklight();  // Turn off backlight
```

### Clearing the Display

```cpp
lcd.clear();       // Clear the display content
lcd.clear_buffer(); // Clear the internal buffer without refreshing
```

## License

This library is distributed under the MIT License. See [LICENSE](LICENSE) for more information.

## Acknowledgments

- Based on the [segment-lcd-with-ht1621](https://github.com/anxzhu/segment-lcd-with-ht1621) library by [anxzhu](https://github.com/anxzhu).
- Extended and partially rewritten by [Valerio Nappi](https://github.com/valerionew).
- Further customized to support unique display designs.

## Contributions

Feel free to contribute to this project by submitting issues or pull requests. Whether it's enhancing functionality or providing new examples, all contributions are welcome!
