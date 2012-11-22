#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
int i;

for(i=1; i<=32; i++) {
char s[]="./kiosk ";
char r[]="input";
char t[]=".txt";
char u[]=strcat(s,r);
char w[]=strcat(i,t);
printf("%s", strcat(u,w));

}
return 0;
}
