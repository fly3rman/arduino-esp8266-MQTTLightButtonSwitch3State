Up#include <Homie.h>
#include "OneButton.h"

const int PIN_BUTTON = D3; // Because on Wemos Button Shield its the D3 pin
const int ledPin = BUILTIN_LED;
int ledState = LOW;
unsigned long buttonPressTimeStamp;

OneButton button(D3, true);
HomieNode buttonNode("1", "button");

void loopHandler() {
}

void oneClick() {
  Serial.print("singleclick!");
  Homie.setNodeProperty(buttonNode, "singleclick", "true", false);
} 

void doubleClick() {
  Serial.print("doublelick!");
 Homie.setNodeProperty(buttonNode, "doubleclick", "true", false);
}
 
// This function will be called once, when the button1 is released after beeing pressed for a long time.
void longPressStart() {
  Serial.print("longpress!");
  Homie.setNodeProperty(buttonNode, "longpress", "true", false);
} 

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  digitalWrite(PIN_BUTTON, HIGH);
  button.attachClick(oneClick);
  button.attachDoubleClick(doubleClick);
  button.attachLongPressStart(longPressStart);
  Homie.setFirmware("awesome-button", "1.0.0");
  Homie.registerNode(buttonNode);
  Homie.setLoopFunction(loopHandler);
  Homie.setup();
}

void loop() {
  Homie.loop();
  button.tick();
}
