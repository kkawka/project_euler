#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <ctype.h>

using namespace std;

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

int main()
{
	s_i numbers; 
	for (int i = 1; i < 334; ++i)
	{
		numbers.insert(3*i);
	}
	
	for (int i = 1; i < 200; ++i)
	{
		if (numbers.find(5*i) == numbers.end())
		{
			numbers.insert(5*i);
		}
	}
	
	int res = accumulate(numbers.begin(), numbers.end(), 0);
	
	printf("sum %d \n", res);
	return 0;
}
