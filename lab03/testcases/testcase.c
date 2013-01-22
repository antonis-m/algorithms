#include <stdio.h>
#include <stdlib.h>

int main () {
long long int N,i,u,v,w;
long long int ** array;
scanf("%lld", &N);

array=(long long int **)malloc(N*sizeof(long long int));
for(i=0; i<N; i++)
  array[i]=(long long int *)malloc(3*sizeof(long long int));




for (i=0; i<N; i++)
  free(array[i]);
free(array);

return 0; 
}
