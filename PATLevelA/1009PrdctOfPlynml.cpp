/*
This time, you are supposed to find A*B where A and B are two polynomials.
Input Specification:
Each input file contains one test case. Each case occupies 2 lines,
and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK,
where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients,
respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.
Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input.
Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
*/
//Ϊ��������㣬����ʹ��c
#include <cstdio>
#define MAX 2002 //������õ�����������Ԫ�ظ���
int main(void)
{
	int N = 0, exp = 0, count = 0;//�ֱ���������������ݴΣ�����������Ŀ
	double cof = 0.0f;//ʹ��double��ʾϵ��
	//�������飬��ʼ��Ϊ0����Ȼ���������ܾ�ȷ��ʾ������0�����ܵ�
	double pA[MAX / 2] = { 0, };
    double pB[MAX / 2] = { 0, };
	double result[MAX] = { 0, };
	//��������
	scanf("%d", &N);
	//����pA������
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %lf", &exp, &cof);
		pA[exp] = cof;
	}
    //����pB
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %lf", &exp, &cof);
		pB[exp] = cof;
	}
	//��ʼ����˻�
	for (int i = 0; i < MAX / 2; ++i)
	{
	    //pA[i] != 0���ܽ�ʡ��ʱ�����
		for (int j = 0; j < MAX / 2 && pA[i] != 0; ++j)
		{
		    //�ο�����ʽ�˷�����
			result[i + j] += pA[i] * pB[j];
		}
	}
	//��¼��Ϊ0��result����
	for (int i = 0; i < MAX; ++i)
	{
	    //�����ȷ�ȹ��ˣ�
		if (result[i] >= 0.1f || result[i] <= -0.1f)
		{
			++count;
		}
	}
	//���count
	printf("%d", count);
	//�������ʽ
	for (int i = MAX - 1; i >= 0; --i)
	{
		if (result[i] != 0.0f)
		{
		    //��ȷ��С�����1λ
			printf(" %d %.1f", i, result[i]);
			--count;
		}
	}
	//���У���Ȼû��Ҫ
	printf("\n");
	//����
	return 0;
}
