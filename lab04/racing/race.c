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

typedef struct linked
{
  long int end;
  long int dist;
  struct linked * next; 
};

char buffer[BSIZE];
long bpos=0L,bsize=0L;

void swap_int (long *,long ,long); 
void swap (heap *,long ,long );
void DecreaseKey (heap *,long *,long);
void IncreaseKey(heap *,long *,long,long long);
heap ExtractMin(heap *,long *,long long );
long int chose_pivot (long ,long);
void quicksort (long *, long, long);
void swap_quick (long *, long *); 

int main() {

long long int N,M,K,L,B;
long int i,j;
edge * array;
long int * track;
long int * gas;
long int * nodes;
heap * list;
long int * heap_pos;
struct linked ** adj_list;
long int * D, * Q;

scanf("%lld %lld %lld %lld %lld",&N,&M,&K,&L,&B);
array=(edge *)calloc(M,sizeof(edge));
track=(long int *)calloc(K, sizeof(long int));
gas=(long int *)calloc(B, sizeof(long int ));
list=(heap *)calloc(N+1,sizeof(heap));
nodes=(long int *)calloc(N,sizeof(long int));
D=(long *)malloc((N+1)*sizeof(long int));
Q=(long *)malloc((N-2)*sizeof(long int));

adj_list=(struct linked **)malloc((N+1)*sizeof(struct linked *));
struct linked * temp, * temp2;
for(i=0; i<=N; i++)
  adj_list[i]=NULL;

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

for(i=0; i<M; i++) {    //diavase kai vale ston pinaka lista
  temp=(struct linked *)malloc(sizeof(struct linked));
  temp2=(struct linked *)malloc(sizeof(struct linked));
  temp->next=NULL;
  j=array[i].begin;
  temp->end=array[i].end;
  temp->dist=array[i].dist;
  temp->next=adj_list[j];
  adj_list[j]=temp;

  temp2->next=NULL;
  j=array[i].end;
  temp2->end=array[i].begin;
  temp2->dist=array[i].dist;
  temp2->next=adj_list[j];
  adj_list[j]=temp2;
}

// temp=adj_list[4];
// while(temp!=NULL ){ printf("%ld ",temp->end); temp=temp->next;}
//printf("\n");
list[0].node=0;
list[0].key=0;
  
for(i=0; i<B; i++) {
 list[i+1].node=gas[i];
 list[i+1].key=0;
 nodes[gas[i]-1]=-1;
}

j=0;
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
   heap_pos[i]=k;  // o komvos i einai sti thesi k tou heap 
  }

for(i=0; i<=N; i++) D[i]=INF;
for(i=0; i<B; i++) D[gas[i]]=0;
D[0]=0;


heap c;
for (k=N; k>=0; k--) {

 c=ExtractMin(list,heap_pos,k);
  D[c.node]=c.key;
  // for all nodes starting from c.node
  temp=adj_list[c.node];
  while(temp!=NULL) {
    if (D[c.node]+temp->dist < D[temp->end]) { 
        D[temp->end]=D[c.node]+temp->dist;
        list[heap_pos[temp->end]].key = D[c.node]+temp->dist;
        DecreaseKey(list,heap_pos,heap_pos[temp->end]); 
      }
    temp=temp->next;    
  }// printf( "same round after controls \n"); for (i=0; i<=N; i++) printf("%ld %ld %ld %ld\n", list[i].node,list[i].key,i,heap_pos[i]);
   // printf("\n\n");
     
}

//find cost of track
i=0;j=1;
long m,l,sum;
sum=0; 
while (j<K) {
  m=track[i]; l=track[j];
  temp=adj_list[m];
  while((temp!=NULL)) {
    if (temp->end == l) 
      break;
    else
      temp=temp->next;
  }
    sum+= temp->dist;

i++; j++; }
printf("%ld \n", sum);

m=track[0];
l=track[K-1];

for (i=2; i<N; i++)  
 Q[i-2]=D[i];

for (i=0; i<N-2; i++)
 printf("%ld ", Q[i]);
printf("\n");
quicksort(Q,0,N-2);
for (i=0;i<N-2; i++) printf("%ld ",Q[i]);
free(D);
free(Q);
for (i=0; i<=N; i++)
 free(adj_list[i]);
free(adj_list); free(heap_pos); free(array); free(track); free(gas); free(list);
return 0;
}














void swap_int(long * list, long a ,long b) {
long int temp;

temp=list[b];
list[b]=list[a];
list[a]=temp;
}

void swap (heap * list, long a,long b){
heap temp;

temp=list[b];
list[b]=list[a];
list[a]=temp;
}

void DecreaseKey (heap * list,long *heap_pos, long i) {
long int k,l,m;

k=list[i].key;
while ((((i-1)/2) >= 0) && ( k < list[(i-1)/2].key)){
  swap(list,i,((i-1)/2));
  l=list[(i-1)/2].node;
  m=list[i].node;
  swap_int(heap_pos,m,l);
  i=(i-1)/2;
 }
}


void IncreaseKey(heap * list,long * heap_pos, long i,long long N) {   // to i antistoixei sto x tou paradeigmatos
heap c;
long l,m;
while ((2*i+1 <= N) || (2*i+2 <=N)) { 
  if (list[2*i+1].key <= list[2*i+2].key) { 
    c=list[2*i+1];
    if (c.key < list[i].key) {
    swap(list,i,2*i+1);
    m=list[i].node;
    l=list[2*i+1].node;
    swap_int(heap_pos,m,l);
    i=2*i+1;
   } else break;
  }

  else {
    c=list[2*i+2];
    if (c.key < list[i].key) {
    swap(list,i,(2*i+2));
    m=list[i].node;
    l=list[2*i+2].node;
    swap_int(heap_pos, m, l);
    i=2*i+2;
     } else break;
    }
  }
}


heap ExtractMin(heap * list,long * heap_pos, long long n) {   //n to megethos tis enapomeinousas listas
  heap c;
  long i,m;
  c.node=list[0].node;
  c.key=list[0].key;
  i=list[n].node;
  m=list[0].node;
  swap(list,0,n);  
  swap_int(heap_pos,m,i); ////

  list[n].key=INF+1000;
//  for (i=0; i<=n; i++) printf("%ld %ld ",list[i].node, heap_pos[i]);
//  printf("\n");
  IncreaseKey(list,heap_pos, 0, n);
  return c;
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


long int choose_pivot (long int i , long int j) {

return (i+j)/2;
}

void quicksort (long * list, long int m, long int n) {
long int key,i,j,k;
   if( m < n)
   {
      k = choose_pivot(m,n);
      swap_quick(&list[m],&list[k]);
      key = list[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i] <= key))
                i++;
         while((j >= m) && (list[j] > key))
                j--;
        if( i < j)
                swap_quick(&list[i],&list[j]);
      }
      // swap two elements
      swap_quick(&list[m],&list[j]);
      // recursively sort the lesser list
      quicksort(list,m,j-1);
      quicksort(list,j+1,n);

   }
}


void swap_quick (long * x, long * y) {
long  temp;
   temp = *x;
   *x = *y;
   *y = temp;

}
