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

bool isPythagorean(int a, int b, int c)
{
	return ((a*a + b*b) == c*c);
}

int main()
{
	int a = 0; // 200, b == 375
	int c = 0; // 425
	
	for (c = 500; c > 333 ; --c)
	{
		for (a = 1; a < 1000 - c; ++a)
		{
			if (isPythagorean(a, 1000 - (a+c) ,c))
			{
				printf("res %d \n", a*c*(1000 - (a+c)));
				return 0;
			}
			
		}
	}	

	return 0;

};
