#include <set>
#include <list>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <ctype.h>
#include <time.h>   
#include "../lib/bigNum.h"
#include "../lib/algo.h"

using namespace std;
using namespace Mq_algo;


int getPowerDigitSum(int n, const v_i &powers)
{
	int res = 0;
	
	while (n > 0)
	{
		res += powers[n % 10];
		n /= 10;
	}
	
	return res;
}


int main()
{
	clock_t t;
	t = clock();
	int res = 0;
	
	v_i powers; 
	
	for (int i = 0; i < 10; ++i)
	{
		powers.push_back(i*i*i*i*i);
	}
	
	int lBound = powers[2];
	int uBound = powers[9]*6;
	
	for (int i = lBound; i <= uBound; ++i)
	{
		if (i == getPowerDigitSum(i, powers))
		{
			res += i;
		}
	}
	
	
	cout << "res : " << res << endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};
