#pragma once
#include "TLists.h"
#include "TMonom.h"
#include "TPolinom.h"
#include <iostream>
#include <math.h>
#include <sstream>

TPolinom::TPolinom(string _Polinom)
{
	ChangePolinom(_Polinom);
}

void TPolinom::ChangePolinom(string _Polinom)
{
	monom.DelList();
	TMonom mn(0, -1);
	monom.InsFict(mn);

	int lenPolinom = _Polinom.length();

	string num; // строка для считывание коэфициента
	int degres;
	double coef;
	int sign = 1;
	int X, Y, Z;

	for (int i = 0; i < lenPolinom; )
	{
		X = Y = Z = 0;
		degres = 0;
		coef = 0;
		num = "";

		while (_Polinom[i] == ' ')
			i++;

		if ((i < lenPolinom) && (IsSign(_Polinom[i])))
		{
			if (_Polinom[i] == '-')
				sign = -1;
			else sign = 1;
			i++;
		}
		while ((i < lenPolinom) && ((!IsVariable(_Polinom[i])) && (!IsSign(_Polinom[i])))) 
		{
			num += _Polinom[i];
			i++;
		}
		while ((i < lenPolinom) && (IsVariable(_Polinom[i])))
		{
			switch (_Polinom[i])
			{
			case 'X':
			{
				if (_Polinom[i + 1] == '^')
				{
					i+=2;
					while ((i < lenPolinom)&&(!IsVariable(_Polinom[i]))&&(!IsSign(_Polinom[i])))
					{
						X = X * 10 + (_Polinom[i] - '0');
						i++;
					}
				}
				else
				{
					X = 1;
					i++;
				}
				continue;
			}
			case 'Y':
			{
				if (_Polinom[i + 1] == '^')
				{
					i+=2;
					while ((i < lenPolinom)&&(!IsVariable(_Polinom[i])) && (!IsSign(_Polinom[i])))
					{
						Y = Y * 10 + (_Polinom[i] - '0');
						i++;
					}
				}
				else
				{
					Y = 1;
					i++;
				}
				continue;
			}
			case 'Z':
			{
				if (_Polinom[i + 1] == '^')
				{
					i+=2;
					while ((i < lenPolinom)&&(!IsVariable(_Polinom[i])) && (!IsSign(_Polinom[i])))
					{
						Z = Z * 10 + (_Polinom[i] - '0');
						i++;
					}
				}
				else
				{
					Z = 1;
					i++;
				}
				continue;
			}
			}

		}

		degres = X * 10000 + Y * 100 + Z;
		if (num == "")
			coef = 1 * sign;
		else
			coef = sign * stoi(num);
		mn.SetValue(coef, degres);

		if (monom.IsEmpty())
			monom.InsFirst(mn);
		else
		{
			monom.InsLast(mn);
		}
		mn.Clear();

	}
	if(!monom.IsEmpty())
	Sort();
}

bool TPolinom::IsVariable(char c)
{
	return (c=='X'||c=='Y'||c=='Z');
}

bool TPolinom::IsSign(char c)
{
	return (c=='+'||c=='-');
}


TPolinom TPolinom::Integration(char c)
{
	TPolinom result("");
	int x, y, z,power;
	double coef;
	switch (c)
	{
		case 'X':
		{
			for (monom.Reset(); !monom.IsListEnded(); monom.GoNext()) // 210540
			{	
				TMonom tmp= monom.GetVal();
				power = tmp.GetPower();

				x = power / 10000 ;
				y = power / 100 - x * 100;
				z = power % 100;

				x++;

				coef = tmp.GetCoef() / x ;
				int newpower = x * 10000 + y * 100 + z;
				tmp.SetValue(coef,newpower);
				result.monom.InsLast(tmp);
			}
			return result;
			break;
		}
		case 'Y':
		{
			for (monom.Reset(); !monom.IsListEnded(); monom.GoNext())
			{
				TMonom tmp = monom.GetVal();
				power = tmp.GetPower();
				x = power/ 10000 ;
				y = power / 100 - x*100;
				z = power % 100;

				y++;

				coef = tmp.GetCoef() / y;
				int newpower = x * 10000 + y * 100 + z;
				tmp.SetValue(coef, newpower);
				result.monom.InsLast(tmp);
			}
			return result;
			break;
		}
		case 'Z':
		{
			for (monom.Reset(); !monom.IsListEnded(); monom.GoNext())
			{	
				TMonom tmp = monom.GetVal();
				
				power = tmp.GetPower();
				z = power % 100;
				z++;
				power++;

				coef = tmp.GetCoef() / z;

				tmp.SetValue(coef, power);
				result.monom.InsLast(tmp);
			}
			return result;
			break;
		}
	}
}

