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

static bool isPrime (llint num)
{
	if (num < 2)
	{
		return false;
	}
	
	for (llint i = 2; i*i <= num; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	
	return true;	
}

int main()
{
	llint res = 2;
	llint p_cnt = 0;
	while (1)
	{
		if (isPrime(res))
		{
			++p_cnt;
		}
		if (p_cnt == 10001)
		{
			break;
		}
		++res;
	}
	
	printf (" res %lld \n", res);
	return 0;
	
};
