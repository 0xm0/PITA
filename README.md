# The PITA Programming Language 

## About PITA
PITA is an esoteric programming that is based off of brainfuck. It's more intuitive, with more descriptive keywords, and it shares the same tape size of 30K bytes. Programmers have a lot of memory to work with, so they can design all sorts of applications. PITA is also turing complete. The challenging part of programming in PITA, is that programmers are not allowed to write comments, the interpreter forbids comments as it makes programming easier.<br/>

## Installation (Linux)
1. ``git clone https://github.com/0xm0/PITA.git``<br/>
2. ``cd PITA``<br/>
3. ``make``<br/>
4. ``./PITA my_PITA_program.pita``<br/>

## The Language Basics
| Instruction | Description |
| --- | --- |
| `pitabegin` | enters a while loop |
| `pitaend` | marks the end of the loop |
| `pitaplus` | increments the current value of the memory pointer (cell)|
| `pitasub` | decrements the current value of the memory pointer (cell) |
| `pitashiftfront` | moves the memory pointer to the next cell |
| `pitashiftback` | moves the memory pointer backwards to the previous cell|
| `pitain` | user input, reads a character to stdin |
| `pitaout` | outputs current value in the cell to stdout |
| `pitaset` | sets the memory pointer to 0 |

### "Hello World" In PITA
- HellWorld.pita <br/>
```
pitashiftfront pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitabegin pitashiftback pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitashiftfront pitasub pitaend pitashiftback pitaout
pitashiftfront pitaplus pitaplus pitaplus pitaplus pitabegin pitashiftback pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitashiftfront pitasub pitaend pitashiftback pitaplus pitaout
pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaout pitaout
pitaplus pitaplus pitaplus pitaout
pitashiftfront pitashiftfront pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitabegin pitashiftback pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitashiftfront pitasub pitaend pitashiftback pitaplus pitaplus pitaout
pitasub pitasub pitasub pitasub pitasub pitasub pitasub pitasub pitasub pitasub pitasub pitasub pitaout
pitashiftfront pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitabegin pitashiftback pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitashiftfront pitasub pitaend pitashiftback pitaplus pitaout
pitashiftback pitaout
pitaplus pitaplus pitaplus pitaout
pitasub pitasub pitasub pitasub pitasub pitasub pitaout
pitasub pitasub pitasub pitasub pitasub pitasub pitasub pitasub pitaout
pitashiftfront pitashiftfront pitashiftfront pitaplus pitaplus pitaplus pitaplus pitabegin pitashiftback pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitaplus pitashiftfront pitasub pitaend pitashiftback pitaplus pitaout
```
Output: ``Hello, World!``<br/>

### License
           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004
 
Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.
 
           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
  TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

 0. You just DO WHAT THE FUCK YOU WANT TO.
