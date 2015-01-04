#include <vector>
#include <string>
#include <set>
#include <list>
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
typedef list<int> l_i;
typedef l_i::iterator it_l_i;
typedef vector<string> v_str;
typedef v_str::iterator it_v_str;
typedef pair<string, string> pair_ss;
typedef vector< pair_ss > v_pair_ss;
typedef v_pair_ss::iterator it_v_pair_ss;

llint calcCollatzLen(llint i)
{
	llint res = 1;

	while (i != 1)
	{
		if (i % 2 == 0)
		{
			i >>= 1;
		}
		else
		{
			i *= 3;
			++i;
		}
		++res;
	}
	return res;
}


int main()
{
	llint res = 0;
	llint collatzLen = 0;
	llint collatzLenMax = 0;
	for (int i = 2; i < 1000000; ++i)
	{
		collatzLen = calcCollatzLen(i);
		if (collatzLen > collatzLenMax)
		{
			collatzLenMax = collatzLen;
			res = i;
		}
	}
	
	cout << res << endl;
	return 0;
};
