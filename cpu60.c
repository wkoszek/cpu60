#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define	MAX(a, b)	((a) > (b)) ? (a) : (b)

int
main(int argc, char **argv)
{
	uint8_t	regs[8];
	char	buf[1000];
	int	i, i0, i1, i2, v2, o, reset_perform;

	reset_perform = 0;
	while ((o = getopt(argc, argv, "r")) != -1) {
		switch (o) {
		case 'r':
			reset_perform++;
			break;
		}
	}

	buf[0] = '\0';
	do {
		if (sscanf(buf, "mov r%d,r%d", &i0, &i1) == 2) {
			regs[i0 % 8] = regs[i1 % 8];
		}
		if (sscanf(buf, "add r%d,r%d,r%d", &i0, &i1, &i2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] + regs[i2 % 8];
		}
		if (sscanf(buf, "addi r%d,r%d,%d", &i0, &i1, &v2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] + v2;
		}
		if (sscanf(buf, "sub r%d,r%d,r%d", &i0, &i1, &i2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] - regs[i2 % 8];
		}
		if (sscanf(buf, "subi r%d,r%d,%d", &i0, &i1, &v2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] - v2;
		}
		if (sscanf(buf, "and r%d,r%d,r%d", &i0, &i1, &i2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] & regs[i2 % 8];
		}
		if (sscanf(buf, "andi r%d,r%d,%d", &i0, &i1, &v2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] & v2;
		}
		if (sscanf(buf, "or r%d,r%d,r%d", &i0, &i1, &i2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] | regs[i2 % 8];
		}
		if (sscanf(buf, "ori r%d,r%d,%d", &i0, &i1, &v2) == 3) {
			regs[i0 % 8] = regs[i1 % 8] | v2;
		}
		buf[MAX(0, strlen(buf) - 1)] = 0;
		for (i = 0; i < 8; i++) {
			printf("reg%1d=%02x %s %s", i, regs[i],
			    i == 7 ? buf : "",
			    i == 7 ? "\n":" ");
		}
	} while (fgets(buf, sizeof(buf), stdin));
}