TPolinom TPolinom::Derivative(char c)
{	
	TPolinom result("");
	int x, y, z,  power;
	double coef;
	switch (c)
	{
		case 'X':
		{	
			monom.Reset();
			while ((!monom.IsListEnded())&&(!monom.IsEmpty()))
			{
				TMonom tmp = monom.GetVal();
				power = tmp.GetPower();
				coef = tmp.GetCoef();
				x = power / 10000;
				y = power / 100 - x * 100;
				z = power%100;

				x--;

				if (x >= 0)
					power -= 100;

				if (x < 0)
				{
					monom.GoNext();
					continue;
				}

				if (x != 0)
					coef = tmp.GetCoef() * (x + 1) ;

				int newpower = x * 10000 + y * 100 + z;
				tmp.SetValue(coef, newpower);
				result.monom.InsLast(tmp);
				monom.GoNext();
			}
			return result;
			break;
		}
		case 'Y':
		{
			monom.Reset();
			while ((!monom.IsListEnded()) && (!monom.IsEmpty()))
			{
				TMonom tmp = monom.GetVal(); 

				power = tmp.GetPower();
				coef = tmp.GetCoef();

				x = power / 10000;
				y = power / 100 - x * 100 ;
				z = power % 100 ;

				y--;

				if (y > 0)
					power -= 10;

				if (y < 0)
				{
					monom.GoNext();
					continue;
				}
				if (y != 0)
					coef = tmp.GetCoef() * (y + 1);

				int newpower = x * 10000 + y * 100 + z;
				tmp.SetValue(coef, newpower);
				result.monom.InsLast(tmp);
				monom.GoNext();
			}
			return result;
			break;
		}
	
		case 'Z':
		{
			monom.Reset();
			while ((!monom.IsListEnded()) && (!monom.IsEmpty()))
			{
				TMonom tmp = monom.GetVal();
				power = tmp.GetPower(); 
				coef = tmp.GetCoef();
				z = power % 100;

				if (z != 0)
				{
					power--;
					z--;
				}
				else
				{
					monom.GoNext();
					continue;
				}

				if (z != 0)
					coef = tmp.GetCoef() * (z + 1);

				tmp.SetValue(coef, power);
				result.monom.InsLast(tmp);
				monom.GoNext();
			}
		}	
		return result;
		break;
	}
}

double TPolinom::ValueInPoint(double _X, double _Y, double _Z)
{
	int X, Y, Z,X1,Y1,Z1,power;
	X = _X;
	Y = _Y;
	Z = _Z;
	double result,coef;
	result = 0.0;
	TMonom tmp;
	for (monom.Reset(); !monom.IsListEnded(); monom.GoNext())
	{
		tmp = monom.GetVal();
		coef = tmp.GetCoef();
		power = tmp.GetPower();
		X1 = power / 10000;
		Y1 = power / 100 - X1 * 100;
		Z1 = power % 100;
		result += coef * pow(X, X1) * pow(Y, Y1) * pow(Z, Z1);
	}
	return result;
}

void TPolinom::Sort()
{
	TPolinom tmp("");
	TMonom p;
	double coef;
	while (!monom.IsListEnded())
	{
		p = monom.GetVal();
		if (tmp.monom.IsEmpty())
		{
			tmp.monom.InsFirst(p); monom.DelFirst();
		}
		else
		{
			tmp.monom.Reset();
			TMonom tmp1 = tmp.monom.GetVal();

			while ((tmp1.GetPower()>p.GetPower()) && (!tmp.monom.IsListEnded()) && (tmp1.GetPower() > 0))
			{
				tmp.monom.GoNext();
				tmp1 = tmp.monom.GetVal();
			}

			if (tmp1.GetPower() == p.GetPower())
			{
				coef = tmp1.GetCoef() + p.GetCoef();
				p.SetCoef(coef);
				tmp.monom.SetCurrentVal(p);
				monom.DelFirst();
			}
			else if (tmp.monom.IsListEnded())
			{
				tmp.monom.InsLast(p);
				monom.DelFirst();
			}
			else if (!tmp.monom.IsListEnded())
			{
				tmp.monom.InsCurrent(p);
				monom.DelFirst();
			}
		}
	}
	*this = tmp;
}

