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
#include "../lib/algo.h"

using namespace std;
using namespace Mq_algo;

typedef vector<int> v_i;
typedef v_i::iterator it_v_i;


int genSeq(int a, int b)
{
	int i = 1;
	while (isPrime(i*i + i*a + b))
	{
		++i;
	}
	return i-1;
}


int main()
{
	clock_t t;
	t = clock();
	
	v_i numPr;
	numPr.reserve(100);
	numPr.push_back(1);
	
	for (int i = 2; i < 1000; ++i)
	{
		if (isPrime(i))
		{
			numPr.push_back(i);
		}
	}
	
	int a = 0;
	int b = 0;
	int res = 0;
	int currLen = 0;
	int tmpAB = 0;
	
	for (it_v_i it1 = numPr.begin(); it1 != numPr.end(); ++it1)
	{
		for (it_v_i it2 = numPr.begin(); it2 != numPr.end(); ++it2)
		{
			tmpAB = genSeq(*it1, *it2);
			if (currLen < tmpAB)
			{
				currLen = tmpAB;
				res = (*it1) * (*it2);
			}
			tmpAB = genSeq(*it1, -(*it2));
			if (currLen < tmpAB)
			{
				currLen = tmpAB;
				res = (*it1) * (-(*it2));
			}
			tmpAB = genSeq(-(*it1), *it2);
			if (currLen < tmpAB)
			{
				currLen = tmpAB;
				res = (-(*it1)) * (*it2);
			}
			tmpAB = genSeq(-(*it1), -(*it1));
			if (currLen < tmpAB)
			{
				currLen = tmpAB;
				res = (-(*it1)) * (-(*it2));
			}
		
		}
	}
	
	cout << "res : " << res << endl;
	
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};
