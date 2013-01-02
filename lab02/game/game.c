#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define min(x,y) (((x) < (y)) ? (x) : (y))



int main() {
long long int N,i,j,l,k;
long long int * array;
long long int **list,list2 ;
scanf( "%lld", &N);
array=malloc(sizeof(long long int)*N);
cum_sum=malloc(sizeof(long long int)*N);

list=(long long int **)malloc(sizeof(long long int *)*N);
//list2=(long long int **)malloc(sizeof(long long int *)*N);

for (i=0; i<N; i++){
 list[i]=(long long int *)malloc(sizeof(long long int)*(N-i));
// list2[i]=(long long int *)malloc(sizeof(long long int )*(N-i));
}


for (i=0; i<N; i++) {
 list[N-1-i][i]=0; 
}
for (i=0; i<N; i++)
   scanf("%lld", &array[i]);
cum_sum[0]=array[0];
for(i=0; i<N; i++)
   cum_sum[i]=array[i]+cum_sum[i-1];


for (l=2; l<=N; l++ ) {   //to mikos tis akolouthias pou koitaw
   for(i=0; i<(n-l+1); i++) {
      j=i+l-1;
      list[N-1-j][i]=-1;
      for (k=i;k<j;k++) {


      } 
   }
}



for (i=0; i<N; i++){
 free(list[i]);
// free(list2[i]);
}

free(list);
free(array);
free(cum_sum);
//free(list2);
return 0;
}
