#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <random>
#include <algorithm>
using namespace std;

int getRandomFloatingPointBetween_progressive(int min, int max) {
	random_device rd; // uniformly-distributed integer random number generator
	mt19937 gen(rd()); //инициализируем Вихрь Мерсенна случайным стартовым числом
	uniform_real_distribution<> dis(min, max);//uniform distribution between min and max
	return dis(gen);
}
int test_cases6() {
	int a = -1;
	for (int count = 0; count < 100; ++count)
	{
		a = getRandomFloatingPointBetween_progressive(1, 10);
	}
	return a;
}


int main()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(test_cases6());
	}

	cout << "Please, enter 10 numbers from 1 to 9: " << endl;

	for (int i = 0; i < 10; ++i) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	random_shuffle(v.begin(), v.end()); // Перемешиваем случайным образом

	cout << endl;

	set<int> st; //удалим дубликаты
	for (int i = 0; i < 20; ++i) {
		st.insert(v[i]);
	}

	int count = 0; // считаем количество четных
	for (auto i : st) {
		if ((i % 2) == 0) {
			continue;
		}
		else {
			count++;
		}
	}
	cout << endl << "The figure of odd numbers is: " << count << endl;

	set<int>::iterator min = st.begin(); // определяем минимальное и максимальное число
	set<int>::iterator max = --st.end();
	cout << "Minimum: " << *min << ", " << "Maximum : " << *max << endl;

	cout << "Prime numbers: "; //поиск простых чисел
	for (auto i : st) {
		bool Prime = true;
		for (int j = 2; j <= sqrt(i); ++j) {
			if (i % j == 0) {
				Prime = false;
				break;
			}
		}
		if (Prime) {
			cout << i << " ";
		}
	}

	cout << "Squares: ";
	for (auto i : st) { //заменяем числа их квадратами
		i = i * i;
		cout << i;
	}
	cout << endl;

	//П2
	vector<int> p2;
	for (int i = 0; i < st.size(); ++i) {
		p2.push_back(test_cases6());
	}

	int sum = 0; //Сумма П2
	for (auto& n : p2) {
		sum += n;
	}
	cout << "The sum of p2: " << sum << endl;

	for (int i = 0; i < 5; ++i) {    // Заменяю несколько первых значений вектора П2 на 1 (несколько = 5)
		p2.at(i) = 1;
	}
	set<int> st2; //для удобства
	for (int i = 0; i < p2.size(); ++i) {
		st2.insert(p2[i]);
	}
	//П3
	vector<int> p3(st.size());
	int j = 0;
	for (auto i : st) {
		p3[j] = i - p2[j];
		j++;
	}

	for (int i = 0; i < p3.size(); ++i) { //Заменяю отрицательные элементы нулем
		if (p3[i] < 0) {
			p3.at(i) = 0;
		}
	}

	for (int i = 0; i < p3.size(); ++i) { //удаляю нули
		if (p3[i] == 0) {
			p3.erase(p3.begin() + i);
			i--;
		}
	}
	cout << "P3: ";
	for (int i = 0; i < p3.size(); ++i) {
		cout << p3[i];
	}
	cout << endl;
	cout << "Reverse P3: ";
	reverse(p3.begin(), p3.end()); //изменяю порядок следования П3 на обратный
	for (int i = 0; i < p3.size(); ++i) {
		cout << p3[i];
	}
	cout << endl;

	set<int> st3;
	for (int i = 0; i < p3.size(); ++i) {
		st3.insert(p3[i]);
	}
	cout << endl;
	//топ-3 наибольших элемента П3
	cout << "Max1: " << *(--st3.end()) << endl;
	st3.erase(--st3.end());
	cout << "Max2: " << *(--st3.end()) << endl;
	st3.erase(--st3.end());
	cout << "Max3: " << *(--st3.end()) << endl;

	// П1 и П2 итак отсортированы по возрастанию, т.к. лежат в set
	//П4 + финальный вывод
	cout << "output all sequences: " << endl;
	cout << "P1: ";
	for (auto n : st) {
		cout << n;
	}
	cout << endl;
	cout << "P2: ";
	for (auto n : st2) {
		cout << n;
	}
	cout << endl;
	cout << "P3: ";
	for (auto n : st3) {
		cout << n;
	}
	cout << endl;
	st.insert(st2.begin(), st2.end()); //сливаю П1 и П2 в П4
	cout << "P4: ";
	for (auto n : st) {
		cout << n;
	}

}