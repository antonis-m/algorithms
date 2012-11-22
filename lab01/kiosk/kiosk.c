#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv) {
FILE * fp;
long int i;
long long int N,dist, kiosk_sum, kiosks, pos, pos_0, pos_N, fin_dist, init_dist, interm;
double res;
//long long int * A;
//long long int * C;
//long long int * M;

fp=fopen(argv[1],"r");

kiosk_sum=0;
fscanf(fp, "%lld", &N);
fscanf(fp, "%lld", &dist);

fscanf(fp, "%lld", &pos_0);
fscanf(fp, "%lld", &kiosks);

kiosk_sum += kiosks;

for (i=1;i<N-1; i++) {

 fscanf(fp, "%lld", &pos);
 fscanf(fp, "%lld", &kiosks);
 
 kiosk_sum += kiosks;
}

fscanf(fp, "%lld", &pos_N);
fscanf(fp, "%lld", &kiosks);
kiosk_sum+=kiosks;

init_dist=abs(pos_N-pos_0);
fin_dist= (kiosk_sum-1)*dist;
interm=fin_dist-init_dist;
res=interm/2;

printf("%f\n", res);
return 0;
}
