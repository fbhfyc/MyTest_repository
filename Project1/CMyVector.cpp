#include "CMyVector.h"

void CMyVector::myvector_find(int a)
{
    

    // ��vector�в���Ԫ��2
    auto it = find(m_V.begin(), m_V.end(), 2);

    // �ж��Ƿ��ҵ�
    if (it != m_V.end()) {
        cout << "�ҵ��ˣ�λ��Ϊ��" << it - m_V.begin() << endl;
    }
    else {
        cout << "û�ҵ���" << endl;
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
