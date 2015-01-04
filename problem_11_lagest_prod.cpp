#include <vector>
#include <string>
#include <set>
#include <list>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <ctype.h>

using namespace std;

typedef long long int llint;

typedef vector<bool> v_b;
typedef v_b::iterator it_v_b;
typedef vector<int> v_i;
typedef v_i::iterator it_v_i;
typedef set<int> s_i;
typedef s_i::iterator it_s_i;
typedef list<int> l_i;
typedef l_i::iterator it_l_i;
typedef vector<string> v_str;
typedef v_str::iterator it_v_str;
typedef pair<string, string> pair_ss;
typedef pair<int, int> pair_ii;
typedef vector< pair_ss > v_pair_ss;
typedef v_pair_ss::iterator it_v_pair_ss;
typedef vector< pair_ii > v_pair_ii;
typedef v_pair_ii::iterator it_v_pair_ii;

int getValLeft(int i, int j, const vector<v_i> &matrix)
{
	if (j > 16)
	{
		return 0;
	}

	return matrix[i][j] * matrix[i][j+1] *matrix[i][j+2] * matrix[i][j+3];
}

int getValLeftDown(int i, int j, const vector<v_i> &matrix)
{
	if (i > 16 || j > 16)
	{
		return 0;
	}

	return matrix[i][j] * matrix[i+1][j+1] *matrix[i+2][j+2] * matrix[i+3][j+3];
}

int getValDown(int i, int j, const vector<v_i> &matrix)
{
	if (i > 16)
	{
		return 0;
	}

	return matrix[i][j] * matrix[i+1][j] *matrix[i+2][j] * matrix[i+3][j];
}

int getValDownRight(int i, int j, const vector<v_i> &matrix)
{
	if (i > 16 || j < 3)
	{
		return 0;
	}

	return matrix[i][j] * matrix[i+1][j-1] *matrix[i+2][j-2] * matrix[i+3][j-3];
}

int getMaxVal(int i, int j, const vector<v_i> &matrix)
{
	return max(
			max(getValLeft(i, j, matrix), getValLeftDown(i, j, matrix)),
			max(getValDown(i, j, matrix), getValDownRight(i, j, matrix)));
}

int main()
{	
	vector<v_i> matrix = vector<v_i>(20, v_i(20));

	ifstream infile;
    infile.open ("problem_11_data.txt");

	int val = 0;
	int i = 0;
	int j = 0;
	int res = 0;
	
	while (!infile.eof())
	{
		infile >> val;
		matrix[i][j++] = val;
		if (j > 19)
		{
			i++;
			j = 0;
		}
	}

	for (i = 0; i < 20; ++i)
	{
		for (j = 0; j < 20; ++j)
		{
			val = getMaxVal(i, j, matrix);
			if (val > res)
			{
				res = val;
			}
		}
	}


	cout << res << endl;

	
	
	
	return 0;
};