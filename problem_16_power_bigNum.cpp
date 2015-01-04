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


int main()
{
	clock_t t;
	t = clock();

	Mq_BigNum power(1);
	int num = (1 << 20);
	
	for (int i = 1; i <= 50; ++i)
	{
		power *= num;
	}
	
	std::cout << std::accumulate(power.begin(),power.end(),0) << endl;
	
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};
