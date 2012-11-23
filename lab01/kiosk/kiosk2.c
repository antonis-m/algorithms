#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

typedef struct {
  long long int position;
  long long int kiosks;
} tuple ;

FILE * fp;
int i,flag;
long long int N, dist, var1,var2,met_pos, met_neg, max_met_pos, max_met_neg; //to right stelnei aristera to left deksia.
tuple right,left;
tuple * A;
 
 fp=fopen(argv[1],"r");
 fscanf(fp,"%lld", &N);        // find number of positions
 fscanf(fp,"%lld", &dist);    //  find min distance between kiosks.
 
 A=malloc(sizeof(tuple)*N);
 flag=0;                      //arxikopoiisi
 for (i=0; i<N; i++) {
   fscanf(fp,"%lld",&var1);
   fscanf(fp,"%lld",&var2);
  
   A[i].position=var1;
   A[i].kiosks=var2;   //loaded elements on array A
  
 };

 right=A[0];
 if (right.kiosks%2==0) {                                  //upologise artia kioskia
   right.kiosks=right.kiosks/2;                           //upologizontai  posa 8a pane aristera kai posa 8a meinoun. Gi afta pou 8a meinoun na
   flag=1;                                                //  8umamai oti exoun prokupsei apo artio pli8os mesw tou flag 
   max_met_neg=-((right.kiosks-1)*dist+(dist/2));         // megisti apostasi gia aristera.                
 } else {                                                 // gia peritta
 };
                                                  
 for (i=1; i<N; i++) {
   right=A[i];
   left =A[i-1];
   // kane diadikasia xwrismatos
 }
 printf ("%lld %lld\n",max_met_neg,right.kiosks);
free(A);
fclose(fp);
return 0;
}
