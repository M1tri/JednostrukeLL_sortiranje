#pragma once
struct NodeDouble
{
	int info;
	NodeDouble* prev;
	NodeDouble* next;
	
	NodeDouble(int info, NodeDouble* prev = nullptr, NodeDouble* next = nullptr)
		:info(info), prev(prev), next(next) {}
	~NodeDouble() {}

};

