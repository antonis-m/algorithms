#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

typedef struct {
  long long int position;
  long long int kiosks;
} tuple ;

FILE * fp;
int i;
long int left,right;
long long int N, dist, var1,var2;
tuple * A;

 fp=fopen(argv[1],"r");
 fscanf(fp,"%lld", &N);        // find number of positions
 fscanf(fp,"%lld", &dist);    //  find min distance between kiosks.
 
 A=malloc(sizeof(tuple)*N);
 for (i=0; i<N; i++) {
   var1=fscanf(fp,"%lld",&var1);
   var2=fscanf(fp,"%lld",&var2);
   A[i].position=var1;
   A[i].kiosks=var2;

 };
 
free(A);
fclose(fp);
return 0;
}
