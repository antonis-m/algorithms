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
long N,i,j,k,l;
struct node * temp;
N=readLong();
struct node ** array;
array= (struct node **)calloc(N+1,sizeof(struct node));
for(i=0; i<=N; i++)
  array[i]=NULL;

for (i=1; i<=N; i++) {   //diavazw input
  j=readLong();
  for (k=0; k<j; k++) {
    temp=(struct node *)malloc(sizeof(struct node));
    l=readLong();
    temp->pos=l;
    temp->next=array[i];
    array[i]=temp;
  } 
}








free(temp);
for(i=0; i<=N; i++)
  free(array[i]);
free(array);
return 0;
}
