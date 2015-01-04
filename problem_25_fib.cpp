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



int main()
{
	clock_t t;
	t = clock();
	
	Mq_BigNum f_n_1 = 1;
	Mq_BigNum f_n = 1;
	Mq_BigNum tmp;
	int res = 2;
	
	while (f_n.size() < 1000)
	{
		++res;
		tmp = f_n + f_n_1;
		f_n_1 = f_n;
		f_n = tmp;
	}
	
	cout << "res " << res  <<endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};
