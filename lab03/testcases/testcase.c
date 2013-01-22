#include <stdio.h>
#include <stdlib.h>

int main () {
long long int N,i,weight;
long long int ** array;
scanf("%lld", &N);

array=(long long int **)malloc(N*sizeof(long long int));
for(i=0; i<N; i++)
  array[i]=(long long int *)malloc(3*sizeof(long long int));
weight=0;

for (i=0; i<N; i++) {
 scanf("%lld",&array[i][0]);
 scanf("%lld",&array[i][1]);
 scanf("%lld",&array[i][2]);
 weight += array[i][2];

}



for (i=0; i<N; i++)
  free(array[i]);
free(array);

return 0; 
}
