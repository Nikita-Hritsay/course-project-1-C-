#pragma once
#include <iostream>
#include <string>

using namespace std;

// полиморфный класс
class Count {
public:
	virtual void Counter();
	virtual void output();
	virtual ~Count();
};
 
// класс Системный блок
class System_block: public Count {
private:
	string type_of_processor; // тип процессора
	float frequence; // частота процессора
	int hard_drive; // объем винчестера
	string CD_drive; // вид CD_drive
	int price; // цена системного блока
public:
	System_block(); // конструктор по умолчанию
	System_block(string type_of_processor, float freaquence, int hard_drive, string CD_drive, int price); // конструктор инициализации
	System_block(const System_block& other); // конструктор кпированию
	
	void Set_type_of_processor(string type_of_processor); // сеттер типа процессора
	void Set_frequence(float frequence); // сеттер частоты 
	void Set_hard_drive(int hard_drive); // сеттер объема винчестера
	void Set_CD_drive(string CD_drive); // сеттер CD_drive
	void Set_price(int price);
	void Counter() ;
	void output();

	string Get_type_of_processor(); // геттер типа процессора
	float Get_frequence(); // геттер частоты
	int Get_hard_drive(); // геттер объема жесткого диска
	string Get_CD_drive(); // геттер CD_drive
	int Get_price(); // геттер цены

	void operator ()(string type_of_processor, float frequence, int hard_drive, string CD_drive, int price); // оператор () 
	System_block& operator = (const System_block& other); // оператор =  

	friend istream& operator >> (istream & in, System_block& vvod); // оператор >>
	friend ostream& operator << (ostream& out, System_block& vivod); // опервтор <<

	~System_block();

};

// класс Монитор
class Monitor : public Count {
private:
	int diagonal; // диагональ
	string quolity; // разрешение
	int price; // цена монитора
public:
	Monitor(); // конструктор по умолчанию
	Monitor(int diagonal, string qoulity, int price); // конструктор инициализации
	Monitor(const Monitor& other); // конструктор кпированию

	void Set_diagonal(int diagonal); // сеттер диагональ
	void Set_quolity(string quolity); // сеттер частоты 
	void Set_price(int price);
	void Counter();
	void output();

	int Get_diagonal(); // геттер диагональ
	string Get_quolity(); // геттер частоты
	int Get_price();
	
	void operator ()(int diagonal, string qoulity, int price); // оператор () 
	Monitor& operator = (const Monitor& other); // оператор = 
	friend istream& operator >> (istream& in, Monitor& vvod); // оператор >>
	friend ostream& operator <<(ostream& out, Monitor& vivod); // опервтор <<
	
	~Monitor(); // деструктор
};

// класс Клавиатура
class Keyboard : public Count {
private:
	string type_of_keyboard; // тип клавиатуры
	int buttons; // количество кнопок
	int price; // цена клавиатуры
public:
	Keyboard(); // конструктор по умолчанию
	Keyboard(string type_of_keyboard, int buttons, int price); // конструктор инициализации
	Keyboard(const Keyboard& other); // конструктор кпированию

	void Set_type_of_keyboard(string type_of_keyboard); // сеттер диагональ
	void Set_buttons(int buttons); // сеттер частоты 
	void Set_price(int price); // сеттер цены
	void Counter();
	void output();

	string Get_type_of_keyboard(); // геттер типа клавитуры
	int Get_buttons(); // геттер количества кнопок
	int Get_price(); // геттер цены

	void operator ()(string type_of_keyboard, int buttons, int price); // оператор () 
	Keyboard& operator = (const Keyboard& other); // оператор = 
	friend istream& operator >> (istream& in, Keyboard& vivod); // оператор >>
	friend ostream& operator <<(ostream& out, Keyboard& vvod); // опервтор <<
	~Keyboard(); // деструктор
};

// класс Мышка
class Mouse : public Count {
private:
	string type_of_mouse; // тип клавиатуры (оптическая или механическая)
	int buttons; // количество кнопок
	int price; // цена клавиатуры
public:
	Mouse(); // конструктор по умолчанию
	Mouse(string type_of_mouse , int buttons, int price); // конструктор инициализации
	Mouse(const Mouse& other); // конструктор кпированию

	void Set_type_of_mouse(string type_of_mouse ); // сеттер диагональ
	void Set_buttons(int buttons); // сеттер частоты 
	void Counter();
	void output();
	
	string Get_type_of_mouse(); // геттер типа мышки
	int Get_buttons(); // геттер частоты
	int Get_price();

	void operator ()(string type_of_mouse, int buttons, int price); // оператор () 
	Mouse& operator = (const Mouse& other); // оператор = 
	friend istream& operator >> (istream& in, Mouse& vivod); // оператор >>
	friend ostream& operator <<(ostream& out, Mouse& vvod); // опервтор <<

	~Mouse(); // деструктор
};

// класс Компьютер (цена целого компьютера)
class Computer : public System_block, public Monitor, public Keyboard, public Mouse {
private :
	int full_price; // цена целого компьютера
	
public:
	Computer(); // конструктор по умолчанию
	void Count_full_price(System_block* a, Monitor b, Keyboard c, Mouse d); // конструктор инициализации
	void Set_full_price(int price); // метод для подсчета цены
	int Get_full_price(); // геттер цены компьютера
	friend istream& operator >> (istream& in, Computer& vvod); // оператор >>
	friend ostream& operator <<(ostream& out, Computer& vivod); // опервтор <<
	~Computer();
};


