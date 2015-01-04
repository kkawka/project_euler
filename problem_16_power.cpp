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

using namespace std;


typedef long long int llint;

typedef vector<int> v_i;
typedef v_i::iterator it_v_i;



int main()
{
	clock_t t;
	t = clock();

	v_i bigNum(1000,0);
	int len = 1;
	bigNum[0] = 1;
	bool overload = false;
	int j = 0;
	
	for (int i = 1; i <= 1000; ++i)
	{
		for (j = 0; j < len; ++j)
		{
			bigNum[j] <<= 1;
		}
		
		for (j = 0; j < len; ++j)
		{
			if (overload)
			{
				++bigNum[j];
				overload = false;
			}
			
			if (bigNum[j] > 9)
			{
				overload = true;
				bigNum[j] -= 10;
			}
		}
		
		if (overload)
		{
			++bigNum[j];
			++len;
			overload = false;
		}
	}
	
	llint res = 0;
	std::cout << std::accumulate(bigNum.begin(),bigNum.end(),res) << endl;
	
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};
