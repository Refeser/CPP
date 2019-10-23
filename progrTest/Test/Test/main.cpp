#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "Rus");
	int kol = 0, otvet1, otvet2, otv1, otv2, kolvo = 16;
	srand(time(NULL));
	cout << "Если ответа нет, пропишите в ответе 12345. Ответ не может привышать 10000 и быть дробным. Если ответ дробный, то в ответе запишите целую часть без округления!" << endl;

	while (kol < 16)
	{
		int a = rand() % 10000; int b = rand() % 10000; int c = rand() % 10000;
		int znak_a = rand() % 2; int znak_b = rand() % 2; int znak_c = rand() % 2;
		if (znak_a == 1) a = -(a); if (znak_b == 1) b = -(b); if (znak_c == 1) c = -(c);

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

		if (otv1 < 10000 && otv2 < 10000)
		{
			cout << a << "X^2 + (" << b << ")X + (" << c << ") = 0" << endl;
			cout << "x1 = ";
			cin >> otvet1;
			cout << endl << "x2 = ";
			cin >> otvet2;

			if ((otvet1 == otv1 && otvet2 == otv2)||(otvet1 == otv2 && otvet2 == otv1))
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
			if (kolvo / 100 * 80 > kol)
			{
				cout << "Поздравляю! Вы успешно решили более 80 процентов уравнений!" << endl;
				break;
			}
		}

	}
	system("pause");
	return 0;
}