# ARay

## the Array-centric RAYcaster

### What is ARay?

ARay is an attempt at a first-person 360° 3d engine, using C89 and a few arrays.

### The state of ARay

ARay is currently in a VERY early phase; it can't even render texturless blocks
in a single frame yet, due to my(Gip-Gip's) terrible debugging skills. It's
current features include:

 * SDL screen writing
 * Sorted code
 * Map/config loading

Future features include:

 * A working renderer
 * Texture loading
 * Keyboard I/O
 * DOS compatability (it currently compiles under Turbo C without writing to the
screen)
 * Windows compatability

### Things that need to be fixed

 * Renderer source code

### Building ARay

First, you need SDL, and you can aquire that by

 * Running `sudo apt-get install libsdl-dev` on Ubuntu/Debian
 * Building the source from the SDL website(ARay uses SDL 1.2, not SDL 2)

After you have downloaded the source, change into the master directory
(aray-master if you downloaded from git) and run `./build`

### How you can help

I would appreciate help in many ways. As always, people who contribute go inside
of AUTHORS.TXT (it will be created when I'm not the only one contributing).

You can help by:

 * Fixing things listed in the *What needs to be fixed?* section
 * Documenting the source code
 * Suggesting new features
 * Highlighting bugs

### What NOT to do

I feel like this is very importiant, as it would suck for every one.

**DONT**:

 * Submit code in any other language than C89(ANSI C 1989), the only exception
being build scripts.
 * Program utilities for maps/images/etc when the formats are not finished

### Code structure

C files are named after the single function inside of them. If there is no
function, it is named after the general theme of the variables. An example is
main.c, where the main function is located inside of it.

Header files are named after the files that need them, and the needs the header
file provides. An example is messages.h, which defines the messages needed by
the program.
