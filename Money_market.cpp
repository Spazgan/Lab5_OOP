#include<iostream>
#include<iomanip>
#include<istream>
#include<vector>
#include<iterator>
#include<fstream>
#include<cstring>
#include<string>
#include "Money_market.h"
#include "Money.h"
#define FILEPATH "f.txt"
using namespace std;
int Money_market::count()
{
	ifstream fin;
	fin.open(FILEPATH);
	string temp;
	getline(fin, temp);
	int count = stoi(temp);
	cout << "Number of currencies--" << count << "\n" << endl;
	return count;
}
void Money_market::ReadMoney()
{
	ifstream fin;
	fin.open(FILEPATH);
	string temp;
	Money temp_obj;
	getline(fin, temp);
	int count = stoi(temp);
	for (int i = 0; i < count; i++)
	{
		getline(fin, temp);
		temp_obj.set_currency(temp);

		getline(fin, temp);
		temp_obj.set_state(temp);

		getline(fin, temp);
		temp_obj.set_code(temp);

		getline(fin, temp);
		temp_obj.set_subunit(temp);

		getline(fin, temp);

		float plp = stof(temp);

		temp_obj.set_fraction(stof(temp));

		getline(fin, temp);
		temp_obj.set_rate(stof(temp));

		arv.push_back(temp_obj);
	}
	fin.close();
}

void Money_market::Input()
{
	ofstream fin;
	fin.open(FILEPATH);
	fin << this->get_arv().size() << endl;

	for (int i = 0; i < arv.size(); i++)
	{
		fin << this->get_arv().at(i).get_currency() << endl;
		fin << this->get_arv().at(i).get_state() << endl;
		fin << this->get_arv().at(i).get_code() << endl;
		fin << this->get_arv().at(i).get_subunit() << endl;
		fin << this->get_arv().at(i).get_fraction() << endl;
		fin << this->get_arv().at(i).get_rate() << endl;
	}

	fin.close();

}
void Money_market::read_from_keyboard()

{
	cout << "Enter the number of currencies you want to enter" << endl;
	int count;
	float temp_numf;
	string temp_line;
	Money temp_obj;
	count = isFloat();
	for (int i = 0; i < count; i++)
	{
		cout << "Input Currency: ";
		cin >> temp_line;
		temp_obj.set_currency(temp_line);
		cout << "Input state: ";
		cin >> temp_line;
		temp_obj.set_state(temp_line);
		cout << "Input code: ";
		cin >> temp_line;
		temp_obj.set_code(temp_line);
		cout << "Input subunit: ";
		cin >> temp_line;
		temp_obj.set_subunit(temp_line);
		cout << "Input fraction: ";
		temp_numf = isFloat();
		temp_obj.set_fraction(temp_numf);
		cout << "Input rate: ";
		temp_numf = isFloat();
		temp_obj.set_rate(temp_numf);
		arv.push_back(temp_obj);
	}
}
void Money_market::delete_money()
{

	cout << "Enter Currency ";
	string name;
	cin >> name;
	for (int i = 0; i < count_cur; i++)
	{
		if (arv[i].get_currency() == name)
		{
			arv.erase(arv.begin() + i);
			count_cur--;
			break;
		}

	}
}

double Money_market::isFloat()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Print number: ";
	}
	return a;
}
int Money_market::isInt()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Print number: ";
	}
	return a;
}

void Money_market::output()
{
	float DR = 0;
	for (int i = 0; i < arv.size(); i++)
	{
		if (get_arv().at(i).get_currency() == "Dollar")
		{
			DR = get_arv().at(i).get_rate();
		}
	}
	cout << "Courses of Valutes" << endl;

	for (int i = 0; i < arv.size(); i++)
	{
		cout << get_arv().at(i).get_code() << "-" << get_arv().at(i).get_rate() << "\n" << endl;
	}
	cout << left << setw(25) << "Name";
	cout << left << setw(24) << "State";
	cout << left << setw(16) << "Code";
	cout << left << setw(24) << "Subunit";
	cout << left << setw(16) << "Frac";
	cout << "Rate" << endl;
	for (int i = 0; i < arv.size(); i++)
	{
		if (DR < get_arv().at(i).get_rate())
		{
			cout << left << setw(25) << get_arv().at(i).get_currency();
			cout << left << setw(24) << get_arv().at(i).get_state();
			cout << left << setw(16) << get_arv().at(i).get_code();
			cout << left << setw(24) << get_arv().at(i).get_subunit();
			cout << left << setw(16) << get_arv().at(i).get_fraction();
			cout << get_arv().at(i).get_rate() << endl;
		}
	}


	cout<<DR<<endl;
}
void Money_market::output_all()
{
	cout << left << setw(25) << "Name";
	cout << left << setw(24) << "State";
	cout << left << setw(16) << "Code";
	cout << left << setw(24) << "Subunit";
	cout << left << setw(16) << "Frac";
	cout << "Rate" << endl;
	for (int i = 0; i < arv.size(); i++)
	{
		cout << left << setw(25) << get_arv().at(i).get_currency();
		cout << left << setw(24) << get_arv().at(i).get_state();
		cout << left << setw(16) << get_arv().at(i).get_code();
		cout << left << setw(24) << get_arv().at(i).get_subunit();
		cout << left << setw(16) << get_arv().at(i).get_fraction();
		cout << get_arv().at(i).get_rate() << endl;
	}
}
void Money_market::operator+=(Money& moneys)
{
	arv.push_back(moneys);
}

