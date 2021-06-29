#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<iomanip>
#define ve "|"
using namespace std;

//Fucntions

void cleanArr(char i[32]) {
	memset(i, 0, sizeof(i));
}
void noSpaceCin(char text[32] = { 0 }) {
	char l;
	cleanArr(text);
	for (int i = 0; i < 32; i++)
	{
		l = _getch();
		if (l == '\r' && i == 0) {
			i -= 1;
			continue;
		}
		if (l == '\r') {
			std::cout << endl;
			break;
		}
		if (l == '\b' && i == 0) {
			i -= 1;
			continue;
		}
		if (l == ' ') {
			i -= 1;
			continue;
		}
		if (l == '\t') {
			i -= 1;
			continue;
		}
		if (l == '\b' && i > 0) {
			text[i - 1] = text[i];
			i -= 2;
			std::cout << "\b \b";
		}
		else {
			std::cout << l;
			text[i] = l;
		}
	}
}

void noSpaceCin(char text[], int k) {
	cleanArr(text);
	char l;
	for (int i = 0; i < k; i++)
	{
		l = _getch();
		if (l == '\r' && i == 0) {
			i -= 1;
			continue;
		}
		if (l == '\r') {
			std::cout << endl;
			break;
		}
		if (l == '\b' && i == 0) {
			i -= 1;
			continue;
		}
		if (l == ' ') {
			i -= 1;
			continue;
		}
		if (l == '\t') {
			i -= 1;
			continue;
		}
		if (l == '\b' && i > 0) {
			text[i - 1] = text[i];
			i -= 2;
			std::cout << "\b \b";
		}
		else {
			cout << l;
			text[i] = l;
		}
	}
	cout << endl;
}

void getchCin(char text[], int k) {
	cleanArr(text);
	char l;
	for (int i = 0; i < k; i++)
	{
		l = _getch();
		if (l == '\r' && i == 0) {
			i -= 1;
			continue;
		}
		if (l == '\r') {
			cout << endl;
			break;
		}
		if (l == '\b' && i == 0) {
			i -= 1;
			continue;
		}
		if (l == ' ' && i == 0) {
			i -= 1;
			continue;
		}
		if (l == '\t') {
			i -= 1;
			continue;
		}
		if (l == '\b' && i > 0) {
			text[i - 1] = text[i];
			i -= 2;
			cout << "\b \b";
		}
		else {
			std::cout << l;
			text[i] = l;
		}
	}
	std::cout << endl;
}

void asteriskCout(int a) {
	for (int i = 0; i < a; i++)
	{
		cout << '*';
	}
}
void newLine(int a) {
	for (int i = 0; i < a; i++)
	{
		cout << endl;
	}
}

//Classes
class PVC {
protected:
	char name[32] = { 0 }, password[32] = { 0 };
public:
	~PVC() {};
	char* getName() {
		return name;
	}
	void setName() {
		std::cout << string(47, ' ') << "Name: ";
		noSpaceCin(name);
	}
	void setName(char name[32]) {
		strcpy_s(this->name, 32, name);
	}
	char* getPassword() {
		return password;
	}
	void setPassword() {
		std::cout << string(43, ' ') << "Password:";
		noSpaceCin(password);
	}
	void setPassword(char pass[32]) {
		strcpy_s(this->password, 32, pass);
	}
	virtual void Display() = 0;
};

class User :public PVC
{
private:
	char contact[16] = { 0 };
public:
	User() {
		string x = "unknown";
		strcpy_s(name, 32, x.c_str());
		strcpy_s(password, 32, x.c_str());
		strcpy_s(contact, 16, x.c_str());
	}
	~User() {};
	char* getContact() {
		return contact;
	}
	void setContact() {
		std::cout << string(39, ' ') << "Contact info:";
		noSpaceCin(contact, 16);
	}
	void setAll() {
		std::cout << string(20, ' ') << "Enter your name and password below (name and pass can not contain spaces)" << endl << endl
			<< string(47, ' ') << "Name: ";
		noSpaceCin(name);
		std::cout << string(43, ' ') << "Password: ";
		noSpaceCin(password);
	}

	friend ostream& operator<<(ostream& out, const User& b);

	void Display() {
	}
};

