#include "CMyVector.h"

void CMyVector::myvector_find(int a)
{
    

    // 在vector中查找元素2
    auto it = find(m_V.begin(), m_V.end(), 2);

    // 判断是否找到
    if (it != m_V.end()) {
        cout << "找到了，位置为：" << it - m_V.begin() << endl;
    }
    else {
        cout << "没找到！" << endl;
    }
}

void CMyVector::myvector_push_back(int a)
{
    m_V.push_back(a);
}

void CMyVector::myvector_popback()
{
    if (m_V.size())
        m_V.pop_back();
    else {
        throw  std::string(" vector is empty");
    }
       
}
