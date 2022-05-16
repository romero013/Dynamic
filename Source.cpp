// Динамическая память
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T> void fillArr(T arr[], int length, int min, int max);
template <typename T> void showArr(T arr[], int length);

template <typename T> void addEl(T *&arr, int length, int n);
template <typename T> void delEl(T *&arr, int length, int n);

int main() {
	setlocale(LC_ALL, "Russian");
	
	// Динамические переменные
	int* pn = new int;
	*pn = 10;
	cout << *pn << endl;
	cout << pn << "\n\n";

	delete pn; // Очищение области памяти указывающей на переменную
	pn = nullptr; // Вынесение переменной за область памяти
	
	pn = new int;

	if (pn != nullptr) {
		*pn = 15;
		cout << *pn << endl;
		cout << pn << endl;
		delete pn;
	}
	else
		cout << "Указатель не инициализирован!\n";

	// Динамические массивы
	int size;
	cout << "Введите размер массива: ";
	cin >> size;
	int *dArr = new int[size]; // Выделение памяти под массив длинной в size
	fillArr(dArr, size, 10, 31);
	cout << "Итоговый массив:\n";
	showArr(dArr, size);
	delete [] dArr; // Очищение области памяти указывающей на элементы массива

	// Задача 1
	cout << "Задача 1.\nВведите длину массива: ";
	int size1;
	cin >> size1;
	int *z1 = new int[size1];
	fillArr(z1, size1, 10, 31);
	cout << "Изначальный массив:\n";
	showArr(z1, size1);

	int newS1;
	cout << "Введите количество ячеек, которое необходимо добавить: ";
	cin >> newS1;
	addEl(z1, size1, newS1);
	if (newS1 > 0)
		size1 += newS1;

	cout << "Итоговый массив:\n";
	showArr(z1, size1);

	delete [] z1;
	z1 = nullptr;

	// Задача 2
	cout << "Задача 2.\nВведите длину массива: ";
	int size2;
	cin >> size2;
	int *z2 = new int[size2];
	fillArr(z2, size2, 10, 31);
	cout << "Изначальный массив:\n";
	showArr(z2, size2);

	int newS2;
	cout << "Введите количество ячеек, которое необходимо удалить: ";
	cin >> newS2;
	delEl(z2, size2, newS2);
	if (newS2 > 0)
		size2 -= newS2;

	cout << "Итоговый массив:\n";
	showArr(z2, size2);

	delete [] z2;
	z2 = nullptr;

	return 0;
}

template <typename T> void fillArr(T arr[], int length, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}

template <typename T> void showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
// Задача 1 (добавляем новые ячейки массива)
template <typename T> void addEl(T *&arr, int length, int n) {
	// *&arr - Ссылка на указатель, чтобы не работать с копией массива, а на прямую с ссылкой на память,
	// в которой находятся элементы массива т.к. после работы функции копия исчезает.
	// А раз мы удалили указатель на массив arr в конце функции, массиву z1 не на что теперь ссылаться.
	if (n <= 0)
		return;
	T *tmp = new T[length + n]; // Создаём новый массив
	for (int i = 0; i < length; i++) // Копируем в него все элементы переданного массива
		tmp[i] = arr[i];
	delete [] arr;
	arr = tmp; // Меняем указатель с arr на новый массив tmp
}
// Задача 2 (удаляем новые ячейки массива)
template <typename T> void delEl(T *&arr, int length, int n) {
	if (n <= 0 || n >= length)
		return;
	T *tmp = new T[length - n];
	for (int i = 0; i < length - n; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}