
#include "CesarCipher.h"
#include <string.h>


bool CesarCipher::isCapital(char c){
	if( (c<='Z') && (c>='A') ){
		setMinChar('A');
		setMaxChar('Z');
		return true;
	}
	return false;
}

bool CesarCipher::isMinor(char c){
	if( (c<='z') && (c>='a') ){
		setMinChar('a');
		setMaxChar('z');
		return true;
	}
	return false;
}

bool CesarCipher::isAlphabetic(char c){
	if(isCapital(c) || isMinor(c) ){
		return true;
	}
	return false;
}

char CesarCipher::codifyCharacter(char c, int step){	
	return (c+step);
}

char CesarCipher::forceToBeALetter(char c){
	if(c>getMaxChar()) return (getMinChar()-1) + (c - getMaxChar());
	if(c<getMinChar()) return getMaxChar() - ((getMinChar()-1) - c);
	return c;
}

char codify(char letter, int step){
	forceToBeALetter(codifyCharacter(letter, step));
}


char* CesarCipher::codify(char * phrase, int step){
	char* codedphrase = (char*)malloc(sizeof(char) * strlen(phrase));
	for(int i=0; i<strlen(phrase); i++){
		codedphrase[i] = phrase[i];
		if(isAlphabetic(phrase[i])){

			codedphrase[i] = codify(phrase[i], step);


		}

	}
codedphrase[strlen(phrase)]='\0';
	return codedphrase;
}