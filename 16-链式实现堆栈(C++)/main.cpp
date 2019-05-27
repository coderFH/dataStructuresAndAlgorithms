//
//  main.cpp
//  16-链式实现堆栈(C++)
//
//  Created by wangfh on 2019/5/27.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;
class LinkedStack {
public:
    LinkedStack (void) : m_pTop (NULL) {}
    ~LinkedStack (void) {
        for (Node* pNode = m_pTop, *pNext; pNode; pNode = pNext) {
            pNext = pNode -> m_pNext;
            delete pNode;
        }
    }
    void Push (int nData) {
        m_pTop = new Node (nData, m_pTop);
    }
    int Pop (void) {
        if (! m_pTop)
            throw UnderFlow ();
        Node* pNode = m_pTop;
        int nData = pNode -> m_nData;
        m_pTop = pNode -> m_pNext;
        delete pNode;
        return nData;
    }
private:
    class Node {
    public:
        Node (int nData, Node* pNext = NULL) : m_nData (nData), m_pNext (pNext) {}
        int m_nData;
        Node* m_pNext;
    };
    class UnderFlow : public exception {
    public:
        const char* what (void) const throw () {
            return "链栈下溢！";
        }
    };
    Node* m_pTop;
};
int main (void) {
    try {
        LinkedStack ls;
        ls.Push (10);
        ls.Push (20);
        ls.Push (30);
        ls.Push (40);
        ls.Push (50);
        ls.Push (60);
        ls.Push (70);
        ls.Push (80);
        for (int i = 0; i < 8; i++)
            cout << ls.Pop () << endl;
        cout << ls.Pop () << endl;
    }
    catch (exception& ex) {
        cout << ex.what () << endl;
        return -1;
    }
    return 0;
}

