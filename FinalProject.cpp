/* DUO SYSTEM*/
//header files/library
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


using namespace std;

//FUNCTIONAL
int main_menu();     //MAIN MENU FUNCTION
float gwa_calc();     //GWA CALCULATOR
float avg_calc();     //AVG CALCULATOR
void exit();     //EXITS THE PROGRAM
void grade_converter();     //GRADE CONVERTER FUNCTION

//functions headers
void main_menu_header();
void gwa_header();
void conv_header();
void avg_header();
void level_1_bank();
void Grade_system();



/* MAIN FUNCTION */
int main(){
system("clear");
    int choices;
    do{
    cout<< "// _-_-_-_-_-WELCOME TO SISTEMA MULTIPLE_-_-_-_- //"<< endl;
    cout<< "//             PLEASE CHOOSE AN OPTION!          //"<< endl<< endl;
    cout<< "//********************MENU************************//"<< endl;
    cout<< "//                  OPTIONS:                      //"<< endl;
    cout<< "//     [1]-ONLINE BANK SYSTEM                     //"<< endl;
    cout<< "//                                                //"<< endl;
    cout<< "//     [2]-GRADING SYSTEM                         //"<< endl;
    cout<< "//                                                //"<< endl;
    cout<< "//     [3]-Exit                                   //"<< endl;
    cout<< "//*********************MENU***********************//"<< endl;
    cout<< "PLEASE CHOOSE FROM THE DIFFERENT OPTIONS: ";
    cin>> choices;
    switch(choices){
    case 1:level_1_bank();
        break;

    case 2:Grade_system();
        break;

    default: if (choices !=3)
            system("clear");
            cout<< "PLEASE ENTER A VALID OPTION"<< endl<<endl;
        break;
        }
    }while(choices != 3);
    system("clear");
    exit(1);

    return 0;
}

/* PROGRAM FUNCTIONS */




//ONLINE CARD BANKING SYSTEM
void level_1_bank(){
    system("clear");
    //variable declaration
    double balance, withdraw, deposit, transfer;
    balance = 0;
    int n, pin, count,option;
    bool istrue = true;
    n = 123456;
    count = 0;
    //login
    cout<< "WELCOME TO ONLINE CARD BANKING SYSTEM"<< endl<< endl;
    string a, b;
    string login = "email@gmail.com";
    string password = "bankpassword";
    cout<< "LOGIN: ";
    cin>> a;
    cout<<"PASSWORD: ";
    cin>> b;
    //CHECKS IF THE IF LOGIN AND PASSWORD IS CORRECT
     if(a == login && b == password){
        do
        {
         cout<< "\nENTER YOUR 6 DIGIT PIN: ";
         cin>> pin;
         cout<< "//**********ENTER PIN**********//"<<endl;
         cout<< "//                             //"<< endl;
         cout<< "//      ENTERED PIN:"<<pin<<"     ""//"<< endl;
         cout<< "//                             //"<< endl;
         cout<< "//*****************************//"<< endl;
         //CHECKS IF THE PIN IS CORRECT
         if(pin == n){
            do{
            cout<< "//*************************//"<< endl;
            cout<< "//                         //"<< endl;
            cout<< "//    [1]-Check Balance    //"<< endl;
            cout<< "//    [2]-Deposit          //"<< endl;
            cout<< "//    [3]-Withdraw         //"<< endl;
            cout<< "//    [4]-Transfer         //"<< endl;
            cout<< "//    [5]-Exit             //"<< endl;
            cout<< "//                         //"<< endl;
            cout<< "//*************************//"<< endl;
            cout<< "PLEASE CHOOSE AN OPTION: ";
            cin>> option;
            system("clear");
            //switch statement with embedded if statement
            switch(option){
                case 1:if (balance<10000000){
                    cout<< "Your Balance is: $"<<balance<< endl<< endl;
                    break;
                    }
                    else{
                    cout<< "Please avail an upgrade"<< endl<< endl;
                    break;
                    }
                case 2: if (balance<10000000){
                    cout<< "Amount you want to deposit: $";
                    cin>> deposit;
                    balance+=deposit;
                    cout<< "\n\t Current balance: $"<< balance<< endl<< endl;
                        break;
                    }
                    else {
                        cout<< "Please avail an upgrade"<< endl<< endl;
                        break;
                        }
                case 3:if(balance < 10000000){
                        cout<< "How much do you want to withdraw: $";
                        cin>> withdraw;
                        if (balance < withdraw){
                            cout<< "You do not have enough money in your account to withdraw"<< endl<< endl;
                            }
                        else{
                            balance -= withdraw;
                            cout<< "\n\t$"<<withdraw<<" has been withdrawn to G cash."<<endl<<endl;
                            cout<< "\n\tCurrent Balance: $"<< balance<< endl<< endl;
                            }
                            break;
                        }
                    else{
                        cout<< "Please avail an upgrade"<< endl<< endl;
                        break;
                        }

                case 4: if(balance < 10000000){
                        cout<< "How much do you want to transfer: $" ;
                        cin>> transfer;
                            if (balance < transfer){
                                cout<< "You do not have enough money in your account to transfer"<< endl<< endl;
                                break;
                            }
                            else{
                                int a;
                                cout << "Account number: ";
                                cin>> a;
                                cout<< "$"<< transfer << " has been succesfully sent to "<< a<< endl;
                                balance -= transfer;
                                cout<< "\n\tCurrent Balance: $"<< balance<< endl<< endl;
                                    break;
                                }
                                break;
                            }
                        else{
                            cout<< "Please avail an upgrade"<< endl<< endl;
                            break;
                }
                default: if(option != 5){
                    cout<< "Invalid option. Please try again!"<< endl<< endl;
                    break;
                }
            }
            }while(option!= 5);
            system("read -p 'Press any key to continue...' var");
            exit(1);
            }
        else{
            count ++;
                if(count == 3)
                    istrue = false;
                else{
                        //DISPLAYED WHEN PING IS INCORRECT
                    cout<< "//*********************//"<< endl;
                    cout<< "//      WRONG PIN !    //"<< endl;
                    cout<< "//*********************//"<< endl;
                }
            }
        }while(istrue != false);
        system("read -p 'Press any key to continue...' var");
        }
    else{
            //DISPLAYED WHEN LOGIN IS INCORRECT
        cout<< "Try Again."<< endl<< endl;
    }
}

