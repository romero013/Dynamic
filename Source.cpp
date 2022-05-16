// ������������ ������
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
	
	// ������������ ����������
	int* pn = new int;
	*pn = 10;
	cout << *pn << endl;
	cout << pn << "\n\n";

	delete pn; // �������� ������� ������ ����������� �� ����������
	pn = nullptr; // ��������� ���������� �� ������� ������
	
	pn = new int;

	if (pn != nullptr) {
		*pn = 15;
		cout << *pn << endl;
		cout << pn << endl;
		delete pn;
	}
	else
		cout << "��������� �� ���������������!\n";

	// ������������ �������
	int size;
	cout << "������� ������ �������: ";
	cin >> size;
	int *dArr = new int[size]; // ��������� ������ ��� ������ ������� � size
	fillArr(dArr, size, 10, 31);
	cout << "�������� ������:\n";
	showArr(dArr, size);
	delete [] dArr; // �������� ������� ������ ����������� �� �������� �������

	// ������ 1
	cout << "������ 1.\n������� ����� �������: ";
	int size1;
	cin >> size1;
	int *z1 = new int[size1];
	fillArr(z1, size1, 10, 31);
	cout << "����������� ������:\n";
	showArr(z1, size1);

	int newS1;
	cout << "������� ���������� �����, ������� ���������� ��������: ";
	cin >> newS1;
	addEl(z1, size1, newS1);
	if (newS1 > 0)
		size1 += newS1;

	cout << "�������� ������:\n";
	showArr(z1, size1);

	delete [] z1;
	z1 = nullptr;

	// ������ 2
	cout << "������ 2.\n������� ����� �������: ";
	int size2;
	cin >> size2;
	int *z2 = new int[size2];
	fillArr(z2, size2, 10, 31);
	cout << "����������� ������:\n";
	showArr(z2, size2);

	int newS2;
	cout << "������� ���������� �����, ������� ���������� �������: ";
	cin >> newS2;
	delEl(z2, size2, newS2);
	if (newS2 > 0)
		size2 -= newS2;

	cout << "�������� ������:\n";
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
// ������ 1 (��������� ����� ������ �������)
template <typename T> void addEl(T *&arr, int length, int n) {
	// *&arr - ������ �� ���������, ����� �� �������� � ������ �������, � �� ������ � ������� �� ������,
	// � ������� ��������� �������� ������� �.�. ����� ������ ������� ����� ��������.
	// � ��� �� ������� ��������� �� ������ arr � ����� �������, ������� z1 �� �� ��� ������ ���������.
	if (n <= 0)
		return;
	T *tmp = new T[length + n]; // ������ ����� ������
	for (int i = 0; i < length; i++) // �������� � ���� ��� �������� ����������� �������
		tmp[i] = arr[i];
	delete [] arr;
	arr = tmp; // ������ ��������� � arr �� ����� ������ tmp
}
// ������ 2 (������� ����� ������ �������)
template <typename T> void delEl(T *&arr, int length, int n) {
	if (n <= 0 || n >= length)
		return;
	T *tmp = new T[length - n];
	for (int i = 0; i < length - n; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}