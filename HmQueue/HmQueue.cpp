#include <Windows.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

int compare(const void* x1, const void* x2)
{
	return (*(int*)x1 - *(int*)x2);
}

void Sort(std::queue <int>& a) {
	int* arr = new int[10];
	int i{ 0 };
	while (!a.empty()) {

		arr[i] = a.front();
		a.pop();
		i++;
	}
	std::cout << "очередь до сортировки:";
	for (int i = 0; i < 10; i++)
	{
		
		std::cout << arr[i] << ", ";
	}
	std::cout << "\n";

	std::qsort(arr, 10, sizeof(int), compare);
	for (int i = 0; i < 10; i++)
	{
		a.push(arr[i]);
	}
	delete[] arr;
}


int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::queue <int> numbers;
	int tmp;
	std::cout << "заполняем очередь:" << "\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "введите число:";
		std::cin >> tmp;
		numbers.push(tmp);
	}


	
	/*while (!numbers.empty())
	{
		std::cout << numbers.front() << ", ";
		numbers.pop();
	}*/

	Sort(numbers);
	std::cout << "ваша отсортированная очередь: ";
	while (!numbers.empty())
	{
		std::cout << numbers.front() << ", ";
		numbers.pop();
	}

	return 0;
}


