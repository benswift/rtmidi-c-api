# C API for the RtMidi library

A C API for interfacing with the (C++)
[RtMidi library](http://music.mcgill.ca/~gary/rtmidi/) by Gary P.
Scavone. This wrapper allows RtMidi to be compiled as a C shared
library. This may be useful when calling a C++ library isn't an
option.

# Installation

1. Download the [RtMidi 2.0.1 source](http://www.music.mcgill.ca/~gary/rtmidi/index.html#download)
2. Copy the `RtMidi-C-Api.h`/`RtMidi-C-Api.c` files from this repo into the RtMidi source directory
3. Build the shared library: this can be done the easy way, or the
   hard way.

*Easy way*

If you're on OSX, or Linux (using ALSA), you can just use the
`make-cshlib` script

```
./make-cshlib
```

*Hard way*

The RtMidi page
[has some instructions](http://www.music.mcgill.ca/~gary/rtmidi/index.html#compiling)
for how to compile and link against the RtMidi classes. You will need
to specify the MIDI API to link against. Here are some examples which
may cover your use case:

**OS X**
```
g++ -dynamiclib -Wall -D__MACOSX_CORE__ -o librtmidi.dylib RtMidi.cpp RtMidi-C-Api.cpp -framework CoreMIDI -framework CoreAudio -framework CoreFoundation
```
**Linux** (ALSA)
```
g++ -shared -fPIC -Wall -D__LINUX_ALSA__ -o  -o librtmidi.so RtMidi.cpp RtMidi-C-Api.cpp -lasound -lpthread
```
**Windows**
If you compile it on Windows, send me the build settings and I'll
include them here.  It should work fine, I just haven't tried it
myself.

# Licence

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation files
(the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

Any person wishing to distribute modifications to the Software is
asked to send the modifications to the original developer so that
they can be incorporated into the canonical version.  This is,
however, not a binding provision of this license.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
