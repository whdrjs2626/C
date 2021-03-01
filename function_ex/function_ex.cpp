#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double inchtocenti(double n); // ��ġ�� ��Ƽ���ͷ� �ٲٴ� �Լ�
int mysquare(int n); // �־��� ���� ������ ���ϴ� �Լ� 
int mycube(int n); // �־��� ���� �������� ���ϴ� �Լ�
int absolute(double n); // ���밪�� �����ϴ� �Լ�
int isprime(int n); // n�� �Ǽ����� �ƴ��� Ȯ���ϴ� �Լ�
void findnum(); // ������ ����� 7�� ���� ã�� �Լ�
void getnumber(int n); // n������ ���� 6��(�ζǹ�ȣ)�� �ߺ����� �ʰ� ����ϴ� �Լ�

void main(void) {
	//inchtocenti(1);
	
    //printf("2�� ������ %d, �������� %d, �ټ������� %d", mysquare(2), mycube(2), mysquare(2) * mycube(2));
	
    //printf("3.14�� ���밪 : %d", absolute(3.14));
    
    /*if (isprime(3) == 1) {
        printf("�Ǽ��Դϴ�.");
    }
    else {
        printf("�Ǽ��� �ƴմϴ�.");
    }*/
    
    //findnum();
    
    getnumber(45);
}

double inchtocenti(double n) {
	printf("%.2f��ġ�� %.2f��Ƽ���� �Դϴ�.", n, n * 2.54);
	return n * 2.54;
}

int mysquare(int n) {
	return n * n;
}

int mycube(int n) {
	return mysquare(n) * n;
}

int absolute(double n) {
	return n / 1;
}

int isprime(int n) {
    if (n <= 1)
    {
        return 0;
    }
    int half = n / 2; // n�� ��� �߿� n/2���� ū ���� ����. 
    for (int i = 2; i <= half; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void findnum() {
    int n;
    srand(time(NULL)); // �õ尪 �ʱ�ȭ
    int random = rand() % 100 + 1; // 1 ~ 100 ������ ���� �߻�
    printf("1 ~ 100�� ������ �����Ǿ����ϴ�. \n 7������ ã���ÿ�.\n ���� �Է� : ");
    scanf_s("%d", &n);
    for (int i = 0; i < 7; i++) {
        if (n == random) {
            printf("ã�ҽ��ϴ�! ������ ������ %d", n);
            return;
        }
        else if (n > random) {
            printf("�Է��� ������ �۽��ϴ�. ���Է� : ");
            scanf_s("%d", &n);
        }
        else {
            printf("�Է��� ������ Ů�ϴ�.   ���Է� : ");
            scanf_s("%d", &n);
        }
    }
    printf("��� ��ȸ�� ����ϼ̽��ϴ�. ã�� ����");
}

void getnumber(int n) {
    int arr[6];
    srand(time(NULL)); // �õ尪 �ʱ�ȭ
    for (int i = 0; i < 6; i++) {
        int random = rand() % 6 + 1;
        arr[i] = random;
        for (int j = 0; j < i; j++) {
            if (arr[j] == random) {
                i--;
                break;
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        printf("%d  ", arr[i]);
    }
}

