#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"
#include <Windows.h>
#pragma warning(disable : 4996)

using namespace std;

void Count::Counter() {}
void Count::output(){}
Count::~Count(){}
// Системный блок 

// Коструктор по умолчанию 
System_block::System_block(){
	this->type_of_processor = "";
	this->frequence = 0;
	this->hard_drive = 0;
	this->CD_drive = "";
} 
// Конструктор инициализации
System_block::System_block(string type_of_processor, float frequence, int hard_drive, string CD_drive, int price) {
	this->type_of_processor = type_of_processor;
	this->frequence = frequence;
	this->hard_drive = hard_drive;
	this->CD_drive = CD_drive;
	this->price = price;
} 
// Конструктор копирования
System_block::System_block(const System_block& other) {
	this->type_of_processor = other.type_of_processor;
	this->frequence = other.frequence;
	this->hard_drive = other.hard_drive;
	this->CD_drive = other.CD_drive;
}
// Деструктор
System_block::~System_block() {}


// сеттер типа процессора

void System_block::Set_type_of_processor(string type_of_processor)	 {
	bool flag = true;
	while (flag == true) {
		string sim = "!@#$%^&*()_-+=";
		bool flag = true;
			for (int i = 0; i < type_of_processor.length(); i++)
			{
				for (int j = 0; j < sim.size(); j++)
				{
					if (type_of_processor[i] == sim[j])
					{
						cout << "Введите коректный тип!" << endl;
						flag = true;
						break;
					}
					if (type_of_processor[i] != sim[j])
					{
						flag = false;
					}
				}
				
			}
			if (flag == false)
			{
				break;
			}
	}

	this->type_of_processor = type_of_processor;
}
// сеттер частоты 
void System_block::Set_frequence(float frequence) {
	while (frequence <=0 ||frequence >5)
	{
		cout << "Введите допустиму частоту от 1 до 5: " << endl;
		cin >> frequence;
	}
	this->frequence = frequence;
}
// сеттер объема винчестера
void System_block::Set_hard_drive(int hard_drive) {
	while (frequence <= 1 || frequence > 5000)
	{
		cout << "Введите допустимый объем жесткого диска от 100 до 5000: " << endl;
		cin >> hard_drive;
	}
	this->hard_drive = hard_drive;
}
// сеттер CD_drive
void System_block::Set_CD_drive(string CD_drive) {
	bool flag = true;
	while (flag == true) {
		string sim = "!@#$%^&*()_-+=1234567890";
		bool flag = true;
		for (int i = 0; i < CD_drive.length(); i++)
		{
			for (int j = 0; j < sim.size(); j++)
			{
				if (CD_drive[i] == sim[j])
				{
					cout << "Введите коректный тип!" << endl;
					flag = true;
					break;
				}
				if (CD_drive[i] != sim[j])
				{
					flag = false;
				}
			}

		}
		if (flag == false)
		{
			break;
		}
	}

	
	this->CD_drive = CD_drive;
}
// сеттер цены
void System_block::Set_price(int price) {
	this->price = price;
}
// подсчет цены систменого блока 
void System_block::Counter() {
	char buf[100];
	string* type_of_processor = new string[9]; // тип процессора
	float *frequence = new float[5]; // частота процессора
	int* hard_drive = new int[5]; // объем винчестера
	string* CD_drive = new string [3]; // вид CD_drive
	int price = 0 ; // цена системного блока
	int choose =0 ; // переменная для выбора пользователя
	ifstream fin("System_block.txt");// открытие файла
	if (!fin)// проверка на открытие
		cout << "ERROR" << endl;
	else {

		// тип процессора
		cout << endl <<"Выберете тип процессора: " << endl ;
		for (int i = 0; i < 9; i++)
		{
			fin.getline(buf, sizeof(buf), '\n'); // считывание с файла до  переноса строки
			type_of_processor[i] = strtok(buf, "\n"); // разделение
			cout << i + 1 << "." << type_of_processor[i] << endl; // вывод считованого типа процессора
		}
		cout << "Ваш выбор: ";
		cin >> choose; // выбор пользователя
		while (choose < 1 || choose > 9) { // проверка на коректность
			cout << "Ваш выбор должен быть от 1 до 9: " << endl;
			cin >> choose;
		}
		
		switch (choose)
			{
			case 1:
				Set_type_of_processor(type_of_processor[0]); // установка типа процессора
				price += 5000; // добаление цены
				break; // остановка 
			case 2:
				Set_type_of_processor(type_of_processor[1]);
				price += 7000;
				break;
			case 3:
				Set_type_of_processor(type_of_processor[2]); 
				price += 9000;
				break;
			case 4:
				Set_type_of_processor(type_of_processor[3]);
				price += 11000;
				break;
			case 5:
				Set_type_of_processor(type_of_processor[4]);
				price += 3000;
				break;
			case 6:
				Set_type_of_processor(type_of_processor[5]);
				price += 5000;
				break;
			case 7:
				Set_type_of_processor(type_of_processor[6]);
				price += 6000;
				break;
			case 8:
				Set_type_of_processor(type_of_processor[7]);
				price += 8000;
				break;
			case 9:
				Set_type_of_processor(type_of_processor[8]);
				price += 10000;
				break;
			default:
				break;
			}
		
		
		// частота
		cout << endl << "Выберете частоту процессора: " << endl;
		for (int i = 0; i < 5; i++)
		{
			fin >> frequence[i];
			cout << i + 1 << ". " <<  frequence[i] << endl;
		}
		choose = 0;
		cout << "Ваш выбор: ";
		cin >> choose;
		while (choose < 1 || choose > 5) {
			cout << "Ваш выбор должен быть от 1 до 4: " << endl;
			cin >> choose;
		}
		switch (choose)
		{
		case 1:
			Set_frequence(frequence[0]);
			price += 1000;
			break;
		case 2:
			Set_frequence(frequence[1]);
			price += 2000;
			break;
		case 3:
			Set_frequence(frequence[2]);
			price += 3000;
			break;
		case 4:
			Set_frequence(frequence[3]);
			price += 4000;
			break;
		case 5:
			Set_frequence(frequence[4]);
			price += 5000;
			break;
		default:
			break;
		}
		

		// объем винчестера 
		cout << endl << "Выберете объем винчестера: "  << endl;
		for (int i = 0; i < 5; i++)
		{
			fin >> hard_drive[i];
			cout << i + 1 << "." << hard_drive[i] << endl;
		}
		cout << "Ваш выбор: ";
		cin >> choose;
		while (choose < 1 || choose > 5) {
			cout << "Ваш выбор должен быть от 1 до 4: " << endl;
			cin >> choose;
		}
		switch (choose)
		{
		case 1:
			Set_hard_drive(hard_drive[0]);
			price += 700;
			break;
		case 2:
			Set_hard_drive(hard_drive[1]);
			price += 1000;
			break;
		case 3:
			Set_hard_drive(hard_drive[2]);
			price += 1500;
			break;
		case 4:
			Set_hard_drive(hard_drive[3]);
			price += 2500;
			break;
		case 5:
			Set_hard_drive(hard_drive[4]);
			price += 4000;
			break;
		default:
			break;
		}
		

		// CD_drive
		cout << endl << "Выберете тип CD_drive: "<< endl;
		for (int i = 0; i < 3; i++)
		{
			fin >> CD_drive[i];
			cout << i + 1 << "." << CD_drive[i] << endl;
		}
		cout << "Ваш выбор: ";
		cin >> choose;
		while (choose < 1 || choose > 3) {
			cout << "Ваш выбор должен быть от 1 до 3: " << endl;
			cin >> choose;
		}
		switch (choose)
		{
		case 1:
			Set_CD_drive(CD_drive[0]);
			price += 500;
			break;
		case 2:
			Set_CD_drive(CD_drive[1]);
			price += 700;
			break;
		case 3:
			Set_CD_drive(CD_drive[2]);
			price += 1000;
			break;
		default:
			break;
		}
		
		


		// тип процессора
		Set_price(price);
	}
	delete[] hard_drive;
	delete[] CD_drive;
	delete[] type_of_processor;
	delete[] frequence;



	fin.close();
	

}
//
void System_block::output() {
	cout <<"Тип процессора: " <<  this->type_of_processor << endl;
	cout << "Частота процессора: " << this->frequence << endl;
	cout << "Объем жесткого диска: " << this->hard_drive << endl;
	cout << "Вид CD_drive: " << this->CD_drive << endl;
	cout << "Цена компьютера: " << this->price << endl;
	cout << "----------" << endl;
} 

