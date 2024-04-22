#pragma once
class Node
{
public:
	int info;
	Node* link;
public:
	Node(int info = 0, Node* link = nullptr): info(info), link(link) {}

	int get_info() const
	{
		return info;
	}

	Node* get_link() const
	{
		return link;
	}

	void set_link(Node* novi)
	{ 
		link = novi;
	}



};

