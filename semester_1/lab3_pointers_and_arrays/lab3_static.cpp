#include <iostream>
#include <cstdlib>    
const int MAX = 100'000;
void razmer(int* n) {
	std::cout << "Введите размер массива: ";
	if (!(std::cin >> *n)) {
		std::cout << "Введите число!";
		std::exit(-1);
	}
	if (*n > MAX) {
		std::cout << "Переполнение массива!" << std::endl;
		std::exit(-1);
	}
	if (*n == 0) {
		std::cout << "Нулевой массив!" << std::endl;
		std::exit(0);
	}
	if (*n < 0) {
		std::cout << "Ошибка!" << std::endl;
		std::exit(-1);
	}
}
void vibrat(int* vibor, int* n, int* arr) {
	int a, b;
	std::cout << "Способ заполнения массива:\n 1) Ручной ввод.\n 2) Рандомное заполнение. \n";
	if (!(std::cin >> *vibor)) {
		std::cout << "Неверный ввод!\nВведите 1 или 2!";
	}
	else
		if (*vibor == 1) {
			std::cout << "Введите элементы массива: ";
			for (int i = 0;i < *n; ++i) {
				std::cin >> arr[i];
				if (arr[i] < 0) {
					std::cout << "Ошибка!\n";
					std::exit(-1);
				}
			}
			std::cout << "Заданный массив: " << std::endl;
			for (int j = 0; j < *n;++j) {

				std::cout << arr[j] << " ";
			}
			std::cout << std::endl;
		}
		else
			if (*vibor == 2) {
				std::cout << "Введите границы интервала: ";
				if (!(std::cin >> a) || !(std::cin >> b)) {
					std::cout << "Введите число!";
					std::exit(-1);
				}
				if (a > b) {
					int temp = a;
					a = b;
					b = temp;
				}
				std::cout << "Заданный массив:\n";
				for (int i = 0;i < *n;++i) {
					arr[i] = a + rand() % (b - a + 1);
					std::cout << arr[i] << " ";
				}
				std::cout << std::endl;
			}
			else if (*vibor != 1 && *vibor != 2) {
				std::cout << "Неверный ввод!";
				std::exit(-1);
			}
}
void smena(int* n, int* arr) {
	for (int i = 0;i < *n;++i) {
		int temp = arr[i];
		int count = 0;
		while (temp > 0) {
			count += temp % 2;
			temp /= 2;
		}
		if (count % 2 == 1) {
			arr[i] = 0;
		}
	}
}
void peremeschenie(int* n, int* arr) {
	int pos = 0;
	for (int i = 0;i < *n;++i) {
		if (arr[i] != 0) {
			arr[pos] = arr[i];
			pos++;
		}
	}
	while (pos < *n) {
		arr[pos] = 0;
		pos++;
	}
}
void vivod(int* n, int* arr) {
	std::cout << "Итоговый массив:\n";
	for (int i = 0;i < *n;++i) {
		std::cout << arr[i] << " ";
	}
}
int main()
{
	int arr[MAX];
	int n;
	setlocale(LC_ALL, ".1251");
	int vibor;
	razmer(&n);
	vibrat(&vibor, &n, arr);
	smena(&n, arr);
	peremeschenie(&n, arr);
	vivod(&n, arr);
	return 0;
}
