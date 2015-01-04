#include <set>
#include <list>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <ctype.h>
#include <time.h>   
#include <assert.h>   
#include "../lib/bigNum.h"
#include "../lib/algo.h"

using namespace std;
using namespace Mq_algo;


typedef set<int> s_i;
typedef s_i::iterator it_s_i;


int getMaxPower(int n)
{
	int res = 1;
	int tmp;
	for(int i = 2 ; i*i <= n; ++i)
	{
		tmp = i;
		res = 1;
		while (tmp < n)
		{
			tmp *= i;
			++res;
		}
		if (tmp == n)
		{
			return res;
		}
	}
	return 1;
}


void testMaxPower()
{
	assert(getMaxPower(2) == 1);
	assert(getMaxPower(3) == 1);
	assert(getMaxPower(4) == 2);
	assert(getMaxPower(5) == 1);
	assert(getMaxPower(6) == 1);
	assert(getMaxPower(7) == 1);
	assert(getMaxPower(8) == 3);
	assert(getMaxPower(9) == 2);
	assert(getMaxPower(16) == 4);
	assert(getMaxPower(25) == 2);
	assert(getMaxPower(27) == 3);
	assert(getMaxPower(32) == 5);
	assert(getMaxPower(64) == 6);
	assert(getMaxPower(72) == 1);
	assert(getMaxPower(100) == 2);
}

int main()
{
	testMaxPower();

	clock_t t;
	t = clock();
	int res = 0;

	s_i powers;
	v_i distPowers;
	distPowers.reserve(7);
	int distCnt = 0;
	
	distPowers.push_back(0);
	distPowers.push_back(99);
	
	for(int i = 2; i < 101; ++i)
	{
		powers.insert(i);
	}
	
	for(int i = 2; i < 7; ++i)
	{
		distCnt = 0;
		for(int j = 2 ; j < 101; ++j)
		{
			if (powers.find(i*j) == powers.end() )
			{
				++distCnt;
				powers.insert(i*j);
			}
		}
		distPowers.push_back(distCnt);
	}
	
	for (int i = 2; i < 101; ++i)
	{
		res += distPowers[getMaxPower(i)];
	}
	
	
	cout << "res : " << res << endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};
