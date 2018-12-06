#include <Bounce.h>

const int buttonPin = 12;
Bounce pushbutton = Bounce(buttonPin, 10);  // 10 ms debounce

void KeyboardPressAndRelease(int key) {
  Keyboard.press(key);
  Keyboard.release(key);
}

void ToggleBold() {
  // unfortunately I can't force it on or off, only toggle!
  KeyboardPressAndRelease(MODIFIERKEY_ALT);
  Keyboard.print("h1"); // bold (hopefully)
}

void Purple() {
  KeyboardPressAndRelease(MODIFIERKEY_ALT);
  Keyboard.print("hfcm");
  KeyboardPressAndRelease(KEY_RIGHT);
  KeyboardPressAndRelease(KEY_TAB);
  KeyboardPressAndRelease(KEY_TAB);
  KeyboardPressAndRelease(KEY_TAB);
  KeyboardPressAndRelease(KEY_TAB);
  Keyboard.print("109");
  KeyboardPressAndRelease(KEY_TAB);
  Keyboard.print("32");
  KeyboardPressAndRelease(KEY_TAB);
  Keyboard.print("119");
  KeyboardPressAndRelease(KEY_ENTER);
}

void Black() {
  KeyboardPressAndRelease(MODIFIERKEY_ALT);
  Keyboard.print("hfca");
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (pushbutton.update()) {
    if (pushbutton.fallingEdge()) {
      Purple();
      
      KeyboardPressAndRelease(MODIFIERKEY_ALT);
      Keyboard.println("hffverdana");
      KeyboardPressAndRelease(MODIFIERKEY_ALT);
      Keyboard.println("hfs9");
      ToggleBold();
      Keyboard.println("Chris Eubanks");
      
      KeyboardPressAndRelease(MODIFIERKEY_ALT);
      Keyboard.println("hfs8");
      ToggleBold();
      Keyboard.println("Electrical Engineer, Neuromodulation");
      Keyboard.println("United States");
      Keyboard.println("");

      Black();
      ToggleBold();
      Keyboard.print("O ");
      ToggleBold();
      Keyboard.println("+1 281 727 2603");
      Keyboard.println("");

      Purple();
      Keyboard.println("chris.eubanks@livanova.com");
      Keyboard.println("www.livanova.com");
      delay(500); // debouncing still isn't perfect
    }
  } 
}
