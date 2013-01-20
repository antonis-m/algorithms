#include <stdio.h>
#include <stdlib.h>


void fastpower (int **,long long int k,long long int N);
int main () {

long long int k,N,s,t,M,i,temp1,temp2;
int **array;

scanf("%lld %lld %lld %lld %lld", &k, &N, &M, &s, &t);
array=(int**)malloc(N*sizeof(int *));
for(i=0; i<N; i++)
  array[i]=(int *)calloc(N,sizeof(int));

for (i=0; i<M; i++) { 
  scanf("%lld %lld", &temp1, &temp2);
  array[temp1][temp2]=1;
}

fastpower(array,k,N);
return 0;
}


void fastpower(int **array, long long int k,long long int N) {
 long long int i; 
 int **temp;
 temp=(int**)malloc(N*sizeof(int *));
 for(i=0; i<N; i++)
   temp[i]=(int *)calloc(N,sizeof(int));
 for(i=0; i<N; i++) 
   temp[i][i]=1;
 while (k>0) {
 if ((k&1) == 0)
  ; // temp=temp*array;
 else { 
    k= k/2;
   // array=array*array;
  }
 }
array=temp;
}


