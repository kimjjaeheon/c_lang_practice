#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char** argv)
{
  struct hostent *host;
  int i;

  //host = gethostbyname("www.google.com");

  /* 127.0.0.1 (loop back) 으로 IP 주소가 들어왔을 경우*/
  //host = gethostbyname("127.0.0.1");

  /* 다른 IP 로 들어올 경우 */
  //host = gethostbyname("192.168.132.233");

  /* 없는 host 일 경우 (진짜 null 인지 확인)*/  
  host = gethostbyname("www.test_jhkim.com");

  if (!host)
  {
    printf("gethostbyname failed\n");
    return -1;
  }
  for (i = 0; NULL != host->h_addr_list[i]; i++)
  {
    printf("%s\n", inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));
  }

  return 0;
}
