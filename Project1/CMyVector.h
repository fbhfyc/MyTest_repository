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
private:
	vector<int>  m_V;
};