// геттер типа процессора
string System_block::Get_type_of_processor() { return type_of_processor; }
// геттер частоты
float System_block::Get_frequence() { return frequence; }
// геттер объема жесткого диска
int System_block::Get_hard_drive() { return hard_drive; }
// геттер CD_drive
string System_block::Get_CD_drive() { return CD_drive; }
// геттер цены
int System_block::Get_price() { return price; }

// оператор () 
void System_block::operator ()(string type_of_processor, float frequence, int hard_drive, string CD_drive, int price) {
	this->type_of_processor = type_of_processor;
	this->frequence = frequence;
	this->hard_drive = hard_drive;
	this->CD_drive = CD_drive;
	this->price = price;
}
//оператор =  
System_block& System_block::operator= (const System_block& other) {
	this->type_of_processor = other.type_of_processor;
	this->frequence = other.frequence;
	this->hard_drive = other.hard_drive;
	this->CD_drive = other.CD_drive;
	this->price = other.price;
	return *this;
}
// оператор >>
istream& operator >> (istream& in, System_block& vvod) {
	cout << "Bведите тип процессора: ";
	in >> vvod.type_of_processor;	

	cout << "Bведите частоту: ";
	in >> vvod.frequence;
	while (vvod.frequence < 0 || vvod.frequence > 5) {
		cout << "Bведите частоту: ";
		in >> vvod.frequence;
	}
	cout << "Bведите объем жесткого диска: ";
	in >> vvod.hard_drive;
	while (vvod.hard_drive < 0 || vvod.hard_drive > 5000) {
		cout << "Bведите объем жесткого диска: ";
		in >> vvod.hard_drive;
	}
	cout << "Введите вид CD_drive: ";
	in >> vvod.CD_drive;
	cout << "Введите цену: ";
	in >> vvod.price;
	while (vvod.price < 3000 || vvod.price > 500000) {
		cout << "Введите цену: ";
		in >> vvod.price;
	}
	return in;
}
// опервтор << 
ostream& operator <<(ostream& out, System_block& vivod) {
	out << endl << "----------" << endl;
	out << "Тип процессора: " << vivod.Get_type_of_processor() << endl;
	out << "Частота процессора: " << vivod.Get_frequence() << endl;
	out << "Объем жесткого диска: " << vivod.Get_hard_drive() << endl;
	out << "Вид CD_drive: " << vivod.Get_CD_drive() << endl;
	out << "Цена компьютера: " << vivod.Get_price() << endl;
	out << "----------" << endl;

	return out;
}


