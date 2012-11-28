#include <stdio.h>
#include <stdlib.h>

typedef struct {
  long double position;
  long long int kiosks;
} tuple ;


int binary_search (tuple * A,int n,int k);
int main(int argc, char **argv) {

FILE *fp;
fp=fopen(argv[1],"r");
int i;
long long int prev_pos,pos,pos_0,apps,dist,kiosks,max_kiosks,sum_kiosks,x,y,k;
tuple * A;

fscanf(fp, "%lld",&apps);
fscanf(fp, "%lld",&dist);

A=malloc(sizeof(tuple)*(apps+1));
for(i=0; i<apps; i++) {
  fscanf(fp,"%lld",&pos);
  fscanf(fp,"%lld",&kiosks);
  A[i].position=pos;
  A[i].kiosks=kiosks; 
}




fclose(fp);

free(A);
return 0;
}

int binary_search(tuple * A, int n, int K) {
int low = 0; 
int up = n-1; 
int mid; 

while (low <= up) {
mid = (low + up) / 2;
if (A[mid] == k) return(mid);
else if (A[mid] > k) up = mid - 1;
else            low = mid + 1; }


return(-1);
}
