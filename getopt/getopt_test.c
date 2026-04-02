#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define NUM 16

/* getopt 함수에서
   optarg 를 복사할 때 
   memcpy 와 strncpy 의 차이 테스트
 */

void print_mem(char* t, int s)
{
  for (int i = 0; i < s; i++)
  {
    printf("%x ", t[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[])
{
  int opt;
  char ip[NUM] = {0,};
  char ip2[NUM] = {0,};

  while((opt = getopt(argc, argv, "i:p:")) != -1)
  {
    switch(opt)
    {
      case 'i':
        printf("option ip: %s\n", optarg);
        memcpy(ip, optarg, NUM);
        strncpy(ip2, optarg, NUM);
        ip[NUM-1] = '\0';
        ip2[NUM-1] = '\0';
        break;
      default:
        printf("default\n");
        return -1;
        break;
    }
  }

  printf("ip: %s\n", ip);
  print_mem(ip, NUM1);
  /* a.out -i 127.0.0.1 명령어 수행시
    결과값: 
    ip: 127.0.0.1
    31 32 37 2e 30 2e 30 2e 31 0 53 48 45 4c 4c 0 
  */

  printf("ip2: %s\n", ip2);
  print_mem(ip2, NUM1);
  /* a.out -i 127.0.0.1 명령어 수행시
    결과값: 
    ip2: 127.0.0.1
    31 32 37 2e 30 2e 30 2e 31 0 0 0 0 0 0 0 
  */
}

