// VIGENERE IMPLEMENTATION - VIGENERE CYPHER
// Brock Ferrari 

#include <iostream>
#include "Vigenere.h"

Vigenere::Vigenere(std::string k)
{
	setKey(k);
};

void Vigenere::setKey(std::string k)
{
	key = toUpperCase(k);
}

std::string Vigenere::getKey()
{
	return key;
}

std::string Vigenere::toUpperCase(std::string k) // Converts key to upper case before setting the value
{
	int i = 0;
	while (k[i])
	{
		k[i] = toupper(k[i]);
		i++;
	}
	return k;
}

std::string Vigenere::encrypt(std::string word) 
{
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c + key[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A - Z ]
		j = (j + 1) % key.length();
	}
	return output;
}

std::string Vigenere::decrypt(std::string word)
{
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c - key[j] + 26) % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A - Z ]
		j = (j + 1) % key.length();
	}
	return output;
}