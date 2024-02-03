//*********** Include All Header files ***********
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
using namespace std;

class Employee_management
{
private:
//*********** Variables for employee details ***********
	char name[30];
	char id[5];
	char designation[10];
	int age, ctc;
	char experience[20];

public:
//********** Functions for employee mangement ***********
	void menu();
	void waitForEnter();
	void insert();
	void display();
	void modify();
	void search();
	void deleted();
};

//********** Functions for Project Menu ***********
void Employee_management::menu()
{
//********** Functions declareation for login ***********
	int password_user(); 
	password_user();
//********** Designing of Login Screen ***********
	while (true)
	{
		int choice;
//********** Options to choose an action ***********
		char x; 
		system("cls");
		cout << "\n\t\t\t\t\t-------------------------------" << endl;
		cout << "\t\t\t\t\t>> EMPLOYE MANAGEMENT SYSTEM <<" << endl;
		cout << "\t\t\t\t\t-------------------------------" << endl;
		cout << "\t\t\t\t\t 1. Enter New Record" << endl;
		cout << "\t\t\t\t\t 2. Display Record" << endl;
		cout << "\t\t\t\t\t 3. Modify Record" << endl;
		cout << "\t\t\t\t\t 4. Search Record" << endl;
		cout << "\t\t\t\t\t 5. Delete Record" << endl;
		cout << "\t\t\t\t\t 6. Exit" << endl;

		cout << "\t\t\t\t\t.................................." << endl;
		cout << "\t\t\t\t\t>> Choice Options: [1/2/3/4/5/6] <<" << endl;
		cout << "\t\t\t\t\t.................................." << endl;
//********** Taking the action input ***********
		cout << " Enter Your Choice: ";
		cin >> choice;
//********** Calling relevant function as per choice ***********
		switch (choice)
		{
//********** Case 1 to insert data ***********
		case 1:
			do
			{
				insert();
				cout << "\n\n\t\t\t Add Another Employe Record Press (Y, N) : ";
				cin >> x;
			} while (x == 'y' || x == 'Y');
			waitForEnter();
			break;
//********** Case 2 to Display data ***********
		case 2:
			display();
			break;
//********** Case 3 to Modify data ***********
		case 3:
			modify();
			break;
//********** Case 4 to Search data ***********
		case 4:
			search();
			break;
//********** Case 5 to Deleted data ***********
		case 5:
			deleted();
			break;
//********** Case 6 to Exit Program ***********
		case 6:
			system("cls");
			cout << "\n\t\t\t>> EMPLOYE MANAGEMENT SYSTEM - By Group 6 <<\n\n";
			Sleep(10);
			exit(0);
		default:
			cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
		}
		_getch();
	}
}

//********** Functions for adding data of employee ***********
void Employee_management::insert()
{
	system("cls");
	fstream file;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Employee Insert Data -------------------------------------------" << endl;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
//********** Taking Data Input ***********
	cout << "\n Enter Name of Employee: ";
	cin >> name;
	cout << "\n Enter Employee ID [max 4 digits]: ";
	cin >> id;
	cout << "\n Enter Designation: ";
	cin >> designation;
	cout << "\n Enter Employee Age: ";
	cin >> age;
	cout << "\n Enter Employee CTC: ";
	cin >> ctc;
	cout << "\n Enter Employee Experience: ";
	cin >> experience;
	file.open("Employee_Record.txt", ios::app | ios::out);
	file << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
	file.close();
}

//********** Function for Displaying data of employee ***********
void Employee_management::display() 
{
	system("cls");
	int total = 1;
	fstream file;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Employee Record Data -------------------------------------------" << endl;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	file.open("Employee_Record.txt", ios::in);
//********** Checking if data is present or not ***********
	if (!file)
	{
		cout << "\n\t\t\tNo Data is Present... ";
		file.close();
	}
	else
	{
//********** Displaying data if present ***********
		file >> name >> id >> designation >> age >> ctc >> experience;
		cout << "\n -------------------------------------------------------------------------------------------------";
		cout << "\n||    NAME    ||    ID    ||    DESIGNATION    ||    AGE    ||      CTC      ||    EXPERIENCE    ||";
		cout << "\n -------------------------------------------------------------------------------------------------";
		while (!file.eof())
		{
			cout << "\n";
			cout << total++ << ". " << name << "\t  " << id << "\t\t  " << designation << "\t\t   " << age << "\t\t  " << ctc << "\t\t" << experience;
			file >> name >> id >> designation >> age >> ctc >> experience;
		}
	}
	file.close();
	waitForEnter();
}

//********** Function for Modifying data of employee ***********
void Employee_management::modify()
{
	system("cls");
	char checkId[5];
	int found = 0;
	fstream file, file1;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Employee Modify Data ------------------------------------------" << endl;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	file.open("Employee_Record.txt", ios::in);
//********** Checking if data is present or not ***********
	if (!file)
	{
		cout << "\n\t\t\tNo Data is Present..";
		file.close();
	}
	else
	{
//********** Asking for id of emplyee whos data is to be modified ***********
		cout << "\nEnter employee id: ";
		cin >> checkId;
		file1.open("record.txt", ios::app | ios::out);
		file >> name >> id >> designation >> age >> ctc >> experience;
		while (!file.eof())
		{
			if (strcmp(checkId, id) == 0)
			{
//********** Getting employee new data ***********
				cout << "\n Enter Name of Employee: ";
				cin >> name;
				cout << "\n Enter Employee ID [max 4 digits]: ";
				cin >> id;
				cout << "\n Enter Designation: ";
				cin >> designation;
				cout << "\n Enter Employee Age: ";
				cin >> age;
				cout << "\n Enter Employee CTC: ";
				cin >> ctc;
				cout << "\n Enter Employee Experience: ";
				cin >> experience;
				cout << "\n\nSuccessfully Modify Details Of Employee";
				file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
				found++;
			}
			else
			{
				file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
			}
			file >> name >> id >> designation >> age >> ctc >> experience;
		}
		if (found == 0)
		{
			cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
		}
		file1.close();
		file.close();
		remove("Employee_Record.txt");
		rename("record.txt", "Employee_Record.txt");
	}
	waitForEnter();
}