//geters
vector<Money> Money_market::get_arv()
{
	return arv;
}
int Money_market::get_count_cur()
{
	return count_cur;
}
//seters
void Money_market::set_count_cur(int cor)
{
	count_cur = cor;
}

istream& operator>>(istream& stream, Money_market mon_container)//Заменяем Read_from_keyboard
{
	
	Money temp_money;
	int count;
	string temp_line;
	float temp_float;

	cout << "Enter the number of currencies you want to enter";
	count = Money_market::isInt();
	for (int i = 0; i < count; i++)
	{
		cout << "Enter Currency";
		stream.get();//.get используем, что-бы число из строки не записывалось в след.поле;
		getline(stream, temp_line);
		temp_money.set_currency(temp_line);

		cout << "Enter State";
		stream.get();
		getline(stream, temp_line);
		temp_money.set_state(temp_line);

		cout << "Enter Code";
		stream.get();
		getline(stream, temp_line);
		temp_money.set_code(temp_line);

		cout << "Enter Subunit";
		stream.get();
		getline(stream, temp_line);
		temp_money.set_subunit(temp_line);

		cout << "Enter Fraction";
		stream >> temp_float;
		temp_money.set_fraction(temp_float);

		cout << "Enter Rate";
		stream >> temp_float;
		temp_money.set_rate(temp_float);



	}
	return stream;
}

ifstream& operator>>(ifstream& stream, Money_market mon_container)//Заменяем Read_Money
{
	string temp_line;
	Money temp_money;
	getline(stream, temp_line);
	int count = stoi(temp_line);

	for (int i = 0; i < count; i++)
	{
		getline(stream, temp_line);
		temp_money.set_currency(temp_line);

		getline(stream, temp_line);
		temp_money.set_state(temp_line);

		getline(stream, temp_line);
		temp_money.set_code(temp_line);

		getline(stream, temp_line);
		temp_money.set_subunit(temp_line);

		getline(stream, temp_line);
		temp_money.set_fraction(stof(temp_line));

		getline(stream, temp_line);
		temp_money.set_rate(stof(temp_line));

		mon_container += temp_money;
	}
	return stream;
}

ostream& operator<<(ostream& stream, Money_market mon_container)//Замена метода output_all
{
	stream << left << setw(25) << "Name";
	stream << left << setw(24) << "State";
	stream << left << setw(16) << "Code";
	stream << left << setw(24) << "Subunit";
	stream << left << setw(16) << "Frac";
	for (int i = 0; i < mon_container.arv.size(); i++)
	{
		stream << left << setw(25) <<mon_container.get_arv().at(i).get_currency();
		stream << left << setw(24) <<mon_container.get_arv().at(i).get_state();
		stream << left << setw(16) <<mon_container.get_arv().at(i).get_code();
		stream << left << setw(24) <<mon_container.get_arv().at(i).get_subunit();
		stream << left << setw(16) <<mon_container.get_arv().at(i).get_fraction();
		stream << mon_container.get_arv().at(i).get_rate() << endl;
	}

	return stream;
}
ofstream& operator<<(ofstream& stream, Money_market mon_container)//Замена метода Input	
{
	stream << mon_container.get_arv().size() << endl;
	for (int i = 0; i < mon_container.get_arv().size(); i++)
	{
		stream << mon_container.get_arv().at(i).get_currency() << endl;
		stream << mon_container.get_arv().at(i).get_state() << endl;
		stream << mon_container.get_arv().at(i).get_code() << endl;
		stream << mon_container.get_arv().at(i).get_subunit() << endl;
		stream << mon_container.get_arv().at(i).get_fraction() << endl;
		stream << mon_container.get_arv().at(i).get_rate() << endl;
	}
	return stream;
}