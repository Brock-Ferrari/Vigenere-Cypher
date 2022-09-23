// MESSAGE IMPLEMENTATION - VIGENERE CYPHER
// Brock Ferrari 

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Vigenere.h"
#include "Message.h"

Message::Message(std::string k)
{
	v.setKey(k);
}
void Message::encryptWord(char* token)
{
	std::string s(token);
	words.push_back(v.encrypt(s));
}
void Message::decryptWord(char* token)
{
	std::string s(token);
	words.push_back(v.decrypt(s));
}
void Message::makeFile(std::string fileName) // Creates a file
{
	std::ofstream outFile(fileName);
	
	for (int i = 0; i < words.size(); ++i)
		outFile << words[i] << " ";
}
void Message::showWords()
{
	for (int i = 0; i < words.size(); ++i)
		std::cout << words[i] << " ";
	std::cout << "\n\n";
}