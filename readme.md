# M5Paper - Countdown Calendar

## Overview
This project is a simple countdown calendar designed to run on the M5Paper e-ink display. It tracks the number of days remaining until a specified date and displays the countdown elegantly on the M5Paper.

## Requirements
- [M5Paper](https://docs.m5stack.com/en/core/m5paper): ESP32-based e-ink display
- [PlatformIO Core CLI](https://docs.platformio.org/en/latest/core/index.html): An open-source platform for IoT development.

## IDE Setup
**CLion**
  - https://www.jetbrains.com/help/clion/platformio.html
  - https://docs.platformio.org/en/stable/integration/ide/clion.html

**VS Code**
  - https://platformio.org/platformio-ide
  - https://docs.platformio.org/en/stable/integration/ide/vscode.html#ide-vscode

**Others**: https://docs.platformio.org/en/stable/integration/ide/index.html

## WIFI
A WiFi connection is required to sync the date and time of the M5Paper.

To configure the connection, create a `config.h` file in the `include/` directory with this content:
```c++
#ifndef CONFIG_H
#define CONFIG_H

#define WIFI_SSID "Your_SSID"
#define WIFI_PASSWORD "Your_Password"

#endif // CONFIG_H
```

## Test
For unit testing the [Google Test](https://github.com/google/googletest) framework is used.

PlatformIO Google Test Documentation: https://docs.platformio.org/en/latest/advanced/unit-testing/frameworks/googletest.html

Run tests:
```bash
pio test
```

## Run
```shell
pio run -e m5stack-fire -t upload
```

## nix
If using nix, run to set up dev environment:
```shell
nix-shell
```

## Useful Links
**M5EPD**: M5Paper Arduino Library
- GitHub: https://github.com/m5stack/M5EPD/
- Code Examples: https://github.com/m5stack/M5EPD/tree/main/examples
