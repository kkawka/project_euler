#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

vector<int> factorials;

int getFactorialSum(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += factorials[i % 10];
        i /= 10;
    }
    return res;

}


void init()
{
    factorials.push_back(1); // 0!
    factorials.push_back(1); // 1!
    factorials.push_back(2); // 2!
    factorials.push_back(6); // 3!
    factorials.push_back(24); // 4!
    factorials.push_back(120); // 5!
    factorials.push_back(720); // 6!
    factorials.push_back(5040); // 7!
    factorials.push_back(40320); // 8!
    factorials.push_back(362880); // 9!
}


int main()
{
	clock_t t;
	t = clock();
	int res = 0;
   
    init();

    for (int i = 10; i < 9999999; ++i)
    {
        if (i == getFactorialSum(i))
        {
            res += i;
        }
    }

	cout << "res : " << res << endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	cin >> res;
	
	return 0;
}