/*
Given a sequence of K integers { N1, N2, ..., NK }.
A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. 
The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements.
For example, given sequence { -2, 11, -4, 13, -5, -2 }, 
its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
Input Specification:
Each input file contains one test case. Each case occupies two lines. 
The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.
Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence.
The numbers must be separated by one space, but there must be no extra space at the end of a line.
In case that the maximum subsequence is not unique, 
output the one with the smallest indices i and j (as shown by the sample case).
If all the K numbers are negative, then its maximum sum is defined to be 0, 
and you are supposed to output the first and the last numbers of the whole sequence.
Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/
#include <iostream>

using namespace std;

//����ṹ��
struct MaxSum
{
	int sum;//�˴��ɵõ�������
	int start;//��Ӧ�Ŀ�ͷ�ͽ�β
	int end;
};

int main(void)
{
	int N = 0;//��������
	//�ֱ�洢�������һ�������ڵ���ʱ��
	MaxSum result, last, temp;

	//����
	cin >> N;
	//���붯̬�滮����ʼ
	cin >> result.sum;
	result.end = result.start = result.sum;
	//����һ����Ϊlast
	last = result;

	for (int i = 1; i < N; ++i)
	{
		cin >> temp.end;//������һ����end����β

		//�����һ����sum����0����ô���ڵĿ��Եõ�������
		//һ�������ڵĽ�β����һ���ĺ�
		//����0�ǱȽϾ���ģ����last��sum��0����ôtemp��sum�ǲ�Ӧ�ü��ϵ�
		if (last.sum > 0)
		{
			//end���䣬start����last��start
			temp.sum = temp.end + last.sum;
			temp.start = temp.start;
		}
		//������ǵ�last��sumС�ڵ���0��ʱ����
		else if (temp.end > 0)//����һ����С�ڵ���0������һ��sum���Եõ��ı�Ȼ�������end��
		{
			//��start��sum��Ϊend��ֵ
			temp.start = temp.sum = temp.end;
		}
		//����һ����end��last��sumС��0����Ӧ�ðѸ��ļ���ȥ����֤һֱС��ȥ��
		//Ϊ�������last�Ǹ�����ô��ǰ��һ�����Ǹ��ģ�����ж����ȫ����׼��
		else if (temp.end < 0)
		{
			temp.sum = temp.end + last.sum;
			temp.start = last.start;
		}
		//����0��last��sum��С�ڵ���0�ģ�����0�ǿ�����������sum�ģ�˵������ȫ������
		else if (temp.end == 0)
		{
			temp.sum = temp.start = temp.end;
		}
		//�ж��Ƿ������
		if (temp.sum > result.sum)
		{
			result = temp;
		}
		//���ڵ�temp����һ����last
		last = temp;
	}

	//���С��0����˵��ȫС��0
	if (result.sum < 0)
	{
		//��ʱ��last��洢�˿�ʼ�ĺͽ�����ֵ
		cout << 0 << " " << last.start << " " << last.end << endl;
	}
	//���ڵ���0˵����ȫΪ�����������������
	else if (result.sum >= 0)
	{
		cout << result.sum << " " << result.start << " " << result.end << endl;
	}

	return 0;
}