// Монитор 


// По умолчанию
Monitor::Monitor() {
	diagonal = 0;
	quolity = "";
	price = 0;
}
// Инициализации
Monitor::Monitor(int diagonal, string qoulity, int price) {
	this->diagonal = diagonal;
	this->quolity = quolity;
	this->price = price;
}
// Копирования
Monitor::Monitor(const Monitor& other) {
	this->diagonal = other.diagonal;
	this->quolity = other.quolity;
	this->price = other.price;
}

// сеттер диагональ
void Monitor::Set_diagonal(int diagonal) {
	while (diagonal <= 14 || diagonal > 100)
	{
		cout << "Введите допустимую диагональ от 14 до 100: " << endl;
		cin >> diagonal;
	}

	this->diagonal = diagonal;
}
// сеттер качества 
void Monitor::Set_quolity(string quolity) {
	bool flag = true;
	while (flag == true) {
		string sim = "!@#$%^&*()_-+=";
		bool flag = true;
		for (int i = 0; i < quolity.length(); i++)
		{
			for (int j = 0; j < sim.size(); j++)
			{
				if (quolity[i] == sim[j])
				{
					cout << "Введите коректный тип!" << endl;
					flag = true;
					break;
				}
				if (quolity[i] != sim[j])
				{
					flag = false;
				}
			}

		}
		if (flag == false)
		{
			break;
		}
	}
	this->quolity = quolity;
}
//
void Monitor::Set_price(int price) {

	this->price = price;
}
// геттер цены
int Monitor::Get_price() {
	return price;
}
//
int Monitor::Get_diagonal() {
	return diagonal;
}
//
string Monitor::Get_quolity() {
	return quolity;
}

