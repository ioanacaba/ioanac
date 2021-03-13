#include<iostream>
#include<list>
#include<string>
#include<iterator>
#include<conio.h>
#include<fstream>
using namespace std;
class Fructe
{

	string tip;
	string nume;
	string valabilitate;
	int pret;
	int cantitate;
public:
	Fructe(string tip, string nume, string valabilitate, int pret, int cantitate)
	{
		this->tip = tip;
		this->nume = nume;
		this->valabilitate = valabilitate;
		this->pret = pret;
		this->cantitate = cantitate;
	}
	friend void afisare();
	friend void cautare();
};
class Autohtone :public Fructe
{
	string judet;
	string producator;
	string data;
public:
	Autohtone(string tip, string nume, string valabilitate, int pret, int cantitate, string judet, string producator, string data) :Fructe(tip, nume, valabilitate, pret, cantitate)
	{
		this->judet = judet;
		this->producator = producator;
		this->data = data;
	}
	friend void afisare();
	friend void cautare();
};
class Import :public Fructe
{
	string tara;
	string importator;
public:
	Import(string tip, string nume, string valabilitate, int pret, int cantitate, string tara, string importator) :Fructe(tip, nume, valabilitate, pret, cantitate)
	{
		this->tara = tara;
		this->importator = importator;
	}
	friend void afisare();
	friend void cautare();
};
list<Fructe*>l;
list<Fructe*>::iterator i;
void citire()
{
	string tip;
	string nume;
	string valabilitate;
	int pret;
	int cantitate;

	string judet;
	string producator;
	string data;

	string tara;
	string importator;

	cout << "Introduceti tipul fructelor(autohtone/import): "; cin >> tip;
	cout << "nume(string): "; cin >> nume;
	cout << "valabilitate(string): "; cin >> valabilitate;
	cout << "pret(int): "; cin >> pret;
	cout << "cantitate(int): "; cin >> cantitate;
	if (tip == "autohtone")
	{
		cout << "judet(string): "; cin >> judet;
		cout << "producator(string): "; cin >> producator;
		cout << "data(string): "; cin >> data;
		l.push_front(new Autohtone(tip, nume, valabilitate, pret, cantitate, judet, producator, data));
	}
	if (tip == "import")
	{
		cout << "tara(string): "; cin >> tara;
		cout << "importator(string): "; cin >> importator;
		l.push_front(new Import(tip, nume, valabilitate, pret, cantitate, tara, importator));
	}
}
void afisare()
{
	for (i = l.begin(); i != l.end(); i++)
	{
		cout << (*i)->tip << " " << (*i)->nume << " " << (*i)->valabilitate << " " << (*i)->pret << " " << (*i)->cantitate << " ";
		if ((*i)->tip == "autohtone")
		{
			Autohtone*m = (Autohtone*)(*i);
			cout << m->judet << " " << m->producator << endl;
		}
		if ((*i)->tip == "import")
		{
			Import*m = (Import*)(*i);
			cout << m->tara << " " << m->importator << endl;
		}
		char ch = _getch();
	}

}
void cautare()
{
	string valabilitate;
	cout << "introduceti termenul de valabilitate: "; cin >> valabilitate;
	for (i = l.begin(); i != l.end(); i++)
	{
		if ((*i)->valabilitate == valabilitate)
		{
			cout << (*i)->tip << " " << (*i)->nume << " " << (*i)->valabilitate << " " << (*i)->pret << " " << (*i)->cantitate << " ";
			if ((*i)->tip == "autohtone")
			{
				Autohtone*m = (Autohtone*)(*i);
				cout << m->judet << " " << m->producator << " ";
			}
			if ((*i)->tip == "import")
			{
				Import*m = (Import*)(*i);
				cout << m->tara << " " << m->importator << " ";
			}
		}
		char ch = _getch();
	}
}
void citire_f()
{
	ifstream f("fisier.txt");
	string tip;
	string nume;
	string valabilitate;
	int pret;
	int cantitate;

	string judet;
	string producator;
	string data;

	string tara;
	string importator;

	while (!f.eof())
	{
		f >> tip;
		f >> nume;
		f >> valabilitate;
		f >> pret;
		f >> cantitate;
		if (tip == "autohtone")
		{
			f >> judet;
			f >> producator;
			f >> data;
			l.push_front(new Autohtone(tip, nume, valabilitate, pret, cantitate, judet, producator, data));
		}
		if (tip == "import")
		{
			f >> tara;
			f >> importator;
			l.push_front(new Import(tip, nume, valabilitate, pret, cantitate, tara, importator));
		}
	}
}

int main()
{
	int opt;
	do {
		//system("CLS");
		cout << "0.Iesire\n";
		cout << "1.Citire\n";
		cout << "2.Afisare\n";
		cout << "3.Cautare\n";
		cout << "4.Citire din fisier\n";
		cout << "Introduceti optiunea dumneavoastra:"; cin >> opt;
		switch (opt)
		{
		case 0:
			//exit(0);
			break;
		case 1:
			citire();
			break;
		case 2:
			afisare();
			break;
		case 3:
			cautare();
			break;
		case 4:citire_f();
			break;
		default:cout << "Alegeti alta optiune\n";
			break;
		}
	} while (opt != 0);
	return 0;
}

