#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define min(x,y) (((x) < (y)) ? (x) : (y))



int main() {
long long int N,i;
long long int * array;
long long int **list;
scanf( "%lld", &N);
array=malloc(sizeof(long long int)*N);
*list=malloc(sizeof(long long int *)*N);

for (i=0; i<N; i++){
 list[i]=malloc(sizeof(long long int)*(N-i));
}


for (i=0; i<N; i++){
   scanf("%lld", &array[i]);
}


return 0;
}
