/*
At the beginning of every day, the first person who 
signs in the computer room will unlock the door,
and the last one who signs out will lock the door. 
Given the records of signing in's and out's, you are 
supposed to find the ones who have unlocked and locked the door on that day.
Input Specification:
Each input file contains one test case. Each case contains the records for one day. 
The case starts with a positive integer M, which is the total number of records, 
followed by M lines, each in the format:
ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, 
and ID number is a string with no more than 15 characters.
Output Specification:
For each test case, output in one line the ID numbers of the 
persons who have unlocked and locked the door on that day. 
The two ID numbers must be separated by one space.
Note: It is guaranteed that the records are consistent. 
That is, the sign in time must be earlier than the sign out time for each person, 
and there are no two persons sign in or out at the same moment.
Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133
*/
#include <iostream>
#include <string>

using namespace std;

class Student
{
	string number;//ѧ��
	int bgn;//��ʼ������ʱ�䣬����Ϊ��λ
	int end;

public:
	//�Կ�ʼѧ�����ж�
	bool operator < (const Student &a)
	{
		return bgn < a.bgn;
	}
	//������뿪��ѧ�����ж�
	bool operator > (const Student &a)
	{
		return end > a.end;
	}
	//��������
	friend istream& operator >> (istream &in, Student &a)
	{
		//ð����ch����
		char ch;
		int hour, min, sec;
		in >> a.number;//ѧ��
		in >> hour >> ch >> min >> ch >> sec;//����ʱ��ͦ���˵�
		a.bgn = hour * 3600 + min * 60 + sec;//��ʼ
		in >> hour >> ch >> min >> ch >> sec;
		a.end = hour * 3600 + min * 60 + sec;//����
		return in;//����in
	}
	//�������
	friend ostream& operator << (ostream &out, const Student &a)
	{
		//����Ҫ��ֻ��Ҫѧ�ţ����ѧ�ż��ɣ��������ص����Ҫ��
		//һ����Խ����Խ�ã���Ϊ�㲻֪�����������һ���ո�����ʲô
		out << a.number;
		return out;//����out��֤�������
	}
};

int main(void)
{
	//first��last�洢����ĺ�����ģ�unknown�洢δ֪��
	Student firstStu, lastStu, unknown;
	//N�������
	int N = 0;
	cin >> N;
	//�Ȱѵ�һ��ѧ�����룬Ȼ��������Ϊ����ĺ������
	cin >> unknown;
	firstStu = lastStu = unknown;
	for (int i = 1; i < N; ++i)
	{
		//���ζ��룬�ж��Ƿ����������
		cin >> unknown;
		if (unknown < firstStu)
		{
			firstStu = unknown;
		}
		//���ں����else���ҿ�ʼ�����ֻ��unknown����first���п�����last�����Ǻ����ύʱ2��3����ȥ��
		//ȥ��else���ˣ������뵽�˿�ʼ�ͽ�����û�й�ϵ�ģ����Բ�����else
		if (unknown > lastStu)
		{
			lastStu = unknown;
		}
	}
	//������
	cout << firstStu << " " << lastStu << endl;

	return 0;
}