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

void swap (heap *,long ,long );
void DecreaseKey (heap *,long ,long,long);
void IncreaseKey(heap *,long, long);
long ExtractMin(heap *);

int main() {

long long int N,M,K,L,B,i,j;
edge * array;
long int * track;
long int * gas;
long int * nodes;
heap * list;

scanf("%lld %lld %lld %lld %lld",&N,&M,&K,&L,&B);
j=0;
array=(edge *)calloc(M,sizeof(edge));
track=(long int *)calloc(K, sizeof(long int));
gas=(long int *)calloc(B, sizeof(long int ));
list=(heap *)calloc(N+1,sizeof(heap));
nodes=(long int *)calloc(N,sizeof(long int));

for (i=0; i<M; i++) {
   array[i].begin=readLong();
   array[i].end=readLong();
   array[i].dist=readLong();
}

for (i=0; i<K; i++)
   track[i]=readLong();
for (i=0; i<B; i++)
   gas[i]=readLong();
for (i=0; i<N; i++)
   nodes[i]=i+1;

list[0].node=0;
list[0].key=0;
  
for(i=0; i<B; i++) {
 list[i+1].node=gas[i];
 list[i+1].key=0;
 nodes[gas[i]-1]=-1;
}

for(i=B+1; i<=N; i++) {
 if (nodes[j]!=-1) {
   list[i].node=nodes[j];
   list[i].key=INF;
   j++;
} else {
   while(nodes[j]==-1 && j<N) 
    j++;
   list[i].node=nodes[j];
   list[i].key=INF;
   j++;
 }    
} 

free(nodes);




free(array);
free(track);
free(gas);
free(list);
return 0;
}

void swap (heap * list, long a,long b){
heap temp;

temp=list[b];
list[b]=list[a];
list[a]=temp;
}

void DecreaseKey (heap * list, long i, long x, long k) {
list[i].node=x;
list[i].key=k;
while (((i/2) != 0) && ( k < list[i/2].key))
  swap(list,i,(i/2));

}


/*
void IncreaseKey(long * list, long x,long k) {
long int c;
list[x]=k;
while ((2*x <= N) || (2*x+1 <=N)) {
  if (list[2*x] <= list[2*x+1]) { 
    c=list[2*x];
    swap(list,x,2*x);
  }
  else {
    c=list[2*x+1];
    swap(list,x,(2*x+1));
    }
  }
}

*/
//long ExtractMin(long * list) {



//} 

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
