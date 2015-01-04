#include <vector>
#include <string>
#include <set>
#include <list>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <ctype.h>
#include <fstream>
#include <time.h>  

using namespace std;

typedef long long int llint;

class Node
{
	public:
		Node(int n)
			: m_num(n)
			, m_maxPath(-1)
			, m_pLeft(NULL)
			, m_pRight(NULL)
		{
		}
		
		void setLeft(Node *l)
		{
			m_pLeft = l;
		}
		
		void setRight(Node *r)
		{
			m_pRight = r;
		}
		
		int getMaxPath()
		{
			if (m_maxPath >= 0)
			{
				return m_maxPath;
			}
			else
			{
				int l = (m_pLeft) ? m_pLeft->getMaxPath() : 0 ;
				int r = (m_pRight) ? m_pRight->getMaxPath() : 0 ;
				m_maxPath = (l < r) ? r : l;
				m_maxPath += m_num;
				return m_maxPath;
			}
		}

	private:
		int m_num;
		int m_maxPath;
		Node *m_pLeft;
		Node *m_pRight;
		
};


typedef vector<Node*> v_nodes;

int main()
{
	clock_t t;
	t = clock();

	v_nodes prev;
	v_nodes curr;
	prev.reserve(200);
	curr.reserve(200);
	Node *root = NULL;
	Node *tmpN = NULL;
	ifstream infile;
	infile.open("problem_67_data.txt");
	
	int val = 0;
	int row = 1;
	
	// first line
	infile >> val;
	root = new Node(val);
	prev.push_back(root);
	
	while (!infile.eof())
	{
		infile >> val;
		tmpN = new Node(val);
		curr.push_back(tmpN);

		for (int i = 0; i < row; ++i)
		{
			infile >> val;
			tmpN = new Node(val);
			curr.push_back(tmpN);
			prev[i]->setLeft(curr[i]);
			prev[i]->setRight(curr[i+1]);
		}
		++row;
		prev.swap(curr);
		curr.clear();
	}

	cout << root->getMaxPath() << endl;

	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	return 0;
};
