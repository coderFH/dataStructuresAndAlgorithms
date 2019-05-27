//
//  main.cpp
//  17-队列
//
//  Created by wangfh on 2019/5/27.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;
class Queue {
public:
    // 构造过程中分配内存
    Queue (size_t uCapacity) : m_pArray (new int[uCapacity]), m_uCapacity (uCapacity), m_uRear (0), m_uFront (0), m_uCount (0) {}
    // 析构过程中释放内存
    ~Queue (void) {
        if (m_pArray) {
            delete m_pArray;
            m_pArray = NULL;
        }
        m_uRear = 0;
        m_uFront = 0;
        m_uCount = 0;
    }
    // 压入
    void Push (int nData) {
        if (m_uCount >= m_uCapacity)
            throw OverFlow ();
        if (m_uRear >= m_uCapacity)
            m_uRear = 0;
        m_uCount++;
        m_pArray[m_uRear++] = nData;
    }
    // 弹出
    int Pop (void) {
        if (! m_uCount)
            throw UnderFlow ();
        if (m_uFront >= m_uCapacity)
            m_uFront = 0;
        m_uCount--;
        return m_pArray[m_uFront++];
    }
private:
    // 上溢异常
    class OverFlow : public exception {
    public:
        const char* what (void) const throw () {
            return "队列上溢！";
        }
    };
    // 下溢异常
    class UnderFlow : public exception {
    public:
        const char* what (void) const throw () {
            return "队列下溢！";
        }
    };
    int* m_pArray; // 数组
    size_t m_uCapacity; // 容量
    size_t m_uRear; // 后端（压入）
    size_t m_uFront; // 前端（弹出）
    size_t m_uCount; // 计数
};
int main (void) {
    try {
        Queue queue (5);
        queue.Push (10);
        queue.Push (20);
        queue.Push (30);
        queue.Push (40);
        queue.Push (50);
        //        queue.Push (60);
        cout << queue.Pop () << endl;
        cout << queue.Pop () << endl;
        queue.Push (60);
        queue.Push (70);
        for (int i = 0; i < 5; i++)
            cout << queue.Pop () << endl;
        //        queue.Pop ();
    }
    catch (exception& ex) {
        cout << ex.what () << endl;
        return -1;
    }
    return 0;
}

