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

static const int SUM = 200;

void moveCoins(v_i &coinsCnt)
{
	int i = 0;
	while (coinsCnt[i] == 0)
	{
		++i;
	}
	
	coinsCnt[i++] = 0;
	if (i < coinsCnt.size())
	{
		coinsCnt[i] += 1;
	}
	
}

int getSum(v_i &coinsCnt, v_i &coinsVal) 
{
	int sum = 0;
	int size = coinsCnt.size();
	for (int i = 0; i < size; ++i)
	{
		sum += coinsCnt[i]*coinsVal[i];
	}
	return sum;
}


int main()
{
	clock_t t;
	t = clock();
	
	
	int res = 0;
	int sum = 0;
	
	
	//1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
	v_i coinsVal(8,0);
	v_i coinsCnt(8,0);
	
	coinsVal[0] = 1;
	coinsVal[1] = 2;
	coinsVal[2] = 5;
	coinsVal[3] = 10;
	coinsVal[4] = 20;
	coinsVal[5] = 50;
	coinsVal[6] = 100;
	coinsVal[7] = 200;
	
	while (1)
	{
		coinsCnt[0] += SUM - sum;
		sum = getSum(coinsCnt, coinsVal);
		while( sum >= SUM )
		{
			if (sum == SUM)
			{
 				res++;
			}
			moveCoins(coinsCnt);
			sum = getSum(coinsCnt, coinsVal);
		}
		if (sum == 0)
		{
			break;
		}
	}
	
	
	cout << "res : " << res << endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	cin >> res; 

	return 0;
};
