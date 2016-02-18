/*
 * MP3 Remote receiver template.
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 February, 2016
 * Author: Elliot Godzich
 * http://www.github.com/blueskymonster
 * 
 * Requires https://github.com/z3t0/Arduino-IRremote to be installed.
 * NOTE: As of Arduino 1.6.7, the "RobotIRremote" must be removed
 *       from the default libraries of Arduino in order for the
 *       above library to function correctly.
 *       
 * If you've connected everything correctly, you should be able
 * to view button presses or holds in the Serial Monitor.
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

int last_button_pressed = 0;

int HOLD_CODE = 0xFFFFFFFF;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

/*
 * The following functions get called when you press
 * a button on the MP3 Remote. The first button press
 * calls the function with button_held = false. If you
 * hold the button, it will repeatedly call the function
 * with button_held = true.
 * 
 * Replace the contents with your own code to make things
 * happen when you press buttons!
 */

void power_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding power button...");
  } else {
    Serial.println("Pressed power button.");
  }
}

void mode_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding mode button...");
  } else {
    Serial.println("Pressed mode button.");
  }
}

void mute_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding mute button...");
  } else {
    Serial.println("Pressed mute button.");
  }
}

void play_pause_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding play/pause button...");
  } else {
    Serial.println("Pressed play/pause button.");
  }
}

void skip_back_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding skip back button...");
  } else {
    Serial.println("Pressed skip back button.");
  }
}

void skip_forward_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding skip forward button...");
  } else {
    Serial.println("Pressed skip forward button.");
  }
}

void eq_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding EQ button...");
  } else {
    Serial.println("Pressed EQ button.");
  }
}

void minus_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding minus button...");
  } else {
    Serial.println("Pressed minus button.");
  }
}

void plus_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding plus button...");
  } else {
    Serial.println("Pressed plus button.");
  }
}

void zero_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding 0 button...");
  } else {
    Serial.println("Pressed 0 button.");
  }
}

void crazy_arrows_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding crazy arrows button...");
  } else {
    Serial.println("Pressed crazy arrows button.");
  }
}

void u_slash_sd_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding U/SD button...");
  } else {
    Serial.println("Pressed U/SD button.");
  }
}

void one_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding 1 button...");
  } else {
    Serial.println("Pressed 1 button.");
  }
}

void two_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding 2 button...");
  } else {
    Serial.println("Pressed 2 button.");
  }
}

void three_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding 3 button...");
  } else {
    Serial.println("Pressed 3 button.");
  }
}

void four_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding 4 button...");
  } else {
    Serial.println("Pressed 4 button.");
  }
}

void five_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding 5 button...");
  } else {
    Serial.println("Pressed 5 button.");
  }
}

void six_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding 6 button...");
  } else {
    Serial.println("Pressed 6 button.");
  }
}

void seven_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding 7 button...");
  } else {
    Serial.println("Pressed 7 button.");
  }
}

void eight_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding 8 button...");
  } else {
    Serial.println("Pressed 8 button.");
  }
}

void nine_button(bool button_held) {
  if (button_held) {
    Serial.println("Holding 9 button...");
  } else {
    Serial.println("Pressed 9 button.");
  }
}

void dispatch_button_press(int ir_code) {
  bool button_held = false;
  int button_code = ir_code;
  if (ir_code == HOLD_CODE) {
    button_code = last_button_pressed;
    button_held = true;
  }
  switch (button_code) {
    case 0xFFA25D: power_button(button_held); break;
    case 0xFF629D: mode_button(button_held); break;
    case 0xFFE21D: mute_button(button_held); break;
    case 0xFF22DD: play_pause_button(button_held); break;
    case 0xFF02FD: skip_back_button(button_held); break;
    case 0xFFC23D: skip_forward_button(button_held); break;
    case 0xFFE01F: eq_button(button_held); break;
    case 0xFFA857: minus_button(button_held); break;
    case 0xFF906F: plus_button(button_held); break;
    case 0xFF6897: zero_button(button_held); break;
    case 0xFF9867: crazy_arrows_button(button_held); break;
    case 0xFFB04F: u_slash_sd_button(button_held); break;
    case 0xFF30CF: one_button(button_held); break;
    case 0xFF18E7: two_button(button_held); break;
    case 0xFF7A85: three_button(button_held); break;
    case 0xFF10EF: four_button(button_held); break;
    case 0xFF38C7: five_button(button_held); break;
    case 0xFF5AA5: six_button(button_held); break;
    case 0xFF42BD: seven_button(button_held); break;
    case 0xFF4AB5: eight_button(button_held); break;
    case 0xFF52AD: nine_button(button_held); break;
    default: Serial.println("Unrecognized code!"); break;
  }
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value != HOLD_CODE) {
      last_button_pressed = results.value;
    }
    dispatch_button_press(results.value);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
