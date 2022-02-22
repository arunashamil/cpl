#include <iostream>
#include <vector>
using namespace std;
#include<stack>

void printStack(std::stack<int> &s)
{
    vector<int> a;
    std::stack<int> copy_s = s;

    while (!copy_s.empty())
    {
        cout << copy_s.top() << endl;
        int& wh = copy_s.top();
        a.push_back(wh);
        copy_s.pop();
    }
}

int main()
{
    std::stack<int> s;
    for (int i = 0; i < 10; i++)
    {
        s.push(i);
    }

    cout << "First call" << endl;
    printStack(s);

    cout << "Second call" << endl;
    printStack(s);

}

