#include <vector>
#include <string>
#include <set>
#include <list>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <ctype.h>
#include <time.h>   

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

static const int NUM_LIMIT = 28123;

int sumDiv(int num)
{
	int res = 1;
	int maxDiv = num / 2 + 1;
	for (int i = 2; i < maxDiv; ++i)
	{
		if (num % i == 0)
		{
			res += i;
			if (i != num / i)
			{
				res += num / i;
			}
			maxDiv = num / i;
		}
	}
	return res;
}

bool isAbundant(int i)
{
	return i < sumDiv(i);
}

bool isAbundantSum(int n, v_i & abuNums)
{
	it_v_i u_bound = lower_bound (abuNums.begin(), abuNums.end(), n);
	it_v_i l_bound = abuNums.begin();
	while (l_bound != u_bound)
	{
		if (binary_search(l_bound, u_bound, n - *l_bound))
		{
			return true;
		}
		++l_bound;
	}
	
	return false;
}

int main()
{
	clock_t t;
	t = clock();
	llint res = 0 ;
	
	v_i abuNumbers;
	abuNumbers.reserve(200);
	
	for (int i = 1; i < NUM_LIMIT; ++i)
	{
		if (isAbundant(i))
		{
			abuNumbers.push_back(i);
		}
	}
	
	for (int i = 1; i < NUM_LIMIT; ++i)
	{
		if (!isAbundantSum(i, abuNumbers))
		{
			res += i;
		}
	}
	
	cout << res << endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};
