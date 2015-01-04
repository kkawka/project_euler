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


typedef std::set<int> s_i;
typedef s_i::iterator it_s_i;

static const int pandigit = 0x1ff; // pandigit mask

inline int getDigits(int i)
{
	int flags = 0;
	int flag = 0;
	while (i > 0)
	{
		flag = (1 << ((i % 10) - 1));
		if (flags & flag) // already exist
		{
			return 0;
		}
		flags |= flag;
		i /= 10;
	}
	return flags;
}

inline int getLen(int i)
{
	int res = 1;
	while (i /= 10)
	{
		++res;
	}
	return res;
}


bool isUnusual(int i, int j, int prod)
{
	int flags = 0;
	int len = 0;
	
	len += getLen(i);
	len += getLen(j);
	len += getLen(prod);

	if (len != 9)
	{
		return false;
	}

	flags ^= getDigits(i);		// XOR
	flags ^= getDigits(j);		// XOR
	flags ^= getDigits(prod);	// XOR

	
	return pandigit == flags;
}

int main()
{
	clock_t t;
	t = clock();
	int res = 0;
	int prod = 0;
	
	assert(isUnusual(39,186,7254));
	
	s_i pandigital; 
	
	for (int i = 1 ; i < 100 ; ++i)
	{
		int lowerB = (i < 10) ? 1234 : 123;
		int upperB = (i < 10) ? 9876 : 987;
		for (int j = lowerB ; j < upperB ; ++j)
		{
			prod = i*j;
			if (isUnusual(i,j,prod))
			{
				cout << "U " << i << " " << j << " " << prod << endl;
				if (pandigital.find(prod) == pandigital.end())
				{
					res += prod;
					pandigital.insert(prod);
				}
			}
		}
	}
	
	
	cout << "res : " << res << endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	cin >> res;
	
	return 0;
};
