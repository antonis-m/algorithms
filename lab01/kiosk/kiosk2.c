#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {

typedef struct {
  long long int position;
  long long int kiosks;
} tuple ;

FILE * fp;
int i,flag;
long long int N, dist, var1,var2,met_pos, met_neg, max_met_pos, max_met_neg,gap,flag_left,flag_right; //right stelnei aristera to left deksia.
tuple right,left;
tuple * A;
 
 fp=fopen(argv[1],"r");
 fscanf(fp,"%lld", &N);        // find number of positions
 fscanf(fp,"%lld", &dist);    //  find min distance between kiosks.
 
 A=malloc(sizeof(tuple)*N);
 flag_left=0;
 flag_right=0;                      //arxikopoiisi
 
 for (i=0; i<N; i++) {
   fscanf(fp,"%lld",&var1);
   fscanf(fp,"%lld",&var2);
  
   A[i].position=var1;
   A[i].kiosks=var2;   //loaded elements on array A
 };

 right=A[0];

 if (right.kiosks%2==0) {                                  //upologise artia kioskia
   right.kiosks=right.kiosks/2;                           //upologizontai  posa 8a pane aristera kai posa 8a meinoun. Gi afta pou 8a meinoun na
   flag_right=1;                                                //  8umamai oti exoun prokupsei apo artio pli8os mesw tou flag 
   max_met_neg=-((right.kiosks-1)*dist+(dist/2));         // megisti apostasi gia aristera.                
 } else {                                                 // gia peritta
   flag_right=0;
   right.kiosks=right.kiosks/2 + 1;
   max_met_neg=-((right.kiosks-1)*dist);  
 };                                                      //teleiwsa me prwto stoixeio.

 //prepei na arxikopoiisw tis metavlites metakinisis !
 for (i=1; i<N; i++) {
   //prepei na prosthetw tis metakiniseis arxika 8a einai miden.
   flag_left=flag_right;                                 //allazw ta flags
   left=right;                                           //egine gia na mi xasw tis allages pou ekana sto right pio prin
   right=A[i];
   if (right.kiosks%2 == 0)   
     flag_right=1; 
   else if (right.kiosks/2==1)
     flag_right=0;
  

   if ((flag_left==1)&&(flag_right==1)) {       
     right.kiosks=right.kiosks/2;
     gap=(right.position-1)-(left.position+1);           // prepei na afairesw ta 2 stoixeia pou einai sta akra.
     var1=(gap/dist)-1;                                  // kiosks fitting in the gap 
   } else if ((flag_left==0)&&(flag_right==0)) {
     right.kiosks= (right.kiosks/2) +1;
     gap=right.position-left.position;
     var1=(gap/dist)-1;    
   } else if ((flag_left==1)&&(flag_right==0)) {
     
   } else if ((flag_left==0)&&(flag_right==1)) {
   
   };
   
 }

free(A);
fclose(fp);
return 0;
}


