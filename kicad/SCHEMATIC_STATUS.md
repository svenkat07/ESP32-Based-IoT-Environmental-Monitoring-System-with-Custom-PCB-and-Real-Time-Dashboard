# Native KiCad schematic: I²C subsystem draft

The `.kicad_sch` file is a **native KiCad 9-format schematic** containing an ESP32-WROOM-32E logical pin subset, a four-pin BME280 **breakout** header and two I²C pull-ups. It uses embedded custom symbols and named nets. It is a **logical wiring draft, not a finished production circuit or routed PCB**.

**Important:** The BME280 breakout pin order is a design assumption and must be checked against the actual selected breakout. The ESP32 symbol includes only selected pins, not all 38 module pads. EN, BOOT and UART pins are labeled but their programming/reset networks are not implemented. The power regulator, bypass capacitors, USB-UART circuit, antenna clearance, ground return and full module pinout are absent. The board cannot be manufactured from this schematic.

The schematic has not been checked with KiCad ERC because `kicad-cli` is not available in the current runtime. Before PCB design, replace the partial symbols with validated library symbols, select exact component part numbers, implement power/reset/programming circuits, assign footprints and run ERC/DRC.
