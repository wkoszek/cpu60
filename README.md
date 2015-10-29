# Simple CPU model written in 60 lines of code

[![Build Status](https://travis-ci.org/wkoszek/cpu60.svg)](https://travis-ci.org/wkoszek/cpu60)

CPU60 is a simple CPU model written in 60 lines of C code.

It supports 8 registers and several simple instructions: `mov`, `add`,
`addi`, `sub`, `subi`, `and`, `andi`, `or`, `ori` instructions. Following
each instruction is the CPU register dump. By default input is read from the
standard input.

Flag `-r` might be passed to simulate the proper reset of the CPU. Upon
reset, all registers are filled with 0's. Without `-r`, the values of the
registers are undefined, and your program instructions can't depend on
register's content.

# How to build

To build:

	make

# How to run

Either manually:

	% ./cpu60
	reg0=a7   reg1=f1   reg2=d9   reg3=2a   reg4=82   reg5=c8   reg6=d8   reg7=fe
	sub r0,r0,r0
	reg0=00   reg1=f1   reg2=d9   reg3=2a   reg4=82   reg5=c8   reg6=d8   reg7=fe sub r0,r0,r0
	sub r1,r1,r1
	reg0=00   reg1=00   reg2=d9   reg3=2a   reg4=82   reg5=c8   reg6=d8   reg7=fe sub r1,r1,r1
	ori r0,r0,1
	reg0=01   reg1=00   reg2=d9   reg3=2a   reg4=82   reg5=c8   reg6=d8   reg7=fe ori r0,r0,1
	ori r1,r1,2
	reg0=01   reg1=02   reg2=d9   reg3=2a   reg4=82   reg5=c8   reg6=d8   reg7=fe ori r1,r1,2
	add r2,r0,r1
	reg0=01   reg1=02   reg2=03   reg3=2a   reg4=82   reg5=c8   reg6=d8   reg7=fe add r2,r0,r1

Or from file:

	% cpu60 < file

Where file can have any valid opcodes.

# How to test

To unit test the model, hit:

	make test

# Author

- Wojciech Adam Koszek, [wojciech@koszek.com](mailto:wojciech@koszek.com)
- [http://www.koszek.com](http://www.koszek.com)
