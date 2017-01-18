## An ESP8266 (Wemos D1 Mini) based Pushbutton for home automatisation

This Button can differentiate between three different actions (Click, DoubleClick and LongPress) and send an event to the MQTT Broker. I use this to control my MiLight system with the help of Node-Red.

Software requirements:
* Homie framework 1.5.0 (https://github.com/marvinroger/homie-esp8266)
* OneButton librarby (https://github.com/mathertel/OneButton)
* Arduino ESP8266 filesystem uploader (https://github.com/esp8266/arduino-esp8266fs-plugin) for configuration upload, see https://homie-esp8266.readme.io/v2.0.0/docs/json-configuration-file
* any MQTT-broker, i am using Mosquitto (https://mosquitto.org/)

Hardware:
* WEMOS D1 mini pro (https://www.wemos.cc/product/d1-mini-pro.html)
* WEMOS D1 mini 1-Button Shield (https://www.wemos.cc/product/1-button-shield.html)

You probably need to change the folliwing lines:
in /data/homie/config.json
* Change your WiFi SSID and password here
  ```yml
  "wifi": {
        "ssid": "xxx",
        "password": "yyy"
    }
  ```
* Change this to your MQTT-broker IP
  ```yml
  "mqtt": {
        "host": "192.168.178.34"
  }
  ```

and in MQTTLightButtonSwitch3State.ino
* If your button is attached to a different pin, change the name here:
```c
  OneButton button(D3, true);
```

Upload the configuration in Arduino IDE with Tools->ESP8266 Sketch Data Upload. Compile and Upload the code with Arduino IDE to your ESP8266.
