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

static llint prev_fib = 0; 
static llint curr_fib = 1;

int main()
{
	llint sum = 0;
	llint new_fib = 0;
	while (1)
	{
		new_fib = prev_fib + curr_fib;
		if (new_fib > 4000000)
		{
			break;
		}
		
		if ((new_fib % 2) == 0)
		{
			sum += new_fib; 
		}
		prev_fib = curr_fib;
		curr_fib = new_fib;
	}
	
	printf ("sum %lld \n", sum);
	return 0;
}
