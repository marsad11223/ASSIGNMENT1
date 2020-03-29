#include "Node.h"
#include <iostream>
using namespace std;

Node::Node()
{
	cost = 1;
	action = -1;
	parent = nullptr;
	state = -1;
}

Node::Node(Node& n)
{
	this->state = n.state;
	this->cost = n.cost;
	this->parent = n.parent;
	this->action = n.action;
}

void Node::operator=(const Node& n)
{
	this->state = n.state;
	this->cost = n.cost;
	this->parent = n.parent;
	this->action = n.action;
}
