// VIGENERE CLASS - VIGENERE CYPHER
// Brock Ferrari 

#pragma once
#include <iostream>

class Vigenere
{
public:
	Vigenere(std::string k = " "); // Default constructor
	void setKey(std::string k); // Sets the key
	std::string getKey(); // Returns key
	std::string toUpperCase(std::string k); // Converts key to upper case before setting the value
	std::string encrypt(std::string word); // Algorithm to encrypt a word
	std::string decrypt(std::string word); // Algorithm to decrypt a word
private:
	std::string key;
};