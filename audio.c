#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024
#define NUM_CHANNELS 1

// Callback function to be called by the PortAudio library
int paCallback(const void *inputBuffer, void *outputBuffer,
               unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo *timeInfo,
               PaStreamCallbackFlags statusFlags,
               void *userData)
{
  // Cast the input and output buffers to short arrays
  const short *in = (const short*)inputBuffer;
  short *out = (short*)outputBuffer;

  // Copy the audio data from the input to the output buffer
  memcpy(out, in, framesPerBuffer * NUM_CHANNELS * sizeof(short));

  return paContinue;
}

int main()
{
  // Initialize the PortAudio library
  PaError err = Pa_Initialize();
  if (err != paNoError) {
    printf("Error initializing PortAudio: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Open an audio stream for input and output
  PaStream *stream;
  err = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, NUM_CHANNELS,
                             paInt16, SAMPLE_RATE, FRAMES_PER_BUFFER,
                             paCallback, NULL);
  if (err != paNoError) {
    printf("Error opening audio stream: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Start the audio stream
  err = Pa_StartStream(stream);
  if (err != paNoError) {
    printf("Error starting audio stream: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Wait for the user to press a key
  getchar();

  // Stop the audio stream
  err = Pa_StopStream(stream);
  if (err != paNoError) {
    printf("Error stopping audio stream: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Close the audio stream
  err = Pa_CloseStream(stream);
  if (err != paNoError) {
    printf("Error closing audio stream: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Terminate the PortAudio library
  err = Pa_Terminate();
  if (err != paNoError) {
    printf("Error terminating PortAudio: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  return 0;
}
