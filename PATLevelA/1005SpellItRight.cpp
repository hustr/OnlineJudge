/*************************************************************************************************
Given a non-negative integer N, your task is to compute the sum of all the digits of N,
and output every digit of the sum in English.
Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).
Output Specification:
For each test case, output in one line the digits of the sum in English words.
There must be one space between two consecutive words, but no extra space at the end of a line.
Sample Input:
12345
Sample Output:
one five
****************************************************************************************************/
#include <iostream>
#include <string>

using namespace std;

//����һ��ת������ĺ���
//������Ҫ���������main()�ж����string����
void print(int num, const string *Number)
{
	int temp = num;//�������ñ����洢
	int count = 0;//count������¼λ��
	int t = 1;//Ҫ�����������ı���

	//��temp����9�ͼ������У�����Ŀ����t����ѭ�����ó���10��count����-1
	while (temp > 9)
	{
		temp /= 10;
		++count;
		t *= 10;
	}
	//�ָ�temp��ֵ
	temp = num;
	//����t��ֵ��������λ
	cout << Number[temp / t];//�����±�
	temp -= temp / t * t;//tempȥ������˵�λ�����õ���temp���0
	t /= 10;//t��count��Ӧ��С
	--count;

	while (count >= 0)
	{
	    //����ַ����Լ�����10
		cout << " " << Number[temp / t];
		temp -= temp / t * t;
		t /= 10;
		--count;
	}
	//���У�Ϊ������
	cout << endl;
}

int main(void)
{
    //����const string��Number����洢Ҫ�õ��ַ���
	const string Number[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	string str;//��str�洢Ҫ������ַ�����ֻ��Ϊ����[]���غܺ���
	int sum = 0;
	cin >> str;
	//���
	for (int i = 0; i < (int)str.length(); ++i)
	{
		sum += str[i] - '0';
	}
	//���
	print(sum, Number);
	//����
	return 0;
}
