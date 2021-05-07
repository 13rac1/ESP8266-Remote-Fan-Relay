# ESP8266 Remote Fan Relay

Convert a manual four-way switched fan to remote WiFi control using a four
channel relay.

## Directions

1. Setup [PlatformIO](https://platformio.org/)
2. Copy the `src/credentials.h.example` file to `src/credentials.h`.
3. Add the WiFi SSID and password to `src/credentials.h`.
4. Test the network connection and confirm the web form appears on port 80.
5. Now "just" assemble the hardware and install fit in your fan. YMMV depending
   on device. In this case, the fan has been wired so the manual control works
   as a failsafe when the power relay is unpowered.
6. Done? Now control your fan with:
   * The HTML form
   * [OpenHAB HTTP binding](https://v2.openhab.org/addons/bindings/http1/)
   * [Home Assitant RESTful Command integration](https://www.home-assistant.io/integrations/rest_command/)
   * Android - [HTTP Request Shortcuts](https://play.google.com/store/apps/details?id=ch.rmy.android.http_shortcuts&hl=en_US&gl=US)

## Parts

* A fan (or other device) with a four position switch: off, low, medium, high.
* [ESP8266 NodeMCU CP2102 ESP-12E Development Board](https://amzn.to/3tsSgZ2)
* [4 Channel 5V Relay Module](https://amzn.to/3tnwi9S)
* [120V AC to DC 5V 2A/10W Power Supply](https://amzn.to/3bbZUAH)
* Wire, Solder, Heatshrink, & Tools
* Optional: [Dustproof Weatherproof IP65 Electrical Box - Project Enclosure](https://amzn.to/3h91ZBi)

## Background

I have a HEPA filter in an out-of-the-way, but awkward to access location.
Problem, solved.

## License

MIT
