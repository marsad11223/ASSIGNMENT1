#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node
{
public:
	int state;
	int action;
	Node* parent;
	int cost;

	Node();
	Node(Node&);
	void operator=(const Node& n);
};


#endif // !NODE_H