//GRADING SYSTEM
void Grade_system(){
	bool main_while = true;
	int main_choice;
	char subj_name[150];   //VARIABLE FOR CASE 1
	float avg_grade;    //VARIABLE FOR CASE 1
	float gwa_answer;   //VARIABLE FOR CASE 2

	while (main_while){
		system("clear");
		main_choice = main_menu();

		switch (main_choice){     //MAIN MENU SWITCH
			case 1:
				//AVERAGE CALCULATOR INPUT
				avg_header();
				cout << "What is the subject name: ";
				cin >> subj_name;
        cin.ignore();
				cout << endl;
				avg_grade = avg_calc();

				//AVG OUTPUT
				system ("clear");
				avg_header();
				cout << "Your average for " << subj_name << " is: " << setprecision (2) << fixed << avg_grade << endl;     //setprecision added
				system("read -p 'Press any key to continue...' var");
				break;

			case 2:
				//COMPUTING OF GWA
        		gwa_header();
        		gwa_answer = gwa_calc();

        		//GWA OUTPUT
        		system ("clear");
				gwa_header();
				cout << "Your GWA is: " << setprecision(2) << fixed << gwa_answer << endl;
				system("read -p 'Press any key to continue...' var");
				break;

			case 3:
				//GRADE CONVERTER
				system ("clear");
				conv_header();
				grade_converter();
				break;

			case 4:
				//PROGRAM EXIT
				system ("clear");
				main_while = false;
				break;

			default:
				//IVALID INPUT
				system ("clear");
				main_menu_header();
				cout << "Invalid input. Press any key to try again.\n" << endl;
				system("read -p 'Press any key to continue...' var");

	}
	}

	exit();
}

//MAIN MENU FOR GRADING SYSTEM
int main_menu(){
	int x;
	cout << "==============================================" << endl;
	cout << "=============== GRADING SYSTEM ===============" << endl;
	cout << "==============================================\n" << endl;

	cout << "----------------------------------------------" << endl;
	cout << setw(10) << left << "||" << setw (26) << left << "[1] Average Calculator" << setw (10) << right << "||" << endl;
	cout << setw(10) << left << "||" << setw (26) << left << "[2] GWA Calculator" << setw (10) << right << "||" << endl;
	cout << setw(10) << left << "||" << setw (26) << left << "[3] Grade Converter" << setw (10) << right << "||" << endl;
	cout << setw(10) << left << "||" << setw (26) << left << "[4] Exit" << setw (10) << right << "||" << endl;
	cout << "----------------------------------------------" << endl;

	cout << "\nEnter Your Choice: ";
	cin >> x;
	cin.ignore();
	return x;
}

//MAIN MENU HEADER
void main_menu_header(){
	cout << "==============================================" << endl;
	cout << "=============== GRADING SYSTEM ===============" << endl;
	cout << "==============================================\n" << endl;
}

