#include <stdio.h>
#include <stdlib.h>
#define BSIZE 1<<15

typedef struct node {
   long pos;
   struct node * next;
};


char buffer[BSIZE];
long bpos = 0L, bsize = 0L;

long readLong()
{
 long d = 0L, x = 0L;
 char c;

 while (1)  {
  if (bpos >= bsize) {
   bpos = 0;
   if (feof(stdin)) return x;
     bsize = fread(buffer, 1, BSIZE, stdin);
   }
   c = buffer[bpos++];
   if (c >= '0' && c <= '9') { x = x*10 + (c-'0'); d = 1; }
   else if (d == 1) return x;
 }
return -1;
}

int main () {
long N;
N=readLong();
struct node ** array;
array= (struct node **)malloc(N*sizeof(struct node));




free(array);
return 0;
}
