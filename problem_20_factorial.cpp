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
	int overload = 0;
	int j = 0;
	
	for (int i = 1; i <= 100; ++i)
	{
		for (j = 0; j < len; ++j)
		{
			bigNum[j] *= i;
		}
		
		for (j = 0; j < len; ++j)
		{
			if (overload > 0)
			{
				bigNum[j] += overload;
				overload /= 10;
			}
			
			if (bigNum[j] > 9)
			{
				overload = bigNum[j] / 10 ;
				bigNum[j] %= 10;
			}
		}
		
		while (overload > 0)
		{
			bigNum[j++] = overload % 10 ;
			++len;
			overload /= 10;
		}
	}
	
	llint res = 0;
	std::cout << std::accumulate(bigNum.begin(),bigNum.end(),res) << endl;
	
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};
