#include <vector>
#include <string>
#include <set>
#include <list>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <ctype.h>
#include <assert.h>

using namespace std;


typedef long long int llint;
typedef unsigned long long int ullint;

typedef vector<bool> v_b;
typedef v_b::iterator it_v_b;
typedef vector<int> v_i;
typedef v_i::iterator it_v_i;
typedef set<int> s_i;
typedef s_i::iterator it_s_i;
typedef list<int> l_i;
typedef l_i::iterator it_l_i;


ullint binomialCoeff(int n, int k)
{
	ullint res = n;
	if (k >= n || k <= 0)
	{
		return 1;
	}
	
	ullint up = (n - k) > k ? (n - k) : k ;
	
	for (int i = 1; i < n - up; )
	{
		res *= n - i;
		res /= ++i;
	}
	return res;
}


void binomialTest()
{
	assert(binomialCoeff(40,0)  == 1);
	assert(binomialCoeff(40,40) == 1);
	assert(binomialCoeff(40,1)  == 40);
	assert(binomialCoeff(40,39) == 40);
	
	assert(binomialCoeff(2,0) == 1);
	assert(binomialCoeff(2,1) == 2);
	assert(binomialCoeff(2,2) == 1);
	
	assert(binomialCoeff(3,0) == 1);
	assert(binomialCoeff(3,1) == 3);
	assert(binomialCoeff(3,2) == 3);
	assert(binomialCoeff(3,3) == 1);
	
	assert(binomialCoeff(4,0) == 1);
	assert(binomialCoeff(4,1) == 4);
	assert(binomialCoeff(4,2) == 6);
	assert(binomialCoeff(4,3) == 4);
	assert(binomialCoeff(4,4) == 1);
}

int main()
{
	binomialTest();
	cout << binomialCoeff(40,20) << endl;
	return 0;
};
