#include <iostream>
#include <string>
#include "TPolinom.h"
#include "TLists.h"

using namespace std;
void PrintMenu();

int main()
{
	setlocale(LC_ALL, "Russian");
	
	cout << "This program performs actions with a polynomial whose monomials can include variables X, Y, Z" << endl;
	cout << "Polynomial input rules:" << endl;
	cout << "1.Variables must be entered in upper case (X, Y, Z);" << endl;
	cout << "2.Degrees are indicated after the variable using the '^' sign;" << endl;
	cout << "3.Degrees must be non-negative." << endl;

	PrintMenu();
	int k,polinom,X,Y,Z;
	char l;
	string polinom1, polinom2;
	
	TPolinom p1(""), p2(""),p3(""), p4("");//p3 - result from operations + - * /, p4 - remainder of division
	do
	{
		cin >> k;
		switch (k)
		{
		case 0:
			PrintMenu();
			break;
		case 1:
			cout << "Enter polynomial: ";
			cin.ignore();
			getline(cin, polinom1);
			p1.ChangePolinom(polinom1);
			break;
		case 2:
			cout << "Enter polynomial: ";
			cin.ignore();
			getline(cin, polinom2);
			p2.ChangePolinom(polinom2);
			break;
		case 3:
			cout << p1 << endl;
			break;
		case 4:
			cout << p2 << endl;
			break;
		case 5:
			cout << "Specify the variable that will be differentiated." << endl;
			cin >> l;
			switch (l)
			{
			case 'X':

				p3 = p1.Derivative('X');
				cout << "Derivative of 'X'" << endl;
				cout << p3 << endl;
				break;
			case 'Y':
				p3 = p1.Derivative('Y');
				cout << "Derivative of 'Y'" << endl;
				cout << p3 << endl;
				break;
			case 'Z':
				p3 = p1.Derivative('Z');
				cout << "Derivative of 'Z'" << endl;
				cout << p3 << endl;
				break;
			default:
				break;
			}
			break;
		case 6:
			cout << "Specify the variable that will be differentiated." << endl;
			cin >> l;
			switch (l)
			{
			case 'X':
				p3 = p2.Derivative('X');
				cout << "Derivative of 'X'" << endl;
				cout << p3 << endl;
				break;
			case 'Y':
				p3 = p2.Derivative('Y');
				cout << "Derivative of 'Y'" << endl;
				cout << p3 << endl;
				break;
			case 'Z':
				p3 = p2.Derivative('Z');
				cout << "Derivative of 'Z'" << endl;
				cout << p3 << endl;
				break;
			default:
				break;
			}
			break;
		case 7:
			cout << "Specify the variable that will be integrated." << endl;
			cin >> l;
			switch (l)
			{
			case 'X':
				p3 = p1.Integration('X');
				cout << "Integration over 'X'" << endl;
				cout << p3 << endl;
				break;
			case 'Y':
				p3 = p1.Integration('Y');
				cout << "Integration over 'Y'" << endl;
				cout << p3 << endl;
				break;
			case 'Z':
				p3 = p1.Integration('Z');
				cout << "Integration over 'Z'" << endl;
				cout << p3 << endl;
				break;
			default:
				break;
			}
			break;
		case 8:
			cout << "Specify the variable that will be integrated." << endl;
			cin >> l;
			switch (l)
			{
			case 'X':
				p3 = p2.Integration('X');
				cout << "Integration over 'X'" << endl;
				cout << p3 << endl;
				break;
			case 'Y':
				p3 = p2.Integration('Y');
				cout << "Integration over 'Y'" << endl;
				cout << p3 << endl;
				break;
			case 'Z':
				p3 = p2.Integration('Z');
				cout << "Integration over 'Z'" << endl;
				cout << p3 << endl;
				break;
			default:
				break;
			}
			break;
		case 9:
			cout << "Specify the polynomial in which to find the value at the point " << endl;
			cin >> polinom;
			switch (polinom)
			{
			case 1:
				cout << "Enter the values of X, Y, Z " << endl;
				cin >> X >> Y >> Z;
				cout << "Polynomial value at point (" << X << "," << Y << "," << Z << ") : ";
				cout << p1.ValueInPoint(X, Y, Z) << endl;
				break;
			case 2:
				cout << "Enter the values of X, Y, Z " << endl;
				cin >> X >> Y >> Z;
				cout << "Polynomial value at point (" << X << "," << Y << "," << Z << ") : ";
				cout << p2.ValueInPoint(X, Y, Z) << endl;
				break;
			default:
				break;
			}
			break;
		case 10:
			cout << "Polynomial Addition: " << endl;
			p3 = p1 + p2;
			cout << p3 << endl;
			break;
		case 11:
			cout << " Subtraction of polynomials: " << endl;
			cout << "1.Subtract the second from the first" << endl;
			cout << "2.Subtract the first from the second" << endl;
			cin >> k;
			switch (k)
			{
			case 1:
				p3 = p1 - p2;
				cout << p3 << endl;
				break;
			case 2:
				p3 = p2 - p1;
				cout << p3 << endl;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		case 12:
			p3 = p1 * p2;
			cout << p3 << endl;
			break;
		case 13:
			cout << "Polynomial Division: " << endl;
			cout << "1.First divide by second" << endl;
			cout << "2.Divide the second by the first" << endl;
			cin >> k;
			switch (k)
			{
			case 1:
				p3 = p1.Division( p2, p4);
				cout <<"The whole part of the division: "<< p3 << endl;
				cout <<"Remainder of the division: "<< p4 << endl;
				break;
			case 2:
				p3 = p2.Division( p1, p4);
				cout << "The whole part of the division: " << p3 << endl;
				cout << "Remainder of the division: " << p4 << endl;
				break;
			default:
				break;
			}
			break;
		}
	} while (k!=14);

	return 0;
}

void PrintMenu()
{
	cout << "Menu" << endl;
	cout << "0.Show Menu." << endl;
	cout << "1.Enter the first polinomial." << endl;
	cout << "2.Enter the second polinomial." << endl;
	cout << "3.Show the first polinomial." << endl;
	cout << "4.Show thw second polinomial." << endl;
	cout << "5.Differentiate the first polynomial." << endl;
	cout << "6.Differentiate the second polynomial." << endl;
	cout << "7.Integrate the first polynomial." << endl;
	cout << "8.Integrate the second polynomial." << endl;
	cout << "9.Find thw value of point." << endl;
	cout << "10.Add polinomials." << endl;
	cout << "11.Sub polinomials." << endl;
	cout << "12.Multiply polinomials." << endl;
	cout << "13.Division of polinomials." << endl;
	cout << "14.End." << endl;
}