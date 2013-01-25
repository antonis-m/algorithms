#include <stdio.h>
#include <stdlib.h>

void swap (long long int ** ,long long int x, long long int y);
long long int ch_pivot (long long int i, long long int j);
void quicksort (long long int **, long long int m, long long int n);
long long int find (long long int, long long int *);
void uni (long long int , long long int, long long int *);

int main () {
long long int N,i,weight,j,k,u,v,ne,added;
long long int ** array;
long long int *p;
scanf("%lld", &N);

array=(long long int **)malloc((N-1)*sizeof(long long int *));
p=(long long int *)malloc(N*sizeof(long long int));
for(i=0; i<N-1; i++) {
  array[i]=(long long int *)malloc(3*sizeof(long long int));
  p[i]=0;
}
p[N-1]=0; 
weight=0;
ne=0;
for (i=0; i<N-1; i++) {
 scanf("%lld",&array[i][0]);
 scanf("%lld",&array[i][1]);
 scanf("%lld",&array[i][2]);
 weight += array[i][2];
}


quicksort(array,0,N-2);
//otan kanw find na zitaw akmi -1

/*for (i=0; i<N-1; i++) {
  j=array[i][0];
  k=array[i][1];
  added=array[i][2]+1;
  u=find(j-1,list);
  v=find(k-1,list);
  uni(u,v,list);
}*/

while(ne<N-1) {

  for (i=0; i<N-1; i++) {
    u=array[i][0]-1;
    v=array[i][1]-1;
    while(p[u])
      u=p[u]; 
    while(p[v])
      v=p[v];
   if (u!=v) {
     ne++;
     p[v]=u;
   } 
      
  }

}


for(i=0; i<N; i++)
  printf("%lld ", p[i]);
for (i=0; i<N-1; i++)
  free(array[i]);
free(array);
free(p);
return 0; 
}


void swap (long long int **array,long long x, long long y) {
   long long int temp1,temp2,temp3;
   temp1 = array[x][0];
   temp2 = array[x][1];
   temp3 = array[x][2];

   array[x][0] =array[y][0];  
   array[x][1] =array[y][1];
   array[x][2] =array[y][2];

   array[y][0] = temp1; 
   array[y][1] = temp2;
   array[y][2] = temp3;
}


long long int ch_pivot (long long int i, long long int j) {
    
    return (i+j)/2;
}


void quicksort (long long int ** array, long long int m, long long int n) {
long long int key,i,j,k;
   if( m < n)
   {
      k = ch_pivot(m,n);
      swap(array,m,k);
      key = array[m][2];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (array[i][2] <= key))
                i++;
         while((j >= m) && (array[j][2] > key))
                j--;
        if( i < j)
                swap(array,i,j);
      }
      // swap two elements
      swap(array,m,j);
      // recursively sort the lesser list
      quicksort(array,m,j-1);
      quicksort(array,j+1,n);

   }
}

long long int find (long long int x,long long int *list) {
while (x!=list[x])
x=list[x];
return x+1;
}

void uni (long long int u, long long int v, long long int * list) {
if (u==v)
 return;
else list[v-1]=u-1;

}
