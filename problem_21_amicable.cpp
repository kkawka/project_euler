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

int main()
{
	clock_t t;
	t = clock();
	
	v_i *divSum = new vector<int>(10000,0);
	
	llint res = 0;
	for (int i = 2; i < 10000; ++i)
	{
		divSum->at(i) = sumDiv(i);
	}
	
	for (int i = 2; i < 10000; ++i)
	{
		if(divSum->at(i) > 0 && 
			divSum->at(i) < 10000 &&
			divSum->at(i) != i &&
			i == divSum->at(divSum->at(i)))
		{
			res += i;
			res += divSum->at(i);
			divSum->at(divSum->at(i)) = -1;
			divSum->at(i) = -1;
		}
	}
	
	delete divSum;
	cout << res << endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	return 0;
};
