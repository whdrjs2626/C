#include <stdio.h>
#include <conio.h>

void int_Ex();
void char_Ex();
void string_Ex();
void intArray_Ex();
void charArray_Ex();
void stringArray_Ex();
void ex1();  // double�� �迭�� �����ͷ� �����ϴ� �Լ�
void ex2();  // ������ �迭���� �����ͷ� ��� ������ ���� n�� ������Ű�� �Լ�
void ex3();  // 1���� �迭�� �ҹ��� ���ڿ��� �����ͷ� �빮�ڷ� ��ȯ�ϴ� �Լ� (touppper ��� X)
void ex4();  // 2���� �迭 1�࿡ �ҹ��� ���ڿ� �Է� �� �����ͷ� 2�࿡ �빮�ڸ� �����ϴ� �Լ�
void ex5();  // �����ͷ� �� ���ڿ� �ձ� == strcat
void ex6();  // �����ͷ� ���ڿ� ���� ���
void ex7();  // ���ڿ��� ���� �ϳ��� �Է¹޾� ���ڿ��� �ش� ���ڰ� �� ������ ���
void ex8();  // 2���� ���� �迭�� �� ��, �� �� , �� ���� ���ϱ�
void ex9();  // ������������ ���ĵǾ� �ִ� �� ������ ���� �迭 ��ġ��, ���� �迭�� ���ĵǾ� �־�� ��
void ex10(); // ���ڿ� ���� ���
void ex11(); // �ҹ��� ���ڿ��� �� ���ڰ� ��� �ִ��� ��� -> ex7 ����

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
	char arr[5], * p;
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

void ex1() {
	double source[] = { 3.12, 5.14, 7.25, 7.48, 5.91 }, * p;
	p = source;
	double target[sizeof(source) / sizeof(source[0])];
	for (int i = 0; i < sizeof(target) / sizeof(target[0]); i++) {
		target[i] = *(p + i);
	}
	printf("������ �迭 ��� : ");
	for (int i = 0; i < sizeof(target) / sizeof(target[0]); i++) {
		printf("%.2f  ", target[i]);
	}
	printf("\n\n");
}

void ex2() {
	int data[] = { 3, 21, 35, 57, 24 }, n, * p;
	p = data;
	printf("���Ҹ��� ������ų �� �Է� : ");
	scanf_s("%d", &n);
	printf("������ �迭 ���ҵ� : ");
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		*(p + i) += n;
		printf("%d  ", *(p + i));
	}
	printf("\n\n");
}

void ex3() {
	char str[50], * p;
	p = str;
	printf("���ڿ� �Է� : ");
	gets_s(p, 50);
	while (*p) {
		*(p++) -= 32;
	}
	p = str; // �ּҸ� �ٽ� ���������ϴ�.
	puts(p);
}

void ex4() {
	char str[2][50], (*p)[50];
	p = str;
	int i;
	printf("�ҹ��� ���ڿ� �Է� : ");
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
	printf("ù��° ���ڿ� �Է� : ");
	gets_s(p1, 50);
	printf("�ι�° ���ڿ� �Է� : ");
	gets_s(p2, 50);
	printf("���α׷� ���� �� : %s, %s\n", p1, p2);
	int acount = 0, bcount = 0;
	for (int i = 0; *p1; i++) {
		p1++;
	}
	for (int i = 0; *p2; i++) {
		*p1++ = *p2++;
	}
	*p1 = '\0';
	p1 = str1;
	printf("���α׷� ���� �� : %s", p1);
}

void ex6() {
	char str[50], *p;
	p = str;
	printf("���ڿ� �Է� : ");
	gets_s(p, 50);
	int i;
	for (i = 0; *p; i++, p++) {
	}
	printf("���ڿ� ���� : %d", i);
}

void ex7() {
	char str[50], ch, * p;
	p = str;
	printf("���ڿ� �Է� : ");
	gets_s(p, 50);
	printf("���� �Է� : ");
	ch = _getche();
	int count = 0;
	for (int i = 0; *p; i++, p++) {
		if (*p == ch) count++;
	}
	p = str;
	printf("\n%s ���ڿ� ���� %c ������ ������ %d", str, ch, count);
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
		printf("%d���� �� : %d\n", row, rowsum);
	}
	for (col = 0; col < sizeof(arr) / sizeof(arr[0]); col++) {
		colsum = 0;
		for (row = 0; row < sizeof(arr[0]) / sizeof(int); row++) {
			colsum += *(*(p + row) + col);
		}
		printf("%d���� �� : %d\n", col, colsum);
	}
	printf("��ü�� �� : %d", total);

	
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
		printf("%d���� �� = %d\n", i, rowsum[i]);
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d���� �� = %d\n", i, colsum[i]);
		sum += colsum[i];
	}
	printf("�� �� = %d", sum);
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
	printf("�ܾ� �Է� : ");
	gets_s(p, 50);
	printf("�Է��� �ܾ �ݴ�� ��� : ");
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
	printf("�ҹ��� ���ڿ� �Է� : ");
	gets_s(p, 50);
	for (int i = 0; *p; i++) {

	}
}

