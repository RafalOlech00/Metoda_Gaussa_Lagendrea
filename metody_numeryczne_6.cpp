#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// przedział całkowania
double a = 0.5;
double b = 5;

double CalkowanaFunkcja(double x) // funkcja zwracająca funkcję do całkowania
{
	// w zależności od potrzebnej funkcji należy odkomentować 
	//return sin(x);
	return (x * x) + (2 * x) + 5;
	//return exp(x);


}



int main()
{
	// Dla 2 węzłów

	double TwoNodes[2];
	TwoNodes[0] = -0.57735;
	TwoNodes[1] = 0.57735;

	double FourNodes[4];
	FourNodes[0] = -0.861136;
	FourNodes[1] = -0.339981;
	FourNodes[2] = 0.339981;
	FourNodes[3] = 0.861136;

	double TwoValue[2];
	TwoValue[0] = 1;
	TwoValue[1] = 1;

	double FourValue[4];
	FourValue[0] = 0.347855;
	FourValue[1] = 0.652145;
	FourValue[2] = 0.652145;
	FourValue[3] = 0.347855;

	double TwoTi[2];
	for (int i = 0; i < 2; i++)
	{
		TwoTi[i]=(a + b) / 2 + (b - a) / 2 * TwoNodes[i];
	}

	double FourTi[4];
	for (int i = 0; i < 4; i++)
	{
		FourTi[i] = (a + b) / 2 + (b - a) / 2 * FourNodes[i];
	}

	double TwoResult = 0;
	for (int i = 0; i < 2; i++)
	{
		TwoResult += TwoValue[i] * CalkowanaFunkcja(TwoTi[i]);
	}
	TwoResult *= ((b - a) / 2);
	// Dla 4 węzłów

	double FourResult = 0;
	for (int i = 0; i < 4; i++)
	{
		FourResult += FourValue[i] * CalkowanaFunkcja(FourTi[i]);
	}
	FourResult *= ((b - a) / 2);

	int n = 4;  // liczba przediałów

	if (CalkowanaFunkcja(b) == sin(b))
	{
		cout << "Wzor calkowanej funkcji: sin(x)" <<endl;
	}
	else if (CalkowanaFunkcja(b) == exp(b))
	{
		cout << "Wzor calkowanej funkcji: exp(x)" <<endl;

	}
	else if (CalkowanaFunkcja(b) == (b * b + 2 * b + 5))
	{
		cout << "Wzor calkowanej funkcji: x^2 + 2*x + 5" <<endl;
	}


	cout << "Liczba przedzialow: " << n <<endl;
	cout << "Przedzial calkowania: <" << a << " , " << b << ">" <<endl<<endl;

	cout << "Wynik dla kwadratury dwu-wezlowej:  ";
	cout << TwoResult << endl ;
	cout << "Wynik dla kwadratury cztero-wezlowej:  ";	
	cout << FourResult << endl;



	return 0;
}