//********** Function for Searching data of employee ***********
void Employee_management::search()
{                                  
	system("cls");
	fstream file;
	char checkId[5];
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Employee Search Data -------------------------------------------" << endl;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	file.open("Employee_Record.txt", ios::in);
//********** Displays all details according to Employee's id ***********
	cout << "\n\nEnter Employee ID: ";
	cin >> checkId;
	if (!file)
	{
		cout << "\n\t\t\tNo Data is Present... ";
		file.close();
	}
	else
	{
		file >> name >> id >> designation >> age >> ctc >> experience;
		while (!file.eof())
		{
//********** Displays Employee's data ***********
			if (strcmp(checkId, id) == 0)
			{
				cout << "\n---------------------\n";
				cout << "Employee Name: " << name << "\n";
				cout << "Employee ID.: " << id << "\n";
				cout << "Employee Designation: " << designation << "\n";
				cout << "Employee Age: " << age << "\n";
				cout << "Employee CTC: " << ctc << "\n";
				cout << "Employee Experience: " << experience << "\n";
				cout << "---------------------\n";
			}
			file >> name >> id >> designation >> age >> ctc >> experience;
		}
	}
	file.close();
	waitForEnter();
}

//********** Function to Delete data of employe ***********
void Employee_management::deleted() 
{
	system("cls");
	char checkId[5];
	fstream file, file1;
	int found = 0;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Delete Employee Data ------------------------------------------" << endl;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	file.open("Employee_Record.txt", ios::in);
	if (!file)
	{
		cout << "\n\t\t\tNo Data is Present..";
		file.close();
	}
	else
	{
//********** Deleting all details according to Employee's id ***********
		cout << "\nEnter Employee Id To Remove Data: ";
		cin >> checkId;
		file1.open("record.txt", ios::app | ios::out);
		file >> name >> id >> designation >> age >> ctc >> experience;
		while (!file.eof())
		{
			if (strcmp(checkId, id) != 0)
			{
				file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tSuccessfully Delete Data";
			}
			file >> name >> id >> designation >> age >> ctc >> experience;
		}
		if (found == 0)
		{
			cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
		}
		file1.close();
		file.close();
		remove("Employee_Record.txt");
		rename("record.txt", "Employee_Record.txt");
		waitForEnter();
	}
}

//********** Function to designing out with enter ***********
void Employee_management::waitForEnter()
{
	cout << "\n\nPress enter to go back: ";
	cin.get();
}

//********** Function for Employee Authentication ***********
int password_user()
{
	string pass_reg = "";
	string name_reg = "";
	string pass = "";
	string name = "";
	fstream file;
	char ch;
	system("cls");
	cout << "\n\t\t\t -------------------------------------------";
	cout << "\n\t\t\t||  WELCOME TO EMPLOYEE MANAGEMENT SYSTEM  ||";
	cout << "\n\t\t\t -------------------------------------------";
	cout << "\n\n\t\t\t   -| Press: [1] Register & [2] Login  |-";
	int selection;
	cout << "\n\nPlease Enter Value: ";
	cin >> selection;
//********** if user press [1], then it would lead them to register ***********
	if (selection == 1)
	{
		system("cls");
		cout << "\n\t\t\t\t\t---------------------------";
		cout << "\n\t\t\t\t\t>> REGISTRATION EMPLOYEE <<";
		cout << "\n\t\t\t\t\t---------------------------";
		cout << "\n\n\t\t\t\t\tEnter Your Name: ";
		cin >> name_reg;
		cout << "\n\t\t\t\t\tEnter Your Password: ";
		ch = _getch();
		while (ch != 13)
		{
			pass_reg.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		file.open("Ep_data.txt", ios::app);
		file << " " << name_reg << " " << pass_reg << "\n";
		file.close();
		cout << "\nRegistration Succesfully save";
		_getch();
		password_user();
	}
//********** if user press [2], then it would lead them to login ***********
	else if (selection == 2)
	{
		system("cls");
		file.open("Ep_data.txt", ios::in);
		cout << "\n\t\t\t\t\t--------------------";
		cout << "\n\t\t\t\t\t>> LOGIN EMPLOYEE <<";
		cout << "\n\t\t\t\t\t--------------------";
		cout << "\n\n\t\t\t\t\tEnter Your Name: ";
		cin >> name;
		cout << "\n\t\t\t\t\tEnter Your Password: ";
		ch = _getch();
		while (ch != 13)
		{
			pass.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		file >> name_reg >> pass_reg;
		while (!file.eof())
		{
			if (pass == pass_reg && name == name_reg)
			{
				cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
				for (int a = 1; a < 8; a++)
				{
					Sleep(500);
					cout << "...";
				}
				cout << "\n\nAccess Granted..\n\n";
				system("PAUSE");
				system("cls");
			}
			else
			{
				cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
				for (int a = 1; a < 8; a++)
				{
					Sleep(500);
					cout << "...";
				}
				cout << "\n\nAccess Aborted...\n\n";
				system("PAUSE");
				system("cls");
				password_user();
			}
			file >> name_reg >> pass_reg;
		}
		file.close();
	}
	else
	{
		cout << "\nInvalid Input.. Please Try Again..";
		password_user();
	}
	return 0;
}
//********** Main function ***********
int main()
{
	Employee_management system;
	system.menu();
	return 0;
}