#include <stdio.h>
#include <conio.h>

void int_Ex() {
	int a, * p;
	p = &a;
	printf("���� �Է� : ");
	scanf_s("%d", p);
	printf("�Է��� ������ %d\n\n", *p);
	while (getchar() != '\n');
}

void char_Ex() {
	char ch, * p;
	p = &ch;
	printf("���� �Է� : ");
	*p = _getche();
	printf("\n�Է��� ���ڴ� %c\n\n", *p);
}

void string_Ex() {
	char str[50], * p;
	p = str;
	printf("���ڿ� �Է� : ");
	gets_s(str, 50);
	printf("�Է��� ���ڿ��� ");
	puts(p);
	printf("\n");
}

void intArray_Ex() {
	int arr[5], * p;
	p = arr;
	printf("���� �迭�� ���� 5�� �Է�\n");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("���� �Է� : ");
		scanf_s("%d", &arr[i]);
	}
	printf("�Է��� ���� �迭 : ");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d  ", *p++);
	}
	printf("\n");
}

void charArray_Ex() {
	char arr[5], *p;
	p = arr;
	printf("\n���� �迭�� ���� 5�� �Է� : ");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		arr[i] = _getche();
	}
	printf("\n�Է��� ���� �迭 : ");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%c  ", *p++);
	}
	printf("\n\n");
	while (getchar() != '\n');
}

void stringArray_Ex() {
	char arr[5][50], (*p)[50];
	p = arr;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("���ڿ� �迭�� %d��° ���ڿ��Է� : ", i);
		gets_s(*(p + i), 50);
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d��°�� �Է��� ���ڿ�: ", i);
		puts(*(p + i));
	}
}

void main(void) {
	int_Ex();
	char_Ex();
	string_Ex();
	intArray_Ex();
	charArray_Ex();
	stringArray_Ex();
}