# Native KiCad PCB: mechanical outline only

The provided `.kicad_pcb` is a **70 × 55 mm preliminary board outline** with four 3.2 mm non-plated M3 mounting holes. It is **not a routed PCB**. No ESP32, BME280, regulator, USB-UART, passives, footprints or traces have been placed. It is an editable mechanical starting point only.

The schematic is also an I²C logical draft with incomplete ESP32 pins. These two files are **not yet a synchronized schematic/PCB pair**. Do not order a board from this project.

## Required engineering work before manufacturing

1. Select exact ESP32 module, sensor package/breakout, regulator and USB-UART components.
2. Replace partial/custom schematic symbols with verified complete library symbols.
3. Complete power, decoupling, EN/reset, GPIO0/BOOT, programming, USB protection and strapping circuits.
4. Assign correct manufacturer footprints, update PCB from schematic and confirm all netlists.
5. Place components with ESP32 antenna clearance, route copper, ground planes and appropriate widths.
6. Run KiCad electrical and design-rule checks and review the board with a hardware engineer.
7. Fabricate, inspect, power-up safely and test hardware before describing it as working.

**Validation note:** KiCad CLI is not installed here, so no ERC or DRC result is claimed.
