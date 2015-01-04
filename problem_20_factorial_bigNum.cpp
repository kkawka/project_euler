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

	Mq_BigNum fact(1);
	
	for (int i = 1; i <= 100; ++i)
	{
		fact *= i;
	}
	
	std::cout << std::accumulate(fact.begin(),fact.end(),0) << endl;
	
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};
