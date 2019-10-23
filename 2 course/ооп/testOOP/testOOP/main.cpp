#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

class Test {
public:
	int kol = 0, otvet1, otvet2, otv1, otv2, kolvo = 16, a, b, c;
	bool kon = false;
	void randUrav();
	void reshenieUrav();
	void proverka();
	void konec();
};

void Test::randUrav() {
	a = rand() % 10000; b = rand() % 10000; c = rand() % 10000;
	int znak_a = rand() % 2; int znak_b = rand() % 2; int znak_c = rand() % 2;
	if (znak_a == 1) a = -(a); if (znak_b == 1) b = -(b); if (znak_c == 1) c = -(c);
}

void Test::reshenieUrav() {
	int d = b*b - 4 * a*c;
	if (d < 0)
	{
		otv1 = 12345;
		otv2 = 12345;
	}
	else if (d == 0)
	{
		otv1 = (-b) / (2 * a);
		otv2 = 12345;
	}
	else
	{
		otv1 = ((-b) + sqrt(d)) / (2 * a);
		otv2 = ((-b) - sqrt(d)) / (2 * a);
	}
}

void Test::proverka() {
	if ((otvet1 == otv1 && otvet2 == otv2) || (otvet1 == otv2 && otvet2 == otv1))
	{
		kol++;
	}
	else if ((otvet1 == otv1 && otvet2 != otv2) || (otvet1 != otv1 && otvet2 == otv2))
	{
		cout << "1 из корней неверен. + 1 уравнение!" << endl;
		kolvo++;
	}
	else
	{
		cout << "Оба ответа неверны! Вам еще + 2 уравнения!" << endl;
		kol--;
		kolvo += 2;
	}
}

void Test::konec() {
	if (kolvo / 100 * 80 >kol)
	{
		kon = true;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	Test t;
	srand(time(NULL));
	cout << "Если ответа нет, пропишите в ответе 12345. Ответ не может превышать 10000 и быть дробным. Если ответ дробный, то в ответе запишите целую часть без округления!" << endl;
	while (t.kol < 16)
	{
		t.randUrav();
		if (t.a == 0) continue;
		t.reshenieUrav();
		if (t.otv1 < 10000 && t.otv2 < 10000) {
			cout << t.a << "X^2 + (" << t.b << ")X + (" << t.c << ") = 0" << endl;
			cout << "x1 = ";
			cin >> t.otvet1;
			cout << endl << "x2 = ";
			cin >> t.otvet2;
			t.proverka();
			t.konec();
		}
		else continue;
		if (t.kon == true)
		{
			cout << "Поздравляю! Вы успешно решили более 80 процентов уравнений!" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}