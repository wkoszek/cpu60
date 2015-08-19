all: cpu60

CFLAGS+= -Wall -pedantic

cpu60:	cpu60.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf cpu60
