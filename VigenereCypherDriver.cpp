// VIGENERE CYPHER
// Brock Ferrari 

#include <iostream>
#include <fstream>
#include <string>
#include "Vigenere.h"
#include "Message.h"
using namespace std;

void DecryptMessage();	// Decrypts message from file
void EncryptMessage();	// Encrypts message from file
int displayMenu();		// Displays menu
	
int main()
{
	bool loop = true;
	while (loop == true)	// Loops until Quit is selected
	{
		int select = displayMenu();

		switch (select)
		{
		case 1:
			EncryptMessage();
			break;
		case 2:
			DecryptMessage();
			break;
		case 3:
			loop = false;
			break;
		}
	}
	
	system("pause");
	return 0;
}

int displayMenu()
{
	bool test = false;
	int selection = 0;
	while (test == false)
	{
		cout << "Vigenere Cypher\n\nMainMenu\n\n";
		cout << "1 - Encrypt File\n" << "2 - Decrypt File\n" << "3 - Quit\n\n";

		cout << "Selection: ";
		cin >> selection;
		while (cin.fail() || selection < 0) // Error checking for integer
		{
			cout << "The selection must be a positive integer. Please try again." << endl << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Selection: ";  cin >> selection;
		}
		switch (selection)
		{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		default:
			cout << "\n\nPlease enter 1, 2, or 3.\n\n\n\n";
		}
	}
}

void EncryptMessage()
{
	ifstream file;
	string fileName = " ";
	cout << "\nEnter the name of the file to encrypt:" << endl;
	cin >> fileName;
	file.open(fileName);
	char sen[1000];
	file.getline(sen, 1000);
	cout << endl << sen << endl;
	file.close();

	string key = " ";
	cout << "\nEnter an encryption/decryption key: " << endl;
	cin >> key;

	Message m(key);

	char delims[] = " .,?!:;";
	char* token = NULL, * next_token = NULL;

	token = strtok_s(sen, delims, &next_token);
	m.encryptWord(token);

	while (token != NULL) // Checks if there is an available token to encrypt
	{
		token = strtok_s(NULL, delims, &next_token);
		if (token != NULL)
			m.encryptWord(token);
	}

	std::string newFile = " ";
	std::cout << "\nA new file will be created that contains the encrypted message.\nPlease enter the name of the new file to create: ";
	std::cin >> newFile;

	m.makeFile(newFile);
	m.showWords();

	return;
}

void DecryptMessage()
{
	ifstream file;
	string fileName = " ";
	cout << "\nEnter the name of the file to decrypt:" << endl;
	cin >> fileName;
	file.open(fileName);
	char sen[1000];
	file.getline(sen, 1000);
	cout << endl << sen << endl;
	file.close();

	string key = " ";
	cout << "\nEnter an encryption/decryption key: " << endl;
	cin >> key;

	Message m(key);

	char delims[] = " .,?!:;";
	char* token = NULL, * next_token = NULL;

	token = strtok_s(sen, delims, &next_token);
	m.decryptWord(token);

	while (token != NULL) // Checks if there is an available token to encrypt
	{
		token = strtok_s(NULL, delims, &next_token);
		if (token != NULL)
			m.decryptWord(token);
	}

	std::string newFile = " ";
	std::cout << "\nA new file will be created that contains the decrypted message.\nPlease enter the name of the new file to create: ";
	std::cin >> newFile;

	m.makeFile(newFile);
	m.showWords();

	return;

}