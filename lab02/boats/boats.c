#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long int dep;
    long long int arr;
} diad;

int main() {
long long int N,i;
diad * array;


scanf( "%lld", &N);
array=malloc(sizeof(diad)*N);


for (i=0; i<N; i++){
   scanf("%lld", &array[i].dep);
   scanf("%lld", &array[i].arr);
}


free(array);
return 0;
}
