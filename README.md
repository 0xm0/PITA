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
GLWTS License <br/>

  GLWTS(Good Luck With That Shit) Public License
            Copyright (c) Every-fucking-one, except the Author

Everyone is permitted to copy, distribute, modify, merge, sell, publish,
sublicense or whatever the fuck they want with this software but at their
OWN RISK.

                             Preamble

The author has absolutely no fucking clue what the code in this project
does. It might just fucking work or not, there is no third option.


                GOOD LUCK WITH THAT SHIT PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION, AND MODIFICATION

  0. You just DO WHATEVER THE FUCK YOU WANT TO as long as you NEVER LEAVE
A FUCKING TRACE TO TRACK THE AUTHOR of the original product to blame for
or held responsible.

IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

Good luck and Godspeed.
