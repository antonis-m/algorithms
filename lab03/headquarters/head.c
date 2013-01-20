#include <stdio.h>
#include <stdlib.h>


void fastpower (int **,long long int k,long long int N);
int main () {

long long int k,N,s,t,M,i,j,temp1,temp2;
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
for (i=0; i<N; i++){ 
 for (j=0; j<N; j++)
    printf("%d ",array[i][j]);
 printf("\n"); 
}
return 0;
}


void fastpower(int **array, long long int k,long long int N) {
 long long int i,j,l; 
 int **temp, **C;
 int sum;
 temp=(int**)malloc(N*sizeof(int *));
 C= (int**)malloc(N*sizeof(int *));

 for(i=0; i<N; i++) {
   temp[i]=(int *)calloc(N,sizeof(int));
   C[i]=(int *)calloc(N,sizeof(int));
  }
 for(i=0; i<N; i++) 
   temp[i][i]=1;

 while (k>0) {
 if ((k&1) == 0) { 
   for (i=0; i<N; i++) {
     for (j=0; j<N; j++) {
       sum=0;
       for (l=0; l<N; l++)
         sum += temp[i][l]*array[l][j];  
         C[i][j]=sum;
     }
   }
 **temp=**C;  
 k--;
 }

  k= k/2;
  for (i=0; i<N; i++) {
    for (j=0; j<N; j++) {
      sum=0;
      for (l=0; l<N; l++)
        sum += array[i][l]*array[l][j];  
        C[i][j]=sum;
    }
  }
 **array=**C;  
 }
array=temp;
for (i=0; i<N; i++) {
  free(temp[i]);
  free(C[i]);
}
free (temp); free(C);
}


