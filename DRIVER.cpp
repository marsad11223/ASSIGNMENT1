#include<iostream>
#include <string>
#include<queue>
#include"Node.h"
#include<set>
#include<stack>
using namespace std;
void input();
bool isgoal(int);
void GraphSearch();
void splitTest(string str);
Node* getChild(Node*, int);
queue<Node*> frontier;
set<int> explored;
int M, N, T;
string* states;
string* actions;
string* test;
int** TransistionTable;
string initialState, finalState;
int main()
{
	input();

	cout << endl;
	cout << "states: " << M << endl;
	cout << "actions: " << N << endl;
	cout << "problems: " << T << endl;
	cout << endl;
	for (int i = 0; i < M; i++)
		cout << states[i] << endl;
	cout << endl;
	for (int i = 0; i < N; i++)
		cout << actions[i] << endl;
	cout << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << TransistionTable[i][j] <<" ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < T; i++)
		cout << test[i] << endl;

	for (int i = 0; i < T; i++)
	{
		splitTest(test[i]);
		GraphSearch();
		cout << endl;
	}

}
void input()
{
	cin >> M;
	cin >> N;
	cin >> T;
	states = new string[M];
	actions = new string[N];
	test = new string[T];

	cin.ignore();
	cin.ignore();
	//inputof states;
	for (int i = 0; i < M; i++)
		getline(cin, states[i]);

	cin.ignore();
	//input of actions
	for (int i = 0; i < N; i++)
		getline(cin, actions[i]);

	cin.ignore();
	// allocation of transistation table
	TransistionTable = new int*[M];
	for (int i = 0; i < M; i++)
		TransistionTable[i] = new int[N];

	// input of transistion table
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> TransistionTable[i][j];
	}

	cin.ignore();
	cin.ignore();
	// input of test cases
	for (int i = 0; i < T; i++)
		getline(cin, test[i]);

}
bool isgoal(int a)
{
	int f = -1;
	for (int i = 0; i < M; i++)
	{
		if (states[i] == finalState)
		{
			f = i;
		}
	}
	if (a == f)
	{
		return true;
	}
	else
	{
		return false;
	}

}
void splitTest(string str)
{
	int x = 0;
	initialState = "";
	finalState = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '	')
		{
			x = i;
			break;
		}
		else
		{
			initialState = initialState + str[i];
		}
	}
	x = x + 1;
	for (int i = x; i < str.length(); i++)
	{
		finalState = finalState + str[i];
	}
}
void GraphSearch()
{
	Node* initial;
	initial = new Node();
	int a = -1;
	for (int i = 0; i < M; i++)
	{
		if (initialState == states[i])
		{
			a = i;
		}
	}
	initial->state = a;
	initial->cost = 0;
	frontier.push(initial);
	while (!frontier.empty())
	{
		if (frontier.empty())
		{
			cout << "No solution exists";
		}
		Node* a1 = frontier.front();
		frontier.pop();
		if (isgoal(a1->state))
		{
			if (a1->parent == nullptr)
			{
				cout << "current state is the goal";
				explored.insert(a1->state);
				delete a1;
			}
			else
			{
				stack<string> solution;
				Node* temp = a1;
				temp = a1;
				while (temp->parent != nullptr)
				{
					solution.push(actions[temp->action]);	
					temp = temp->parent;
				}
				while (!solution.empty())
				{
					string a = solution.top();

					cout << a ;
					solution.pop();
					if (!solution.empty())
					{
						cout << "->";
					}
				}
				explored.insert(a1->state);
				delete a1;
			}
		}
		else
		{
			Node* temp1 = a1;
			explored.insert(a1->state);
			for (int i = 0; i < N; i++)
			{
				Node* child;
				child = getChild(temp1, i);
				if (explored.find(child->state) != explored.end())
				{
					continue;
				}
				else
				{
					frontier.push(child);
				}
			}
		}
	}
}
Node* getChild(Node* n, int a)
{
	Node* child;
	child = new Node();
	child->parent = n;
	child->action = a;
	child->state = TransistionTable[n->state][a];
	child->cost = n->cost + child->cost;

	return child;
}