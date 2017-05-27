/******************************************************************************************************
This time, you are supposed to find A+B where A and B are two polynomials.
Input
Each input file contains one test case.
Each case occupies 2 lines, and each line contains the information of a polynomial:
K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial,
Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively.
It is given that 1 <= K <= 10��0 <= NK < ... < N2 < N1 <=1000.
Output
For each test case you should output the sum of A and B in one line, with the same format as the input.
Notice that there must be NO extra space at the end of each line.
Please be accurate to 1 decimal place.
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
*******************************************************************************************************/
//����ͷ�ļ�
#include <iostream>
#include <cstdio>//��Ҫ����С�����һλ��������%.1f����ʱ������c++�ı�׼���
#define MAXK 1001 //��������ʹ��

using namespace std;

int main(void)
{
	float aK[MAXK] = { 0, };//ϵ�����飬�Դ�ָ��
	int iN = 0;//��Ҫ�������Ŀ
	int ix = 0;
	float ia = 0;//ָ����ϵ��

	//��һ������
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		cin >> ix >> ia;
		aK[ix] += ia;
	}//end of for (int i = 0; i < iN; ++i)

	//�ڶ�������
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		cin >> ix >> ia;
		aK[ix] += ia;
	}//end of for (int i = 0; i < iN; ++i)

	//������ϣ���ʼ�����
	//�ȼ���������Ч����
	int iCount = 0;
	for (int i = 0; i < MAXK; ++i)
	{
		if (aK[i] != 0)
		{
			++iCount;
		}//end of if (aK[i] > 0)
	}//end of for (int i = MAXK - 1; i >= 0; --i)

	cout << iCount;//�����Ч��
	
	//��������Ӹߵ������
	for (int i = MAXK - 1; i >= 0 && iCount > 0; --i)
	{
		if (aK[i] != 0)
		{
			printf(" %d %.1f", i, aK[i]);
			--iCount;
		}//end of if (aK[i] > 0)
	}//end of for (int i = MAXK - 1; i >= 0; --i)
	cout << endl;

	return 0;
}