//
//  main.cpp
//  15-堆栈(C++)
//
//  Created by wangfh on 2019/5/23.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Stack {
public:
    Stack(size_t capacity) : m_nArray(new int[capacity]),m_nCapacity(capacity),m_nTop(0) {}
    ~Stack(void) {
        delete [] m_nArray;
        
    }
    void Push(int nData) {
        if (m_nTop >= m_nCapacity)
            throw OverFlow();
        m_nArray[m_nTop++] = nData;
    }
    
    int Pop(void) {
        if (!m_nTop)
            throw UnderFlow();
        return m_nArray[--m_nTop];
    }
    
private:
    class OverFlow : public exception {
    public:
        const char* what(void) const throw() {
            return "堆栈溢出";
        }
    };
    class UnderFlow : public exception {
    public:
        const char* what(void) const throw() {
            return "堆栈已空";
        }
    };
    int *m_nArray;      //数组
    size_t m_nCapacity; //容量
    size_t m_nTop;      //栈顶
};
int main(int argc, const char * argv[]) {
    try {
        Stack stack(5);
        stack.Push(10);
        stack.Push(20);
        stack.Push(30);
        stack.Push(40);
        stack.Push(50);
        
//        stack.Push(60);
        
        cout << stack.Pop() << endl;
        cout << stack.Pop() << endl;
        cout << stack.Pop() << endl;
        cout << stack.Pop() << endl;
        cout << stack.Pop() << endl;
        
//        cout << stack.Pop() << endl;
        
    } catch (exception& ex) {
        cout << ex.what() << endl;
        return -1;
    }
    return 0;
}