// подсчет цены
void Monitor::Counter() {
	// тип процессора
	ifstream fin("Monitor.txt");
	int* diagonal = new int[5];
	string*quolity = new string[5];
	int price = 0;
	char buf[100];
	int choose;

	if (!fin) {
		cout << "ERROR" << endl;
	}
	else {
		// диагональ
		cout << endl << "Выберете диагональ:" << endl;
		for (int i = 0; i < 5; i++) {
			fin.getline(buf, sizeof(buf), ';\n');
			diagonal[i] = atoi(strtok(buf, ";\n"));
			cout << i + 1 << "." << diagonal[i] << endl;
		}
		cout << "Ваш выбор: ";
		cin >> choose;
		while (choose < 1 || choose > 5) {
			cout << "Ваш выбор должен быть от 1 до 5: " << endl;
			cin >> choose;
		}
		switch (choose)
		{
		case 1:
			Set_diagonal(diagonal[0]);
			price += 6000;
			break;
		case 2:
			Set_diagonal(diagonal[1]);
			price += 8000;
			break;
		case 3:
			Set_diagonal(diagonal[2]);
			price += 10000;
			break;
		case 4:
			Set_diagonal(diagonal[3]);
			price += 12000;
			break;
		case 5:
			Set_diagonal(diagonal[4]);
			price += 14000;
			break;
		default:
			break;
		}
		// качество
		cout << endl << "Выберете качетсво: " << endl;
		for (int i = 0; i < 5; i++) {
			fin.getline(buf, sizeof(buf), ';');
			quolity[i] = strtok(buf, ";");
			cout << i + 1 << "." << quolity[i] << endl;
		}
		cout << "Ваш выбор: ";
		cin >> choose;
		while (choose < 1 || choose > 5) {
			cout << "Ваш выбор должен быть от 1 до 5: " << endl;
			cin >> choose;
		}
		switch (choose)
		{
		case 1:
			price += 5000;
			Set_quolity(quolity[0]);
			break;
		case 2:
			price += 6000;
			Set_quolity(quolity[1]);
			break;
		case 3:
			price += 7000;
			Set_quolity(quolity[2]);
			break;
		case 4:
			price += 8000;
			Set_quolity(quolity[3]);
			break;
		case 5:
			price += 9000;
			Set_quolity(quolity[4]);
			break;
		default:
			break;
		}
		Set_price(price);
	}
	fin.close();
	delete[] diagonal;
	delete[] quolity;
}
// 
void Monitor::output() {
	cout << endl << "----------" << endl;
	cout << "Диагонал: " << diagonal << endl;
	cout << "Качество: " << quolity << endl;
	cout << "Цена: " << price << endl;
	cout << "----------" << endl;

}

// оператор () 
void Monitor::operator ()(int diagonal, string qoulity, int price) {
	this->diagonal = diagonal;
	this->quolity = quolity;
	this->price = price;
}
// оператор = 
Monitor& Monitor::operator= (const Monitor& other) {
	this->diagonal = other.diagonal;
	this->quolity = other.quolity;
	this->price = other.price;
	return *this;
}
// оператор >> 
istream& operator >> (istream& in, Monitor& vvod) { 
	cout << "Введите дигональ:";
	in >> vvod.diagonal;
	while (vvod.diagonal < 13 || vvod.diagonal > 100) {
		cout << "Введите дигональ:";
		in >> vvod.diagonal;
	}
	cout << "Введите качество:";
	in >> vvod.quolity;
	cout << "Введите цену: ";
	in >> vvod.price;
	while (vvod.price < 1000 || vvod.price > 30000) {
		cout << "Введите цену: ";
		in >> vvod.price;
	}
	return in; 
}
// опервтор << 
ostream& operator <<(ostream& out, Monitor& vivod) {
	out << endl << "----------" << endl;
	out << "Диагонал: " << vivod.diagonal << endl;
	out << "Качество: " << vivod.quolity << endl;
	out << "Цена: " << vivod.price << endl;
	out << "----------" << endl;
	return out; 
}

Monitor::~Monitor() {}


// Keyboard


