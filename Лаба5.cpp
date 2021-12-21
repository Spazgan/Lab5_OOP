#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>
#include"Money.h"
#include"Money.cpp"
#include"Money_market.h"
#include"Money_market.cpp"
#define FILEPATH "f.txt"
using namespace std;
int main()
{
	int key = -1;
	Money_market arv;
	Money tempMoney;
	ifstream fin;
	fin.open(FILEPATH);
	Money_market mon_container;
	fin >> mon_container;
	fin.close();
	arv.ReadMoney();
	cout<<mon_container;
	ofstream fon;
	cout << "\nPress 1 if you want to output all currency \n" << endl;
	cout << "Press 2 if you want to write a new currency\n" << endl;
	cout << "Press 3 if you wnat to delete currency from program\n" << endl;


	while (key != 4)
	{
		cin >> key;



		switch (key)
		{
		case 1:
			cout << mon_container;
			break;
		case 2:
			fon.open(FILEPATH);
			//arv += tempMoney;
			cin >> mon_container;
			fon << mon_container;
			//arv.read_from_keyboard();
			//arv.Input();
			fon.close();
			cout << "done" << endl;

			break;
		case 3:
			//arv.delete_money();
			cout << "done" << endl;
			break;

		}
	}
	return 0;
}