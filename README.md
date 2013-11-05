# C API for the RtMidi library

A C API for interfacing with the (C++)
[RtMidi library](http://music.mcgill.ca/~gary/rtmidi/) by Gary P.
Scavone. This wrapper allows RtMidi to be compiled as a C shared
library. 

The C API isn't complete, it is fit-for-purpose, but doesn't have all
the features of the C++ one. If you can use C++, you probably
should---but this C wrapper may be useful when calling a C++ library
isn't an option.

# Installation

There are a couple of makefiles which should make building the shared
lib easy.

- If you're on **OSX**, use `Makefile-osx`
- If you're on **Linux** (using ALSA), use `Makefile-linux`

If you manage to compile it on **Windows**, send me the build
settings/commands you used and I'll include them here. It should work
fine, I just haven't tried it myself.

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
