#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include <chrono>


using namespace std;
using hrClock = chrono::high_resolution_clock;
 

class FinalGrade3 {
private:
	string vardas = "", pavarde = "";
	double nd = 0, egz = 0, galutinis = 0;
	static const int db = 20;
	
	vector<double>n;
	string v[db], p[db];
	double ndd[db], e[db], g[db];
	int kiekStud = 0, vARm=0, ndx = 1;

public:
	FinalGrade3() {}
	FinalGrade3(string v, string p, double n, double e) {
		vardas = v;
		pavarde = p;
		nd = n;
		egz = e;
	}
	FinalGrade3& operator= (FinalGrade3& obj) {
		vardas = obj.vardas;
		pavarde = obj.pavarde;
		nd = obj.nd;
		egz = obj.egz;
		cout << "---Assignment operator---" << endl;
		return *this;
	}
	FinalGrade3(FinalGrade3& copy) {
		vardas = copy.vardas;
		pavarde = copy.pavarde;
		nd = copy.nd;
		egz = copy.egz;
		cout << "---Copy constructor---" << endl;
	}
	~FinalGrade3() {}
	void ivesk() {
		cout << "Ivesti studentu kieki ";
		cin >> kiekStud;
		for (int q = 0; q < kiekStud; q++)
		{
			cout << "---Ivesk duomenis---" << endl;
			cout << "Studento Vardas: " << endl;
			cin >> vardas;
			cout << "Studento Pavarde: " << endl;
			cin >> pavarde;
			cout << "Namu darbu kiekis ";
			cin >> ndx;
			cout << "--Namu darbu pazymiai sugeneruoti--" << endl;
			for (int i = 0; i < ndx; i++) {
				n.push_back(i);
				double x = randomas(1, 10);
				cout << "pazymys uz namu darba nr." << i + 1 << ":"<< setprecision(2) << fixed << x << endl;
				n.insert(n.begin()+i, x);
			}
			for (int i = 0; i < ndx; i++) {
				nd = nd + n[i];
			}
			egz = randomas(1, 10);
			cout << "Pazymys uz egzamina: " << setprecision(2) << fixed << egz <<endl;
			cout << "--------------------------------------------------" << endl;
			v[q] = vardas;
			p[q] = pavarde;
			ndd[q] = nd;
			e[q] = egz;
		}
	}
	void print() {
		cout << " vidurkis ar mediana?" << endl << "vidurkis = 1; mediana = 2: ";
		cin >> vARm;
		while (vARm != 1 && vARm != 2) {
				cout << "Klaida! Pasirinkti is naujo." << endl;
				cin >> vARm;
		}
		
		if (vARm == 1) {
			cout << left << setw(12) << "Pavarde" << left << setw(12) << "Vardas" << right << setw(10) << "Galutinis (Vid.)" << endl;
			cout << "--------------------------------------------------" << endl;
			for (int q = 0; q < kiekStud; q++)
			{
				vidurkis();
				cout << left << setw(12) << p[q] << left << setw(12) << v[q] << right << setprecision(2) << fixed << g[q] << endl;
			}
		}
		else if (vARm == 2) {
			cout << left << setw(12) << "Pavarde" << left << setw(12) << "Vardas" << right << setw(10) << "Galutinis (Med.)" << endl;
			cout << "--------------------------------------------------" << endl;
			for (int q = 0; q < kiekStud; q++)
			{
				mediana();
				cout << left << setw(12) << p[q] << left << setw(12) << v[q] << right << setprecision(2) << fixed << g[q] << endl;
			}
		}
	}
	void vidurkis() {
		
		for (int q = 0; q < kiekStud; q++) {
			ndd[q] = (ndd[q] / ndx) * 0.4;
			e[q] = e[q] * 0.6;
			g[q] = ndd[q] + e[q];
		}
	}
	double sort(double x, double y) {
		double temp;
		for (int i = 0; i < ndx; i++) {
			for (int j = i + 1; j < ndx; j++) {
				if (n[j] < n[i]) {
					temp = n[i];
					n[i] = n[j];
					n[j] = temp;
				}
			}
		}
		return 0;
	}
	void mediana() {
		
		for (int q = 0; q < kiekStud; q++) {
			sort(n[0], n[ndx-1]);
			if (ndx % 2 == 0) {
				ndd[q] = (n[ndx / 2 - 1] + n[ndx / 2]) / 2;
			}
			else {
				ndd[q] = n[ndx / 2];
			}
			
			ndd[q] = ndd[q] * 0.4;
			e[q] = e[q] * 0.6;
			g[q] = ndd[q] + e[q];
		}
	}
	double randomas(double a, double b) {
		mt19937 mt(static_cast<double>(hrClock::now().time_since_epoch().count()));
		uniform_real_distribution<double> dist(a, b);
		return dist(mt);
	}

};
