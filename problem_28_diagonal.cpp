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

int main()
{
	clock_t t;
	t = clock();
	
	llint res = 1;
	llint curr = 3;
	for (int i = 2; i < 1001; i += 2)
	{
		res += 4*curr + 6*i;
		curr += 4*i+2;
	}
	
	
	cout << "res : " << res << endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};