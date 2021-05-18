// gcc -o clock clock.c
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
int main() {
  struct timeval tv;
  unsigned int i,j,l,op;
  unsigned char t[32],c,g,n,p;
  unsigned char o[4096];
  char *ct;
  static unsigned char d[]={
  "A0002620262026202620262026202620A000042404240424042404240424042404240424\
A000082008200820A000280028002800A000A000082008200820A000082008200820A0002620\
262026202620A0000820082008200820A000280028002800A000082008200820A000A0002800\
28002800A000262026202620A000A00008200820082008200820082008200820A00026202620\
2620A000262026202620A000A000262026202620A00008200820082008200200020002002000\
02002000020002000200"
  };
  printf("\033[2J\033[H");
  printf("\n\n\n\n\n\n\n\n");
loop:
  gettimeofday(&tv,0); usleep(1000000-tv.tv_usec); tv.tv_sec++;
  ct=ctime(&tv.tv_sec);
  op=0; o[op++]=13; o[op++]=033; o[op++]='['; o[op++]='8'; o[op++]='A';
  for(l=0;l<9;l++) {
    for(j=0;j<8;j++) {
      c=ct[j+11]; if(c==':') c='9'+1;
      c-='0'; p=0;
      for(i=0;i<4;i++) {
        p=1-p; n=d[c*36+l*4+i]; if(n=='A') n='9'+1;
        n-='0';
        if(p==1 && n!=0 ) {
          o[op++]=033; o[op++]='['; o[op++]='7'; o[op++]='m';
          for(g=0;g<n;g++) o[op++]=' ';
          o[op++]=033; o[op++]='['; o[op++]='0'; o[op++]='m';
        } else {
          for(g=0;g<n;g++) o[op++]=' ';
        }
      }
      if(j<7) { o[op++]=' '; o[op++]=' '; }
    }
    if(l<8) o[op++]='\n';
  }
  o[op++]=' '; o[op++]=' '; o[op]=0; write(1,o,op); fflush(stdout);
  goto loop;
  return 0;
}
