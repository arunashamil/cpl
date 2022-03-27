#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()

unsigned int my_random()
{
	// Наше стартовое число - 4 541
	static unsigned int seed = 4541;

	// Из-за использования очень больших чисел (и переполнения) угадать следующее число исходя из предыдущего - очень сложно
	seed = (8253729 * seed + 2396403);

	// Берем стартовое число и возвращаем значение в диапазоне от 0 до 32767
	return seed % 32768;
}

#include <random>
int getRandomFloatingPointBetween_progressive(int min, int max) {
	std::random_device rd; // uniformly-distributed integer random number generator
	std::mt19937 gen(rd()); //инициализируем Вихрь Мерсенна случайным стартовым числом
	std::uniform_real_distribution<> dis(min, max);//uniform distribution between min and max
	return dis(gen);
}

int test_cases6() {
	//std::cout << "Mersen float random between:\n";
	int omega = -1;
	for (int count = 0; count < 100; ++count)
	{
		omega = getRandomFloatingPointBetween_progressive(0, 100);
	}
	return omega;
}
int main()
{
	vector<int> vec;
	for (int i = 0; i < 1000; i++)
	{
		int omega = test_cases6();
		vec.push_back(omega);
	}

	double start_time_vec = clock(); // начальное время
	sort(vec.begin(), vec.end());
	double end_time_vec = clock(); // конечное время
	double search_time_vec = end_time_vec - start_time_vec; // искомое время

	//////////////////////////////////////

	set <int> set;
	double start_time_set = clock(); // начальное время

	for (int i = 0; i < 1000; i++)
	{
		set.insert(vec[i]);
	}

	double end_time_set = clock(); // конечное время
	double search_time_set = end_time_set - start_time_set; // искомое время


	cout << "set_time = " << search_time_set << endl;
	cout << "vec_time = " << search_time_vec << endl;
}