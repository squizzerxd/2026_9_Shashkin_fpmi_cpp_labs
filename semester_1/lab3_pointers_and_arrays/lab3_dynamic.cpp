#include <iostream>
#include <cstdlib>    
void razmer(int* n) {
	std::cout << "Введите размер массива: ";
	if (!(std::cin >> *n)) {
		std::cout << "Введите число!";
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
void findmax(int* n, int* arr, int* min_k, int* max_val) {
	*min_k = 1000000;      
	*max_val = -1000000;   
	for (int i = 0; i < *n; i++) {
		bool uzhe_bilo = false;
		for (int k = 0; k < i; k++) {
			if (arr[k] == arr[i]) {
				uzhe_bilo = true; 
				break;
			}
		}
		if (uzhe_bilo == true) {
			continue;
		}
		int count = 0;
		for (int j = 0; j < *n; j++) {
			if (arr[j] == arr[i]) {
				count++;
			}
		}
		     if (count < *min_k) {
			*min_k = count;
			*max_val = arr[i];
		}
		else if (count == *min_k) {
			if (arr[i] > *max_val) {
				*max_val = arr[i];
			}
		}
	}
}
void vivod(int* min_k, int* max_val) {
	
	std::cout << "\nМинимальная кратность: " << *min_k << std::endl;
	std::cout << "Максимальный элемент с этой кратностью: " << *max_val << std::endl;
	}
int main()
{
	int n;
	setlocale(LC_ALL, ".1251");
	int vibor;
	razmer(&n);
	int* arr = new int[n];
	int min_k, max_val;
	vibrat(&vibor, &n, arr);
	findmax(&n, arr, &min_k, &max_val );
	vivod(&min_k, &max_val);
	delete[] arr;
	return 0;
}