// По умолчанию
Keyboard::Keyboard() {
	type_of_keyboard = ""; // тип клавиатуры
	buttons = 0; // количество кнопок
	price = 0; // цена клавиатуры
}
// Инициализации
Keyboard::Keyboard(string type_of_keyboard, int buttons, int price) {
	this->type_of_keyboard = type_of_keyboard;
	this->buttons = buttons;
	this->price = price;
}
// Копирования
Keyboard::Keyboard(const Keyboard& other) {
	this->buttons = other.buttons;
	this->type_of_keyboard = other.type_of_keyboard;
	this->price = other.price;
}
// Деструктор
Keyboard::~Keyboard() {}


// Сеттер тип клавиатуры
void Keyboard::Set_type_of_keyboard(string type_of_keyboard) {
	bool flag = true;
	while (flag == true) {
		string sim = "!@#$%^&*()_-+=1234567890";
		bool flag = true;
		for (int i = 0; i < type_of_keyboard.length(); i++)
		{
			for (int j = 0; j < sim.size(); j++)
			{
				if (type_of_keyboard[i] == sim[j])
				{
					cout << "Введите коректный тип!" << endl;
					flag = true;
					break;
				}
				if (type_of_keyboard[i] != sim[j])
				{
					flag = false;
				}
			}

		}
		if (flag == false)
		{
			break;
		}
	}
	this->type_of_keyboard = type_of_keyboard;
}	
// сеттер количество кнопок
void Keyboard::Set_buttons(int buttons) {
	this->buttons = buttons;
}
// сеттер цены
void Keyboard::Set_price(int price) {
	while(price < 400 || price > 10000)
	this->price = price;
}
// подсчет цены 
void Keyboard::Counter() {
	ifstream fin("Keyboard.txt");
	string* type = new string[4];
	int* but = new int[4];
	int choose;
	char buf[20];
	cout << endl << "Выберете тип клавиатуры:" << endl;
	if (fin) {
			for (int i = 0; i < 4; i++) {
				fin.getline(buf, sizeof(buf), '\n');
				type[i] = strtok(buf, "\n");
				cout << i + 1 << "." << type[i] << endl;
			}
			cout << "Ваш выбор: ";
			cin >> choose;
			while (choose < 1 || choose > 4) {
				cout << "Ваш выбор должен быть от 1 до 4: " << endl;
				cin >> choose;
			}
			switch (choose)
			{
			case 1:
				Set_type_of_keyboard(type[0]);
				price += 1000;
				break;
			case 2:
				Set_type_of_keyboard(type[1]);
				price += 1500;
				break;
			case 3:
				Set_type_of_keyboard(type[2]);
				price += 2000;
				break;
			case 4:
				Set_type_of_keyboard(type[3]);
				price += 3000;
				break;

			default:
				break;
			}

			cout << endl << "Выберете количество клавиш:" << endl;

			for (int i = 0; i < 4; i++) {
				fin.getline(buf, sizeof(buf), '\n');
				but[i] = atoi(strtok(buf, "\n"));
				cout << i + 1 << "." << but[i] << endl;
			}
			cout << "Ваш выбор: ";
			cin >> choose;
			while (choose < 1 || choose > 4) {
				cout << "Ваш выбор должен быть от 1 до 4: " << endl;
				cin >> choose;
			}
			switch (choose)
			{
			case 1:
				Set_buttons(but[0]);
				price += 200;
				break;
			case 2:
				Set_buttons(but[1]);
				price += 300;
				break;
			case 3:
				Set_buttons(but[2]);
				price += 500;
				break;
			case 4:
				Set_buttons(but[3]);
				price += 600;
				break;

			default:
				break;
			}
		}
	else {
			cout << "ERROR";
		}

	fin.close();
	delete[] type;
	delete[] but;
}
//
void Keyboard::output() {
	cout << endl << "----------" << endl;
	cout << "Тип клавиатуры: " << type_of_keyboard << endl;
	cout << "Количество кнопок:  " << buttons << endl;
	cout << "Цена: " << price << endl;
	cout << "----------" << endl;
}

// Геттер количества кнопок
int Keyboard::Get_buttons() {
	return this->buttons;
}
// геттер типа клавитуры
string Keyboard::Get_type_of_keyboard() {
	return  this->type_of_keyboard;
}
// геттер цены
int Keyboard::Get_price() {
	return this->price;
}

