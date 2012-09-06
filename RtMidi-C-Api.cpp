// rtmidi-C-Api.cpp

#include "RtMidi-C-Api.h"

int32_t getCurrentApi( outDevice* dev ){
     try {
          return (int32_t)dev->ptr->getCurrentApi();
     }
     catch ( RtError &error ) {
          error.printMessage();
          return (int32_t)100;
     }
};

int64_t getPortCount( outDevice* dev ){
     try {
          return (int64_t)dev->ptr->getPortCount();
     }
     catch ( RtError &error ) {
          error.printMessage();
          return (int64_t)0;
     }
};

int8_t* getPortName( outDevice* dev, int64_t portNumber ){
     try {
          return (int8_t*)dev->ptr->getPortName(portNumber).data();
     }
     catch ( RtError &error ) {
          error.printMessage();
          char* name = "no name";
          return (int8_t*)name;
     }
};

// midi out devices

rtErr newMidiOutDevice( outDevice* dev, apiType api, char* clientName ){
     try {
          std::string name(clientName);
          dev->ptr = new RtMidiOut((RtMidi::Api)api, name);
          return RTMIDI_NOERROR;
     }
     catch ( RtError &error ) {
          error.printMessage();
          return RTMIDI_ERROR;
     }
};

rtErr openPort( outDevice* dev, int64_t portNumber, char* portName ){
     try {
          std::string name(portName); 
          dev->ptr->openPort(portNumber, name);
          return RTMIDI_NOERROR;
     }
     catch ( RtError &error ) {
          error.printMessage();
          return RTMIDI_ERROR;
     }
};

rtErr openVirtualPort( outDevice* dev, char* portName ){
     try {
          std::string name(portName); 
          dev->ptr->openVirtualPort(name);
          return RTMIDI_NOERROR;
     }
     catch ( RtError &error ) {
          error.printMessage();
          return RTMIDI_ERROR;
     }
};

rtErr closePort( outDevice* dev ){
     try {
          dev->ptr->closePort();
          return RTMIDI_NOERROR;
     }
     catch ( RtError &error ) {
          error.printMessage();
          return RTMIDI_ERROR;
     }
};

rtErr sendMessage( outDevice* dev, int64_t messageSize, uint8_t* message ){
     try {
          std::vector<uint8_t> msgVector;
          for (int i = 0; i < (int)messageSize; ++i)
          {
               msgVector.push_back(message[i]);
          }
          dev->ptr->sendMessage(&msgVector);
          return RTMIDI_NOERROR;
     }
     catch ( RtError &error ) {
          error.printMessage();
          return RTMIDI_ERROR;
     }
};

rtErr deleteMidiOutDevice( outDevice* dev ){
     try {
          delete dev->ptr;
          return RTMIDI_NOERROR;
     }
     catch ( RtError &error ) {
          error.printMessage();
          return RTMIDI_ERROR;
     }
}
