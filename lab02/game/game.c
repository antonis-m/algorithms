#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define min(x,y) (((x) < (y)) ? (x) : (y))

typedef struct {
           
           long long int val;
                     int index;
   } str;

long long int print_money (long long int N, long long int ** list, str ** list2,long long int i, long long int j); 
int main() {
long long int N,i,j,l,k,mik,mkj,money,temp;
long long int * array, * cum_sum;
long long int **list;
int index;
str **list2;
scanf( "%lld", &N);

array=malloc(sizeof(long long int)*N);
cum_sum=malloc(sizeof(long long int)*N);

list=(long long int **)malloc(sizeof(long long int *)*N);
list2=(str **)malloc(sizeof(str *)*N);

for (i=0; i<N; i++){
 list[i]=(long long int *)malloc(sizeof(long long int)*(N-i));
 list2[i]=(str *)malloc(sizeof(str)*(N-i));
 }

money=0;
for (i=0; i<N; i++) { 
 list[N-i-1][i]=0;  
 list2[N-i-1][i].val=0;
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
      for (k=i;k<=j;k++) {
          if (k==0) {
            mik = 0;
            mkj = cum_sum[j]-cum_sum[0]+array[0];
           } else {
          mik = cum_sum[k-1]-cum_sum[i]+array[i]; 
          mkj = cum_sum[j]-cum_sum[k-1];
          }
          if (mik<mkj) {
             temp=mik;
             index=0; 
          } else {
             temp=mkj;
             index=1;
          }
//          printf("%lld %lld %lld \n",i,j,temp);
          if (temp >= list[N-j-1][i]) {
          list[N-j-1][i]=temp;
          list2[N-j-1][i].val=k;
          list2[N-j-1][i].index=index;
          }
      } 
//printf("%lld %lld %lld %lld %d\n",N-j-1,i,list[N-j-1][i],list2[N-j-1][i].val, list2[N-j-1][i].index);
   }
}
temp=N-1;
money=print_money(N,list,list2,0,temp);
//printf("%lld\n",money);



for (i=0; i<N; i++)
 free(list[i]);


free(list);
free(array);
free(cum_sum);
return 0;
}

long long int print_money (long long int N,long long int ** list, str ** list2,long long int i, long long int j){
/* long long int coins=0;
 long long int k;
  if (i==j)
    return coins;
  else if ((i!=j) && (list2[N-1-j][i].index == 0)){
     k=list2[N-1-j][i].val;
     coins +=list[N-1-j][i];
     return coins + print_money(N,list,list2,i,k-1);   
  } else if ((i!=j) && (list2[N-1-j][i].index ==1)) {
     coins += list[N-1-j][i];
     return coins + print_money(N,list,list2,k,j);
  }*/
}