// оператор () 
void Keyboard::operator ()(string type_of_keyboard, int buttons, int price) {
	this->type_of_keyboard = type_of_keyboard;
	this->buttons = buttons;
	this->price = price;
}
// оператор = 
Keyboard& Keyboard::operator= (const Keyboard& other) {
	this->type_of_keyboard = other.type_of_keyboard;
	this->buttons = other.buttons;
	this->price = other.price;
	return *this;
}
// оператор >> 
istream& operator >> (istream& in, Keyboard& vvod) {
	cout << "Введите тип клавиатуры: ";
	in >> vvod.type_of_keyboard;
	cout << "Введите количество кнопок: ";
	in >> vvod.buttons;
	while (vvod.buttons < 50 || vvod.buttons > 120) {
		cout << "Введите количество кнопок: ";
		in >> vvod.buttons;
	}
	cout << "Введите цену: ";
	in >> vvod.price;
	while (vvod.price < 100 || vvod.price > 4000) {
		cout << "Введите цену: ";
		in >> vvod.price;
	}
	return in;
}
// опервтор << 
ostream& operator <<(ostream& out, Keyboard& vivod) {
	out << endl << "----------" << endl;
	out << "Тип клавиатуры: " << vivod.type_of_keyboard << endl;
	out << "Количество кнопок:  " << vivod.buttons << endl;
	out << "Цена: " << vivod.price << endl;
	out << "----------" << endl;
	return out;
}


// Мышка


// По умолчанию
Mouse::Mouse() {
	type_of_mouse = ""; // тип клавиатуры (оптическая или механическая)
	buttons = 0; // количество кнопок
	price = 0; // цена клавиатуры

}
// Инициализации
Mouse::Mouse(string type_of_mouse, int buttons , int price) {
	this->type_of_mouse = type_of_mouse;
	this->buttons = buttons;
	this->price = price;
}
// Копирования
Mouse::Mouse(const Mouse& other) {
	this->type_of_mouse = other.type_of_mouse;
	this->buttons = other.buttons;
	this->price = other.price;
}
//
Mouse::~Mouse() {}

// Геттер типа мышки
string Mouse::Get_type_of_mouse() {
	return type_of_mouse;
}
// Геттер количества кнопок
int Mouse::Get_buttons() {
	return buttons;
}
// Геттер цены
int Mouse::Get_price() {
	return price;
}

// Сеттер  типа мышки
void Mouse::Set_type_of_mouse(string type_of_mouse) {
	bool flag = true;
	while (flag == true) {
		string sim = "!@#$%^&*()_-+=1234567890";
		bool flag = true;
		for (int i = 0; i < type_of_mouse.length(); i++)
		{
			for (int j = 0; j < sim.size(); j++)
			{
				if (type_of_mouse[i] == sim[j])
				{
					cout << "Введите коректный тип!" << endl;
					flag = true;
					break;
				}
				if (type_of_mouse[i] != sim[j])
				{
					flag = false;
				}
			}

		}
		if (flag == false)
		{
			break;
		}
	}
	this->type_of_mouse = type_of_mouse;
}
// Сеттер количества кнопок
void Mouse::Set_buttons(int buttons) {
	this->buttons = buttons;
}
// подсчет цены
void Mouse::Counter() {
	ifstream fin("Mouse.txt");
	string* type = new string[4];
	int* but = new int[4];
	int choose;
	char buf[20];
	cout << endl << "Выберете тип мышки:" << endl;
	if (fin) {
		for (int i = 0; i < 4; i++) {
			fin.getline(buf, sizeof(buf), ';\n');
			type[i] = strtok(buf, ";\n");
			cout << i + 1 << "." << type[i] << endl;
		}
		cout << "Ваш выбор: ";
		cin >> choose;
		while (choose < 1 || choose > 4) {
			cout << "Ваш выбор должен быть от 1 до 4: " << endl;
			cin >> choose;
		}
		switch (choose)
		{
		case 1:
			Set_type_of_mouse(type[0]);
			price += 1000;
			break;
		case 2:
			Set_type_of_mouse(type[1]);
			price += 1500;
			break;
		case 3:
			Set_type_of_mouse(type[2]);
			price += 2000;
			break;
		case 4:
			Set_type_of_mouse(type[3]);
			price += 3000;
			break;

		default:
			break;
		}

		cout << endl << "Выберете количество кнопок:" << endl;

		for (int i = 0; i < 4; i++) {
			fin.getline(buf, sizeof(buf), ';\n');
			but[i] = atoi(strtok(buf, ";\n"));
			cout << i + 1 << "." << but[i] << endl;
		}
		cout << "Ваш выбор: ";
		cin >> choose;
		while (choose < 1 || choose > 4) {
			cout << "Ваш выбор должен быть от 1 до 4: " << endl;
			cin >> choose;
		}
		switch (choose)
		{
		case 1:
			Set_buttons(but[0]);
			price += 200;
			break;
		case 2:
			Set_buttons(but[1]);
			price += 300;
			break;
		case 3:
			Set_buttons(but[2]);
			price += 500;
			break;
		case 4:
			Set_buttons(but[3]);
			price += 600;
			break;

		default:
			break;
		}
	}
	else {
		cout << "ERROR";
	}

	fin.close();
	delete[] type;
	delete[] but;
}
//
void Mouse::output() {
	cout << endl << "----------" << endl;
	cout << "Тип мышки: " << type_of_mouse << endl;
	cout << "Количество кнопок: " << buttons << endl;
	cout << "Цена: " << price << endl;
	cout << "----------" << endl;
}

