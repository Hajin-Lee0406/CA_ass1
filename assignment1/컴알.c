#include <stdio.h>
#include<math.h>
#include <stdlib.h>


void main() {

	int T[32] = {0}; // 2진수 
	int A[32] = {0}; // 8진수 
	char H[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; // 16진수 
	char S[20] = {0}; //16진수

	int D; //10진수

	printf("10진수 입력: ");
	scanf_s("%d", &D);

	int a = D; // 10진수->2진수
	int b = D; // 10진수->8진수
	int c = D; // 10진수->16진수

	////// 입력받은 수가 양수인 경우 //////
	if (D >= 0) { 
		while (a > 1) // 양수_2진수
		{
			for (int i = 0; i < 32; i++) {
				T[i] = a % 2;
				a = a / 2;
			}
		}
		while (b > 7) // 양수_8진수
		{
			for (int i = 0; i < 32; i++) {
				A[i] = b % 8;
				b = b / 8;
			}
		}
		// 양수_16진수
		int i16 = 0; // 반복용 변수 i16
		int M, N;
		do {
			M = c / 16;
			N = c % 16;
			S[i16] = H[N];
			i16++;
			c = M;
		} while (M >= 16);

		S[i16] = H[M];
		int K = i16;

		printf("2진수 : ");
		for (int i = 31; i >= 0; i--) { //index = 31~0출력
			printf("%d ", T[i]);
		}
		printf("\n8진수 : ");
		for (int i = 31; i >= 0; i--) { //index = 31~0출력
			printf("%d ", A[i]);
		}
		printf("\n16진수 : "); // K를 i부터 시작하여 1까지 감소하면서 T(K)를 출력
		do
		{
			printf("%c", S[K]);
			K--;
		} while (K>=0);
	}

	//////// 입력받은 수가 음수인 경우 ////////
	if (D < 0) {
		// 음수 _ 2진수
		a = -a; // 2진수_1)음수 부호 생략
		while (a > 1) // 2진수_2) 2진수 변형
		{
			for (int i = 0; i < 32; i++) {
				T[i] = a % 2;
				a = a / 2;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
			}
		}
		for (int i = 0; i <= 31; i++) { // 2진수_3) 1의 보수화
			T[i] = 1 - T[i];
		}	
		int B = 1; // 2진수_4) 가수(B=1)를 반영한다
		for (int i = 0; i <= 31; i++) {
			if (T[i] == 0) {
				T[i] = T[i] + B;
				B = 0;  // 0인경우 올림이 발생하지 않아 가수를 0으로 바꾸어준다.
			}
			if (T[i] == 1) { 
				T[i] = T[i] + B;
			}
		}
		for (int i = 0; i <= 31; i++) { // 원소 값이 2인 경우 0으로 바꾸어준다.
			if (T[i] == 2) {
				T[i] = 0;
			}
		}


		//음수_8진수 (2진수 이용)
		int count = 0;
		for (int i = 0; i <= 9; i++) {
			int A1 = 0;
			int A2 = 0; // 바깥 for문을 반복할 때 마다 초기화 해준다
			for (int j = 0; j <= 2; j++) { // 3비트씩 끊어주는 반복문
				A1 = T[j + count] * (int)pow(2,j);  
				A2 = A2 + A1;
			} // 2의 제곱값을 각 원소에 곱하여 더한 값을 A2에 누적 시켜준다
			A[i] = A2; 
			count = count + 3; // count를 이용해 배열T[]의 인덱스 값을 증가시킨다
		}
		A[10] = T[30] * (int)pow(2, 0) + T[31] * (int)pow(2, 1) + 0;

		//음수 16진수 (2진수 이용)
		int count2 = 0;
		for (int i = 0; i <= 7; i++) {
			int S1 = 0;
			int S2 = 0;
			for (int j = 0; j <= 3; j++) {
				S1 = T[j + count2] * (int)pow(2, j);
				S2 = S2 + S1;
			}
			S[i] = H[S2];
			count2 = count2 + 4;
		}


		// 출력
		printf("\n2진수 : ");
		for (int i = 31; i >= 0; i--) { //index = 31~0출력
			printf("%d ", T[i]);
		}
		printf("\n8진수 : ");
		for (int i = 31; i >= 0; i--) { //index = 31~0출력
			printf("%d ", A[i]);
		}
		printf("\n16진수 : ");
		for (int i = 19; i >= 0; i--) { //index = 19~0출력
			printf("%c ", S[i]);
		}
	}
}