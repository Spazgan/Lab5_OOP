#ifndef Ырср_4_EXTA_H
#define Ырср_4_EXTA_H


#include<string>
#include<cstring>
#include<vector>

#define FILEPATH "f.txt"
using namespace std;
class Money
{
private:
	string currnecy;
	string state;
	string code;
	string subunit;
	double fraction;
	double rate;

public:
	string get_currency();
	string get_state();
	string get_code();
	string get_subunit();
	double get_fraction();
	double get_rate();
	void set_currency(string arg);
	void set_state(string arg);
	void set_code(string arg);
	void set_subunit(string arg);
	void set_fraction(float arg);
	void set_rate(float arg);

};
#endif