ostream& operator<<(ostream& out, const User& b)
{
	asteriskCout(11);

	std::cout << endl << '*' << "Name: " << b.name << setw(8) << ' ';
	std::cout << endl << '*' << "Password: " << b.password << setw(4) << ' ';
	std::cout << endl << '*' << "Contact info: " << b.contact << ' ' << endl;

	asteriskCout(11);
	std::cout << endl;
	return out;
}

class Book :public PVC
{
private:
	char author[32] = { 0 }, review[128] = { 0 },
		genre[32] = { 0 }, userAdded[32] = { 0 };

public:
	Book() {
		string x = "unknown";
		strcpy_s(name, 32, x.c_str());
		strcpy_s(author, 32, x.c_str());
		strcpy_s(review, 128, x.c_str());
		strcpy_s(genre, 32, x.c_str());
	}
	~Book() {};
	char* getAuthor() {
		return author;
	}
	char* getDescription() {
		return review;
	}
	char* getGenre() {
		return genre;
	}
	void setUserAdded(char userName[32]) {
		strcpy_s(userAdded, userName);
	}
	char* getUserAdded() {
		return userAdded;
	}

	friend ostream& operator<<(ostream& out, const Book& b);

	void Display() {
	}
	void setAll() {
		std::cout << string(18, ' ') << "Fill information about the book below (genre can not contain spaces)" << endl << endl
			<< string(47, ' ') << "Name: ";
		getchCin(name, 32);
		std::cout << string(45, ' ') << "Author: ";
		getchCin(author, 32);
		std::cout << string(45, ' ') << "Review: ";
		getchCin(review, 128);
		std::cout << string(46, ' ') << "Genre: ";
		noSpaceCin(genre);
	}
};

ostream& operator<<(ostream& out, const Book& b)
{
	cout << endl << '|' << " Name: " << b.name << setw(12) << ' ';
	cout << endl << '|' << " Author: " << b.author << setw(10) << ' ';
	cout << endl << '|' << " Review: " << b.review << setw(10) << ' ';
	cout << endl << '|' << " Genre: " << b.genre << setw(11) << ' ';
	cout << endl << '|' << " Reviewed added by " << b.userAdded << ' ' << endl;
	return out;
}

