/* This example uses the Zumo32U4PrimeBuzzer class to play a
series of notes on the buzzer.

This example demonstrates the use of the playFrequency(),
playNote(), and playFromProgramSpace() functions, which play
entirely in the background, requiring no further action from the
user once the function is called.  The CPU is then free to
execute other code while the buzzer plays.

This example also shows how to use the stopPlaying() function to
stop the buzzer, and it shows how to use the isPlaying() function
to tell whether the buzzer is still playing or not. */

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Buzzer buzzer;

// Store this song in program space using the PROGMEM macro.
// Later we will play it directly from program space, bypassing
// the need to load it all into RAM first.
const char fugue[] PROGMEM =
  "! O5 L16 agafaea dac+adaea fa<aa<bac#a dac#adaea f";

void setup()       // run once, when the sketch starts
{
}

void loop()        // run over and over again
{
  // Start playing a tone with frequency 440 Hz at maximum
  // volume (15) for 200 milliseconds.
  buzzer.playFrequency(440, 200, 15);

  // Delay to give the tone time to finish.
  delay(1000);

  // Start playing note A in octave 4 at maximum volume
  // volume (15) for 2000 milliseconds.
  buzzer.playNote(NOTE_A(4), 2000, 15);

  // Wait for 200 ms and stop playing note.
  delay(200);
  buzzer.stopPlaying();

  delay(1000);

  // Start playing a fugue from program space.
  buzzer.playFromProgramSpace(fugue);

  // Wait until it is done playing.
  while(buzzer.isPlaying()){ }

  delay(1000);
}
