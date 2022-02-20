#include "Uzd1.cpp" 
#include "Uzd2.cpp" 
#include "Uzd3.cpp" 
#include "Uzd4.cpp" 
#include "Uzd5.cpp" 

int main()
{
	int number = 1;

	cout << "chose file (1 2 3 4 5)" << endl;

	cin >> number;

	if (number == 1) {
		FinalGrade1 stud;
		stud.ivesk();
		stud.print();
	

	}
	else if (number == 2) {
		FinalGrade2 stud;
		stud.ivesk();
		stud.print();
	 
	
	}
	else if (number == 3) {
		FinalGrade3 stud;
		stud.ivesk();
		stud.print();


	}
	else if (number == 4) {
		FinalGrade4 stud;
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
		FinalGrade5 stud;
		
		stud.generateFiles(5, 1000, "kursiokai");

		stud.openFile("kursiokai1.txt");
		//stud.print();
		stud.splitByGalutinis();
		stud.listsToFiles("kietiakai", "vargsiukai");

		stud.openFile("kursiokai2.txt");
		stud.splitByGalutinis();
		stud.listsToFiles("kietiakai2", "vargsiukai2");

		stud.openFile("kursiokai3.txt");
		stud.splitByGalutinis();
		stud.listsToFiles("kietiakai3", "vargsiukai3");

		stud.openFile("kursiokai4.txt");
		stud.splitByGalutinis();
		stud.listsToFiles("kietiakai4", "vargsiukai4");


	}

	return 0;
}