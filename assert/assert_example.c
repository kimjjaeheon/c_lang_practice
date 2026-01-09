#include <stdio.h>
#include <assert.h>

#define ERROR 0

/* Assert Context 패턴 */

/* [사용하는 opensource]
 * Wireshark 에서는
 * register_capture_dissector 함수가
 * assert 를 사용하여 dissector 등록이 고유한지 확인한다.
 * 
 * Git 에서는
 * SHA1 해시 값을 저장하는 함수는 assert 를 사용하여
 * 해시 값을 저장해야 하는 파일의 경로가 올바른지 확인한다.
 *
 * C 에서는
 * strcpy 함수가 사용자 입력이 유효한지 여부를
 * 점검하지 않는다.
 * 따라서 함수에 NULL 포인터를 제공하면 함수는 충돌한다.
 */

void print_file_name(char* file_name);

int main()
{
	int ret = ERROR;
	char* file_name = 0;

	print_file_name(file_name);

	return 0;
}

void print_file_name(char* file_name)
{
	assert(file_name != NULL && "Invalid filename");
	printf("file_name: %s\n", file_name);
}


