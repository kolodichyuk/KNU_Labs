#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <functional>
#include <conio.h>

using namespace std;

class MenuAndGenerators {
	private: 
		vector<int>  generatedNumbers, MofUFirstSequence, MofUSecondSequence;
		vector<function<void()>> generators = {   // масив методів генерації псевдовипадкових чисел
			[&]() { // лінійний конгруентний метод
				cout << 
					"\t\t\t\t\t    Лiнiйний конгруентний метод                                       \n" <<
					"\t\t          Для генерацiї  випадкових  чисел  лiнiйним конгруентним методом   \n" <<
					"\t\t          та  побудови гiстограми  вам  необхiдно ввести  деякi параметри   \n" <<
					"\t\t          \\-------------------------------------------------------------/\n\n" <<
					"                                Вибiр модуля                                    \n" <<
					"Модуль повинен бути  достатньо  великим. Нехай w – довжина комп’ютерного  слова.\n" <<
					"В якостi модуля рекомендується брати найбiльше просте число, яке не перевищує w.\n" <<
					"|-------------------------|\n";
				cout << "Введiть значення модуля(m): ";
				int m = 0;
				cin >> m;
				cout <<
					"                         Вибiр множника та приросту                             \n" <<
					"Цей вибiр  визначається наступною  теоремою:  лiнiйна конгруентна послiдовнiсть,\n" <<
					"визначена  модулем(m),  множником(a),  приростом(c) i  початковим числом(X0) має\n" <<
					"перiод m тодi i лише тодi коли виконуються наступнi умови:                      \n" <<
					"     1) числа c та m є взаємно простими;                                        \n" <<
					"     2) число b = a - 1 є кратним числу p, де p - просте число яке єдiльником m;\n" <<
					"     3) число b є кратним 4, якщо число b кратне 4;                             \n";
				int a = 0, c = 0, initalNumber = 0;
				cout << "|---------------------------|\n";
				cout << "Введiть значення множника(a): ";
				cin >> a;
				cout << "Введiть значення приросту(c): ";
				cin >> c;
				cout << "Введiть  початкове число(X0): ";
				cin >> initalNumber;
				generatedNumbers.clear();
				MofUFirstSequence.clear();
				generatedNumbers.push_back(initalNumber);
				MofUFirstSequence.push_back(initalNumber);
				for (int i = 0; i < 99; i++) {
					initalNumber = (a * initalNumber + c) % m;
					generatedNumbers.push_back(initalNumber);
					MofUFirstSequence.push_back(initalNumber);
				}
				BuildChart();
			},

			[&]() { // квадратичний конгруентний метод
				cout << 
					"\t\t\t\t\t  Квадратичний конгруентний метод                                     \n" <<
					"\t\t          Для генерацiї випадкових чисел квадратичним конгруентним методом  \n" <<
					"\t\t          та   побудови гiстограми  вам  необхiдно ввести деякi  параметри  \n" <<
					"\t\t          \\-------------------------------------------------------------/\n\n" <<
					"                                 Вибiр параметрiв                               \n" <<
					"Цей вибiр визначається наступною теоремою: квадратична конгруентна послiдовнiсть\n" <<
					"визначена числами m, a, c, d, X0, має перiод m тодi i лише тодi коли виконуються\n" <<
					"чотири у мови:                                                                  \n" <<
					"     1) числа c та m є взаємно простими;                                        \n" <<
					"     2) числа d i a - 1 кратнi числу p, де p - простi дiльники числа m;         \n" <<
					"     3) число d парне i конгруентне a-1 mod m, якщо число m кратне 4;           \n" <<
					"     4) число d не не конгруентне 3с mod 9, якщо m кратне 3;                    \n" <<
					"|---------------------------|\n";
				int m = 0, a = 0, c = 0, d = 0, initalNumber = 0;
				cout << "Введіть значення параметра m: ";
				cin >> m;
				cout << "Введіть значення параметра a: ";
				cin >> a;
				cout << "Введіть значення параметра c: ";
				cin >> c;
				cout << "Введіть значення параметра d: ";
				cin >> d;
				cout << "Введіть початкове значення X: ";
				cin >> initalNumber;
				generatedNumbers.clear();
				MofUSecondSequence.clear();
				generatedNumbers.push_back(initalNumber);
				MofUSecondSequence.push_back(initalNumber);
				for (int i = 0; i < 99; i++) {
					initalNumber = (a * initalNumber * initalNumber + a * initalNumber + c) % m;
					generatedNumbers.push_back(initalNumber);
					MofUSecondSequence.push_back(initalNumber);
				}
				BuildChart();
                        },

			[&]() { // метод числел Фiбоначчi
				cout << 
					"\t\t\t\t\t          Числа Фiбоначчi                                             \n" << 
					"\t\t             Для генерацiї випадкових чисел методом чисел Фібоначі та       \n" <<
					"\t\t             побудови гiстограми вам необхiдно ввести деякi параметри       \n" <<
					"\t\t             \\-----------------------------------------------------/     \n\n" << 
					"                                 Вибiр параметрiв                               \n" <<
					"Єдиним параметром  даного  способу  генерації псевдовипадкових чисел є модуль(m)\n" <<
					"|-------------------------|\n";
				int m = 0, initalFrist = 0, initalSecond = 0;
				cout << "Введiть значення модуля(m): ";
				cin >> m;
				cout << "Введiть значення першого початкового числа: ";
				cin >> initalFrist;
				cout << "Введiть значення другого початкового числа: ";
				cin >> initalSecond;
				int inital;
				generatedNumbers.clear();
				generatedNumbers.push_back(initalFrist);
				generatedNumbers.push_back(initalSecond);
				for (int i = 0; i < 98; i++) {
					inital = (initalFrist + initalSecond) % m;
					generatedNumbers.push_back(inital);
					initalSecond = initalFrist;
					initalFrist = inital;
				}
				BuildChart();
			},

			[&]() { // метод оберненої конгруентної послідовності
				cout <<
					"\t\t\t\t\t Обернена конгруентна послiдовнiсть                                    \n" <<
					"\t\t       Для генерацiї випадкових чисел оберненої конгруентної послiдовностi   \n" <<
					"\t\t       та   побудови  гiстограми  вам необхiдно  ввести  деякi   параметри   \n" <<
					"\t\t       \\-----------------------------------------------------------------/\n\n" <<
					"                                 Вибiр параметрiв                                \n" <<
					"Параметрами даного методу генерацiї псевдовипадкових висел є множник(a),         \n" <<
					"прирiст(с), просте число p та початкове значення                                 \n" <<
	                                "|----------------------------|\n";
				int a = 0, c = 0, p = 0, initalNumber = 0;
				cout << "Введiть  значення множника(a): ";
				cin >> a;
				cout << "Введiть значення  приросту(c): ";
				cin >> c;
				cout << "Введіть будь яке просте число: ";
				cin >> p;
				cout << "Введіть початкове значення X: ";
				cin >> initalNumber;
				generatedNumbers.clear();
				generatedNumbers.push_back(initalNumber);
				for (int i = 0; i < 100; i++) {
					initalNumber = (a / initalNumber + c) % p;
					generatedNumbers.push_back(initalNumber);
				}
				BuildChart();
                        },

			[&]() { // метод об'єднань
				cout <<
					"\t\t\t\t\t         Метод об’єднання                                             \n" <<
					"\t\t             Для генерацiї випадкових чисел методом чисел Фiбоначi та       \n" <<
					"\t\t             побудови гiстограми вам необхiдно ввести деякi параметри       \n" <<
					"\t\t             \\-----------------------------------------------------/     \n\n" <<
					"                                 Вибiр параметрiв                               \n" <<
					"Параметром даного методу генерацiї псевдовипадкових висел є модуль(m),          \n" <<
					"|-------------------------|\n";
				int m = 0;
				cout << "Введiть значення модуля(m): ";
				cin >> m;
				generatedNumbers.clear();
				for (int i = 0; i < 100; i++) {
					int item = (MofUFirstSequence[i] - MofUSecondSequence[i]) % m;
					generatedNumbers.push_back(item);
				}
				BuildChart();
                        }, 
		};

