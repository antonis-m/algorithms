#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long int dep;
    long long int arr;
} diad;


void swap (diad *x, diad *y);
long long int ch_pivot (long long int i, long long int j);
void quicksort_dep (diad array[] ,long long int m, long long int n);

int main() {
long long int N,i;
diad * array;


scanf( "%lld", &N);
array=malloc(sizeof(diad)*N);


for (i=0; i<N; i++){
   scanf("%lld", &array[i].dep);
   scanf("%lld", &array[i].arr);
}


quicksort_dep(array,0,N-1);
//check for common departure point
//evresi megistis koinis upakolou8ias.
for (i=0;i<N;i++)
    printf("%lld %lld \n", array[i].dep, array[i].arr);

free(array);
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

void quicksort_dep (diad list[], long long int m, long long int n){
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
      quicksort(list,m,j-1);
      quicksort(list,j+1,n);

   }
}


