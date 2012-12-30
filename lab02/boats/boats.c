#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))


typedef struct {
    long long int dep;
    long long int arr;
} diad;


void swap (diad *x, diad *y);
long long int ch_pivot (long long int i, long long int j);
void quicksort_dep (diad array[], long long int m, long long int n);
void quicksort_arr (diad array[], long long int m, long long int n);
long long int LIS (long long int array[], long long int N);

int main() {
long long int N,i,j,result;
diad * array;
long long int * list_arr;


scanf( "%lld", &N);
array=malloc(sizeof(diad)*N);


for (i=0; i<N; i++){
   scanf("%lld", &array[i].dep);
   scanf("%lld", &array[i].arr);
}


quicksort_dep(array,0,N-1);
i=j=0;
while (i != (N-1)) {
	while (array[i].dep == array[j].dep) {
    		j++;
	}
	if (i != j-1) {
    		quicksort_arr(array,i,j-1);
                i=j; 
       } else
    		i=j;
}

list_arr=malloc(sizeof(long long int)*N);
for (i=0; i<N; i++)
    list_arr[i]=array[i].arr;


//evresi megistis koinis upakolou8ias.
result=LIS(list_arr, N);

for (i=0;i<N;i++)
    printf("%lld \n", list_arr[i]);

free(array);
free(list_arr);
return 0;
}

void swap (diad * x, diad * y) {
   diad temp;
   temp = *x;
   *x = *y;
   *y = temp; 
}

long long int ch_pivot (long long int i, long long int j) {
    
    return (i+j)/2;
}

void quicksort_dep (diad list[], long long int m, long long int n) {
long long int key,i,j,k;
   if( m < n)
   {
      k = ch_pivot(m,n);
      swap(&list[m],&list[k]);
      key = list[m].dep;
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i].dep <= key))
                i++;
         while((j >= m) && (list[j].dep > key))
                j--;
        if( i < j)
                swap(&list[i],&list[j]);
      }
      // swap two elements
      swap(&list[m],&list[j]);
      // recursively sort the lesser list
      quicksort_dep(list,m,j-1);
      quicksort_dep(list,j+1,n);

   }
}

void quicksort_arr (diad list[], long long int m, long long int n) {
long long int key,i,j,k;
   if( m < n)
   {
      k = ch_pivot(m,n);
      swap(&list[m],&list[k]);
      key = list[m].arr;
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i].arr <= key))
                i++;
         while((j >= m) && (list[j].arr > key))
                j--;
        if( i < j)
                swap(&list[i],&list[j]);
      }
      // swap two elements
      swap(&list[m],&list[j]);
      // recursively sort the lesser list
      quicksort_arr(list,m,j-1);
      quicksort_arr(list,j+1,n);

   }
}

long long int LIS (long long int array[], long long int N) {

   long long int L,i,j,low,high,mid;
   long long int c[N];
   for (i=0; i<N; i++)
       c[i]=-1;
   c[0]=array[0];
   L=1;
   for (i=1; i<N; i++) {
      if (array[i] >= c[i-1]) {
         c[i]=array[i];
         L += 1;
      } else {
         low=0; high=(i-1); 
         while (low<=high) {
           mid=(low+high)/2;

           if (c[mid]<array[i]) {
               low=mid+1;
           } else if (c[mid]>=array[i])
               high=mid;
           
          c[mid]=array[i];         
         }
      }

   }
return L;
}