		#pragma region Методи відображення результатів
		void BuildChart() {
			int maxNumber = 0;
			for (const auto &number : generatedNumbers)
				if (number > maxNumber)
					maxNumber = number;
			map<string, int> resultChart = {
				{"[0 - 0.1]:  ", 0},
				{"[0.1 - 0.2]:", 0},
				{"[0.2 - 0.3]:", 0},
				{"[0.3 - 0.4]:", 0},
				{"[0.4 - 0.5]:", 0},
				{"[0.5 - 0.6]:", 0},
				{"[0.6 - 0.7]:", 0},
				{"[0.7 - 0.8]:", 0},
				{"[0.8 - 0.9]:", 0},
				{"[0.9 - 1]:  ", 0}
			};
			for (int i = 0; i < 100; i++) {
				double value = generatedNumbers[i] / maxNumber;
				if (value >= 0 && value <= 0.1)
					resultChart.at("[0 - 0.1]:  ")++;
				else if (value > 0.1 && value <= 0.2)
					resultChart.at("[0.1 - 0.2]:")++;
				else if (value > 0.2 && value <= 0.3)
					resultChart.at("[0.2 - 0.3]:")++;
				else if (value > 0.3 && value <= 0.4)
					resultChart.at("[0.3 - 0.4]:")++;
				else if (value > 0.4 && value <= 0.5)
					resultChart.at("[0.4 - 0.5]:")++;
				else if (value > 0.5 && value <= 0.6)
					resultChart.at("[0.5 - 0.6]:")++;
				else if (value > 0.6 && value <= 0.7)
					resultChart.at("[0.6 - 0.7]:")++;
				else if (value > 0.7 && value <= 0.8)
					resultChart.at("[0.7 - 0.8]:")++;
				else if (value > 0.8 && value <= 0.9)
					resultChart.at("[0.8 - 0.9]:")++;
				else if (value > 0.9 && value <= 1.0)
					resultChart.at("[0.9 - 1]:  ")++;
			}
			cout << "\n\tГiстограма результатів\n" <<
				"\t\\--------------------/\n";
			for (auto it = resultChart.begin(); it != resultChart.end(); it++) {
				cout << it->first << " " << it->second << "%\n";
			}
			_getch();
		}
		#pragma endregion