//HEADER FOR AVERAGE CALCULATOR
void avg_header(){
	system ("clear");
	cout << "==============================================" << endl;
	cout << "============= AVERAGE CALCULATOR =============" << endl;
	cout << "==============================================\n" << endl;

}

//AVERAGE CALCULATOR
float avg_calc(){
	int a = 0;
	int s;
	float summa_grades[100];
	float total_summa;
	float sum = 0;
	float finals_grade;
	float total_avg;
	float summa_items;
	float finals_items;
	float per_summa;
	float total_finals;

	//SUMMATIVES
	cout << "Enter number of summatives: ";
	cin >> s;
	cin.ignore();
	cout << endl;

	for (a = 0; a < s; a++){
		cout << "Enter grade: ";
		cin >> summa_grades[a];
		cin.ignore();
		//cout << endl;

		cout << "What is the number of items: ";
		cin >> summa_items;
		cin.ignore();
		cout << endl;

		per_summa = (summa_grades[a] / summa_items) * 100;

		sum += per_summa;
	}

	total_summa = sum / s;

	//FINALS
	cout << "Enter finals grade: ";
	cin >> finals_grade;
	cin.ignore();
	//cout << endl;

	cout << "What is the number of items: ";
	cin >> finals_items;
	cin.ignore();
	cout << endl;

	total_finals = (finals_grade / finals_items) * 100;


	total_avg = (total_summa * 0.75) + (total_finals * 0.25);


	return total_avg;
}


//HEADER FOR GWA CALCLUATOR
void gwa_header(){
	system ("clear");
	cout << "==============================================" << endl;
	cout << "=============== GWA CALCULATOR ===============" << endl;
	cout << "==============================================\n" << endl;

}

//GWA CALCULATOR
float gwa_calc(){
  int n = 0;     //ARRAY COUNTER
  float units[20];
  float grades[20];
  float sum_of_multiplication[20];
  float answer;
  float sum = 0;
  int units_total = 0, subjects;

  cout << "How many Subjects do you have?: ";
  cin >> subjects;
  cin.ignore();
  cout << endl;

  for (n = 0; n < subjects; n++){
    cout << "Enter subject grade: ";
    cin >> grades[n];
    cin.ignore();

    cout << "Enter units for that subject: ";
    cin >> units[n];
    cin.ignore();
    cout << endl;
  }

  //DETERMINING NUMBER OF UNITS AND SUM OF MULTIPLICATION OF EACH GRADE AND UNIT
  for (n = 0; n < subjects; n++){
  	units_total = units_total + units[n];
  	sum_of_multiplication[n] = grades[n] * units[n];
  }

  // SUM OF ALL PRODUCTS
  for (n = 0; n < subjects; n++){
  	sum = sum + sum_of_multiplication[n];
  }

  answer = sum / units_total;

  return answer;
}

//EXIT SCREEN
void exit(){
	system ("clear");
	cout << "==============================================" << endl;
	cout << "=============== GRADING SYSTEM ===============" << endl;
	cout << "==============================================\n" << endl;

	cout << "Thank you for using our grading system. Have a great day!\n" << endl;
}

//HEADER FOR GRADE CONVERTER
void conv_header(){
	cout << "==============================================" << endl;
	cout << "============== GRADE CONVERTER ===============" << endl;
	cout << "==============================================\n" << endl;
}

//GRADE CONVERTER
void grade_converter(){
	float grade, x;
	string desc, letter;

	cout << "Enter Raw Score: ";
	cin >> x;
	cin.ignore();

	if (x <= 100 && x >= 95.9){
		grade = 4.0;
		letter = "A";
		desc = "Excellent";
	}else if (x <= 95.7 && x >= 91.5){
		grade = 3.5;
		letter = "A-";
		desc = "Superior";
	}else if (x <= 91.4 && x >= 87.2){
		grade = 3.0;
		letter = "B+";
		desc = "Very Good";
	}else if (x <= 87.1 && x >= 82.9){
		grade = 2.5;
		letter = "B";
		desc = "Good";
	}else if (x <= 82.8 && x >= 78.6){
		grade = 2.0;
		letter = "B-";
		desc = "Satisfactory";
	}else if (x <= 78.5 && x >= 74.3){
		grade = 1.5;
		letter = "C";
		desc = "Fair";
	}else if (x <= 74.2 && x >= 70.0){
		grade = 1.0;
		letter = "D";
		desc = "Pass";
	}else if (x < 70.0){
		grade = 0.5;
		letter = "E";
		desc = "Fail";
	}

	cout << "\nGrade Point: " << setprecision(1) << fixed << grade << endl;
	cout << "Letter Rating: " << letter << endl;
	cout << "Description: " << desc << endl;
	system("read -p 'Press any key to continue...' var");

}

