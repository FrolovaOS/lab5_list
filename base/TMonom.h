 #pragma once

using namespace std;
class TMonom
{
private:
	
		double coef;
		int power;

public:
	TMonom();
	TMonom(double _coef, int _power);
	void Clear();
	int GetPower() { return power; };
	double GetCoef() { return coef; };
	void SetValue(double _coef, int _power);
	void SetPower(int _power) { power = _power; };
	void SetCoef(double _coef) { coef = _coef; };
	//операции
	bool operator!=(const TMonom& _mon);
	bool operator==(const TMonom& _mon);
	TMonom operator*(TMonom& mn);
	TMonom& operator=(const TMonom& _mn);


};
