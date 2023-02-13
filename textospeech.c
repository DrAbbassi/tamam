#include </usr/bin/espeak/speak_lib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 0, NULL, 0);
  espeak_SetVoiceByName("en");
  espeak_Synth("Hello, how are you today?", sizeof("Hello, how are you today?"), 0, POS_CHARACTER, 0, espeakCHARS_UTF8, NULL, NULL);
  espeak_Synchronize();
  espeak_Terminate();
  return 0;
}
