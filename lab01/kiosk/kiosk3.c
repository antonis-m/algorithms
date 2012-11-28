#include <stdio.h>
#include <stdlib.h>
 
#ifndef max
        #define max(a,b) ( ((a) > (b)) ? (a) : (b) )
#endif
#ifndef min
        #define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif
 
void fixOne(int  * previous, int * beg, int * end,int amount,int place,int minimum,int * maxSofar) { //υπολογισμός άκρων διστήματος
        int step = (amount-1)*minimum/2;
        *previous = *end;
        *beg = place - step;
        *end = place + step;
 
//      if (*maxSofar<step) *maxSofar = step;   
 
}
 
 
int main() {
 
int pointNo,minDis;
 
scanf("%d",&pointNo);
scanf("%d",&minDis);
 
minDis = 2*minDis;
 
 
 
 int i;
 int position;
 int amount;
 int maxMove = 0;
 int previousRight ;
 int left,right;
 int offset;
 
scanf("%d",&position); // adding the first double
position = position*2;
scanf("%d",&amount);
offset = (amount-1)*minDis/2;
left = position - offset;
right = position + offset;
maxMove = offset;
previousRight = right;
 
 
//printf ("maxMove = %.2f\n",(float)maxMove/2);
 
int rest;
int mustMove;
 
for (i=1;i<pointNo;i++) {
        scanf("%d",&position);
        position = position*2; 
        scanf("%d",&amount);
        offset = (amount-1)*minDis/2;
        previousRight = right; 
        left = position - offset;
        right = position + offset;
//      printf("from main begin = %.2f and end = %.2f\n", (float)left/2, (float)right/2);
 
 
 
        mustMove = previousRight+minDis-left; 
        //printf("mustMove = %.2f\n",(float)mustMove/2 );       
 
 
 
 
 
        //printf("offset is = %.2f\n",(float)offset/2);
        if (mustMove>0)  // check here....
 
                if (mustMove > abs(maxMove - offset)) {
                        rest = mustMove - abs(offset-maxMove);  //rest = mustMove - (maxMove - offset);
                        //printf("rest = %f\n",(float)rest/2);
                        maxMove = max(offset,maxMove) + rest/2; //maxMove =  maxMove + rest/2; //(maxMove + mustMove )/2;
                        right = right + maxMove - offset;
 
                } else{
//                      printf("fits ok at %d\n",i);
                        maxMove = max(maxMove,offset);
                        right = mustMove + right;
                        }
        else if (mustMove < 0) {
                right = right - min(abs(mustMove),maxMove-offset); 
  //            printf("needed to shorten\n");
                }
 
 
        //      printf("The New max just became:%f NewMostRight=%f\n",(float)maxMove/2,(float)right/2); 
 
}
        printf("%.2f\n",(float)maxMove/2);
 
}
