#include "CMyVector.h"

void CMyVector::vector_find(int& a)
{
    vector<int> vec = { 1, 2, 3, 4, 5 };

    // ��vector�в���Ԫ��2
    auto it = find(vec.begin(), vec.end(), 2);

    // �ж��Ƿ��ҵ�
    if (it != vec.end()) {
        cout << "�ҵ��ˣ�λ��Ϊ��" << it - vec.begin() << endl;
    }
    else {
        cout << "û�ҵ���" << endl;
    }
}
