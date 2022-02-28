#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <array>
#include <algorithm>
#include <tuple>
#include <list>
#include <forward_list>

const int t = 10000;
using namespace std;

int main()
{
	vector<int> v;
	deque<int> d;
	array<int, t> a;
	static list<int> l;
	forward_list<int> f_1;
	forward_list<int> f_2;
	for (int i = 0; i < t; i++)
	{
		int random = std::rand() % t;
		v.push_back(random);
		d.push_back(random);
		a[i] = random;
		l.push_back(random);
		f_2.push_front(random);
	}

	f_2.reverse();

	cout << "/////////// vector ///////////" << endl;

	double start_time_v = clock(); // начальное время
	sort(v.begin(), v.end());
	double end_time_v = clock(); // конечное время
	double search_time_v = end_time_v - start_time_v; // искомое время

	cout << "search_time_v = " << search_time_v << endl;
	cout << "////////////////////////////////" << endl;


	cout << "/////////// deque ///////////" << endl;

	double start_time_d = clock(); // начальное время
	sort(d.begin(), d.end());
	double end_time_d = clock(); // конечное время
	double search_time_d = end_time_d - start_time_d; // искомое время

	cout << "search_time_d = " << search_time_d << endl;

	cout << "////////////////////////////////" << endl;


	cout << "/////////// array ///////////" << endl;

	double start_time_a = clock(); // начальное время
	sort(a.begin(), a.end());

	double end_time_a = clock(); // конечное время
	double search_time_a = end_time_a - start_time_a; // искомое время

	cout << "search_time_a = " << search_time_a << endl;

	cout << "////////////////////////////////" << endl;

	cout << "/////////// list ///////////" << endl;

	double start_time_l = clock(); // начальное время
	l.sort();
	double end_time_l = clock(); // конечное время
	double search_time_l = end_time_l - start_time_l; // искомое время

	cout << "search_time_l = " << search_time_l << endl;


	cout << "////////////////////////////////" << endl;



	cout << "/////////// forward_list ///////////" << endl;

	double start_time_f_2 = clock(); // начальное время
	f_2.sort();
	double end_time_f_2 = clock(); // конечное время
	double search_time_f_2 = end_time_f_2 - start_time_f_2; // искомое время
	cout << "search_time_f_own_sort = " << search_time_f_2 << endl;


	cout << "////////////////////////////////" << endl;

	vector<double> maximum_the_hormone = {search_time_a, search_time_d, search_time_f_2, search_time_l, search_time_v };

	auto minmax = minmax_element(maximum_the_hormone.begin(), maximum_the_hormone.end());
	cout << "AND THE WINNER IS " << *minmax.first << endl;
	return 0;
}