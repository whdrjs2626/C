#include <stdio.h>
#include <conio.h>

void int_Ex() {
	int a, * p;
	p = &a;
	printf("정수 입력 : ");
	scanf_s("%d", p);
	printf("입력한 정수는 %d\n\n", *p);
	while (getchar() != '\n');
}

void char_Ex() {
	char ch, * p;
	p = &ch;
	printf("문자 입력 : ");
	*p = _getche();
	printf("\n입력한 문자는 %c\n\n", *p);
}

void string_Ex() {
	char str[50], * p;
	p = str;
	printf("문자열 입력 : ");
	gets_s(str, 50);
	printf("입력한 문자열은 ");
	puts(p);
	printf("\n");
}

void intArray_Ex() {
	int arr[5], * p;
	p = arr;
	printf("정수 배열에 정수 5개 입력\n");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("정수 입력 : ");
		scanf_s("%d", &arr[i]);
	}
	printf("입력한 정수 배열 : ");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d  ", *p++);
	}
	printf("\n");
}

void charArray_Ex() {
	char arr[5], *p;
	p = arr;
	printf("\n문자 배열에 문자 5개 입력 : ");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		arr[i] = _getche();
	}
	printf("\n입력한 문자 배열 : ");
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
		printf("문자열 배열에 %d번째 문자열입력 : ", i);
		gets_s(*(p + i), 50);
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d번째로 입력한 문자열: ", i);
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