#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {

typedef struct {
  long long int position;
  long long int kiosks;
} tuple ;

FILE * fp;
int i,flag_left,flag_right;
long long int N, dist, var1,kiosks_to_move;
long long int kiosks_to_move_left, kiosks_to_move_right, space_needed; //right stelnei aristera to left deksia.
double var2,shift_p,shift_neg,max_met_pos,max_met_neg,met_pos,met_neg;
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
 
 
 max_met_pos=max_met_neg=0.0;
 shift_p=shift_neg=0.0; 
 var2=0.0;
 for (i=1; i<N; i++) {
   left.position +=var2;      //paratirw oti mono to left xreiazetai na kanw shift..
   met_pos = var2;           // check meta giati mono to aristero kineitai. ara to deksi den epireazetai. provlimatizomai metaksu shift_ var2
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
     if (var1>=space_needed) {                           // pithanws kati na xreiastei na peiraxtei gia diastimata pou prepei na mikrunoun.
        met_pos+=(left.kiosks-1)*dist + dist/2.0;
        if (met_pos>max_met_pos)
          max_met_pos=met_pos; 
        met_neg=-((right.kiosks-1)*dist + dist/2.0);
        if (abs(met_neg)>abs(max_met_neg))
          max_met_neg=met_neg;       
     } else { 

       var2=(space_needed -var1)/2.0;                    // isotimo anoigma deksia kai aristera.
       shift_p += var2;
       shift_neg += -var2;
       max_met_pos +=var2;
       max_met_neg -=var2;              
       met_pos=-var2+(left.kiosks-1)*dist + dist/2.0; //
       if (met_pos>max_met_pos)
         max_met_pos=met_pos; 
       met_neg=var2-((right.kiosks-1)*dist + dist/2.0); //edw eixe shiftp anti gia var2
       if (abs(met_neg)>abs(max_met_neg))
         max_met_neg=met_neg;       
      };
  
   } else if ((flag_left==0)&&(flag_right==0)) {
     
     right.kiosks= (right.kiosks/2) +1;
     var1=right.position-left.position;
     kiosks_to_move=left.kiosks-1 + right.kiosks-1;    
     kiosks_to_move_right= left.kiosks-1;
     kiosks_to_move_left = right.kiosks-1;
     space_needed= (left.kiosks-1)*dist + dist + (right.kiosks-1)*dist;
     if (var1>=space_needed) {                           // pithanws kati na xreiastei na peiraxtei gia diastimata pou prepei na mikrunoun.
        met_pos+=(left.kiosks-1)*dist;
        if (met_pos>max_met_pos)
          max_met_pos=met_pos; 
        met_neg=-(right.kiosks-1)*dist;
        if (abs(met_neg)>abs(max_met_neg))
          max_met_neg=met_neg;       
     } else { 

       var2=(space_needed -var1)/2.0;                    // isotimo anoigma deksia kai aristera.
       shift_p += var2;
       shift_neg += -var2;
       max_met_pos +=var2;
       max_met_neg -=var2;              
       met_pos=-var2+(left.kiosks-1)*dist; 
       if (met_pos>max_met_pos)
         max_met_pos=met_pos; 
       met_neg=var2-((right.kiosks-1)*dist + dist/2.0); // edw eixe shift p anti gia var2
       if (abs(met_neg)>abs(max_met_neg))
         max_met_neg=met_neg;       
       }
 
   } else if ((flag_left==1)&&(flag_right==0)) {
     
     right.kiosks=(right.kiosks/2)+1;
     var1=right.position-left.position;
     kiosks_to_move= left.kiosks + right.kiosks-1;
     kiosks_to_move_right= left.kiosks;
     kiosks_to_move_left=  right.kiosks-1;
     space_needed= ((left.kiosks-1)*dist) + (dist/2.0) +dist+ (right.kiosks-1)*dist;
     if (var1>=space_needed) {                           // pithanws kati na xreiastei na peiraxtei gia diastimata pou prepei na mikrunoun.
        met_pos+=(left.kiosks-1)*dist + (dist/2.0);
        if (met_pos>max_met_pos)
          max_met_pos=met_pos; 
        met_neg=-(right.kiosks-1)*dist;
        if (abs(met_neg)>abs(max_met_neg))
          max_met_neg=met_neg;       
     } else { 

       var2=(space_needed -var1)/2.0;                    // isotimo anoigma deksia kai aristera.
       shift_p += var2;
       shift_neg += -var2;
       max_met_pos +=var2;
       max_met_neg -=var2;              
       met_pos=-var2+(left.kiosks-1)*dist; 
       if (met_pos>max_met_pos)
         max_met_pos=met_pos; 
       met_neg=var2-((right.kiosks-1)*dist + dist/2.0); // edw eixe shift p anti gia var2
       if (abs(met_neg)>abs(max_met_neg))
         max_met_neg=met_neg;       


     }
   } else if ((flag_left==0)&&(flag_right==1)) {
     
     right.kiosks=right.kiosks/2;
     var1=right.position - left.position;
     kiosks_to_move= left.kiosks-1 + right.kiosks;
     kiosks_to_move_right =left.kiosks-1; 
     kiosks_to_move_left= right.kiosks;
     space_needed= (left.kiosks-1)*dist + dist + (right.kiosks-1)*dist + (dist/2); 
   };
   
 }
      printf("%lf %lf %lf %lf\n",met_pos,met_neg,max_met_pos,max_met_neg);

//printf("%lf %lf \n", max_met_pos,max_met_neg);
free(A);
fclose(fp);
return 0;
}


