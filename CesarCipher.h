
#ifndef CESARCIPHER_H
#define CESARCIPHER_H value

#include <stdio.h>
#include <stdlib.h>

class CesarCipher{
private:
	char minChar;
	char maxChar;
public:

	CesarCipher();
	char getMinChar(){return minChar;}
	char getMaxChar(){return maxChar;}
	void setMinChar(char min){minChar = min;}
	void setMaxChar(char max){maxChar = max;}
	char forceToBeALetter(char c);
	char* codify(char* phrase,int step);
	char codifyCharacter(char c, int step);
	bool isAlphabetic(char c);
	bool isCapital(char c);
	bool isMinor(char c);


};

#endif