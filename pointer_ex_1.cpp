#include <stdio.h>
#include <conio.h>

void int_Ex() {
	int a, * p;
	p = &a;
	printf("���� �Է� : ");
	scanf_s("%d", p);
	printf("�Է��� ������ %d\n", *p);
	while (getchar() != '\n');
}

void char_Ex() {
	char ch, * p;
	p = &ch;
	printf("���� �Է� : ");
	*p = _getche();
	printf("\n�Է��� ���ڴ� %c\n", *p);
}

void string_Ex() {
	char str[50], * p;
	p = str;
	printf("���ڿ� �Է� : ");
	gets_s(str, 50);
	printf("�Է��� ���ڿ��� ");
	puts(p);
}

void main(void) {
	int_Ex();
	char_Ex();
	string_Ex();
}