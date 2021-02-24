#include <stdio.h>
#include <conio.h>

void int_Ex();
void char_Ex();
void string_Ex();
void intArray_Ex();
void charArray_Ex();
void stringArray_Ex();
void ex1();  // double형 배열을 포인터로 복사하는 함수
void ex2();  // 정수형 배열에서 포인터로 모든 원소의 값을 n씩 증가시키는 함수
void ex3();  // 1차원 배열에 소문자 문자열을 포인터로 대문자로 변환하는 함수 (touppper 사용 X)
void ex4();  // 2차원 배열 1행에 소문자 문자열 입력 후 포인터로 2행에 대문자를 저장하는 함수
void ex5();  // 포인터로 두 문자열 잇기 == strcat
void ex6();  // 포인터로 문자열 길이 출력
void ex7();  // 문자열과 문자 하나를 입력받아 문자열에 해당 문자가 몇 개인지 출력
void ex8();  // 2차원 정수 배열의 열 합, 행 합 , 총 합을 구하기
void ex9();  // 오름차순으로 정렬되어 있는 두 일차원 정수 배열 합치기, 병합 배열도 정렬되어 있어야 함
void ex10(); // 문자열 역순 출력
void ex11(); // 소문자 문자열에 각 문자가 몇개씩 있는지 출력 -> ex7 응용

void main(void) {
	//int_Ex();
	//char_Ex();
	//string_Ex();
	//intArray_Ex();
	//charArray_Ex();
	//stringArray_Ex();
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	//ex5();
	//ex6();
	//ex7();
	//ex8();
	//ex9();
	//ex10();
	ex11();
}

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
	char arr[5], * p;
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

void ex1() {
	double source[] = { 3.12, 5.14, 7.25, 7.48, 5.91 }, * p;
	p = source;
	double target[sizeof(source) / sizeof(source[0])];
	for (int i = 0; i < sizeof(target) / sizeof(target[0]); i++) {
		target[i] = *(p + i);
	}
	printf("복사한 배열 출력 : ");
	for (int i = 0; i < sizeof(target) / sizeof(target[0]); i++) {
		printf("%.2f  ", target[i]);
	}
	printf("\n\n");
}

void ex2() {
	int data[] = { 3, 21, 35, 57, 24 }, n, * p;
	p = data;
	printf("원소마다 증가시킬 값 입력 : ");
	scanf_s("%d", &n);
	printf("증가된 배열 원소들 : ");
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		*(p + i) += n;
		printf("%d  ", *(p + i));
	}
	printf("\n\n");
}

void ex3() {
	char str[50], * p;
	p = str;
	printf("문자열 입력 : ");
	gets_s(p, 50);
	while (*p) {
		*(p++) -= 32;
	}
	p = str; // 주소를 다시 돌려놓습니다.
	puts(p);
}

void ex4() {
	char str[2][50], (*p)[50];
	p = str;
	int i;
	printf("소문자 문자열 입력 : ");
	gets_s(*p, 50);
	for (i = 0; *(*(p)+i); i++) {
		*(*(p + 1) + i) = *(*(p)+i) - 32;
	}
	*(*(p + 1) + i) = '\0';
	puts(*(p + 1));
}

void ex5() {
	char str1[50], str2[50], * p1, * p2;
	p1 = str1;
	p2 = str2;
	printf("첫번째 문자열 입력 : ");
	gets_s(p1, 50);
	printf("두번째 문자열 입력 : ");
	gets_s(p2, 50);
	printf("프로그램 수행 전 : %s, %s\n", p1, p2);
	int acount = 0, bcount = 0;
	for (int i = 0; *p1; i++) {
		p1++;
	}
	for (int i = 0; *p2; i++) {
		*p1++ = *p2++;
	}
	*p1 = '\0';
	p1 = str1;
	printf("프로그램 수행 후 : %s", p1);
}

void ex6() {
	char str[50], *p;
	p = str;
	printf("문자열 입력 : ");
	gets_s(p, 50);
	int i;
	for (i = 0; *p; i++, p++) {
	}
	printf("문자열 길이 : %d", i);
}

