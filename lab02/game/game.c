#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define min(x,y) (((x) < (y)) ? (x) : (y))



int main() {
long long int N,i,j,l,k,mik,mkj,money,temp;
long long int * array, * cum_sum;
long long int **list, **list2;
scanf( "%lld", &N);

array=malloc(sizeof(long long int)*N);
cum_sum=malloc(sizeof(long long int)*N);

list=(long long int **)malloc(sizeof(long long int *)*N);
list2=(long long int **)malloc(sizeof(long long int *)*N);

for (i=0; i<N; i++){
 list[i]=(long long int *)malloc(sizeof(long long int)*(N-i));
 list2[i]=(long long int *)malloc(sizeof(long long int)*(N-i));
 }

money=0;
for (i=0; i<N; i++) { 
 list[N-i-1][i]=0;  
 list2[N-i-1][i]=0;
}
for (i=0; i<N; i++) 
   scanf("%lld", &array[i]);

cum_sum[0]=array[0];
for(i=1; i<N; i++) 
   cum_sum[i]=array[i]+cum_sum[i-1];
 
for (l=2; l<=N; l++ ) {   //to mikos tis akolouthias pou koitaw
   for(i=0; i<=(N-l); i++) {
      j=i+l-1;
      list[N-j-1][i]=-1;
//      printf("%lld %lld %lld %lld\n",N/*-1*/-j,j,i,N-i-1);
      for (k=i;k<=j;k++) {
          if (k==0) {
            mik = 0;
            mkj = cum_sum[j]-cum_sum[0]+array[0];
           } else {
          mik = cum_sum[k-1]-cum_sum[i]+array[i]; 
          mkj = cum_sum[j]-cum_sum[k-1];
          }
          temp=min(mik,mkj);
          if (temp >= list[N-j-1][i]) {
          list[N-j-1][i]=temp;
          list2[N-j-1][i]=k;
          }
      } 
//printf("%lld %lld %lld %lld\n",N-j-1,i,list[N-j-1][i],list2[N-j-1][i]);
   }
//money += list[N-1-j][i];
}

printf("%lld\n",money);


for (i=0; i<N; i++)
 free(list[i]);


free(list);
free(array);
free(cum_sum);
return 0;
}
