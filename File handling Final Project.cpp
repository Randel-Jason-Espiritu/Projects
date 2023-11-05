#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;

struct Person{
	string FullName;
	int Age;
	char SchoolNumber[15];
	string raw_name[8];
	int raw[8];
	int subjno;
	int sum_raw;
	double ave_raw;
};


void mainmenu();
void case1header();

int main(){
	Person students[100];
	bool main_choice = true;
	int switch_choice;
	
	//case 1 variables
	int cnt = 0;		//determines how many students were already entered
	int no;			//number of subjects
	do{
		system("cls");
		mainmenu();
		cin >> switch_choice;
		cin.ignore();
		switch(switch_choice){
			case 1:
				{
				system("cls");
				case1header();
				cout<< "Enter The Students Full Name: ";
				getline(cin, students[cnt].FullName);
				cout << "Enter The Student Number #: ";
				cin >> students[cnt].SchoolNumber;
				cin.ignore();
				cout << "Enter The Students Age: ";
				cin >> students[cnt].Age;
				cout << endl;
				cout << "Enter the number of subjects you have (maximum 8): ";
				cin >> students[cnt].subjno;
				no = students[cnt].subjno;
				for(int i = 0; i < no; i++){
					cin.ignore();
					cout << "Enter subject name: ";
					getline(cin, students[cnt].raw_name[i]);
					cout << "Enter subject raw score: ";
					cin >> students[cnt].raw[i];
					cout << endl;
				}
				
				for(int i = 0; i < no; i++){
					students[cnt].sum_raw += students[cnt].raw[i];
					students[cnt].ave_raw = students[cnt].sum_raw / no;
				}
				
				//will append the inputed Student Information
				ofstream myfile("Filehandling.txt", ios::app);
				myfile << "Student FullName: "<< students[cnt].FullName <<"  ||";
				myfile << "Student Number: "<< students[cnt].SchoolNumber <<"  ||";
				myfile << "Age: " << students[cnt].Age <<"  ||";
				myfile << "Course: BSCS" <<"  ||" << endl;
				for (int i = 0; i < no; i++){
					myfile << 	students[cnt].raw_name[i] << ": " << students[cnt].raw[i] <<endl;
				}
				myfile << "Total raw score: " << students[cnt].ave_raw << endl;
				//will display and convert the raw score // determines if the student passed or not;
				if (students[cnt].ave_raw <= 100 && students[cnt].ave_raw >= 97){
					myfile<< "Final Grade: 4.0 " << "(PASSED)"; 
                }else if (students[cnt].ave_raw <= 96 && students[cnt].ave_raw >= 93){
					myfile<< "Final Grade: 3.5 " << "(PASSED)"; 
				}else if (students[cnt].ave_raw <= 92 && students[cnt].ave_raw >= 89){
					myfile<< "Final Grade: 3.0 " << "(PASSED)"; 
				}else if (students[cnt].ave_raw <= 88 && students[cnt].ave_raw >= 85){
					myfile<< "Final Grade: 2.5 " << "(PASSED)"; 
				}else if (students[cnt].ave_raw <= 84 && students[cnt].ave_raw >= 81){
					myfile<< "Final Grade: 2.0 " << "(PASSED)"; 		
				}else if (students[cnt].ave_raw <= 80 && students[cnt].ave_raw >= 78){
					myfile<< "Final Grade: 1.5 " << "(PASSED)"; 
				}else if (students[cnt].ave_raw <= 77 && students[cnt].ave_raw >= 75){
					myfile<< "Final Grade: 1.0 " << "(PASSED)"; 
				}else if (students[cnt].ave_raw < 75){
					myfile<< "Final Grade: .5 " << "(FAILED)"; 
				}
				myfile << endl;
				myfile << "===============================================================================================\n";
				myfile.close();
				
				
				break;
				}
			case 2:{ // will display the contents of the txt file
				system("cls");
				string content;
				ifstream myfile;
				myfile.open("Filehandling.txt", fstream::in);
                while(getline(myfile, content)){
                    cout << content << endl;
                }
                getch();
                myfile.close();
				system("pause");
				break;
				}
			case 3:{ //exits the program
				main_choice = false;
				break;
			}
		}
		
	}while(main_choice);
	return 0;
}

void mainmenu(){
	cout << "==============================================" << endl;
	cout << "=============== GRADING SYSTEM ===============" << endl;
	cout << "==============================================" << endl;
	cout << "1. Add Student Data" << endl;
	cout << "2. Display Saved File" << endl;
	cout << "3. Exit\n" << endl;
	cout << "Enter your choice: ";
}
void case1header(){
	cout << "==============================================" << endl;
	cout << "=============== ADD STUDENT DATA =============" << endl;
	cout << "==============================================\n" << endl;
}



