#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    vector<int> a;
    cout << "start a_capacity = " << a.capacity() << endl;
    cout << "////////////////////////////////" << endl;

    for (int i = 0; i < 100; i++)
    {
        a.push_back(i);
        cout << "a[" << i << "] = " << a[i] << endl;
        cout << "current a_capacity = " << a.capacity() << endl;
    }

    cout << "////////////////////////////////" << endl;

    vector<int> b;
    cout << "start b_capacity = " << b.capacity() << endl;
    cout << "////////////////////////////////" << endl;
    b.reserve(10);
    for (int i = 0; i < 100; i++)
    {
        b.push_back(i);
        cout << "b[" << i << "] = " << b[i] << endl;
        cout << "current b_capacity = " << b.capacity() << endl;
    }

    cout << "////////////////////////////////" << endl;

    vector<int> c;
    c.reserve(10000000000000000);
    cout << "start c_capacity = " << c.capacity() << endl;
    for (int i = 0; i < 100; i++)
    {
        b.push_back(i);
        cout << "b[" << i << "] = " << b[i] << endl;
        cout << "current b_capacity = " << b.capacity() << endl;
    }

    /* При запросе большой памяти возникает необработанное исключение, 
    дальнейшая часть программы, в том числе и вывод значения переменной c_capacity, не выполняется*/

	return 0;
}