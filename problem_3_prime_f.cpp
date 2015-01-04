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

typedef vector<llint> v_lli;
typedef v_lli::iterator it_v_lli;

typedef set<llint> s_lli;
typedef s_lli::iterator it_s_lli;

typedef vector<string> v_str;
typedef v_str::iterator it_v_str;

typedef pair<string, string> pair_ss;

typedef vector< pair_ss > v_pair_ss;
typedef v_pair_ss::iterator it_v_pair_ss;

bool isPrime(llint num)
{
	if (num < 2)
	{
		return false;
	}
	
	for (llint i = 2; i*i <= num; ++i)
	{
		if ((num % i) == 0)
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	llint num = 600851475143;
	llint res = 0;
	llint tmp = 0;
	
	for (llint i = 1; i * i < num / 2; ++i)
	{

		if ((num % i) == 0)
		{
			tmp = num / i;
			if (isPrime(i) && i > res)
			{
				res = i;
			}
			if (isPrime(tmp) && tmp > res)
			{
				res = tmp;
			}
		}
	}
	
	printf("res %lld \n", res);
	return 0;
}
