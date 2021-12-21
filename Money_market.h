#pragma once
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<fstream>
#include<vector>
#define FILEPATH "f.txt"
using namespace std;
class Money_market
{
private:
	int count_cur;
	vector<Money> arv;
public:
	Money_market()
	{
		count_cur = Money_market::count();

	};
	~Money_market()
	{
		/*arv.clear();
		cout << "Memory cleared" << endl;*/

	}
	vector<Money> get_arv();
	void output_all();
	void Input();
	void output();
	int count();
	int get_count_cur();
	void set_count_cur(int cor);
	void read_from_keyboard();
	static double isFloat();
	static int isInt();
	void ReadMoney();
	void delete_money();

	void operator+=(Money& moneys);
	/*void operator -= (vector<Money> arv) { delete_money(); }*/

	friend ifstream& operator>>(ifstream& stream, Money_market mon_container);
	friend istream&  operator>>(istream& stream, Money_market mon_container);
	friend ostream&  operator<<(ostream& stream, Money_market mon_container);
	friend ofstream& operator<<(ofstream& stream, Money_market mon_container);

};
