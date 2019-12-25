#pragma once
#include "TMonom.h"


TMonom::TMonom()
{
	coef = 0;
	power = 0;
}

TMonom::TMonom(double _coef, int _power)
{
	coef = _coef;
	power = _power;
}

void TMonom::Clear()
{
	coef = power = 0;
}

void TMonom::SetValue(double _coef, int _power)
{
	coef = _coef;
	power = _power;
}

bool TMonom::operator!=(const TMonom& _mon)
{
	return this->power != _mon.power || coef != _mon.coef;
}

bool TMonom::operator==(const TMonom& _mon)
{
	return this->power == _mon.power && coef == _mon.coef;;
}

TMonom TMonom::operator*(TMonom& mn)
{
	TMonom tmp;
	tmp.SetCoef(this->coef*mn.GetCoef());
	tmp.SetPower(power + mn.GetPower());
	return tmp;
}

TMonom& TMonom::operator=(const TMonom& _mn)
{
	if (*this == _mn) return *this;
	coef = _mn.coef;
	power = _mn.power;
	return *this;
}




