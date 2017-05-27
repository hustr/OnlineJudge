#include<iostream>
#include<cstdio>//ʹ��C�ı�׼����������м䲻��3λ

using namespace std;

void Output(int target);

int Print(char ch){
	int r = 0;
	r = ch - '0';
	return r;
}

int main(void)
{
	//�������������
	int a = 0;
	int b = 0;
	cin >> a >> b;

	//����Output����
	Output(a + b);

	return 0;
}

void Output(int target)
{
	int count = 1;//����λ��
	int test = target;//ʹ�þֲ������������ԭ���ݸĶ�

					  //�ж�������Ϊ��һ��׼��
	if (test < 0)
	{
		cout << '-';
		test = 0 - test;
		target = test;//�ʵ��Ķ�
	}

	//����λ��
	while (test > 9)
	{
		++count;
		test /= 10;
	}
	test = target;//�ָ�test��ֵ

	if (count <= 3)
	{
		printf("%d\n", test);//ֱ�������������Ϊ0��һλ����count = 1
	}
	else if (count <= 6)
	{
		printf("%d,%03d\n", test / 1000, test % 1000);//��׼�������
	}
	else
	{
		printf("%d,", test / 1000000);//�������ǰ��
		test -= test / 1000000 * 1000000;//���������ϵ�ȥ��
		printf("%03d,%03d\n", test / 1000, test % 1000);//��������
	}

	return;//�����˳�������һ��ϰ�߰�
}

/************************
Calculate a + b and output the sum in standard format.
that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
Input
Each input file contains one test case. 
Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. 
The numbers are separated by a space.
Output
For each test case, you should output the sum of a and b in one line. 
The sum must be written in the standard format.
Sample Input
-1000000 9
Sample Output
-999,991
*************************/
