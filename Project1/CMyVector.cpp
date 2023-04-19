#include "CMyVector.h"

void CMyVector::vector_find(int& a)
{
    vector<int> vec = { 1, 2, 3, 4, 5 };

    // 在vector中查找元素2
    auto it = find(vec.begin(), vec.end(), 2);

    // 判断是否找到
    if (it != vec.end()) {
        cout << "找到了，位置为：" << it - vec.begin() << endl;
    }
    else {
        cout << "没找到！" << endl;
    }
}
