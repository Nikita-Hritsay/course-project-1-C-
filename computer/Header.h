#pragma once
#include <iostream>
#include <string>

using namespace std;

// ����������� �����
class Count {
public:
	virtual void Counter();
	virtual void output();
	virtual ~Count();
};
 
// ����� ��������� ����
class System_block: public Count {
private:
	string type_of_processor; // ��� ����������
	float frequence; // ������� ����������
	int hard_drive; // ����� ����������
	string CD_drive; // ��� CD_drive
	int price; // ���� ���������� �����
public:
	System_block(); // ����������� �� ���������
	System_block(string type_of_processor, float freaquence, int hard_drive, string CD_drive, int price); // ����������� �������������
	System_block(const System_block& other); // ����������� ����������
	
	void Set_type_of_processor(string type_of_processor); // ������ ���� ����������
	void Set_frequence(float frequence); // ������ ������� 
	void Set_hard_drive(int hard_drive); // ������ ������ ����������
	void Set_CD_drive(string CD_drive); // ������ CD_drive
	void Set_price(int price);
	void Counter() ;
	void output();

	string Get_type_of_processor(); // ������ ���� ����������
	float Get_frequence(); // ������ �������
	int Get_hard_drive(); // ������ ������ �������� �����
	string Get_CD_drive(); // ������ CD_drive
	int Get_price(); // ������ ����

	void operator ()(string type_of_processor, float frequence, int hard_drive, string CD_drive, int price); // �������� () 
	System_block& operator = (const System_block& other); // �������� =  

	friend istream& operator >> (istream & in, System_block& vvod); // �������� >>
	friend ostream& operator << (ostream& out, System_block& vivod); // �������� <<

	~System_block();

};

// ����� �������
class Monitor : public Count {
private:
	int diagonal; // ���������
	string quolity; // ����������
	int price; // ���� ��������
public:
	Monitor(); // ����������� �� ���������
	Monitor(int diagonal, string qoulity, int price); // ����������� �������������
	Monitor(const Monitor& other); // ����������� ����������

	void Set_diagonal(int diagonal); // ������ ���������
	void Set_quolity(string quolity); // ������ ������� 
	void Set_price(int price);
	void Counter();
	void output();

	int Get_diagonal(); // ������ ���������
	string Get_quolity(); // ������ �������
	int Get_price();
	
	void operator ()(int diagonal, string qoulity, int price); // �������� () 
	Monitor& operator = (const Monitor& other); // �������� = 
	friend istream& operator >> (istream& in, Monitor& vvod); // �������� >>
	friend ostream& operator <<(ostream& out, Monitor& vivod); // �������� <<
	
	~Monitor(); // ����������
};

// ����� ����������
class Keyboard : public Count {
private:
	string type_of_keyboard; // ��� ����������
	int buttons; // ���������� ������
	int price; // ���� ����������
public:
	Keyboard(); // ����������� �� ���������
	Keyboard(string type_of_keyboard, int buttons, int price); // ����������� �������������
	Keyboard(const Keyboard& other); // ����������� ����������

	void Set_type_of_keyboard(string type_of_keyboard); // ������ ���������
	void Set_buttons(int buttons); // ������ ������� 
	void Set_price(int price); // ������ ����
	void Counter();
	void output();

	string Get_type_of_keyboard(); // ������ ���� ���������
	int Get_buttons(); // ������ ���������� ������
	int Get_price(); // ������ ����

	void operator ()(string type_of_keyboard, int buttons, int price); // �������� () 
	Keyboard& operator = (const Keyboard& other); // �������� = 
	friend istream& operator >> (istream& in, Keyboard& vivod); // �������� >>
	friend ostream& operator <<(ostream& out, Keyboard& vvod); // �������� <<
	~Keyboard(); // ����������
};

// ����� �����
class Mouse : public Count {
private:
	string type_of_mouse; // ��� ���������� (���������� ��� ������������)
	int buttons; // ���������� ������
	int price; // ���� ����������
public:
	Mouse(); // ����������� �� ���������
	Mouse(string type_of_mouse , int buttons, int price); // ����������� �������������
	Mouse(const Mouse& other); // ����������� ����������

	void Set_type_of_mouse(string type_of_mouse ); // ������ ���������
	void Set_buttons(int buttons); // ������ ������� 
	void Counter();
	void output();
	
	string Get_type_of_mouse(); // ������ ���� �����
	int Get_buttons(); // ������ �������
	int Get_price();

	void operator ()(string type_of_mouse, int buttons, int price); // �������� () 
	Mouse& operator = (const Mouse& other); // �������� = 
	friend istream& operator >> (istream& in, Mouse& vivod); // �������� >>
	friend ostream& operator <<(ostream& out, Mouse& vvod); // �������� <<

	~Mouse(); // ����������
};

// ����� ��������� (���� ������ ����������)
class Computer : public System_block, public Monitor, public Keyboard, public Mouse {
private :
	int full_price; // ���� ������ ����������
	
public:
	Computer(); // ����������� �� ���������
	void Count_full_price(System_block* a, Monitor b, Keyboard c, Mouse d); // ����������� �������������
	void Set_full_price(int price); // ����� ��� �������� ����
	int Get_full_price(); // ������ ���� ����������
	friend istream& operator >> (istream& in, Computer& vvod); // �������� >>
	friend ostream& operator <<(ostream& out, Computer& vivod); // �������� <<
	~Computer();
};


