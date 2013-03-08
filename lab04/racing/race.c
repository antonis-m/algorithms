#include <stdio.h>
#include <stdlib.h>
#define BSIZE 1<<15
#define INF 100000

long readLong();
typedef struct 
{
  long int begin;
  long int end;
  long int dist;
} edge;

typedef struct 
{ 
  long int node;
  long int key;
} heap;

char buffer[BSIZE];
long bpos=0L,bsize=0L;

int main () {

long long int N,M,K,L,B,i;
edge * array;
long int * track;
long int * gas;
heap * list;

scanf("%lld %lld %lld %lld %lld",&N,&M,&K,&L,&B);
array=(edge *)calloc(M,sizeof(edge));
track=(long int *)calloc(K, sizeof(long int));
gas=(long int *)calloc(B, sizeof(long int ));
list=(heap *)calloc(N+1,sizeof(long int));

for (i=0; i<M; i++) {
   array[i].begin=readLong();
   array[i].end=readLong();
   array[i].dist=readLong();
}

for (i=0; i<K; i++)
   track[i]=readLong();

for (i=0; i<B; i++)
   gas[i]=readLong();

list[0].node=0;
list[0].key=0;

//8a kanw push ka8e kainourio node sto heap. Gia ta venzinadika 8a prepei kapws na dw wste to dist na einai 0

free(array);
free(track);
free(gas);
free(list);
return 0;
}


long readLong() 
{

 	long d= 0L, x=0L;
        char c;
        while(1) {
             if (bpos >= bsize ) {
                 bpos=0;
                 if (feof(stdin)) return x;
                 bsize=fread(buffer,1,BSIZE,stdin);
              }
              c= buffer[bpos++];
              if (c >= '0' && c<= '9') { x=x*10 + (c-'0'); d=1;}
              else if (d==1) return x;
            }
        return -1;
}
