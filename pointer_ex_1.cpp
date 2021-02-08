#include <stdio.h>
#include <conio.h>

void int_Ex() {
	int a, * p;
	p = &a;
	printf("정수 입력 : ");
	scanf_s("%d", p);
	printf("입력한 정수는 %d\n", *p);
	while (getchar() != '\n');
}

void char_Ex() {
	char ch, * p;
	p = &ch;
	printf("문자 입력 : ");
	*p = _getche();
	printf("\n입력한 문자는 %c\n", *p);
}

void string_Ex() {
	char str[50], * p;
	p = str;
	printf("문자열 입력 : ");
	gets_s(str, 50);
	printf("입력한 문자열은 ");
	puts(p);
}

void main(void) {
	int_Ex();
	char_Ex();
	string_Ex();
}