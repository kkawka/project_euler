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
#include <iterator> 
#include "../lib/bigNum.h"

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


int getCycleLen(int i)
{
	int n = 1;
	v_i divs;
	it_v_i p = find(divs.begin(), divs.end(), n);
	while (1)
	{
		if (n < i)
		{
			divs.push_back(n);
			n *= 10;
		}
		else
		{
			p = find(divs.begin(), divs.end(), n);
			if (p != divs.end())
			{
				break;
			}
			divs.push_back(n);
			n = (n %= i) * 10;
			if (n == 0)
			{
				return 0;
			}
		}
	}
	return distance(p,divs.end());
}

int main()
{
	clock_t t;
	t = clock();
	
	int res = 1;
	int longest = 0;
	int cycleLen = 0;
	
	for (int i = 999; i > longest; --i)
	{
		cycleLen = getCycleLen(i);
		if (cycleLen > longest)
		{
			longest = cycleLen;
			res = i;
		}
	}
	
	cout << "res : " << res << endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};
