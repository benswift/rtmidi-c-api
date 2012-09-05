// rtmidi-C-Api.cpp

#include "RtMidi-C-Api.h"

int64_t getCurrentApi( outDevice* dev ){
     try {
          return dev->ptr->getCurrentApi();
     }
     catch ( RtError &error ) {
          error.printMessage();
          return (int64_t)100;
     }
};

int64_t getPortCount( outDevice* dev ){
     return (int64_t)dev->ptr->getPortCount();
};

int8_t* getPortName( outDevice* dev, int64_t portNumber ){
     return (int8_t*)dev->ptr->getPortName(portNumber).data();
};

// midi out devices

rtErr newMidiOutDevice( outDevice* dev, apiType api, char* clientName ){
     try {
          // std::string name(clientName);
          dev->ptr = new RtMidiOut((RtMidi::Api)api);
          return RTMIDI_NOERROR;
     }
     catch ( RtError &error ) {
          error.printMessage();
          return RTMIDI_ERROR;
     }
};

rtErr openPort( outDevice* dev, int64_t portNumber, char* portName ){
     try {
          // std::string name(portName); 
          // name.assign(portName);
          dev->ptr->openPort(portNumber);
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