// оператор () 
void Mouse::operator ()(string type_of_mouse, int buttons, int price) {
	this->type_of_mouse = type_of_mouse;
	this->buttons = buttons;
	this->price = price;
}
// оператор =
Mouse& Mouse::operator= (const Mouse& other) {
	this->type_of_mouse = other.type_of_mouse;
	this->buttons = other.buttons;
	this->price = other.price;
	return *this;
}
// оператор >> 
istream& operator >> (istream& in, Mouse& vvod) {
	cout << "Введите тип мышки:";
	in >> vvod.type_of_mouse;
	cout << "Введите количество кнопок:";
	in >> vvod.buttons;
	while (vvod.buttons < 3 || vvod.buttons > 10) {
		cout << "Введите количество кнопок:";
		in >> vvod.buttons;
	}
	cout << "Введите цену: ";
	in >> vvod.price;
	while (vvod.price < 100 || vvod.price > 4000) {
		cout << "Введите цену: ";
		in >> vvod.price;
	}
	return in;
}
// опервтор << 
ostream& operator <<(ostream& out, Mouse& vivod) {
	out << endl << "----------" << endl;
	out << "Тип мышки: " << vivod.type_of_mouse << endl;
	out << "Количество кнопок: " << vivod.buttons << endl;
	out << "Цена: " << vivod.price << endl;
	out << "----------" << endl;
	return out;
}


// Computer
Computer::Computer() {
	full_price = 0;
}
// 
void Computer::Set_full_price(int price) {
	full_price += price;
}
void Computer::Count_full_price(System_block* a, Monitor b, Keyboard c, Mouse d) {
	Set_full_price(a->Get_price());
	//cout << a->Get_price() << endl;

	Set_full_price(b.Get_price());
	//cout << b.Get_price() << endl;

	Set_full_price(c.Get_price());
	//cout << c.Get_price() << endl;

	Set_full_price(d.Get_price());
	//cout << d.Get_price() << endl;

}
int Computer::Get_full_price() { return this->full_price; }
istream& operator >> (istream& in, Computer& vvod) {
	vvod.System_block::Counter();
	vvod.Monitor::Counter();
	vvod.Keyboard::Counter();
	vvod.Mouse::Counter();
	return in;
}
ostream& operator <<(ostream& out, Computer& vivod) {
	out << "--Цена целого блока компьютера: "<< vivod.Get_full_price() << endl;
	return out;
}
Computer::~Computer() {}

// контейнер 
template <typename T>
class classroom {
	T* arr; // шаблоный массив объектов
	int _n; // количество объектов в масссиве
	int price_class = 0; // начальная цена
public:
	class Iterator;
	// конструктор инициализации
	classroom(int n ) : _n(n) {
		arr = new T[n];
	}
	// сеттер цены
	void Set(int a) {
		price_class += a;
	}
	// подсчет цены
	void Count(int num) {
		price_class = 0;
		for (int i = 0; i < num; i++)
		{
			Set(arr[i].Get_full_price());
		}
	}
	// метод для вывода цены компьютерного класса
	void output() {
		cout << endl << "Цена целого компьютерного класса = " << price_class << endl;
	}
	// оператор []
	T& operator[] (const int& n) {
		if (n > 0 && n < _n)
			return arr[n];
		return arr[0];
	}
	Iterator begin() { return arr; }
	Iterator end() { return arr + _n; }

