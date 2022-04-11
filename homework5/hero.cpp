#include <iostream>
#include <cstdlib>

using namespace std;

class Hero
{
public:
	string name;
	int health;
	int strength;

	Hero(string name, int strength)
	{
		this->name = name;
		this->strength = strength;
		this->health = 1000;
	};

	void strike(Hero& otherHero)
	{
		srand(this->strength + this->health);
		int random = static_cast<int>(rand());
		int delta = random % 100;
		otherHero.health = otherHero.health - delta;
	}
};

int main()
{
	Hero Naruto("Uzumaki Naruto", 500);
	Hero Sasuke("Uchiha Sasuke", 500);

	while ((Naruto.health > 0) && (Sasuke.health > 0))
	{
		if (Naruto.health > 0) Naruto.strike(Sasuke);
		if (Sasuke.health > 0) Sasuke.strike(Naruto);

		if (Naruto.health > 0)cout << Naruto.name << ": " << Naruto.health << endl;
		else
		{
			cout << Naruto.name << " lost" << endl;
			break;
		}
		if (Sasuke.health > 0)cout << Sasuke.name << ": " << Sasuke.health << endl;
		else
		{
			cout << Sasuke.name << " lost" << endl;
			break;
		}
	}
}
