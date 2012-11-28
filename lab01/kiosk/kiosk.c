#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char **argv) {
FILE * fp;
long int i;
long long int N,pos,dist,kiosks;
long double backtrack,offset, offset_left, offset_right, res, right,left,p_right,max_met,mmove,interm;
long long int * A;


fp=fopen(argv[1],"r");

fscanf(fp, "%lld", &N);
fscanf(fp, "%lld", &dist);

fscanf(fp, "%lld", &pos);
fscanf(fp, "%lld", &kiosks);


 offset = (kiosks-1)*dist;
 offset_left=offset_right=offset/2.0;
 right=pos+offset_right;
 res= offset_left; 
 backtrack=0;
for (i=1; i<N; i++) {

 fscanf(fp, "%lld", &pos);
 fscanf(fp, "%lld", &kiosks);

 p_right=right;


 offset = (kiosks-1)*dist;
 offset_left=offset_right=offset/2.0;
 left=pos-offset_left;
 right=pos+offset_right;
 mmove=p_right+dist-left;

 if (mmove>0) {
    if (mmove>fabs(res-offset_left)) {
      interm= mmove- fabs(offset_left-res);
      
      //printf("%Lf %Lf %Lf %Lf\n",interm/2.0, mmove, offset_left, res);
      if(offset_left>res)
        res = interm/2.0 + offset_left;
      else
        res = interm/2.0 +res;  
      right=right+res-offset_left;
      //backtrack+= (res-offset_left)/2.0;
      //printf("%ld, %Lf 1\n",i,res);
   }  else {
        if(res>offset_left) 
          res=res;
        else
          res= offset_left;
        right+=mmove;
        //backtrack+=mmove/2.0;
        //printf("%ld, %Lf 2\n",i,res);
    } 
  
  } else if (mmove<0) {

      mmove=abs(p_right+dist-left);
      //printf("%Lf \n", mmove);
      interm=(res- offset_left);
      if (mmove<interm) 
       right-=mmove; 
      else right-= interm;
      
  }
 
};

printf("%.2Lf\n", res);
return 0;
}
