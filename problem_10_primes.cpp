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

bool isPrime(int n)
{
	for (int i = 2; i*i <= n; ++i)
	{
		if ((n % i) == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	llint res = 5;
	for (int i = 5; i < 2000000; i += 2)
	{
		if (isPrime(i))
		{
			res += i;
		}
	}
	printf (" res %lld \n", res);
	return 0;
};
