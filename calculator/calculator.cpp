// calculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stack>
using namespace std;

struct Leksema //Структура, описывающая любое число или операцию
{
	char type; // 0 для чисел, "+" для операции сложения и т.д.
	double value; //Значение (только для чисел). У операций значение всегда "0"
};

bool Maths(stack <Leksema>& Stack_n, stack <Leksema>& Stack_o, Leksema& item) { //Математическая функция, которая производит расчеты
	//Функция имеет тип bool, чтобы при возникновении какой-либо ошибки возвращать "false"
	double a, b, c;
	a = Stack_n.top().value; //Берется верхнее число из стека с числами
	Stack_n.pop(); //Удаляется верхнее число из стека с числами
	switch (Stack_o.top().type) {  //Проверяется тип верхней операции из стека с операциями
	case '+': //Если тип верхней операции из стека с операциями сложение
		b = Stack_n.top().value;
		Stack_n.pop();
		c = a + b;
		item.type = '0';
		item.value = c;
		Stack_n.push(item); //Результат операции кладется обратно в стек с числами
		break;

	case '-':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = b - a;
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		break;

	case '*':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = a * b;
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		break;

	case '/':
		b = Stack_n.top().value;
		if (a == 0) {
			cerr << "\nНа 0 делить нельзя!\n";
			return false;
		}
		else {
			Stack_n.pop();
			c = (b / a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			break;
		}
	default:
		cerr << "\nОшибка!\n";
		return false;
		break;
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "rus");
	char Ch; //Переменная, в которую будет записываться текущий обрабатываемый символ
	double value;
	stack <Leksema> Stack_n; //Стек с числами
	stack <Leksema> Stack_o; //Стек с операциями
	Leksema item; //Объект типа Leksema
	while (1) {
		Ch = cin.peek(); //Смотрим на первый символ
		if (Ch == '\n')break; //Если достигнут конец строки, выходим из цикла
		if (Ch >= '0' && Ch <= '9') { //Если прочитано число
			cin >> value;
			item.type = '0';
			item.value = value;
			Stack_n.push(item); //Число кладется в стек с числами
			continue;
		}
		if (Ch == '+' || Ch == '-' || Ch == '*' || Ch == '/') { //Если прочитана операция
			item.type = Ch;
			item.value = 0;
			Stack_o.push(item); //Операция кладется в стек с операциями
			cin.ignore();
			continue;
		}
	}
	if (Maths(Stack_n, Stack_o, item) == false) { //Если функция вернет "false", то прекращаем работу
		system("pause");
		return 0;
	}
	else { //Если все хорошо, выдаем ответ
		cout << "Otvet: " << Stack_n.top().value << endl;
		return 0;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
