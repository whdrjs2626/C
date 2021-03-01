#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double inchtocenti(double n); // 인치를 센티미터로 바꾸는 함수
int mysquare(int n); // 주어진 수의 제곱을 구하는 함수 
int mycube(int n); // 주어진 수의 세제곱을 구하는 함수
int absolute(double n); // 절대값을 리턴하는 함수
int isprime(int n); // n이 실수인지 아닌지 확인하는 함수
void findnum(); // 난수를 만들어 7번 내에 찾는 함수
void getnumber(int n); // n까지의 난수 6개(로또번호)를 중복되지 않게 출력하는 함수

void main(void) {
	//inchtocenti(1);
	
    //printf("2의 제곱은 %d, 세제곱은 %d, 다섯제곱은 %d", mysquare(2), mycube(2), mysquare(2) * mycube(2));
	
    //printf("3.14의 절대값 : %d", absolute(3.14));
    
    /*if (isprime(3) == 1) {
        printf("실수입니다.");
    }
    else {
        printf("실수가 아닙니다.");
    }*/
    
    //findnum();
    
    getnumber(45);
}

double inchtocenti(double n) {
	printf("%.2f인치는 %.2f센티미터 입니다.", n, n * 2.54);
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
    int half = n / 2; // n의 약수 중에 n/2보다 큰 것은 없다. 
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
    srand(time(NULL)); // 시드값 초기화
    int random = rand() % 100 + 1; // 1 ~ 100 사이의 난수 발생
    printf("1 ~ 100의 난수가 결정되었습니다. \n 7번내에 찾으시오.\n 정수 입력 : ");
    scanf_s("%d", &n);
    for (int i = 0; i < 7; i++) {
        if (n == random) {
            printf("찾았습니다! 생성된 난수는 %d", n);
            return;
        }
        else if (n > random) {
            printf("입력한 수보다 작습니다. 재입력 : ");
            scanf_s("%d", &n);
        }
        else {
            printf("입력한 수보다 큽니다.   재입력 : ");
            scanf_s("%d", &n);
        }
    }
    printf("모든 기회를 사용하셨습니다. 찾기 실패");
}

void getnumber(int n) {
    int arr[6];
    srand(time(NULL)); // 시드값 초기화
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

