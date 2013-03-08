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


char buffer[BSIZE];
long bpos=0L,bsize=0L;

void swap (long *,long ,long );
void DecreaseKey (long *,long ,long);
void insert(long *,long,long);   //to prwto long einai i 8esi stin opoia 8a ginei to insert
int main() {

long long int N,M,K,L,B,i;
edge * array;
long int * track;
long int * gas;
long * list;

scanf("%lld %lld %lld %lld %lld",&N,&M,&K,&L,&B);
array=(edge *)calloc(M,sizeof(edge));
track=(long int *)calloc(K, sizeof(long int));
gas=(long int *)calloc(B, sizeof(long int ));
list=(long int *)calloc(N+1,sizeof(long int));

for (i=0; i<M; i++) {
   array[i].begin=readLong();
   array[i].end=readLong();
   array[i].dist=readLong();
}

for (i=0; i<K; i++)
   track[i]=readLong();

for (i=0; i<B; i++)
   gas[i]=readLong();

list[0]=0;
for(i=1; i<=B; i++)
 insert(list,i,0);


free(array);
free(track);
free(gas);
free(list);
return 0;
}

void swap (long * list, long a,long b){
long temp;

temp=list[b];
list[b]=list[a];
list[a]=temp;
}

void DecreaseKey (long * list, long x, long k) {
list[x]=k;
while (((x/2) != 0) && ( k < list[x/2]))
  swap(list,x,(x/2));

}

void insert(long * list,long x, long k) {
list[x]=k;
DecreaseKey(list,x,k);

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
