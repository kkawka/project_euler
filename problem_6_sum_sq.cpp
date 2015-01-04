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



int main()
{
	llint sqr_sum = 101 * 50;
	sqr_sum *= sqr_sum;
	
	llint sum_sqr = 0;
	
	for (int i = 1; i < 101; ++i)
	{
		sum_sqr += i*i;
	}
	
	printf("res %lld", sqr_sum - sum_sqr);
	
	return 0;
}
