#include <stdio.h>

/* padding 방법 */
typedef struct 
{
  char a; /* 1 byte */
  int  b; /* 4 byte */
} __attribute__((packed)) A;
/* 총 5 byte 가 나와야 한다. */

typedef struct 
{
  char a;
  int  b;
} not_padding;

/* pack 으로 push 와 pop 사이 구조체에 대해
padding 을 1 byte 단위로 하겠다. 
즉, 패딩을 제거하겠다. */
#pragma pack(push, 1)
typedef struct 
{
  char a;
  int  b;
} B;
#pragma pack(pop)

int main(int argc, char** argv)
{
  printf("size A : %ld\n", sizeof(A));
  printf("size B : %ld\n", sizeof(B));
  printf("not padding : %ld\n", sizeof(not_padding));
  return 0;
}