void ex7() {
	char str[50], ch, * p;
	p = str;
	printf("문자열 입력 : ");
	gets_s(p, 50);
	printf("문자 입력 : ");
	ch = _getche();
	int count = 0;
	for (int i = 0; *p; i++, p++) {
		if (*p == ch) count++;
	}
	p = str;
	printf("\n%s 문자열 내의 %c 문자의 개수는 %d", str, ch, count);
}

void ex8() {
	int arr[][4] = {
		78, 48, 78, 98,
		99, 92, 83, 29,
		29, 64, 83, 89,
		34, 78, 92, 56
	};
	int(*p)[4] = arr;
	int row, rowsum, col, colsum, total = 0;
	for (row = 0; row < sizeof(arr) / sizeof(arr[0]); row++) {
		rowsum = 0;
		for (col = 0; col < sizeof(arr[0]) / sizeof(int); col++) {
			rowsum += *(*(p + row) + col);
			total += *(*(p + row) + col);
		}
		printf("%d행의 합 : %d\n", row, rowsum);
	}
	for (col = 0; col < sizeof(arr) / sizeof(arr[0]); col++) {
		colsum = 0;
		for (row = 0; row < sizeof(arr[0]) / sizeof(int); row++) {
			colsum += *(*(p + row) + col);
		}
		printf("%d열의 합 : %d\n", col, colsum);
	}
	printf("전체의 합 : %d", total);

	
	/*
	int rowsum[4] = { 0, 0, 0, 0 }, colsum[4] = { 0, 0, 0, 0 }, sum = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0][0]); i++) {
		switch (i%4) {
		case 0:
			colsum[0] += *(*(p) + i);
			break;
		case 1:
			colsum[1] += *(*(p) + i);
			break;
		case 2:
			colsum[2] += *(*(p) + i);
			break;
		case 3:
			colsum[3] += *(*(p) + i);
			break;
		}
		if (i < 4) {
			rowsum[0] += *(*(p)+i);
		}
		else if (4 <= i && i < 8) {
			rowsum[1] += *(*(p)+i);
		}
		else if (8 <= i && i < 12) {
			rowsum[2] += *(*(p)+i);
		}
		else {
			rowsum[3] += *(*(p)+i);
		}
	}
	printf("\n");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d행의 합 = %d\n", i, rowsum[i]);
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d열의 합 = %d\n", i, colsum[i]);
		sum += colsum[i];
	}
	printf("총 합 = %d", sum);
	*/
}

void ex9() {
	int a[] = { 1, 2, 5, 7, 9, 14}, *ap;
	int b[] = { 2, 3, 6, 8, 13, 14}, *bp;
	ap = a;
	bp = b;
	int c[sizeof(a) / sizeof(a[0]) + sizeof(b) / sizeof(b[0])];
	int big = (sizeof(a) / sizeof(a[0]) > sizeof(b) / sizeof(b[0])) ? sizeof(a) / sizeof(a[0]) : sizeof(b) / sizeof(b[0]);
	for (int i = 0; i < big; i++) {
		if (i == big - 1 && sizeof(c)/sizeof(c[0])%2 == 1) {
			c[i * 2] = (big == sizeof(a) / sizeof(a[0])) ? *ap : *bp;
		}
		else {
			if (*ap == *bp) {
				c[i * 2] = *ap++;
				c[i * 2 + 1] = *bp++;
			}
			else if (*ap > *bp) {
				c[i * 2] = *bp++;
				c[i * 2 + 1] = *ap++;
			}
			else {
				c[i * 2] = *ap++;
				c[i * 2 + 1] = *bp++;
			}
		}
	}
	for (int i = 0; i < sizeof(c) / sizeof(c[0]); i++) {
		printf("%d  ", c[i]);
	}
}

void ex10() {
	char str[50], *p;
	p = str;
	printf("단어 입력 : ");
	gets_s(p, 50);
	printf("입력한 단어를 반대로 출력 : ");
	int i;
	for (i = 0; *p; i++, p++) {
	}
	for (; i >= 0; i--, p--) {
		printf("%c", *p);
	}
}

void ex11() {
	char str[50], *p;
	p = str;
	printf("소문자 문자열 입력 : ");
	gets_s(p, 50);
	for (int i = 0; *p; i++) {

	}
}

