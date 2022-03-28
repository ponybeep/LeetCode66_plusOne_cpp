#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include <string>
#include <math.h>
#include <vector>


//题目描述：
//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放数组的首位，数组中每个元素只存储单个数字。
//可以假设除了整数0之外，这个整数不会以0开头

//解题思路一：
//考虑设置一个缓存变量sumtemp,其既可以是加法运算每一位相加后的和，也可以是和与10相除的结果（sumtemp/=10;)，也可以是和与10的余数（sumtemp%=10)。
//其中sumtemp/10后只能为0或者1，正好可以作为判断是否进行下一位高位加法的标志。
//值得注意的是边界条件，若digits={0},则判断整体大小是否加一应为if(ntemp==-1&&sumtemp),否则只需要判断if(ntemp=-1)。
//值得强调的是，转换一种思路，若是要让整体大小加一，则等价于该数组digits全是999,可以判断if(digits[0]=0),因为上一步会把sumetemp%10赋给digits[ntemp],即digits[0]=10%10=0,而正常情况下不可能一个整数数组
//（高位排序）是以0开头的。

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

		if (sumtemp && ntemp == -1)		//也可以用if(digits[0]==0)代替
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;

	}
};


//解题思路二：
//如果digits的末尾没有9，例如{1,2.3},直接将末尾的数加一，得到{1,2,4}返回
//若果digits的末尾有若干个9，例如{1,2,3,9,9},我们要找出从末尾开始的第一个不为9的元素，即3，将该元素加一，得到{1,2,4,9,9}。随后将末尾的9全部置0，得到{1,2,4,0,0}返回
//如果digits的所有元素都是9，例如{9,9,9,9}，答案为{1,0,0,0,0}。我们要构造一个长度比digits多1的新数组，将首元素置为1，其余元素为0即可。

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
				++digits[i];        //一定要注意不要在这里作为if语句花括号的结尾，因为若后几位为9，\
                还要判断那个数开始不为9，然后给所有9置换成0.
				for (int j = i + 1; j < n; ++j)
				{
					digits[j] = 0;
				}
				return digits;
			}
		}
		//接下来就是全为9的情况
		vector<int> ans(n + 1);		//ans(num)括号里面的数字代表赋初值num个0；
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
	cout << "正确答案应该为：	" << endl;
	cout << "ans1=" << 1 << "    ";
	cout << "ans2=" << 10 << "    ";
	cout << "ans3=" << 100 << "    ";
	cout << "ans4=" << 40 << "    ";
	cout << endl;
	cout << "测试的结果为：" << endl;
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
	cout << "正确答案应该为：	" << endl;
	cout << "ans1=" << 1 << "    ";
	cout << "ans2=" << 10 << "    ";
	cout << "ans3=" << 100 << "    ";
	cout << "ans4=" << 40 << "    ";
	cout << endl;
	cout << "测试的结果为：" << endl;
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
	cout << "-------------这是两种算法的华丽分割线------------" << endl;
	test02();






	system("pause");
	return 0;
}