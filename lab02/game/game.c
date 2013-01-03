#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define min(x,y) (((x) < (y)) ? (x) : (y))
//gia kathe timi tou k koitaw ti pairnw ap ti dedomeni katastasi kai ti apo ta upoprovlimata pou dimiourgountai. Krataw to min.

int main() {
long long int N,i,j,l,k,mik,mkj,temp;
long long int * array, * cum_sum;
long long int **list;


scanf( "%lld", &N);

array=malloc(sizeof(long long int)*N);
cum_sum=malloc(sizeof(long long int)*N);

list=(long long int **)malloc(sizeof(long long int *)*N);

for (i=0; i<N; i++)
 list[i]=(long long int *)malloc(sizeof(long long int)*(N-i));

for (i=0; i<N; i++)  
 list[N-i-1][i]=0;  

for (i=0; i<N; i++) 
   scanf("%lld", &array[i]);

cum_sum[0]=array[0];
for(i=1; i<N; i++) 
   cum_sum[i]=array[i]+cum_sum[i-1];
 
for (l=2; l<=N; l++ ) {   //to mikos tis akolouthias pou koitaw
   for(i=0; i<=(N-l); i++) {
      j=i+l-1;
      list[N-j-1][i]=-1;
      for (k=i+1;k<=j;k++) {     //xekinaw apo to i+1 
           if (k!=1 ) 
              temp=min((list[N-1-(k-1)][i] + cum_sum[k-1]-cum_sum[i]+array[i] ),(list[N-j-1][k] + cum_sum[j]-cum_sum[k-1]));
           else  
              temp=min ((list[N-1-(k-1)][i] + cum_sum[k-1]),(list[N-j-1][k] + cum_sum[j]-cum_sum[k-1]));
           if (temp >= list[N-j-1][i]) 
              list[N-j-1][i]=temp;
            
          

      } 
//printf("%lld %lld %lld\n",N-j-1,i,list[N-j-1][i]);
   }
}
printf("%lld\n",list[0][0]);


for (i=0; i<N; i++)
 free(list[i]);


free(list);
free(array);
free(cum_sum);
return 0;
}

