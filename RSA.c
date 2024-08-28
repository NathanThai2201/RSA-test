#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

/*
supports ints up to 50
*/

int coprime(int a);

int main(int argc, char *argv[]) {
  // primes
  int p = 2521;
  int q = 5503;
  // n calc
  int n = p*q;
  int temp = (p-1)*(q-1);
  int e = coprime(temp);
  
  char inp[100];
  printf("Enter an integer: ");
  fgets(inp, sizeof(inp),stdin);
  int inp2 = atoi(inp);

  double e1 = pow((double) inp2,(double) e);
  // printf("pow: %d %d %d %f\n", inp2, e, n, e1);
  
  long long e2 = (long long) ((long long) e1) % n;
  printf("Encryted integer %lld\n",e2);

  // (e * d) % temp = 1
}

int coprime(int a) {
  int b;
  for (b = 1; b<a;  b++) {
    int ans = a % b;
    if (ans != 0) {
        printf("first %d\n", b);
        return b;
    }
  }
  return 0;
}

