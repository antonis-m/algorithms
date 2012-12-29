#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long int dep;
    long long int arr;
} diad;


void swap (diad *x, diad *y);
long long int ch_pivot (long long int i, long long int j);
void quicksort_dep (diad array[], long long int m, long long int n);
void quicksort_arr (diad array[], long long int m, long long int n);

int main() {
long long int N,i,j;
diad * array;


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

