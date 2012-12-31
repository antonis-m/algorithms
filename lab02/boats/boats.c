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
while ((i != (N-1)) && (j<(N-1))) {
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

//for (i=0;i<N;i++)
//printf("%lld \n", list_arr[i]);
//printf("\n\n");
result=LIS(list_arr, N);
printf("%lld\n", result);


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

   long long int L,i,j,k,l,low,high,mid,temp;
   long long int c[N];
   j=0;
   for (i=0; i<N; i++)  
       c[j]=-1;
   c[0]=array[0];
   L=1;
   for (i=1; i<N; i++) {
       if (array[i] >= c[j]) {
         j++;
         c[j]=array[i];
         L += 1;
      } else {
         low=0;
         high=j; 
         while (low<=high) {
           mid=(low+high)/2;

           if (c[mid]<array[i])
                low=mid+1;

             else if (c[mid]>array[i]) {
               if (mid==0) {                  //simantiki allagi pou ekane ton kwdika na doulepsei. krataw panta to mikrotero apo ta megalutera
                /* temp=c[mid];
                 k=mid+1;
                 while (c[k]==temp) {
                     c[k]=array[i];
                     k++;
                 } */
                 c[mid]=array[i];
                 high=mid-1;
              }  else {
                 high=mid-1;
                 if (c[mid-1]<array[i]) {
                   /*  temp=c[mid];
                     k=mid+1;
                     while (c[k]==temp) {
                       c[k]=array[i];
                       k++;
                     } */
                    c[mid]=array[i];
                    }              
                }
           }  else if (c[mid]==array[i]) {
                  
                   k=mid;
                   while (c[k]==c[mid]) {
                        k++;
                    }
                    temp=c[k];
                    c[k]=array[i]; 
                    k++;
                    while (c[k]==temp) {
                       c[k]=array[i];
                       k++;
                       }
                   break;         
            } 
                              
         }   
      }




//for(l=0; l<L;l++)
//printf("%lld\n",c[l]);
//printf("\n");
}
return L;
}



