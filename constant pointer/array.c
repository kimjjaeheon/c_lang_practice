#include <stdio.h>

/* 배열명 = 시작주소값이며, 배열의 요소들은 주소들이 연속적으로 붙어있다. */
/* 이 때 연속적인 주소 정보를 변경시키면 안 되기 때문에, 주소를 바꾸지 못하도록 */
/* 주소가 상수값으로 고정되어 있다. */
/* 그러므로 배열명은 포인터 상수이며, 배열의 주소를 변경 할 수 없다. */

int main(int argc, char* argv[])
{
  int nums[] = { 1, 2, 3 };

  *nums = 5; /* 값 변경 가능하다 */

  printf("배열의 첫번째 값 : %d\n", *nums);
  printf("배열의 값 : ");
  for (int i = 0; i < 3; i++){
    printf("%d", nums[i]); 
  }
  printf("\n");

  int a = 10;
  int* ptr = nums; /* 새로운 포인터 변수가 배열 nums 의 첫번째 값을 가리킨다 */
  ptr = &a;     /* 가능하다 */
  //nums = &a;  /* 불가능하다 */

  return 0;
}
