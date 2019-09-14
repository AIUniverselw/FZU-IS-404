#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

//����ģ26�����������������ʾ�����򣬽����ο�
//����ǿ

//��������
int** genA(int n);
void matrixAddRangeMod26(int** A, int n, int Li, int Lj, int r);
int mod26(int x);
int getRandomReversableMod26();
int getReverMod26(int a);
int extendEuclid(int a, int b, int* result);
void printMatrix(int** A, int n);
int getDetMod26(int** A, int n);
int** getStarMatrixMod26(int** A, int n);
int** getReverseMatrixMod26(int** A, int n);
void freeMatrix(int** A, int n);

//����ʾ������������һ��ģ26�����������
int main() {
	int n=3;
	int** A;
	int ADet;
	int** AR;
	printf("����������ģn(n>2):");
	scanf_s("%d", &n);
	//�������
	srand(time(NULL));
	//��̬���ɾ���A
	A = genA(n);
	//��ӡ�������A
	printMatrix(A, n);
	//������ʽ��ֵ
	ADet = getDetMod26(A, n);
	printf("\n����ʽ�������ǣ�%d \n",ADet);
	//��������
	AR = getReverseMatrixMod26(A,n);
	//��ӡ�������A
	printf("������:\n");
	printMatrix(AR, n);
	//�ͷ��ڴ�
	freeMatrix(A,n);
	freeMatrix(AR, n);

	//���Կα�����
	int AAE[3][3] = { {11,2,19},{5,23,25},{20,7,17} };
	int** AA= (int**)malloc(sizeof(int*) * 3);
	AA[0] = AAE[0];
	AA[1] = AAE[1];
	AA[2] = AAE[2];
	//��ӡ���
	printf("�̲���1-2�õľ����ǣ�\n");
	printMatrix(AA, 3);
	//������ʽֵ
	int AADet = getDetMod26(AA, 3);
	printf("����ʽֵΪ��%d\n��ԪΪ��%d\n",AADet, getReverMod26(AADet));
	//��������
	int** AAS = getStarMatrixMod26(AA, 3);
	printf("��������ǣ�\n");
	printMatrix(AAS, 3);
	//������
	int** AAR= getReverseMatrixMod26(AA, 3);
	printf("�������ǣ�\n");
	printMatrix(AAR, 3);
	//�ͷ��ڴ�
	freeMatrix(AAS, 3);
	freeMatrix(AAR, 3);
	free(AA);
}

//��̬���ɾ���
int** genA(int n) {
	if (n < 3)return NULL;
	//����ά�������ռ�
	int** A;
	A = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(sizeof(int) * n);
	}
	//���Խ�����1
	for (int i = 0; i < n;i++) {
		A[i][i] = 1;
	}
	//�����Ͻ��������
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			A[i][j] = rand() % 26;
	//ͨ�����ȱ任�������½������
	for (int i = n - 2; i >= 0; i--) 
		for (int j = i + 1; j < n; j++) {
			//���ȱ任��Lj=Lj+Li*r
			matrixAddRangeMod26(A, n, i, j, rand()%25+1);
		}
	//���Խ����Ƿ�Ϊ1
	for (int i = 0; i < n; i++)
		if (A[i][i] == 1) {
			//�г��Ͽ��������
			int r = getRandomReversableMod26();
			for (int j = 0; j < n; j++)
				A[i][j] = mod26(A[i][j] * r);
		}
	return A;
}
//���ȱ任�����(ģ26����)��Lj=Lj+Li*r
void matrixAddRangeMod26(int** A,int n, int Li, int Lj, int r) {
	for (int i = 0; i < n; i++) 
		A[Lj][i] = mod26(A[Lj][i]+ A[Li][i]*r);	
}
//��26ȡģ
int mod26(int x) {
	return (x % 26 + 26) % 26;
}
//��ȡģ26���������
int getRandomReversableMod26() {
	int r = rand() % 25 + 1;
	while (getReverMod26(r) == -1)
		r++;
	return r;
}

//��ģ26��Ԫ,����ֵΪ-1��û����Ԫ
int getReverMod26(int a) {
	int b = 0;
	int c = 0;
	c = extendEuclid(26, a, &b);
	if (c == 0) return -1;
	return b;
}

