#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <ctype.h>

using namespace std;

typedef long long int llint;

typedef vector<bool> v_b;
typedef v_b::iterator it_v_b;

typedef vector<int> v_i;
typedef v_i::iterator it_v_i;

typedef set<int> s_i;
typedef s_i::iterator it_s_i;

typedef vector<string> v_str;
typedef v_str::iterator it_v_str;

typedef pair<string, string> pair_ss;

typedef vector< pair_ss > v_pair_ss;
typedef v_pair_ss::iterator it_v_pair_ss;


bool isPalindrome(string s_num)
{
	int i = 0;
	int j = s_num.size() - 1;
	while (i <= j)
	{
		if (s_num.c_str()[i++] != s_num.c_str()[j--])
		{
			return false;
		}
	}
	return true;
}


int main()
{
	int num = 0;
	int res = 0;
	char s_num[10];
	for(int i = 999; i > 99; --i)
	{
		for(int j = i; j > 99; --j)
		{
			num = i * j;
			sprintf(s_num, "%d", num);
			if (isPalindrome(s_num) && num > res)
			{
				res = num;
			}
		}
	}
	
	printf ("res %d \n", res);
	return 0;
}
