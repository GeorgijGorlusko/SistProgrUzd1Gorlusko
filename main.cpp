#include "P1.cpp" 
#include "P2.cpp" 
#include "P3.cpp" 
#include "P4.cpp" 
#include "P5.cpp" 

int main()
{
	int number = 1;

	cout << "chose file (1 2 3 4 5)" << endl;

	cin >> number;

	if (number == 1) {
		GalutinisBalas1 stud;
		stud.ivesk();
		stud.print();
	

	}
	else if (number == 2) {
		GalutinisBalas2 stud;
		stud.ivesk();
		stud.print();
	
	
	}
	else if (number == 3) {
		GalutinisBalas3 stud;
		stud.ivesk();
		stud.print();


	}
	else if (number == 4) {
		GalutinisBalas4 stud;
		stud.generateFile(100, "kursiokai.txt");
		stud.openFile("kursiokai.txt");
		try {
			stud.print();
		}
		catch (const std::out_of_range& oor) {
			cerr << "Out of Range error: " << oor.what() << '\n';
		}


	}
	else if (number == 5) {
		GalutinisBalas5 stud;
		
		stud.generateFiles(5, 1000, "kursiokai");//kiek failu, kiek studentu, failo pavadinimas. kiekvienas sarasas dideja 10x

		stud.openFile("kursiokai1.txt");
		//stud.print();
		stud.splitByGalutinis();
		stud.listsToFiles("saunuoliai", "nesaunuoliai");

		stud.openFile("kursiokai2.txt");
		stud.splitByGalutinis();
		stud.listsToFiles("saunuoliai2", "nesaunuoliai2");

		stud.openFile("kursiokai3.txt");
		stud.splitByGalutinis();
		stud.listsToFiles("saunuoliai3", "nesaunuoliai3");

		stud.openFile("kursiokai4.txt");
		stud.splitByGalutinis();
		stud.listsToFiles("saunuoliai4", "nesaunuoliai4");


	}

	return 0;
}