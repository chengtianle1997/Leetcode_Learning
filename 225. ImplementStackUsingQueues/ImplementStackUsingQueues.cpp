#include <iostream>
#include <queue>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if (m_queue_1.empty())
            m_queue_2.push(x);
        else if (m_queue_2.empty())
            m_queue_1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = 0;
        if (m_queue_1.empty())
        {
            // backup all elements from queue2 to queue1
            while (m_queue_2.size() > 1)
            {
                m_queue_1.push(m_queue_2.front());
                m_queue_2.pop();
            }
            top = m_queue_2.front();
            m_queue_2.pop();
            return top;
        }
        else if (m_queue_2.empty())
        {
            // backup all elements from queue1 to queue2
            while (m_queue_1.size() > 1)
            {
                m_queue_2.push(m_queue_1.front());
                m_queue_1.pop();
            }
            top = m_queue_1.front();
            m_queue_1.pop();
            return top;
        }
        return top;
    }

    /** Get the top element. */
    int top() {
        int top = 0;
        if (m_queue_1.empty())
        {
            // backup all elements from queue2 to queue1
            while (m_queue_2.size() > 1)
            {
                m_queue_1.push(m_queue_2.front());
                m_queue_2.pop();
            }
            top = m_queue_2.front();
            m_queue_1.push(top);
            m_queue_2.pop();
            return top;
        }
        else if (m_queue_2.empty())
        {
            // backup all elements from queue1 to queue2
            while (m_queue_1.size() > 1)
            {
                m_queue_2.push(m_queue_1.front());
                m_queue_1.pop();
            }
            top = m_queue_1.front();
            m_queue_2.push(top);
            m_queue_1.pop();
            return top;
        }
        return top;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return m_queue_1.empty() && m_queue_2.empty();
    }

private:
    std::queue<int> m_queue_1;
    std::queue<int> m_queue_2;
};

int main()
{
    MyStack* stack = new MyStack();
    std::cout << stack->empty() << std::endl;
    stack->push(1);
    stack->push(2);
    stack->push(3);
    std::cout << stack->empty() << std::endl;
    std::cout << stack->top() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->empty() << std::endl;
    
}