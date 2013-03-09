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
void IncreaseKey(heap *,long,long long);
long ExtractMin(heap *,long long );

int main() {

long long int N,M,K,L,B;
long int i,j;
edge * array;
long int * track;
long int * gas;
long int * nodes;
heap * list;
long int * heap_pos;
long int * edge_pos;

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





long int k;
heap_pos=(long *)calloc(N+1,sizeof(long int));
for (k=0; k<=N; k++) {
   i=list[k].node;
   heap_pos[i]=k; 
  }

edge_pos=(long *)calloc(N+1,sizeof(long int));
edge_pos[0]=0;
for(k=1; k<=N; k++){


  


k=N;
//for (k=N; k>=0; k--)
//i=ExtractMin(list,k);



free(edge_pos);
free(heap_pos);
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
while ((((i-1)/2) != 0) && ( k < list[(i-1)/2].key))
  swap(list,i,((i-1)/2));

}


void IncreaseKey(heap * list, long i,long long N) {   // to i antistoixei sto x tou paradeigmatos
heap c;
while ((2*i+1 <= N) && (2*i+2 <=N)) {    //den eimai toso sigouros gi afto to &&
  if (list[2*i+1].key <= list[2*i+2].key) { 
    c=list[2*i+1];
    if (c.key <= list[i].key) {
    swap(list,i,2*i+1);
    i=2*i+1;
   } else break;
  }

  else {
    c=list[2*i+2];
    if (c.key <= list[i].key) {
    swap(list,i,(2*i+2));
    i=2*i+2;
     } else break;
    }
  }
}


long ExtractMin(heap * list, long long n) {      //n to megethos tis enapomeinousas listas
  printf("%ld %ld \n",list[0].node, list[0].key);
  swap(list,0,n);
  IncreaseKey(list, 0, n-1);
  return 1;
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
