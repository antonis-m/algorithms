#include <stdio.h>
#include <stdlib.h>


int main () {

long long int k,N,s,t,M,i;
int **array;

scanf("%lld %lld %lld %lld %lld", &k, &N, &M, &s, &t);
array=(int**)malloc(N*sizeof(int *));
for(i=0; i<N-1; i++)
  array[i]=(int *)calloc(N,sizeof(int));


return 0;
}