//��չŷ������㷨
//����ֵY3,0��ʾ���ص���ab���Լ����1��ʾ���ص���b��ģa�µ���Ԫ
int extendEuclid(int a,int b,int* result) {
	int x[3] = { 1,0,a };
	int y[3] = { 0,1,b };
	int t[3] = { 0,0,0 };
	while (y[2]!=0 && y[2]!=1) {
		int q = x[2] / y[2];
		t[0] = x[0] - y[0] * q;
		t[1] = x[1] - y[1] * q;
		t[2] = x[2] - y[2] * q;
		x[0] = y[0];
		x[1] = y[1];
		x[2] = y[2];
		y[0] = t[0];
		y[1] = t[1];
		y[2] = t[2];
	}
	if (y[2] == 0) {
		//�й�����
		*result = x[2];
		return 0;
	}
	else{
		//ab����
		*result = y[1];
		return 1;
	}
}

// �������
void printMatrix(int** A, int n) {
	printf("\n");
	for (int i = 0; i < n; i++){
		printf("| ");
		for (int j = 0; j < n; j++) {
			printf("%2d ",A[i][j]);
		}
		printf("|\n");
	}
}
//��ģ26����ʽ��ֵ��
int getDetMod26(int** A,int n) {
	int det = 0;
	int item = 0;
	if (n <= 0)return 0;
	if (n == 1) return A[0][0];
	if (n == 2) {
		det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	}
	else {
		det = 0;
		for (int i = 0; i < n; i++)
			det = det + A[0][i] * getSubDetMod26(A,n,0,i);
	}
	//����ģ26���
	return mod26(det);
}

//��ģ26��������ʽ
int getSubDetMod26(int** A, int n,int i,int j) {
	//��Ч�Լ��
	if (i >= n || j >= n||i<0||j<0)return 0;
	//����������ʽ�ռ�
	int** subA;
	subA = (int**)malloc(sizeof(int*) * (n-1));
	for (int i = 0; i < n-1; i++) {
		subA[i] = (int*)malloc(sizeof(int) * (n-1));
	}
	//��������ʽ��ֵ(���ĸ�����)
	for (int r = 0; r < i; r++)
		for (int c=0;c<j;c++)
			subA[r][c]=A[r][c];
	for (int r = 0; r < i; r++)
		for (int c = j; c < n-1; c++)
			subA[r][c] = A[r][c+1];
	for (int r = i; r < n-1; r++)
		for (int c = 0; c < j; c++)
			subA[r][c] = A[r+1][c];
	for (int r = i; r < n-1; r++)
		for (int c = j; c < n - 1; c++)
			subA[r][c] = A[r+1][c + 1];
	//printf("��������ʽ:\n");
	//printMatrix(subA, n-1);
	//����������ʽ��ֵ
	int subADet = getDetMod26(subA, n - 1);
	//printf("��������ʽ������:%d\n", subADet);
	//��������ʽ������
	if ((i + j) % 2 == 1)
		subADet = (26 - subADet)%26; //�ӷ���Ԫ
	//�ͷż����õ�������ʽ�ռ�
	freeMatrix(subA,n-1);

	return subADet;
}

//��ģ26�������
int** getStarMatrixMod26(int** A,int n) {
	//������������ռ�
	int** AStar;
	AStar = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n ; i++) {
		AStar[i] = (int*)malloc(sizeof(int) * n);
	}
	//���������Ԫ�ظ�ֵ
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			AStar[j][i] = getSubDetMod26(A,n,i,j);
	return AStar;
}

//��ģ26����
int** getReverseMatrixMod26(int** A,int n) {	
	//��A����ʽ��ֵ
	int ADet = getDetMod26(A,n);
	//����Ԫ
	int RADet = getReverMod26(ADet);
	//��������
	int** AR = getStarMatrixMod26(A,n);
	//������
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			AR[i][j] = mod26(AR[i][j] * RADet);
	return AR;
}

//�ͷž����ڴ�
void freeMatrix(int** A,int n) {
	for (int i = 0; i < n; i++)
		free(A[i]);
	free(A);
}
