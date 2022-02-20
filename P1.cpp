#include <iostream>
#include <iomanip>
#include <string>


using namespace std;
const int ndx = 5;



class FinalGrade1 {
private:
	string vardas = "", pavarde = "";
	double nd = 0, egz = 0, galutinis = 0;
	static const int db = 20;
	double* n = new double[ndx];
	string v[db], p[db];
	double ndd[db], e[db], g[db];
	int kiekStud = 0;
public:
	FinalGrade1() {}
	FinalGrade1(string v, string p, double n, double e) {
		vardas = v;
		pavarde = p;
		nd = n;
		egz = e;
	}
	FinalGrade1& operator= (FinalGrade1& obj) {
		vardas = obj.vardas;
		pavarde = obj.pavarde;
		nd = obj.nd;
		egz = obj.egz;
		cout << "---Assignment operator---" << endl;
		return *this;
	}
	FinalGrade1(FinalGrade1& copy) {
		vardas = copy.vardas;
		pavarde = copy.pavarde;
		nd = copy.nd;
		egz = copy.egz;
		cout << "---Copy constructor---" << endl;
	}
	~FinalGrade1() {}
	

	void ivesk() {

		

		cout << "Keliu studentu duomenis norite ivesti? ";
		cin >> kiekStud;

		for (int q = 0; q < kiekStud; q++)
		{
			cout << "---Ivesk duomenis---" << endl;
			cout << "Vardas: " << endl;
			cin >> vardas;
			cout << "Pavarde: " << endl;
			cin >> pavarde;
			for (int i = 0; i < ndx; i++) {
				cout << i + 1 << "-jo namu darbo ivertinimas: " << endl;
				cin >> n[i];
			}
			for (int i = 0; i < ndx; i++) {
				nd = nd + n[i];
			}
			cout << "Egzamino ivertinimas: " << endl;
			cin >> egz;
			cout << "--------------------------------------------------" << endl;
			v[q] = vardas;
			p[q] = pavarde;
			ndd[q] = nd;
			e[q] = egz;
		}
	}
	void print() {
		cout << left << setw(12) << "Pavarde" << left << setw(12) << "Vardas" << right << setw(10) << "Galutinis (Vid.)" << endl;
		cout << "--------------------------------------------------" << endl;
		for (int q = 0; q < kiekStud; q++)
		{
			vidurkis();
			cout << left << setw(12) << p[q] << left << setw(12) << v[q] << right << setprecision(2) << fixed << g[q] << endl;
		}
	}
	void vidurkis() {
		
		for (int q = 0; q < kiekStud; q++) {
			ndd[q] = (ndd[q] / ndx) * 0.4;
			e[q] = e[q] * 0.6;
			galutinis = ndd[q] + e[q];
			g[q] = galutinis;
		}
	}
	

};
