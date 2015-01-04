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

int getDigits(int i)
{
    int flags = 0;
    while (i > 0)
    {
        flags |= (1 << (i % 10));
        i /= 10;
    }
    return flags;

}

int remDigit(int i, int flag)
{
    int res = 1 << (i % 10);
    if (flag == (1 << (i % 10)))
    {
        return i / 10;
    }
    return i % 10;
}

void test()
{
    int flagI = getDigits(49);
    int flagJ = getDigits(98);
    int res = flagI & flagJ;
    int resI = 49 * remDigit(98, res);
    int resJ = 98 * remDigit(49, res);

}

void simplify(int &up, int &res)
{
    int i = 2;
    while (i <= up)
    {
        if (up % i == 0    &&
            res  % i == 0)
        {
            up /= i;
            res /= i;
        }
        else
        {
            ++i;
        }
    }
}

int main()
{
	clock_t t;
	t = clock();
	
    int up = 1;
    int res = 1;
    int flags = 0;
   
    test();

    for (int i = 10; i < 100; ++i)
    {
        for (int j = i + 1; j < 100; ++j)
        {
            flags = getDigits(i) & getDigits(j);
            if (flags > 1)
            {
                if (i * remDigit(j, flags) == j * remDigit(i, flags))
                {
                    cout << "i :" << i << " j: " << j << endl;
                    up *= remDigit(i, flags);
                    res *= remDigit(j, flags);
                }
            }
        }
    }

    simplify(up, res);
    
	cout << "res : " << res << endl;
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	cin >> res;
	
	return 0;
}