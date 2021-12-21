#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<sstream>
#include<cstring>
#include<fstream>
#include<Windows.h>
#include"Money.h"
#include <winnt.h>
#include "Money.h"
#define FILEPATH "f.txt"
using namespace std;
string Money::get_currency()
{
	return currnecy;
}

string Money::get_state()
{
	return state;
}

string Money::get_code()
{
	return code;
}

string Money::get_subunit()
{
	return subunit;
}

double Money::get_fraction()
{
	return fraction;
}

double Money::get_rate()
{
	return rate;
}
// seter

void Money::set_currency(string arg)
{
	currnecy = arg;
}

void Money::set_state(string arg)
{
	state = arg;
}

void Money::set_code(string arg)
{
	code = arg;
}

void Money::set_subunit(string arg)
{
	subunit = arg;
}

void Money::set_fraction(float arg)
{
	fraction = arg;
}

void Money::set_rate(float arg)
{
	rate = arg;
}
