#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include <string>
#include <math.h>
#include <vector>


//��Ŀ������
//����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//���λ���ִ���������λ��������ÿ��Ԫ��ֻ�洢�������֡�
//���Լ����������0֮�⣬�������������0��ͷ

//����˼·һ��
//��������һ���������sumtemp,��ȿ����Ǽӷ�����ÿһλ��Ӻ�ĺͣ�Ҳ�����Ǻ���10����Ľ����sumtemp/=10;)��Ҳ�����Ǻ���10��������sumtemp%=10)��
//����sumtemp/10��ֻ��Ϊ0����1�����ÿ�����Ϊ�ж��Ƿ������һλ��λ�ӷ��ı�־��
//ֵ��ע����Ǳ߽���������digits={0},���ж������С�Ƿ��һӦΪif(ntemp==-1&&sumtemp),����ֻ��Ҫ�ж�if(ntemp=-1)��
//ֵ��ǿ�����ǣ�ת��һ��˼·������Ҫ�������С��һ����ȼ��ڸ�����digitsȫ��999,�����ж�if(digits[0]=0),��Ϊ��һ�����sumetemp%10����digits[ntemp],��digits[0]=10%10=0,����������²�����һ����������
//����λ��������0��ͷ�ġ�

class Solution1
{
public:
	vector<int> plusOne(vector<int> digits)
	{
		int sumtemp = 1;
		int ntemp = digits.size() - 1;
		while (sumtemp && ntemp != -1)
		{
			sumtemp += digits[ntemp];
			digits[ntemp] = sumtemp % 10;
			sumtemp /= 10;
			ntemp--;
		}

		if (sumtemp && ntemp == -1)		//Ҳ������if(digits[0]==0)����
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;

	}
};


//����˼·����
//���digits��ĩβû��9������{1,2.3},ֱ�ӽ�ĩβ������һ���õ�{1,2,4}����
//����digits��ĩβ�����ɸ�9������{1,2,3,9,9},����Ҫ�ҳ���ĩβ��ʼ�ĵ�һ����Ϊ9��Ԫ�أ���3������Ԫ�ؼ�һ���õ�{1,2,4,9,9}�����ĩβ��9ȫ����0���õ�{1,2,4,0,0}����
//���digits������Ԫ�ض���9������{9,9,9,9}����Ϊ{1,0,0,0,0}������Ҫ����һ�����ȱ�digits��1�������飬����Ԫ����Ϊ1������Ԫ��Ϊ0���ɡ�

class Solution2
{
public:
	vector<int> plusOne(vector<int> digits)
	{
		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] != 9)
			{
				++digits[i];        //һ��Ҫע�ⲻҪ��������Ϊif��仨���ŵĽ�β����Ϊ����λΪ9��\
                ��Ҫ�ж��Ǹ�����ʼ��Ϊ9��Ȼ�������9�û���0.
				for (int j = i + 1; j < n; ++j)
				{
					digits[j] = 0;
				}
				return digits;
			}
		}
		//����������ȫΪ9�����
		vector<int> ans(n + 1);		//ans(num)������������ִ�����ֵnum��0��
		ans[0] = 1;
		return ans;

	}
};

void test01()
{
	vector<int> v1, v2, v3, v4;
	v1.push_back(0);
	v2.push_back(9);
	v3.push_back(9);
	v3.push_back(9);
	v4.push_back(3);
	v4.push_back(9);
	Solution1 solution;
	vector<int> ans1 = solution.plusOne(v1);
	vector<int> ans2 = solution.plusOne(v2);
	vector<int> ans3 = solution.plusOne(v3);
	vector<int> ans4 = solution.plusOne(v4);
	vector<vector<int>> v_ans;
	v_ans.push_back(ans1);
	v_ans.push_back(ans2);
	v_ans.push_back(ans3);
	v_ans.push_back(ans4);
	cout << "��ȷ��Ӧ��Ϊ��	" << endl;
	cout << "ans1=" << 1 << "    ";
	cout << "ans2=" << 10 << "    ";
	cout << "ans3=" << 100 << "    ";
	cout << "ans4=" << 40 << "    ";
	cout << endl;
	cout << "���ԵĽ��Ϊ��" << endl;
	for (int i = 0; i < 4; i++)
	{
		vector<int> anstemp = v_ans[i];
		cout << "ans" << i+1 << "=";
		for (vector<int>::iterator it = anstemp.begin(); it != anstemp.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}


}


void test02()
{
	vector<int> v1, v2, v3, v4;
	v1.push_back(0);
	v2.push_back(9);
	v3.push_back(9);
	v3.push_back(9);
	v4.push_back(3);
	v4.push_back(9);
	Solution2 solution;
	vector<int> ans1 = solution.plusOne(v1);
	vector<int> ans2 = solution.plusOne(v2);
	vector<int> ans3 = solution.plusOne(v3);
	vector<int> ans4 = solution.plusOne(v4);
	vector<vector<int>> v_ans;
	v_ans.push_back(ans1);
	v_ans.push_back(ans2);
	v_ans.push_back(ans3);
	v_ans.push_back(ans4);
	cout << "��ȷ��Ӧ��Ϊ��	" << endl;
	cout << "ans1=" << 1 << "    ";
	cout << "ans2=" << 10 << "    ";
	cout << "ans3=" << 100 << "    ";
	cout << "ans4=" << 40 << "    ";
	cout << endl;
	cout << "���ԵĽ��Ϊ��" << endl;
	for (int i = 0; i < 4; i++)
	{
		vector<int> anstemp = v_ans[i];
		cout << "ans" << i + 1 << "=";
		for (vector<int>::iterator it = anstemp.begin(); it != anstemp.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}


}






int main() {

	test01();
	cout << "-------------���������㷨�Ļ����ָ���------------" << endl;
	test02();






	system("pause");
	return 0;
}