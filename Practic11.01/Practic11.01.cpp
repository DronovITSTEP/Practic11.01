#include <iostream>

using namespace std;

/*int main()
{
	//константный указатель
	int a = 12;
	int* const ptr = &a;
	int b = 9;
	//ptr = &b; // error
	*ptr += 5;
	cout << *ptr << " " << a << endl;
	//int* const p; // error

	//указатель на константу
	const int* ptr2;
	ptr2 = &a;
	cout << *ptr2 << endl;
	ptr2 = &b;
	cout << *ptr2 << endl;
	//*ptr2 += 5; // error

	//константный указатель на константу
	const int* const ptr3 = &a;
	//ptr3 = &b;  //error
	//*ptr3 += 15;//error

	//имя_типа& имя_ссылки = выражение;
	//имя_типа& имя_ссылки (выражение);

	int ivar = 1234;
	int* iptr = &ivar;
	int& iref = ivar;
	int* p = &iref;

	cout << &ivar << endl << iptr << endl << &iref << endl << p;
}*/

/*//заполнение двумерного массива одинаковыми числами
int a[10][2];
int& rf(int index) {
	return a[index][1];
}


int main(){
	int b;
	cout << "Fill array\n";
	for (int i = 0; i < 10; i++) {
		cout << i + 1 << " element: ";
		cin >> b;
		a[i][0] = b;
		rf(i) = b;
	}

	cout << "\nShow array\n";
	for (int i = 0; i < 10; i++) {
		cout << a[i][0] << " " << a[i][0] << endl;
	}
}*/

/*//нахождение максимального элемента в массиве и замена его на ноль
int& rmax(int n, int d[]) {
	int im = 0;
	for (int i = 1; i < n; i++) {
		im = d[im] > d[i] ? im : i;
	}
	return d[im];
}

int main() {
	int arr[]{ 10,20,30,15 };
	int n = 4;
	cout << "max = " << rmax(n, arr) << endl;

	rmax(n, arr) = 0;

	for (int i = 0; i < n; i++) {
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}*/

/*
//динамическое выделение памяти
int main() {
	int* p = new int;
	*p = 9;
	int i = 23;
	delete p;
	p = &i;

	int c;
	cin >> c;
	int* a = new int[c];

	srand(time(NULL));
	int size;
	int* dar;

	cout << "Enter size: ";
	cin >> size;
	dar = new int[size];
	for (int i = 0; i < size; i++) {
		dar[i] = rand() % 100;
		cout << dar[i] << " ";
	}
	if (dar)
		delete[]dar;
}*/


/*
Используя указатели и оператор разыменования, 
определить наибольшее из двух чисел.
*/
void f1(int* a, int* b) {
	(*a > *b) ? cout << *a : cout << *b;
}

/*
Используя указатели и оператор разыменования, 
определить знак числа, введённого с клавиатуры.
*/
void f2(int* a) {
	(*a >= 0) ? cout << "poz" : cout << "neg";
}

/*
Используя указатель на массив целых чисел, 
посчитать сумму элементов массива. Использовать
в программе арифметику указателей для продвижения
по массиву, а также оператор разыменования.
*/
void f3(int* arr, int s, int& sum) {
	for (int i = 0; i < s; i++) {
		sum += *(arr++);
	}
}

/*
Дан массив: А[M] (M вводится с клавиатуры). 
Необходимо удалить из массива четные или нечетные значения. 
Пользователь вводит данные в массив, а также
с помощью меню решает, что нужно удалить.
*/
void f4(int* arr, int m, bool f) {
	int count = 0;
	int* temp;
	for (int i = 0; i < m; i++) {
		if (f) {
			if (*(arr + i) % 2 == 0) count++;
		}
		else
			if (*(arr + i)) count++;
	}
	temp = new int[count];
	for (int i = 0; i < m; i++) {
		if (f) {
			if (*(arr + i) % 2 == 0) {
				*temp = *(arr + i);
				temp++;
			}
		}
		else
			if (*(arr + i)) *(temp++) = *(arr + i);
	}
	delete[]arr;
	for (int i = 0; i < count; i++) {
		cout << *(temp + i) << " ";
	}
}

int main(){
	/*int a = 9, b = 34;
	int* pa = &a, *pb = &b;
	//f1(pa, pb);
	//f1(&a, &b);
	//f1(9, 34); //error
	//f2(&a);

	int sum = 0;
	int arr[5]{ 7,9,4,3,4 };
	f3(arr, 5, sum);
	cout << sum;*/
	setlocale(LC_ALL, "");

	int* arr = nullptr;
	int M;
	bool flag;
	cout << "Введите размер массива: "; cin >> M;
	arr = new int[M];
	int a;
	cout << "Внесение значений в массив\n";
	for (int i = 0; i < M; i++) {
		cout << "элемент " << i + 1 << ": ";
		cin >> a;
		arr[i] = a;
	}

	cout << "Какие числа удалить? (четные - 1/нечетные - 0): ";
	cin >> flag;
	f4(&arr[0], M, flag);
}