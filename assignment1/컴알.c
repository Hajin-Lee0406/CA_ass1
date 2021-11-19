#include <stdio.h>
#include<math.h>
#include <stdlib.h>


void main() {

	int T[32] = {0}; // 2���� 
	int A[32] = {0}; // 8���� 
	char H[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; // 16���� 
	char S[20] = {0}; //16����

	int D; //10����

	printf("10���� �Է�: ");
	scanf_s("%d", &D);

	int a = D; // 10����->2����
	int b = D; // 10����->8����
	int c = D; // 10����->16����

	////// �Է¹��� ���� ����� ��� //////
	if (D >= 0) { 
		while (a > 1) // ���_2����
		{
			for (int i = 0; i < 32; i++) {
				T[i] = a % 2;
				a = a / 2;
			}
		}
		while (b > 7) // ���_8����
		{
			for (int i = 0; i < 32; i++) {
				A[i] = b % 8;
				b = b / 8;
			}
		}
		// ���_16����
		int i16 = 0; // �ݺ��� ���� i16
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

		printf("2���� : ");
		for (int i = 31; i >= 0; i--) { //index = 31~0���
			printf("%d ", T[i]);
		}
		printf("\n8���� : ");
		for (int i = 31; i >= 0; i--) { //index = 31~0���
			printf("%d ", A[i]);
		}
		printf("\n16���� : "); // K�� i���� �����Ͽ� 1���� �����ϸ鼭 T(K)�� ���
		do
		{
			printf("%c", S[K]);
			K--;
		} while (K>=0);
	}

	//////// �Է¹��� ���� ������ ��� ////////
	if (D < 0) {
		// ���� _ 2����
		a = -a; // 2����_1)���� ��ȣ ����
		while (a > 1) // 2����_2) 2���� ����
		{
			for (int i = 0; i < 32; i++) {
				T[i] = a % 2;
				a = a / 2;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
			}
		}
		for (int i = 0; i <= 31; i++) { // 2����_3) 1�� ����ȭ
			T[i] = 1 - T[i];
		}	
		int B = 1; // 2����_4) ����(B=1)�� �ݿ��Ѵ�
		for (int i = 0; i <= 31; i++) {
			if (T[i] == 0) {
				T[i] = T[i] + B;
				B = 0;  // 0�ΰ�� �ø��� �߻����� �ʾ� ������ 0���� �ٲپ��ش�.
			}
			if (T[i] == 1) { 
				T[i] = T[i] + B;
			}
		}
		for (int i = 0; i <= 31; i++) { // ���� ���� 2�� ��� 0���� �ٲپ��ش�.
			if (T[i] == 2) {
				T[i] = 0;
			}
		}


		//����_8���� (2���� �̿�)
		int count = 0;
		for (int i = 0; i <= 9; i++) {
			int A1 = 0;
			int A2 = 0; // �ٱ� for���� �ݺ��� �� ���� �ʱ�ȭ ���ش�
			for (int j = 0; j <= 2; j++) { // 3��Ʈ�� �����ִ� �ݺ���
				A1 = T[j + count] * (int)pow(2,j);  
				A2 = A2 + A1;
			} // 2�� �������� �� ���ҿ� ���Ͽ� ���� ���� A2�� ���� �����ش�
			A[i] = A2; 
			count = count + 3; // count�� �̿��� �迭T[]�� �ε��� ���� ������Ų��
		}
		A[10] = T[30] * (int)pow(2, 0) + T[31] * (int)pow(2, 1) + 0;

		//���� 16���� (2���� �̿�)
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


		// ���
		printf("\n2���� : ");
		for (int i = 31; i >= 0; i--) { //index = 31~0���
			printf("%d ", T[i]);
		}
		printf("\n8���� : ");
		for (int i = 31; i >= 0; i--) { //index = 31~0���
			printf("%d ", A[i]);
		}
		printf("\n16���� : ");
		for (int i = 19; i >= 0; i--) { //index = 19~0���
			printf("%c ", S[i]);
		}
	}
}