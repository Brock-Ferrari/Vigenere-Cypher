// MESSAGE CLASS - VIGENERE CYPHER
// Brock Ferrari 

#pragma once
#include <iostream>
#include <vector>
#include "Vigenere.h"

class Message
{
public:
	Message(std::string k = " ");
	void encryptWord(char* token);
	void decryptWord(char* token);
	void makeFile(std::string fileName);
	void showWords();
private:
	std::vector <std::string> words;
	Vigenere v;
};