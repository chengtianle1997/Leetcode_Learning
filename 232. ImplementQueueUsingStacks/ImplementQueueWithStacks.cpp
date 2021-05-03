#include <iostream>
#include <stack>
#include <vector>
#include <string>

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        m_stack_in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // if stack_out is empty
        if (m_stack_out.empty())
        {
            // pop all the elements from stack_in and push them into stack_out.
            while (!m_stack_in.empty())
            {
                m_stack_out.push(m_stack_in.top());
                m_stack_in.pop();
            }
        }
        int top = m_stack_out.top();
        m_stack_out.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        
        // if stack_out is empty
        if (m_stack_out.empty())
        {
            // pop all the elements from stack_in and push them into stack_out.
            while (!m_stack_in.empty())
            {
                m_stack_out.push(m_stack_in.top());
                m_stack_in.pop();
            }
        }
        return m_stack_out.top();
        
        //// reuse pop(): slower
        //int res = this->pop();
        //m_stack_out.push(res);
        //return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return m_stack_in.empty() && m_stack_out.empty();
    }
private:
    std::stack<int> m_stack_in;
    std::stack<int> m_stack_out;
};

void PrintResult(std::vector<std::string> operations, std::vector<int> input)
{
    if (operations.size() == 0 || operations.size() != input.size())
        return;
    std::vector<std::string> result;
    MyQueue* queue = nullptr;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "MyQueue")
        {
            queue = new MyQueue();
            result.push_back("null");
        }
        else if (operations[i] == "push")
        {
            queue->push(input[i]);
            result.push_back("null");
        }
        else if (operations[i] == "peek")
        {
            result.push_back(std::to_string(queue->peek()));
        }
        else if (operations[i] == "pop")
        {
            result.push_back(std::to_string(queue->pop()));
        }
        else if (operations[i] == "empty")
        {
            if (queue->empty())
                result.push_back("true");
            else
                result.push_back("false");
        }
    }
    std::cout << "[ " << result[0];
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << ", " << result[i];
    }
    std::cout << " ]" << std::endl;
}

int main()
{
    MyQueue* queue = new MyQueue();
    std::cout << queue->empty() << std::endl;
    queue->push(1);
    queue->push(2);
    queue->push(3);
    std::cout << queue->empty() << std::endl;
    //std::cout << queue->peek() << std::endl;
    std::cout << queue->pop() << std::endl;
    std::cout << queue->pop() << std::endl;
    std::cout << queue->pop() << std::endl;
    std::cout << queue->empty() << std::endl;
    PrintResult({ "MyQueue", "push", "push", "peek", "pop", "empty" }, { NULL, 1, 2, NULL, NULL, NULL });
}