int main() {
	Book TempBook;
	User TempUser;

	ofstream writeFile;
	ifstream readFile;

	//Welcome window
	newLine(11);
	cout << string(26, ' ');
	asteriskCout(60);
	cout << endl << string(47, ' ') << "Welcome to BookLit!" << endl;
	cout << string(26, ' ');
	asteriskCout(60);
	cout << endl;
	newLine(15);
	//Login Part

Login:

	char userName[32] = { 0 }, password[32] = { 0 };
	char name[32] = { 0 }, author[32] = { 0 };
	char userNameLook[32] = { 0 };
	char x = '0', y = '0', z = '1', p = 'o';
	int a = 1;

	while (1) {
		system("pause");
		system("cls");
		newLine(12);
		std::cout << string(42, ' ') << ve << " Choose one option, please " << ve << endl << endl
			<< string(45, ' ') << ve << " Press 1 -> login    " << ve << endl
			<< string(45, ' ') << ve << " Press 2 -> register " << ve << endl
			<< string(45, ' ') << ve << " Press 0 -> exit     " << ve << endl;
		newLine(14);
		z = _getch();


		if (z == '0') {
			goto Exit;
		}
		if (z == '1') {
			while (x != '1') {
				system("cls");
				newLine(9);
				cout << string(21, ' ') << "Enter your name and password below (Enter 0 in name field to go back)" << endl << endl
					<< string(47, ' ') << "Name: ";
				noSpaceCin(userName);
				if (strcmp(userName, "0") == 0) {
					goto Login;
				}

				cout << string(43, ' ') << "Password: ";
				char l;
				for (int i = 0; i < 31; i++)
				{
					l = _getch();
					if (l == '\r' && i == 0) {
						continue;
					}
					if (l == '\r') {
						break;
					}
					if (l == '\b' && i == 0) {
						i -= 1;
						continue;
					}
					if (l == '\b' && i > 0) {
						password[i - 1] = password[i];
						i -= 2;
						cout << "\b \b";
					}
					if (l == ' ') {
						i -= 1;
						continue;
					}
					if (l == '\t') {
						i -= 1;
						continue;
					}
					else {
						cout << "*";
						password[i] = l;
					}
				}
				cout << endl;
				readFile.open("login", ios::binary);
				readFile.seekg(0);
				x = '0';
				y = '0';
				readFile.clear();
				while (readFile.read((char*)&TempUser, sizeof(TempUser))) {
					if (strcmp(userName, TempUser.getName()) == 0 && strcmp(password, TempUser.getPassword()) == 0) {
						x = '1';
					}
					else if (strcmp(userName, TempUser.getName()) == 0) {
						y = '1';
					}
				}
				readFile.close();

				if (x == '1') {
					system("cls");
					newLine(10);
					cout << string(26, ' ');
					asteriskCout(60);
					cout << endl << string(53, ' ') << "Hello, " << userName << endl;
					cout << string(26, ' ');
					asteriskCout(60);
					cout << endl;
					newLine(16);

					system("pause");
					goto Menu;
				}
				else if (y == '1') {
					cout << endl
						<< string(42, ' ') << "Password is incorrect" << endl;
					newLine(14);
					system("pause");
				}
				else if (y == '0') {
					cout << endl
						<< string(37, ' ') << "There is no account with name " << userName << " :(" << endl;
					newLine(14);
					system("pause");
				}
			}

			readFile.close();
		}
		else if (z == '2') {
		Register:
			writeFile.open("login", ios::binary | ios::app);
			readFile.open("login", ios::binary);
			system("cls");
			newLine(10);
			TempUser.setAll();
			strcpy_s(userName, 32, TempUser.getName());
			strcpy_s(password, 32, TempUser.getPassword());
			while (readFile.read((char*)&TempUser, sizeof(TempUser))) {
				if (strcmp(userName, TempUser.getName()) == 0) {
					cout << endl << string(30, ' ') << "This name is already taken. Please, input another one" << endl;
					newLine(12);
					system("pause");
					readFile.close();
					writeFile.close();
					goto Register;
				}
			}
			TempUser.setName(userName);
			TempUser.setPassword(password);
			readFile.close();
			writeFile.write((char*)&TempUser, sizeof(TempUser));
			writeFile.close();
			cout << endl << string(38, ' ') << "You are successfully registrated!" << endl;
			newLine(12);

		}
		else if (z == '3') {
			readFile.open("login", ios::binary);
			while (readFile.read((char*)&TempUser, sizeof(TempUser))) {
				cout << TempUser;
			}
			readFile.close();
		}
	}

	//Main menu
Menu:

	while (1) {
		system("cls");
		newLine(8);
		cout << string(26, ' ');
		asteriskCout(60);
		cout << endl << string(52, ' ') << "Main Menu" << endl;
		cout << string(26, ' ');
		asteriskCout(60);
		cout << endl;
		cout << string(41, ' ') << ve << " Press 1 -> add book review    " << ve << endl
			<< string(41, ' ') << ve << " Press 2 -> show list of books " << ve << endl
			<< string(41, ' ') << ve << " Press 3 -> find book          " << ve << endl
			<< string(41, ' ') << ve << " Press 4 -> open your profile  " << ve << endl
			<< string(41, ' ') << ve << " Press 5 -> find user          " << ve << endl
			<< string(41, ' ') << ve << " Press 6 -> go to login menu   " << ve << endl
			<< string(41, ' ') << ve << " Press 0 -> go to exit         " << ve << endl;
		newLine(10);
		z = _getch();
		if (z == '6') {
			goto Login;
		}
		if (z == '1') {
			system("cls");
			writeFile.open("books", ios::binary | ios::app);
			newLine(8);
			TempBook.setAll();
			newLine(10);
			TempBook.setUserAdded(userName);
			writeFile.write((char*)&TempBook, sizeof(TempBook));
			writeFile.close();
		}
		else if (z == '2') {
			system("cls");
			readFile.open("books", ios::binary);
			while (readFile.read((char*)&TempBook, sizeof(TempBook))) {
				cout << TempBook;
				cout << endl;
			}
			readFile.close();
		}
		else if (z == '3') {
			while (y != 0) {
				newLine(12);
				cout << string(41, ' ') << ve << "Press 1 -> search via name  " << ve << endl
					<< string(41, ' ') << ve << "Press 2 -> search via author" << ve << endl
					<< string(41, ' ') << ve << "Press 0 -> go to main menu  " << ve << endl;
				newLine(14);
				y = _getch();
				switch (y) {
				case '1':
					std::system("cls");
					newLine(10);
					std::cout << string(43, ' ') << "Input the name of the book" << endl << endl
						<< string(47, ' ') << "Name: ";
					getchCin(name, 32);
					readFile.open("books", ios::binary);
					while (readFile.read((char*)&TempBook, sizeof(TempBook))) {
						if (strcmp(name, TempBook.getName()) == 0) {
							cout << TempBook;
							a = 0;
						}
					}
					if (a == 1) {
						cout << endl << string(41, ' ') << "There is no book with name " << name << " :(" << endl;
					}
					newLine(12);
					a = 1;
					readFile.close();
					system("pause");
					break;
				case '2':
					std::system("cls");
					newLine(10);
					std::cout << string(42, ' ') << "Input the author of the book" << endl << endl
						<< string(46, ' ') << "Author: ";
					getchCin(author, 32);
					readFile.open("books", ios::binary);
					while (readFile.read((char*)&TempBook, sizeof(TempBook))) {
						if (strcmp(author, TempBook.getAuthor()) == 0) {
							cout << TempBook;
							a = 0;
						}
					}
					if (a == 1) {
						cout << endl << string(40, ' ') << "There is no book with author " << author << " :(" << endl;
					}
					newLine(12);
					a = 1;
					readFile.close();
					system("pause");
					break;
				case '0':
					goto Menu;
				}
			}
		}
		else if (z == '4') {
			y = '9';
			while (y != '0') {
			Profile:
				system("cls");
				newLine(8);
				cout << string(51, ' ') << " Username: " << userName << endl
					<< string(47, ' ') << " Contact info: ";
				if (strcmp(TempUser.getContact(), "0") == 0) {
					cout << "Not added yet" << endl;
				}
				else {
					cout << TempUser.getContact() << endl;
				}
				cout << endl
					<< string(39, ' ') << ve << " Input 1 -> change username     " << ve << endl
					<< string(39, ' ') << ve << " Input 2 -> change password     " << ve << endl
					<< string(39, ' ') << ve << " Input 3 -> change contact info " << ve << endl
					<< string(39, ' ') << ve << " Input 4 -> delete account      " << ve << endl
					<< string(39, ' ') << ve << " Input 0 -> go to main menu     " << ve << endl;
				newLine(13);
				y = _getch();

				switch (y) {
				case '1':
				NameChange:
					std::system("cls");
					writeFile.open("temp", ios::binary | ios::app);
					readFile.open("login", ios::binary);
					while (readFile.read((char*)&TempUser, sizeof(TempUser)))
					{
						if (strcmp(userName, TempUser.getName()) == 0 && strcmp(password, TempUser.getPassword()) == 0) {
							streamoff loc = writeFile.tellp();
							streamoff p = sizeof(TempUser) + loc;
							writeFile.seekp(p);
							newLine(12);
							TempUser.setName();
							cout << string(27, ' ') << "Enter name one more time: ";
							noSpaceCin(userName);
							if (strcmp(userName, TempUser.getName()) != 0) {
								cout << endl << string(37, ' ') << "Name does not match, enter one more time" << endl;
								newLine(14);
								system("pause");
								goto NameChange;
							}
							writeFile.write((char*)&TempUser, sizeof(TempUser));
							readFile.seekg(writeFile.tellp());
						}
						else {
							writeFile.write((char*)&TempUser, sizeof(TempUser));
						}
					}

					writeFile.close();
					readFile.close();

					std::remove("login");
					try {
						if (rename("temp", "login") == 0) {}
						else {
							throw "Rename crashed";
						}
					}
					catch (const char* c) {
						cout << c << endl;
					}
					break;
				case '2':
				PassChange:
					writeFile.open("temp", ios::binary | ios::app);
					readFile.open("login", ios::binary);
					while (readFile.read((char*)&TempUser, sizeof(TempUser)))
					{
						if (strcmp(userName, TempUser.getName()) == 0 && strcmp(password, TempUser.getPassword()) == 0) {
							streamoff loc = writeFile.tellp();
							streamoff p = sizeof(TempUser) + loc;
							writeFile.seekp(p);
							newLine(12);
							TempUser.setPassword();
							cout << string(27, ' ') << "Enter name one more time: ";
							noSpaceCin(userName);
							if (strcmp(userName, TempUser.getName()) != 0) {
								cout << endl << string(36, ' ') << "Password does not match, enter one more time" << endl;
								newLine(14);
								system("pause");
								goto PassChange;
							}
							writeFile.write((char*)&TempUser, sizeof(TempUser));
							readFile.seekg(writeFile.tellp());
						}
						else {
							writeFile.write((char*)&TempUser, sizeof(TempUser));
						}
					}

					writeFile.close();
					readFile.close();

					std::remove("login");
					try {
						if (rename("temp", "login") == 0) {}
						else {
							throw "Rename crashed";
						}
					}
					catch (const char* c) {
						cout << c << endl;
					}
					break;
				case '3':
					system("cls");
					writeFile.open("temp", ios::binary | ios::app);
					readFile.open("login", ios::binary);
					while (readFile.read((char*)&TempUser, sizeof(TempUser)))
					{
						if (strcmp(userName, TempUser.getName()) == 0 && strcmp(password, TempUser.getPassword()) == 0) {
							streamoff loc = writeFile.tellp();
							streamoff p = sizeof(TempUser) + loc;
							writeFile.seekp(p);
							newLine(12);
							TempUser.setContact();
							writeFile.write((char*)&TempUser, sizeof(TempUser));
							readFile.seekg(writeFile.tellp());
						}
						else {
							writeFile.write((char*)&TempUser, sizeof(TempUser));
						}
					}

					writeFile.close();
					readFile.close();

					std::remove("login");
					try {
						if (rename("temp", "login") == 0) {}
						else {
							throw "Rename crashed";
						}
					}
					catch (const char* c) {
						cout << c << endl;
					}
					break;
				case '4':
					while (p != 'y' && p != 'n') {
						system("cls");
						newLine(12);
						cout << string(50, ' ') << "Are you sure?" << endl;
						cout << string(37, ' ') << "Press 'y' for yes" << "\t";
						cout << "Press 'n' for no" << endl;
						p = _getch();
						if (p == 'y') {
							cout << endl << string(44, ' ') << "Your account was deleted" << endl;
							writeFile.open("temp", ios::binary | ios::app);
							readFile.open("login", ios::binary);
							while (readFile.read((char*)&TempUser, sizeof(TempUser)))
							{
								if (strcmp(userName, TempUser.getName()) == 0 && strcmp(password, TempUser.getPassword()) == 0) {
								}
								else {
									writeFile.write((char*)&TempUser, sizeof(TempUser));
								}
							}

							writeFile.close();
							readFile.close();

							std::remove("login");
							try {
								if (rename("temp", "login") == 0) {}
								else {
									throw "Rename crashed";
								}
							}
							catch (const char* c) {
								cout << c << endl;
							}
							p = 'o';
							goto Login;
						}
						else if (p == 'n') {
							p = 'o';
							goto Profile;
						}
					}
					break;
				case '0':
					break;
				}
			}
		}
		else if (z == '5') {
			system("cls");
			newLine(12);
			cout << string(42, ' ') << "Input username of wanted user" << endl;
			cout << string(48, ' ') << "Username: ";
			noSpaceCin(userNameLook);
			newLine(2);
			readFile.open("login", ios::binary);
			while (readFile.read((char*)&TempUser, sizeof(TempUser)))
			{
				if (strcmp(userNameLook, TempUser.getName()) == 0) {
					cout << endl;
					cout << ve << " Username: " << TempUser.getName() << endl;
					cout << ve << " Contact information: " << TempUser.getContact() << endl;
				}
			}
			readFile.close();
		}
		std::system("pause");
		if (z == '0') {
			goto Exit;
		}
	}

Exit:
	if (z == '0') {
		system("cls");

		newLine(11);
		cout << string(26, ' ');
		asteriskCout(60);
		cout << endl << string(47, ' ') << "Goodbye, see you soon!" << endl;
		cout << string(26, ' ');
		asteriskCout(60);
		cout << endl;
		newLine(15);
	}

	std::system("pause");
	return 0;
}