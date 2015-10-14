#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define	MAX(a, b)	((a) > (b)) ? (a) : (b)

int
main(int argc, char **argv)
{
	uint32_t	i, i0, i1, i2, v2, reset_perform;
	uint8_t	regs[8];
	char	buf[1000];

	reset_perform = 0;
	if (argc == 2 && (strcmp(argv[1], "-r") == 0)) {
		reset_perform++;
	}
	for (i = 0; i < sizeof(regs)/sizeof(regs[0]); i++) {
		regs[i] = reset_perform ? 0 : rand();
	}

	buf[0] = '\0';
	do {
		if (sscanf(buf, "mov r%u,r%u", &i0, &i1) == 2) {
			regs[i0 % 8] = regs[i1 % 8];
		}
		if (sscanf(buf, "add r%u,r%u,r%u", &i0, &i1, &i2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] + regs[i2 % 8];
		}
		if (sscanf(buf, "addi r%u,r%u,%u", &i0, &i1, &v2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] + v2;
		}
		if (sscanf(buf, "sub r%u,r%u,r%u", &i0, &i1, &i2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] - regs[i2 % 8];
		}
		if (sscanf(buf, "subi r%u,r%u,%u", &i0, &i1, &v2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] - v2;
		}
		if (sscanf(buf, "and r%u,r%u,r%u", &i0, &i1, &i2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] & regs[i2 % 8];
		}
		if (sscanf(buf, "andi r%u,r%u,%u", &i0, &i1, &v2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] & v2;
		}
		if (sscanf(buf, "or r%u,r%u,r%u", &i0, &i1, &i2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] | regs[i2 % 8];
		}
		if (sscanf(buf, "ori r%u,r%u,%u", &i0, &i1, &v2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] | v2;
		}
		buf[MAX(0, (int)(strlen(buf) - 1))] = 0;
		for (i = 0; i < 8; i++) {
			printf("reg%1d=%02x %s %s", i, regs[i],
					i == 7 ? buf : "", i == 7 ? "\n":" ");
		}
	} while (fgets(buf, sizeof(buf), stdin));
	return 0;
}