string TPolinom::GetPolinom()
{
	string k="";

	double  coef;
	int power, x, y, z;
	TMonom p;
	if (monom.IsEmpty())
		cout << 0 << endl;
	else
	{
		for (monom.Reset(); !monom.IsListEnded(); monom.GoNext())
		{
			p = monom.GetVal();
			coef = p.GetCoef();

			if (coef > 0) k += "+";
			string s = "";
			power = p.GetPower();
			x = power / 10000;
			y = power / 100 - x * 100;
			z = power % 100;

			if ((x == 0) && (y != 0) && (z != 0))
			{
				s = ToString(coef);
				s += 'Y'; s += '^'; s += ToString(y);
				s += 'Z'; s += '^'; s += ToString(z);
			}
			else if ((x != 0) && (y == 0) && (z != 0))
			{
				s = ToString(coef);
				s += 'X'; s += '^'; s += ToString(x);
				s += 'Z'; s += '^'; s += ToString(z);
			}
			else if ((x != 0) && (y != 0) && (z == 0))
			{
				s = ToString(coef);
				s += 'X'; s += '^';
				s += ToString(x);
				s += 'Y'; s += '^'; s += ToString(y);
			}
			else if ((x == 0) && (y == 0) && (z != 0))
			{
				s = ToString(coef);
				s += 'Z'; s += '^'; s += ToString(z);
			}
			else if ((x != 0) && (y == 0) && (z == 0))
			{
				s = ToString(coef);
				s += 'X'; s += '^';
				s += ToString(x);
			}
			else if ((x == 0) && (y != 0) && (z == 0))
			{
				s = ToString(coef);
				s += 'Y'; s += '^'; s += ToString(y);
			}
			else if ((x == 0) && (y == 0) && (z == 0))
				s = ToString(coef);
			else if ((x != 0) && (y != 0) && (z != 0))
			{
				s = ToString(coef); 
				s += 'X'; s += '^';s += ToString(x);
				s += 'Y'; s += '^'; s += ToString(y);
				s += 'Z'; s += '^'; s += ToString(z);
			}
			k += s;
		}
	}
	return k;
}

string TPolinom::ToString(double k)
{
	std::ostringstream oss;
	oss << k;
	return oss.str();
}




TPolinom TPolinom::Division(TPolinom& pl2, TPolinom& remainder)
{
	monom.Reset();
	pl2.monom.Reset();
	remainder.monom.DelList();
	TMonom tmp1, tmp2,tmp3,tmp4;//tmp1- stores the first monom tmp2- stores the second monom tmp3-monomials in quotient, tmp4 - monomials formed for subtraction
	int power;
	double coef;
	tmp1 = monom.GetVal();
	tmp2 = pl2.monom.GetVal();
	int X, X1, Y, Y1, Z, Z1;
	if (tmp1.GetPower() < tmp2.GetPower())//исправить
	{
		cout << "Error" << endl;
		throw "error";
	}
	else
	{
		TPolinom quotient(""); //частное 
		TPolinom CurrResult1("");//уменьшаемый полином,вычитаемый полиномы

		CurrResult1 = *this;
		
		tmp4 = CurrResult1.monom.GetVal();
		tmp2 = pl2.monom.GetVal();

		while (tmp4.GetPower() >= tmp2.GetPower())
		{
			TPolinom CurrResult2("");
			power = tmp4.GetPower() - tmp2.GetPower();
			coef = tmp4.GetCoef() / tmp2.GetCoef();
			tmp3.SetValue(coef, power);
			quotient.monom.InsLast(tmp3);

			while (!pl2.monom.IsListEnded())
			{
				tmp4 = tmp2 * tmp3;
				CurrResult2.monom.InsLast(tmp4);
				pl2.monom.GoNext();
				tmp2 = pl2.monom.GetVal();
			}
			CurrResult1 = CurrResult1 - CurrResult2;
			
			tmp4 = CurrResult1.monom.GetVal();
			CurrResult2.monom.DelList();
			pl2.monom.Reset();
			tmp2 = pl2.monom.GetVal();
		}
		remainder = CurrResult1;
		return quotient;
	}
}

TPolinom TPolinom::operator+(TPolinom& pl)
{	
	TMonom tmp1, tmp2;
	TPolinom result("");
	
	monom.Reset();
	pl.monom.Reset();
	int power1, power2;
	double newcoef;
	
	while (!monom.IsListEnded())
	{
		tmp1 = monom.GetVal();
		tmp2 = pl.monom.GetVal();
		
		power1 = tmp1.GetPower();
		power2 = tmp2.GetPower();
		if (power1 < power2)
		{
			result.monom.InsLast(tmp2);
			pl.monom.GoNext();		
		}
		else if (power1 == power2)
		{
			newcoef = tmp1.GetCoef() + tmp2.GetCoef();
			if (newcoef != 0)
			{
				tmp1.SetCoef(newcoef);
				result.monom.InsLast(tmp1);
			}
			monom.GoNext();
			pl.monom.GoNext();
		}
		else
		{
			result.monom.InsLast(tmp1);
			monom.GoNext();
		}
	}
	while (!pl.monom.IsListEnded())
	{
		result.monom.InsLast(tmp2);
		pl.monom.GoNext();
		tmp2 = pl.monom.GetVal();
		power2 = tmp2.GetPower();
	}
	return result;
}

