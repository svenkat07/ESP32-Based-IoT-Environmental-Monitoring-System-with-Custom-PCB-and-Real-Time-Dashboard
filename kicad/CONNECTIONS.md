# KiCad PCB design specification (proposed, not electrically verified)

## Hardware concept

ESP32-WROOM-32E module + BME280 environmental sensor (I²C) + USB-to-UART programming interface + 3.3 V regulator.

## Logical connections

| Net | ESP32 pin | Other connection | Note |
|---|---|---|---|
| I2C_SDA | GPIO21 | BME280 SDA | 4.7 kΩ pull-up to 3.3 V |
| I2C_SCL | GPIO22 | BME280 SCL | 4.7 kΩ pull-up to 3.3 V |
| 3V3 | 3V3 | BME280 VDD/VDDIO | Regulated 3.3 V, decoupling required |
| GND | GND | BME280 GND | Common ground |
| UART_TX | GPIO1 / U0TXD | USB-UART RX | 3.3 V logic |
| UART_RX | GPIO3 / U0RXD | USB-UART TX | 3.3 V logic |
| EN | EN | Reset network | Follow Espressif reference schematic |
| BOOT | GPIO0 | Boot switch | Follow Espressif reference schematic |

## Design requirements before PCB release

1. Choose exact BME280 package or breakout: the footprints and required passive components differ.
2. Select exact USB-UART chip, USB-C connector, ESD protection and 3.3 V regulator; check ESP32 peak current and power integrity.
3. Use Espressif's official ESP32-WROOM-32E reference design for EN, boot strapping, decoupling, antenna keepout and power routing.
4. Confirm all symbol-to-footprint mappings and manufacturer pin numbering in KiCad.
5. Route a 2-layer board with a solid ground reference and appropriate antenna clearance.
6. Run KiCad ERC and DRC; review power, reset, USB, I²C, and test pads.
7. Do not claim manufacturing readiness until a valid native KiCad schematic and PCB pass review.

**Status:** electrical architecture and connection plan, not a finished routed PCB. The browser dashboard runs independently and uses simulated data.
