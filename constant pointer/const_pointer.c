#include <stdio.h>

/* 상수 포인터 (constant pointer)*/
int main(int argc, char **argv)
{
  int num = 1;
  /* 포인터 상수 constant pointer */
  /* 값은 변경 할 수 있으나, 주소 변경은 불가능하다. */
  int* const ptr = &num;

  *ptr = 4;
  printf("ptr : %d\n", *ptr);

  int num2 = 100;
  //ptr = &num2; /* 에러: 가리키는 주소의 변경은 불가능하다. */

  return 0;
}
