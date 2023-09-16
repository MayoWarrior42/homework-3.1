#include <iostream>
#include <fstream>
#include <string>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::ifstream fin("in.txt");
	std::ofstream fil("out.txt");
	std::string a;
	fin >> a;
	int size = stoi(a);
	int* arr = new int[size];
	std::cout << "Размер массива N: " << size;
	std::cout << "\nМассив: ";
	for (int i = 0; i < size; i++) {
		fin >> arr[i];
		std::cout << arr[i] << " ";
	}
	std::string s;
	fin >> s;
	int M = stoi(s);
	int* mas = new int[M];
	std::cout << "\nРазмер массива M: " << M;
	std::cout << "\nМассив: ";
	for (int i = 0; i < M; i++) {
		fin >> mas[i];
		std::cout << mas[i] << " ";
	}
	fil << size << "\n";
	std::cout << "\nМассив: ";
	int temp = arr[0];
	for (int i = 0; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = temp;

	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
		fil << arr[i] << " ";
	}
	int x = mas[M - 1];
	fil << "\n" << M << "\n";
	std::cout << "\nМассив: ";
	for (int i = M - 1; i > 0; i--) {
		mas[i] = mas[i - 1];
	}
	mas[0] = x;
	for (int i = 0; i < M; i++) {
		std::cout << mas[i] << " ";
		fil << mas[i] << " ";
	}
	fin.close();
	fil.close();
	delete[] arr;
	delete[] mas;
	return 0;
}

