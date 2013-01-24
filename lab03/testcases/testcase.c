#include <stdio.h>
#include <stdlib.h>

void swap (long long int ** ,long long int x, long long int y);
long long int ch_pivot (long long int i, long long int j);
void quicksort (long long int **, long long int m, long long int n);
long long int find (long long int, long long int *);
void uni (long long int , long long int, long long int *);

int main () {
long long int N,i,weight,u;
long long int ** array;
long long int *list;
scanf("%lld", &N);

array=(long long int **)malloc((N-1)*sizeof(long long int *));
list=(long long int *)malloc(N*sizeof(long long int));
for(i=0; i<N-1; i++) {
  array[i]=(long long int *)malloc(3*sizeof(long long int));
  list[i]=i;
} 
weight=0;

for (i=0; i<N-1; i++) {
 scanf("%lld",&array[i][0]);
 scanf("%lld",&array[i][1]);
 scanf("%lld",&array[i][2]);
 weight += array[i][2];
}


quicksort(array,0,N-2);
//for (i=0; i<N-1; i++)
//printf("%lld %lld %lld\n",array[i][0],array[i][1],array[i][2]);




for (i=0; i<N-1; i++)
  free(array[i]);
free(array);
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
return x;
}

void uni (long long int u, long long int v, long long int * list) {



}
