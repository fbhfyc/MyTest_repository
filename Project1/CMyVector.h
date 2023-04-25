#pragma once
#include "base.h"
class CMyVector
{
public:
	void myvector_find(int a);
	void myvector_push_back(int a);
	size_t myvector_size()
	{
		return m_V.size();
	}
	size_t myvector_capacity()
	{
		return m_V.capacity();
	}
	void myvector_popback();
	void mySort();
	vector<int> getV()
	{
		return m_V;
	}
private:
	vector<int>  m_V;
};

