# ESP32-Based IoT Environmental Monitoring System with Custom PCB and Dashboard

**Project 3 | Browser simulation + embedded firmware draft + KiCad design starter**

## Interactive dashboard

Open [dashboard/index.html](dashboard/index.html) locally in a browser. The offline dashboard generates **simulated** temperature, humidity and pressure readings, updates a chart every 2 seconds, and supports pause/resume, reset and CSV export.

> **Simulation only:** The dashboard does not connect to physical hardware. The firmware has not been compiled or tested on a board.

## Repository structure

| Path | Contents |
| --- | --- |
| [dashboard/index.html](dashboard/index.html) | Interactive browser-based BME280 simulation |
| [tests/test_dashboard.js](tests/test_dashboard.js) | Offline static dashboard smoke test |
| [firmware/src/main.cpp](firmware/src/main.cpp) | ESP32 Arduino + BME280 serial telemetry draft |
| [firmware/platformio.ini](firmware/platformio.ini) | PlatformIO build configuration |
| [kicad/esp32-bme280-i2c-subsystem.kicad_sch](kicad/esp32-bme280-i2c-subsystem.kicad_sch) | Native KiCad schematic **draft** |
| [kicad/esp32-bme280-mechanical-outline.kicad_pcb](kicad/esp32-bme280-mechanical-outline.kicad_pcb) | 70 × 55 mm mechanical PCB outline with four M3 holes |
| [kicad/CONNECTIONS.md](kicad/CONNECTIONS.md) | Proposed electrical connection plan |
| [kicad/BOM.csv](kicad/BOM.csv) | Preliminary bill of materials |
| [kicad/SCHEMATIC_STATUS.md](kicad/SCHEMATIC_STATUS.md) | Schematic limitations |
| [kicad/PCB_LAYOUT_STATUS.md](kicad/PCB_LAYOUT_STATUS.md) | PCB limitations and next steps |

## Run locally

1. Download the repository ZIP from GitHub.
2. Open `dashboard/index.html` in a browser.
3. Optional: run `node tests/test_dashboard.js` to check static demo features.

## Current validation status

- **Dashboard:** implemented as an offline simulated demonstration.
- **Firmware:** source written; **not compiled or hardware-tested**.
- **KiCad schematic:** partial logical I²C design; incomplete power, reset, programming and module pins.
- **KiCad PCB:** mechanical outline only; **no placed circuit components or routed traces**.
- **KiCad ERC/DRC:** not run.
- **Physical hardware:** not assembled, fabricated or tested.

**Do not manufacture the PCB from these files.** The circuit and layout require completion and electrical review first.
