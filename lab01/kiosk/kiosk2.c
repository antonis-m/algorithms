#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

struct tuple {
  long long int position;
  long long int kiosks;
};

FILE * fp;
long int left,right;
long long int N, dist;
tuple * A;

 fp=fopen(argv[1],"r");
 fscanf(fp,"%lld",N);        // find number of positions
 fscanf(fp,"%lld",dist);    //  find min distance between kiosks.
 
 A=malloc(sizeof(tuple)*N);

 
free(A);
fclose(fp);
return 0;
}