        #pragma region Методи показу елементів меню
		void MainMenu() {   // показ головного меню
			cout <<
				"\t\t Програма  призначена  для  демонстрацiї  роботи  5-ти  алгоритмiв генерацiї\n"  <<
				"\t\t псевдовипадкових чисел. Для запуску потрiбного алгоритму виберiть його номер\n"  <<
				"\t\t \\........................................................................../\n" <<
				"\tАлгоритми генерування рiвномiрно розподiлених чисел:\n"            <<
				"[0]:  Лiнiйний конгруентний метод.\n"                                <<
				"[1]:  Квадратичний конгруентний метод.\n"                            <<
				"[2]:  Числа Фiбоначчi.\n"                                            <<
				"[3]:  Обернена конгруентна послiдовнiсть.\n"                         <<
				"[4]:  Метод об’єднання.\n"                                           <<
				"[-1]: Вихiд.\n"                                                      <<
				"|-----------------|\n"                                               <<
				"Зробiть свiй вибiр: ";
		}
        #pragma endregion
	public:
	     void MainLogic() {   // головна логіка програми
		while (true) {
			system("cls");
			MainMenu();
			int inputValue = 0;
			cin >> inputValue;
			if (inputValue == -1)
			    break;
			system("cls");
			generators[inputValue]();
		}
	     }
};
