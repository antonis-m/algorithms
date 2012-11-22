#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv) {
FILE * fp;
int i,x,y,k;
long int N,c,B;
long int * A;
long int * C;
int * M;

fp=fopen(argv[1],"r");

fscanf(fp, "%ld", &N);
fscanf(fp, "%ld", &c);

A=malloc(sizeof(long int) * N+1);    
C=malloc(sizeof(long int) * N+1);
M=malloc(sizeof(int) * N+1);

for(i=0 ; i < N ; i++) {  
  fscanf(fp,"%ld",&B);
  A[i] = B - c ; 
}

M[0]=C[0]=0;
x=y=0;

for (i=1; i<N; i++) {
  C[i]=C[i-1] + A[i];
  if (C[i-1]<C[M[i-1]]) 
    M[i]=i-1;
  else 
    M[i]=M[i-1];

  k=i-y+x-1;
  while (k>0) {
    if ((C[i] - C[M[k]]) >=0 )
      k=M[k];
    else 
      break;
    x=k+1;
    y=i;
  }  

}
printf("%d \n", y-x+1);

fclose(fp);
free(A);
free(C);
free(M);
return 0;
}
