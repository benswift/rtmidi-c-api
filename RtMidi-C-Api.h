/* A C API for interacting with the RtMidi library */

#include <sys/types.h>
#include <iostream>
#include <vector>
#include <string>
#include "RtMidi.h"

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

int64_t getCurrentApi( outDevice* dev );
int64_t getPortCount( outDevice* dev );
int8_t* getPortName( outDevice* dev, int64_t portNumber );

// midi out devices

rtErr newMidiOutDevice( outDevice* dev, apiType api, char* clientName );
rtErr openPort( outDevice* dev, int64_t portNumber, char* portName );
rtErr closePort( outDevice* dev );
rtErr sendMessage( outDevice* dev, int8_t* message );

rtErr deleteMidiOutDevice( outDevice* dev );

// midi input

// rtErr newMidiInDevice( outDevice* dev );
