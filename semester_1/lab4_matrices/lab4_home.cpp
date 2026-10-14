
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <clocale>
int SizeOfMatrix() {
	int n;
	std::cout << "Введите размер массива: ";
	if (!(std::cin >> n)) {
		std::cout << "Введите число!";
		std::exit(-1);
	}
	if (n == 0) {
		std::cout << "Нулевой массив!" << std::endl;
		std::exit(0);
	}
	if (n < 0) {
		std::cout << "Ошибка!" << std::endl;
		std::exit(-1);
	}
	return n;
}
int** pamyatMatrix(int n) {

	int** arr = new int* [n];
	for (int i = 0; i < n;++i) {
		arr[i] = new int[n];
	}
	return arr;
}
void FullMatrix(int** arr, int n) {
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			arr[i][j] = std::abs(i - j);
		}
	}


}

void vivodMatrix(int** arr, int n) {
	std::cout << "Текущая матрица:" << std::endl;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			std::cout << std::setw(2) <<  arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void CountAllTri(int** arr, int n, int* SumUp, int* SumDown, int* SumLeft, int* SumRight) {
	
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			if (i == j || i + j == n - 1) continue;
			if (i < j && i + j < n - 1) *SumUp += arr[i][j];
			else if (i > j && i + j > n - 1) *SumDown += arr[i][j];
			else if (i < j && i + j > n - 1) *SumRight += arr[i][j];
			else if (i > j && i + j < n - 1) *SumLeft += arr[i][j];
		}
	}
}

void vivodAllTri(int* SumUp, int* SumDown, int* SumLeft, int* SumRight) {
	std::cout << "Сумма элементов верхнего треугольника: " << *SumUp << std::endl;
	std::cout << "Сумма элементов нижнего треугольника: " << *SumDown << std::endl;
	std::cout << "Сумма элементов левого треугольника: " << *SumLeft << std::endl;
	std::cout << "Сумма элементов правого треугольника: " << *SumRight << std::endl;

}
void deletearr(int** arr, int n) {
	for (int i = 0; i < n; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}
int main()
{
	int SumUp = 0;
	int SumDown = 0;
	int SumRight = 0;
	int SumLeft = 0;
	setlocale(LC_ALL, ".1251");
	int n = SizeOfMatrix();
	int** arr = pamyatMatrix(n);
    FullMatrix(arr,n);
	vivodMatrix(arr,n);
    CountAllTri(arr,n,&SumUp,&SumDown,&SumLeft,&SumRight);
	vivodAllTri(&SumUp, &SumDown, &SumLeft, &SumRight);
	deletearr(arr, n);
}
