//
//  main.cpp
//  18-链式实现队列(C++)
//
//  Created by wangfh on 2019/5/27.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;
class LinkedQueue {
public:
    LinkedQueue (void) : m_pRear (NULL), m_pFront (NULL) {};
    ~LinkedQueue (void) {
        for (Node* pNode = m_pRear, *pNext; pNode; pNode = pNext) {
            pNext = pNode -> m_pNext;
            delete pNode;
        }
    }
    void Push (int nData) {
        m_pRear = new Node (nData, NULL, m_pRear);
        if (m_pRear -> m_pNext)
            m_pRear -> m_pNext -> m_pPrev=m_pRear;
        else
            m_pFront = m_pRear;
    }
    int Pop (void) {
        if (! m_pFront)
            throw UnderFlow ();
        Node* pNode = m_pFront;
        int nData = pNode -> m_nData;
        m_pFront = pNode -> m_pPrev;
        if (m_pFront)
            m_pFront -> m_pNext = NULL;
        else
            m_pRear = m_pFront;
        delete pNode;
        return nData;
    }
private:
    class Node {
    public:
        Node (int nData, Node* pPrev = NULL, Node* pNext = NULL) : m_nData (nData), m_pPrev (pPrev), m_pNext (pNext) {}
        int m_nData;
        Node* m_pPrev;
        Node* m_pNext;
    };
    class UnderFlow : public exception {
    public:
        const char* what (void) const throw () {
            return "链队下溢！";
        }
    };
    Node* m_pRear;
    Node* m_pFront;
};
int main (void) {
    try {
        LinkedQueue lq;
        lq.Push (10);
        lq.Push (20);
        cout << lq.Pop () << endl; // 10
        lq.Push (30);
        lq.Push (40);
        lq.Push (50);
        cout << lq.Pop () << endl; // 20
        lq.Push (60);
        cout << lq.Pop () << endl; // 30
        cout << lq.Pop () << endl; // 40
        cout << lq.Pop () << endl; // 50
        cout << lq.Pop () << endl; // 60
    }
    catch (exception& ex) {
        cout << ex.what () << endl;
    }
    return 0;
}