TPolinom TPolinom::operator*(TPolinom& pl)
{
	TPolinom result("");
	monom.Reset();
	pl.monom.Reset();
	TMonom tmp1, tmp2,tmp3;
	int power1, power2;
	double newcoef,coef1, coef2;
	while (!monom.IsListEnded())
	{
		tmp1 = monom.GetVal();
		while (!pl.monom.IsListEnded())
		{
			tmp2 = pl.monom.GetVal();
			tmp3 = tmp1 * tmp2;
			result.monom.InsLast(tmp3);
			pl.monom.GoNext();
		}
		pl.monom.Reset();
		monom.GoNext();
	}
	result.Sort();
	return result;
}

TPolinom TPolinom::operator-(TPolinom& pl)
{
	TMonom tmp1, tmp2;
	TPolinom result("");

	monom.Reset();
	pl.monom.Reset();
	int power1, power2;
	double newcoef, coef2;

	while (!monom.IsListEnded())
	{
		tmp1 = monom.GetVal();
		tmp2 = pl.monom.GetVal();
		coef2 = tmp2.GetCoef();
		tmp2.SetCoef(-1 * coef2);
		power1 = tmp1.GetPower();
		power2 = tmp2.GetPower();

		if (power1 < power2)
		{
			result.monom.InsLast(tmp2);
			pl.monom.GoNext();
		}
		else if (power1 == power2)
		{
			newcoef = tmp1.GetCoef() + tmp2.GetCoef();
			if (newcoef != 0)
			{
				tmp1.SetCoef(newcoef);
				result.monom.InsLast(tmp1);
			}
			monom.GoNext();
			pl.monom.GoNext();
		}
		else
		{
			result.monom.InsLast(tmp1);
			monom.GoNext();
		}
	}
	while (!pl.monom.IsListEnded())
	{
		result.monom.InsLast(tmp2);
		pl.monom.GoNext();
		tmp2 = pl.monom.GetVal();
		power2 = tmp2.GetPower();
	}
	return result;
}

TPolinom& TPolinom::operator=(const TPolinom& pl)
{
	
	if (*this == pl) return *this;
	monom.DelList();
	TPolinom tmp = pl;
	TMonom mn(0, -1);
	monom.InsFict(mn);
	if (!tmp.monom.IsEmpty())
	{
		for (tmp.monom.Reset(); !tmp.monom.IsListEnded(); tmp.monom.GoNext())
		{
			monom.InsLast(tmp.monom.GetVal());
		}
	}
	
	return *this;
}

bool TPolinom::operator==(const TPolinom& pl) 
{
	TPolinom tmp = pl;
	if ((tmp.monom.IsEmpty()) && (monom.IsEmpty())) return 1;
	if ((!tmp.monom.IsEmpty()) && (!monom.IsEmpty()))
	{
		for (tmp.monom.Reset(), monom.Reset(); !tmp.monom.IsListEnded(); tmp.monom.GoNext(), monom.GoNext())
		{
			if (monom.GetVal() != tmp.monom.GetVal())
				return 0;

		}
	}
	else return 0;
	return 1;
	
}


ostream& operator<<(ostream& os, TPolinom& pl)
{
	double  coef;
	int power,x, y, z;
	TMonom p;
	if (pl.monom.IsEmpty())
		cout << 0<<endl;
	else
	{
		for (pl.monom.Reset(); !pl.monom.IsListEnded(); pl.monom.GoNext())
		{
			p = pl.monom.GetVal();
			coef = p.GetCoef();
			string s = "";
			if (coef > 0) s = " + ";

			power = p.GetPower();
			x = power / 10000;
			y = power / 100 - x * 100;
			z = power % 100;

			if ((x == 0) && (y != 0) && (z != 0))
				os << s << coef << "Y^" << y << "Z^" << z << " ";
			else if ((x != 0) && (y == 0) && (z != 0))
				os << s << coef << "X^" << x << "Z^" << z << " ";
			else if ((x != 0) && (y != 0) && (z == 0))
				os << s << coef << "X^" << x << "Y^" << y << " ";
			else if ((x == 0) && (y == 0) && (z != 0))
				os << s << coef << "Z^" << z << " ";
			else if ((x != 0) && (y == 0) && (z == 0))
				os << s << coef << "X^" << x << " ";
			else if ((x == 0) && (y != 0) && (z == 0))
				os << s << coef << "Y^" << y << " ";
			else if ((x == 0) && (y == 0) && (z == 0))
				os << s << coef << " ";
			else if ((x != 0) && (y != 0) && (z != 0))
				os << s << coef << "X^" << x << "Y^" << y << "Z^" << z << " ";

		}
	}
	return os;
}
