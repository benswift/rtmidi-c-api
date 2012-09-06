/* A C API for interacting with the RtMidi library */

// to compile (on OSX):
// clang++ -dynamiclib -Wall -D__MACOSX_CORE__ -o librtmidi.dylib RtMidi.cpp RtMidi-C-Api.cpp -framework CoreMIDI -framework CoreAudio -framework CoreFoundation

#include <sys/types.h>
#include <iostream>
#include <vector>
#include <string>
#include "RtMidi.h"

#ifdef __cplusplus
extern "C" {
#endif

// error codes

enum rtErr {
     RTMIDI_NOERROR,
     RTMIDI_ERROR
};

struct outDevice {
     RtMidiOut* ptr;
};

typedef int32_t apiType;

// midi device info

int32_t getCurrentApi( outDevice* dev );
int64_t getPortCount( outDevice* dev );
int8_t* getPortName( outDevice* dev, int64_t portNumber );

// midi out devices

rtErr newMidiOutDevice( outDevice* dev, apiType api, char* clientName );
rtErr openPort( outDevice* dev, int64_t portNumber, char* portName );
rtErr openVirtualPort( outDevice* dev, char* portName );
rtErr closePort( outDevice* dev );
rtErr sendMessage( outDevice* dev, int64_t messageSize, uint8_t* message );

rtErr deleteMidiOutDevice( outDevice* dev );

// midi input

// rtErr newMidiInDevice( outDevice* dev );

#ifdef __cplusplus
} // extern "C"
#endif
