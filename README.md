# Sticky
Sticky is a 3D printed remote control handset for robotics projects. It uses an ESP32 and 2.4Ghz Wifi/ESP-Now for communication rather than conventional remote control RX/TX hardware.

The intention is that Sticky can interact directly with the computers involved in robotics projects rather than connecting a game controller etc. to a computer. The communication method might be MQTT, some kind of Websockets API, or through use of MicroROS to talk to ROS directly. This project is very much an early work in progress so software support is initially basic, with an expectation people will roll their own as every robotics project is different. Initial focus is on my m2mDirect Arduino library to connect to another Espressif ESP8266/ESP32.

The design is 3D printable on common hobbyist 3D printers in whatever material you fancy. PLA works fine.

Sticky uses all the GPIO on an ESP32, without multiplexing, to provide plenty of buttons and switches for your project.

![](images/sticky01.png)

## Supported joysticks

The expected joystick is the JH-D400X-R4 3-axis, or alternatively the JH-D202X-R4 2-axis or equivalents. Both fit the same mounting space. Ideally use the R4 models as they have 10k potentiometers.

![](images/joystick01.png)

![](images/joystick02.png)

When wiring, ensure there are ~4k resistors in series at both the ground and VCC connection for the joystick axes. This moves the working area into the middle of the more linear range of the ADCs on the ESP32.

## Supported switches

Through variant top panels, different switch types can be supported. You need four toggle SPST on/off miniature toggle switches and six 'normally open' momentary switches. Switches of similar size can be used with careful use of a file or knife to open the holes out. These sizes are pretty common so easy to get hold of and you may already have some.

### Variant 1

- One on/off rocker 'power' switch, 20x7mm cut-out
- Four miniature toggle switches, 6mm 'keyed' cut-out
- Six 'square' momentary NO buttons, 12.4 x 11mm cut-out

### Variant 2

- One on/off rocker 'power' switch, 20x7mm cut-out
- Four miniature toggle switches, 6mm 'keyed' cut-out
- Six round momentary NO buttons, 8mm cut-out

### Example square buttons

![](images/squareButtons01.png)

### Example round buttons

![](images/roundButtons01.png)

### Example toggle switches

![](images/toggleSwitches01.png)

## Supported screen

The current supported screen is the [1.44" Adafruit 128x128](https://www.adafruit.com/product/2088) TFT display. Support for other screens would be simple in software but contingent on access to them to accommodate them in the 3D printed design.

## Suggested development boards

You should use an ESP32 development board with onboard battery charging/protection, power switch and that exposes as many GPIO as possible as Sticky can use all the main GPIO on an ESP32.

I used a "WEMOS WiFi & Bluetooth Battery" board like the one below then carefully de-soldered the on/off switch and 18650 battery holder to fit external connections.

![](images/devBoard01.png)

You will also need a small micro-USB breakout to connect from the development board to the charge/programming connector on your development board.

I am considering doing a small run of custom boards designed specifically to support Sticky that allow for a more optimised case design.
