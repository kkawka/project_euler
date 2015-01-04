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

int divNum(llint num)
{
	int cnt = 2;
	int maxDiv = num / 2;
	for (int i = 2; i < maxDiv; ++i)
	{
		if (num % i == 0)
		{
			cnt++;
			if (i != num / i)
			{
				cnt++;
			}
			maxDiv = num / i;
		}
	}
	return cnt;
}

int main()
{
	llint res = 28 ;
	int i = 8;
	while (1)
	{
		res += i++;
		if (divNum(res) > 500)
		{
			cout << res << endl;
			break;
		}
	
	}
	return 0;
};
