# Sticky
Sticky is a 3D printed remote control handset for robotics projects. It uses an ESP32 and 2.4Ghz Wifi/ESP-Now for communication rather than conventional remote control RX/TX hardware.

The intention is that Sticky can interact directly with the computers involved in robotics projects rather than connecting a game controller etc. to a computer. The communication method might be MQTT, some kind of Websockets API, or through use of MicroROS to talk to ROS directly. This project is very much an early work in progress so software support is initially basic, with an expectation people will roll their own as every robotics project is different. Initial focus is on my m2mDirect Arduino library to connect to another Espressif ESP8266/ESP32.

The design is 3D printable on common hobbyist 3D printers in whatever material you fancy. PLA works fine.

Sticky uses all the GPIO on an ESP32, without multiplexing, to provide plenty of buttons and switches for your project.

![](images\sticky01.png)

## Supported joysticks

The expected joystick is the JH-D400X-R4 3-axis, or alternatively the JH-D202X-R4 2-axis or equivalents. Both fit the same mounting space. Ideally use the R4 models as they have 10k potentiometers.

When wiring, ensure there are ~4k resistors in series at both the ground and VCC connection for the joystick axes. This moves the working area into the middle of the more linear range of the ADCs on the ESP32.

## Supported switches

Through variant top panels, several different switch types are supported.

## Supported screen

The current supported screen is the [1.44" Adafruit 128x128](https://www.adafruit.com/product/2088) TFT display. Support for other screens would be simple in software but contingent on access to them to accommodate them in the 3D printed design.

## Suggested development boards

You should use an ESP32 development board with onboard battery charging/protection and that exposes as many GPIO as possible as sticky can use all the main GPIO on an ESP32.

You will also need a small micro-USB breakout to connect from the development board to the charge/programming connector on your development board.

I am considering doing a small run of custom boards designed specifically to support Sticky.
