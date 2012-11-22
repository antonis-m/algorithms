#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv) {
FILE * fp;
long int i;
long long int N,c,B,k,x,y;
long long int * A;
long long int * C;
long long int * M;

fp=fopen(argv[1],"r");

fscanf(fp, "%lld", &N);
fscanf(fp, "%lld", &c);

A=malloc(sizeof(long long int) * N+1);    
C=malloc(sizeof(long long int) * N+1);
M=malloc(sizeof(long long int) * N+1);

for(i=1 ; i <= N ; i++) {  
  fscanf(fp,"%lld",&B);
  A[i] = B - c ; 
}

M[0]=C[0]=0;
x=y=0;

for (i=1; i<=N; i++) {
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
printf("%lld \n",y-x+1);


fclose(fp);
free(A);
free(C);
free(M);
return 0;
}