	// оператор << 
	friend ostream& operator<<(ostream& out, const classroom<T>& cc);

	class Iterator {
		T* cur;
	public:
		Iterator(T* first) :cur(first) {};

		T& operator+(int n) { return *(cur + n); }
		T& operator-(int n) { return *(cur - n); }
		T& operator++(int) { return *(cur++); }
		T& operator--(int) { return *(cur--); }
		T& operator++() { return *(++cur); }
		T& operator--() { return *(--cur); }

		bool operator !=(const Iterator& it) { return cur != it.cur; }
		bool operator ==(const Iterator& it) { return cur == it.cur; }
	
		T& operator* () { return *cur; }
	};

};

template <typename T>
ostream& operator<< (ostream& out, const classroom<T>& cc) {
	out << classroom::arr[cc];
	return out;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char hello;

	System_block block;
	Count* con;
	con = &block;
	System_block* a = &block;

	Monitor monitor;
	Count* mon;
	mon = &monitor;

	Keyboard key;

	Mouse mouse;

	Computer comp;

	
	System_block test_for_block ;
	Monitor test_for_monitor ;
	Keyboard test_for_key;
	Mouse test_for_momo;

	cout << "Программа определения цены компьютерного класса" << endl;
	cout << "Чтобы выбрать уже готовые комплектующие, нажмите 1\nвводить данные самому 2\nдля выхода нажмите 0 \n" << endl;
	cin >> hello;
	cout << "------------------" << endl;

	
	do{
		if(hello == '0') exit(1);
		else if (hello == '1') {
			cout << "Выберете комплектующие системного блока:" << endl;
			con->Counter();
			cout << endl << "Общая цена сборки одного системного блока : " << block.Get_price() << endl;
			cout << block;
			cout << "------------------" << endl;

			cout << "Выберете характеристики монитора:" << endl;
			mon->Counter();
			cout << endl << "Общая цена за монитор: " << monitor.Get_price() << endl;
			cout << monitor;
			cout << "------------------" << endl;

			cout << "Выберете характеристики клавиатуры:" << endl;
			key.Counter();
			cout << endl << "Общая цена за клавиатуру: " << key.Get_price() << endl;
			cout << key;
			cout << "------------------" << endl;

			cout << "Выберете характеристику мышки:" << endl;
			mouse.Counter();
			cout << "Общая цена за мышку: " << mouse.Get_price() << endl;
			cout << mouse;


			comp.Count_full_price(a, monitor, key, mouse);
			cout << comp;

			int num = 0;
			cout << "Введите количество компьютеров: ";

			cin >> num;
			classroom<Computer> arr(num);
			for (int i = 0; i < num; i++)
			{
				arr[i] = comp;
			}

			arr.Count(num);
			arr.output();

			auto it = classroom<Computer>::Iterator(arr.begin());

			while (it != arr.end()) {
				cout << *it << endl;
				it++;
			}
		}


		else {

			System_block* test = &test_for_block;

			cin >> test_for_block;
			cout << test_for_block;
			cin >> test_for_monitor;
			cout << test_for_monitor;
			cin >> test_for_key;
			cout << test_for_key;
			cin >> test_for_momo;
			cout << test_for_momo;

			comp.Count_full_price(test, test_for_monitor, test_for_key, test_for_momo);
			cout << comp;

			int num = 0;
			cout << "Введите количество компьютеров: ";

			cin >> num;
			classroom<Computer> arr(num);
			for (int i = 0; i < num; i++)
			{
				arr[i] = comp;
			}

			arr.Count(num);
			arr.output();

			auto it = classroom<Computer>::Iterator(arr.begin());

			while (it != arr.end()) {
				cout << *it << endl;
				it++;
			}
			
		}

		cout << "Чтобы выбрать уже готовые комплектующие, нажмите 1\nвводить данные самому 2\nдля выхода нажмите 0 \n" << endl;
		cin >> hello;
	} while (true);
	

	return 0;
}