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

int circ(int num)
{
	int digit = num % 10;
	int base = num / 10;
	
	while (num >= 10)
	{
		digit *= 10;
		num /= 10;
	}
	return base + digit; 
}

bool isCircPrime(int i)
{
	int num = i;
	if (isPrime(i))
	{
		do
		{
			num = circ(num);
			if (!isPrime(num))
			{
				return false;
			}
		}
		while (num != i);
		
		return true;
		
	}
	return false;
}


void test()
{
	assert (11 == circ(11));
	assert (197 == circ(971));
	assert (971 == circ(719));
	assert (719 == circ(197));
	assert (197 == circ(circ(circ((197)))));
}


int main()
{
	clock_t t;
	t = clock();
	int res = 0;
	
	for (int i = 2; i < 1000000; ++i)
	{
		if (isCircPrime(i))		
		{
			++res;
		}
	}
	
	cout << "res : " << res << endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	cin >> res;
	
	return 0;
};
