CC = gcc
CFLAGS = -Wall -std=c99 


RSA:	RSA.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f RSA core CORE RSA.out
