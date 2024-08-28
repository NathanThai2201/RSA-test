#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

/*
supports ints up to 34 ovoiding max long long overflow when decrypt
*/

int coprime(int a);

int main(int argc, char *argv[]) {
  // primes
  int p = 5;
  int q = 7;
  // n calc
  int n = p*q;
  int temp = (p-1)*(q-1);
  int e = coprime(temp);
  
  char inp[100];
  printf("Enter an integer: ");
  fgets(inp, sizeof(inp),stdin);
  int inp2 = atoi(inp);

  // *encrypt
  double e1 = pow((double) inp2,(double) e);
  //printf("pow: %d %d %d %f\n", inp2, e, n, e1);
  
  long long e2 = (long long) ((long long) e1) % n;
  printf("Encryted integer %lld\n",e2);



  // *decrypt
  // (e * d) % temp = 1
  long long d = 0;
  long long ans = 0;
  while (ans != 1) {
    d++;
    ans = (((long long) e) * d) % ((long long) temp);
  }

  long double e3 = (long double) pow((double) e2,(double) d);
  long long e4 = (long long) e3 % (long long) n;
  printf("Decryted integer %lld\n",e4);
}

int coprime(int a) {
  int b;
  for (b = 1; b<a;  b++) {
    int ans = a % b;
    if (ans != 0) {
        return b;
    }
  }
  return 0;
}

