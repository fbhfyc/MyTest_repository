#include "CMyVector.h"

CMyVector vv;
    void vec_test_find() {
        

        vv.myvector_push_back(1);
        vv.myvector_find(2);
    }

    void vec_test_popback()
    {
        try {
            vv.myvector_popback();
        }
        catch( string& err ){
            cout << "catched an err: "<< err << endl;
        }
        
    }

    void vec_test_mySort()
    {
        vv.myvector_push_back(132);
        vv.myvector_push_back(1324);
        vv.myvector_push_back(1322);
        vv.myvector_push_back(13);
        vv.mySort();
    }