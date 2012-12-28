#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv) {
FILE * fp;
int i;
long long int N,c,B,k,x,y;
long long int * A;
long long int * Sums;
long long int * M;


scanf( "%lld", &N);
scanf( "%lld", &c);

A=malloc(sizeof(long long int) *(N+1));          
Sums=malloc(sizeof(long long int) *(N+1));
M=malloc(sizeof(long long int) *(N+1));

for(i=1 ; i <= N ; i++) {  
  scanf("%lld",&B);
  A[i] = B - c ;  // anagw to provlima se afto tis makruteris sumvoloseiras me mi arnitiko a8roisma.
}

M[0]=Sums[0]=0;
x=y=0;

for (i=1; i<=N; i++) {
  Sums[i]=Sums[i-1] + A[i];
  if (Sums[i-1]<Sums[M[i-1]]) {
    M[i]=i-1;
  //  printf("%d %lld \n",i, M[i]);
 }  else { 
    M[i]=M[i-1];
   // printf("%d %lld \n",i, M[i]);
    }
  k=i-y+x-1;
  while (k>0) {
    if ((Sums[i] - Sums[M[k]]) >=0 )
      k=M[k];
    else 
      break;
    x=k+1;
    y=i;
  }  

}
if (x!=y) 
printf("%lld\n",y-x+1);
else 
printf("0\n");

//fclose(fp);
free(A);
free(M);
free(Sums);
return 0;
}
