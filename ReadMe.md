# Encore Firmware for Flipper Zero

This project is not affiliated with Flipper Devices. Encore is the community's answer to [Flipper Devices abandoning Flipper Zero](https://spicemesh.de/posts/open-call-to-flipper/).

We aim to unofficially replace the official firmware, becoming an updated basis for users to use, app developers to target, and custom firmwares to base off of.

We plan to have updated forks, with new features and fixes, of:
- Flipper Zero Firmware (this repo)
- Flipper Lab
- Flipper Mobile Apps
- qFlipper
- Flipper App Catalog
- Flipper JS SDK
- Flipper Docs and Developer Docs

while removing all reliance on Flipper Devices.

Encore will not be a traditional "custom firmware", it just aims to be an updated version of official firmware without many frills and distractions, just good and stable updates without re-inventing the wheel - like the official firmware would've continued to be if it wasn't abandoned.

These plans are ambitious and will require time to reach, but we are determined to do what Flipper Devices have proven unable and/or uninterested to do.\
<sub>Our frustration is aimed at Flipper Devices as an entity; we are extremely thankful for and admire the amazing work done by official firmware developers, it is the people in charge that we take issue with.</sub>

# Contributing

Our main goal is to build a healthy and sustainable community around Flipper, so we're open to any new ideas and contributions. We also have some rules and taboos here, so please read this page and our [Code of Conduct](/CODE_OF_CONDUCT.md) carefully.

## I need help

The best place to search for answers is our [User Documentation](https://docs.flipper.net). If you can't find the answer there, check our [Discord Server](https://discord.gg/97vH4hFZY6). If you want to contribute to the firmware development or modify it for your own needs, you can also check our [Developer Documentation](https://developer.flipper.net/flipperzero/doxygen).

## I want to report an issue

If you've found an issue and want to report it, please check our [Issues](https://github.com/flipperencore/flipperzero-encore/issues) page. Make sure the description contains information about the firmware version you're using, your platform, and a clear explanation of the steps to reproduce the issue.

## I want to contribute code

Before opening a PR, please confirm that your changes must be contained in the firmware. Many ideas can easily be implemented as external applications and published in the [Flipper Application Catalog](https://github.com/flipperdevices/flipper-application-catalog). If you are unsure, reach out to us on the [Discord Server](https://discord.gg/97vH4hFZY6) or the [Issues](https://github.com/flipperencore/flipperzero-encore/issues) page, and we'll help you find the right place for your code.

Also, please read our [Contribution Guide](/CONTRIBUTING.md) and our [Coding Style](/CODING_STYLE.md), and make sure your code is compatible with our [Project License](/LICENSE).

Finally, open a [Pull Request](https://github.com/flipperencore/flipperzero-encore/pulls) and make sure that CI/CD statuses are all green.

# Development

Flipper Zero Firmware is written in C, with some bits and pieces written in C++ and armv7m assembly languages. An intermediate level of C knowledge is recommended for comfortable programming. C, C++, and armv7m assembly languages are supported for Flipper applications.

## Requirements

Supported development platforms:

- Windows 10+ with PowerShell and Git (x86_64)
- macOS 12+ with Command Line tools (x86_64, arm64)
- Ubuntu 20.04+ with build-essential and Git (x86_64)

Supported in-circuit debuggers (optional but highly recommended):

- [Flipper Zero Wi-Fi Development Board](https://shop.flipperzero.one/products/wifi-devboard)
- CMSIS-DAP compatible: Raspberry Pi Debug Probe and etc...
- ST-Link (v2, v3, v3mods)
- J-Link

Flipper Build System will take care of all the other dependencies.

## Cloning source code

Make sure you have enough space and clone the source code:

```shell
git clone --recursive https://github.com/flipperencore/flipperzero-encore.git
```

## Building

Build firmware using Flipper Build Tool:

```shell
./fbt
```

## Flashing firmware using an in-circuit debugger

Connect your in-circuit debugger to your Flipper and flash firmware using Flipper Build Tool:

```shell
./fbt flash
```

## Flashing firmware using USB

Make sure your Flipper is on, and your firmware is functioning. Connect your Flipper with a USB cable and flash firmware using Flipper Build Tool:

```shell
./fbt flash_usb_full
```

## Documentation

- [Flipper Build Tool](/documentation/fbt.md) - building, flashing, and debugging Flipper software
- [Applications](/documentation/AppsOnSDCard.md), [Application Manifest](/documentation/AppManifests.md) - developing, building, deploying, and debugging Flipper applications
- [Hardware combos and Un-bricking](/documentation/KeyCombo.md) - recovering your Flipper from the most nasty situations
- [Flipper File Formats](/documentation/file_formats) - everything about how Flipper stores your data and how you can work with it
- [Universal Remotes](/documentation/UniversalRemotes.md) - contributing your infrared remote to the universal remote database
- And much more in the [Developer Documentation](https://developer.flipper.net/flipperzero/doxygen)

# Project structure

- `applications`        - Applications and services used in firmware
- `applications_user`   - Place for your additional applications and services
- `assets`              - Assets used by applications and services
- `documentation`       - Documentation generation system configs and input files
- `furi`                - Furi Core: OS-level primitives and helpers
- `lib`                 - Our and 3rd party libraries, drivers, tools and etc...
- `scripts`             - Supplementary scripts and various python libraries
- `site_scons`          - Build system configuration and modules
- `targets`             - Firmware targets: platform specific code

Also, see `ReadMe.md` files inside those directories for further details.

# Links

- Discord: [discord.gg/97vH4hFZY6](https://discord.gg/97vH4hFZY6)
- Website: [encore-zero.dev](https://encore-zero.dev)
- Update Server: [builds/firmware](https://up.encore-zero.dev/builds/firmware)
- Update Indexer: [directory.json](https://up.encore-zero.dev/firmware/directory.json)
