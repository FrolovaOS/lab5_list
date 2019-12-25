#pragma once
#include <string>
#include "TLists.h"
#include "TMonom.h"

using namespace std;

class TPolinom
{
private:
	TList<TMonom> monom;
	
public:
	TPolinom(string _Polinom);
	void ChangePolinom(string _Polinom);
	bool IsVariable(char c); // 
	bool IsSign(char c); // + or -
	TPolinom Integration(char c);
	TPolinom Derivative(char c); 
	double ValueInPoint(double _X, double _Y, double _Z);
	void Sort();
	string GetPolinom();//for google tests
	string ToString(double k);//for google tests
	friend ostream& operator<<(ostream& os, TPolinom& pl);
	//операции
	TPolinom Division( TPolinom& pl2, TPolinom& pl3);
	TPolinom operator+(TPolinom& pl);
	TPolinom operator*(TPolinom& pl);
	TPolinom operator-(TPolinom& pl);
	TPolinom& operator=(const TPolinom& pl);
	bool operator==(const TPolinom& pl) ;

}; 
ostream& operator<<(ostream& os, TPolinom& pl);