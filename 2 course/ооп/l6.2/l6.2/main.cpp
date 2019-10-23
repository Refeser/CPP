#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream vivod;
ifstream vvod;

int *m;
class stack
{
private:
	int size;
	int *a;
public:
	int count = 0;
	stack();
	void del();
	void vvod(int l);
	void vyvod();
	void pop();
	void push();
	int& operator[](int i);
	int Getsize()
	{
		return size;
	};
	friend istream& operator >> (istream&, stack&);
	friend ostream& operator << (ostream&, stack&);

};

void stack::del()
{
	delete[]a;
	size = 0;
};

stack::stack()
{
	a = new int[256];
	size = 0;
}

void stack::vvod(int l)
{
	if (size>256)
	{
		cout << "Perepolnenie!!!" << endl;
	}
	else
	{
		a[size] = l;
		size++;
		count++;
	}
};

int& stack::operator[](int i)
{
	if (i<0 || i >= size)
	{
		cout << "(i=" << i << ")" << endl;
	}
	return a[i];
}

void stack::vyvod()
{
	vivod.open("vivod.txt");
	for (int i = 0; i < size; i++)
	{
		vivod << a[i];
		vivod << ' ';
	}
	cout << endl;
	vivod.close();
};

void stack::pop()
{
	int i;
	m = new int[size];
	for (i = 0; i<size; i++)
	{
		m[i] = a[i];
	}

};

void stack::push()
{
	int i, j = 1;
	for (i = 0; i<size / 2; i++)
	{
		a[i] = m[j];
		j = j + 2;
	}
	size = size / 2;
}


istream& operator >> (istream& in, stack &t)
{
	int z, n;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		in >> z;
		t.vvod(z);
	}
	return in;
}

ostream& operator << (ostream& out, stack &t)
{
	for (int i = t.Getsize() - 1; i >= 0; i--)
	{
		out << t[i];
	}
	return out;

}

int main()
{
	setlocale(LC_ALL, "Rus");
	int  j;
	string d;
	stack a;
	cout << "Идет ввод элементов..." << endl;
	vvod.open("vvod.txt", ios_base::in);
	for (j = 0; j < a.count; j++)
	{
		if (!vvod.is_open()) cout << "Error: File is not founded!";
		else {
			for (int i = 0; i < a.count; i++) {
				vvod >> d;
				a.vvod(stoi(d));
			}
		}
	}
	vvod.close();
	cout << endl;

	cout << "Удаление нечетных элементов..." << endl;
	a.pop();
	a.push();
	cout << "Удаление нечетных элементов завершено!" << endl;

	//vivod.open("vivod.txt");
	//vivod << a;
	//vivod.close();
	a.vyvod();


	cout << "Результат записан в файл vivod.txt!";
	cout << endl;
	a.del();
	return 0;
	system("pause");
}