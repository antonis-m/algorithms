#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {

typedef struct {
  long long int position;
  long long int kiosks;
} tuple ;

FILE * fp;
int i,flag_left,flag_right;
long long int N, dist, var1,var2,max_met_pos, max_met_neg,gap,kiosks_to_move, kiosks_to_move_left, kiosks_to_move_right, space_needed; //right stelnei aristera to left deksia.
tuple right,left;
tuple * A;
 
 fp=fopen(argv[1],"r");
 fscanf(fp,"%lld", &N);        // find number of positions
 fscanf(fp,"%lld", &dist);    //  find min distance between kiosks.
 
 A=malloc(sizeof(tuple)*N);
 flag_left=0;
 flag_right=0;                      //arxikopoiisi
 
 for (i=0; i<N; i++) {
   fscanf(fp,"%lld",&A[i].position);
   fscanf(fp,"%lld",&A[i].kiosks);
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
   kiosks_to_move=0;
   flag_left=flag_right;                                 //allazw ta flags
   left=right;                                           //egine gia na mi xasw tis allages pou ekana sto right pio prin
   right=A[i];
   if (right.kiosks%2 == 0)   
     flag_right=1; 
   else if (right.kiosks/2==1)
     flag_right=0;
  

   if ((flag_left==1)&&(flag_right==1)) {       
     
     right.kiosks=right.kiosks/2;
     var1=right.position-left.position;                   //existing distance 
     kiosks_to_move = left.kiosks + right.kiosks;        //  posa kioskia 8a metakinisw ap tis arxikes tous 8eseis.. 
     kiosks_to_move_right  = left.kiosks;
     kiosks_to_move_left   = right.kiosks;  
     space_needed= (left.kiosks-1)*dist + (right.kiosks-1)*dist + 2*(dist/2) +dist; 
 
   } else if ((flag_left==0)&&(flag_right==0)) {
     
     right.kiosks= (right.kiosks/2) +1;
     var1=right.position-left.position;
     kiosks_to_move=left.kiosks-1 + right.kiosks-1;    
     kiosks_to_move_right= left.kiosks-1;
     kiosks_to_move_left = right.kiosks-1;
     space_needed= (left.kiosks-1)*dist + dist + (right.kiosks-1)*dist;
  
   } else if ((flag_left==1)&&(flag_right==0)) {
     
     right.kiosks=(right.kiosks/2)+1;
     var1=right.position-left.position;
     kiosks_to_move= left.kiosks + right.kiosks-1;
     kiosks_to_move_right= left.kiosks;
     kiosks_to_move_left=  right.kiosks-1;
     space_needed= ((left.kiosks-1)*dist) + (dist/2) +dist+ (right.kiosks-1)*dist;

   } else if ((flag_left==0)&&(flag_right==1)) {
     
     right.kiosks=right.kiosks/2;
     var1=right.position - left.position;
     kiosks_to_move= left.kiosks-1 + right.kiosks;
   };
   
 }

free(A);
fclose(fp);
return 0;
}


