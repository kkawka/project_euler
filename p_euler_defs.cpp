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





int main()
{
	clock_t t;
	t = clock();
	int res = 0;
	
	
	cout << "res : " << res << endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	cin >> res;
	
	return 0;
};
