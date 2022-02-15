#include <iostream>
#include <memory>
using namespace std;

class BankCell
{
public:
	BankCell()
	{
		cout << "I am created" << endl;
	}
	~BankCell()
	{
		cout << "I am deleted" << endl;
	}
};

class Human
{
private:
	std::shared_ptr<BankCell> p;

public:
	Human(std::shared_ptr<BankCell> p)
	{
		this->p = p;
		cout << "I am created" << endl;
	}

	Human(const Human&) = delete;

	~Human()
	{
		cout << "I am deleted" << endl;
	}
};

int main()
{
	cout << "Hey" << endl;
	BankCell* V = new BankCell();
	std::shared_ptr<BankCell> bkcl_ptr(V);
	Human Sasha(bkcl_ptr);
	Human Vova(bkcl_ptr);
}