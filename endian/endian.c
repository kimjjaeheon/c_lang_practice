#include <stdio.h>
#include <stdint.h>
#include <endian.h>

typedef struct {
  int a;
  int b;
} a;

int main() 
{
  /* endian*/
  if (__BYTE_ORDER == __LITTLE_ENDIAN) {
    printf("Little-endian\n");
  } else if (__BYTE_ORDER == __BIG_ENDIAN) {
    printf("Big-endian\n");
  } else {
    printf("Unknown endianness\n");
  }

  uint32_t original_32 = 0x12345678;
  uint64_t original_64 = 0x123456789ABCDEF0;

  // 엔디안 변환 수행
  uint32_t swapped_32 = __builtin_bswap32(original_32);
  uint64_t swapped_64 = __builtin_bswap64(original_64);

  // 결과 출력
  printf("Original uint32: 0x%X, Swapped uint32: 0x%X\n", original_32, swapped_32);
  printf("Original uint64: 0x%lX, Swapped uint64: 0x%lX\n", original_64, swapped_64);

  // 구조체 상태일 때 변환이 잘 되는 지 궁금.
  a test;
  test.a = 0x12345678;
  test.b = 0x12345678;
  printf("test.a: 0x%X, test.b: 0x%X\n", test.a, test.b);
  uint64_t test_64 = __builtin_bswap64(*(uint64_t*)&test);
  printf("test_64: 0x%lX\n", test_64);

  return 0;
}
