#include <Bounce.h>

const int buttonPin = 12;
Bounce pushbutton = Bounce(buttonPin, 10);  // 10 ms debounce

void KeyboardPressAndRelease(int key) {
  Keyboard.press(key);
  Keyboard.release(key);
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (pushbutton.update()) {
    if (pushbutton.fallingEdge()) {
      Keyboard.print("Hello Matt");
      Keyboard.press(MODIFIERKEY_ALT);
      KeyboardPressAndRelease(KEY_E);
      KeyboardPressAndRelease(KEY_M);
      Keyboard.release(MODIFIERKEY_ALT);
      KeyboardPressAndRelease(KEY_ENTER);
    }
  } 
}

