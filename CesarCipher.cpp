
#include "CesarCipher.h"
#include <string.h>

CesarCipher::CesarCipher(){}




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
	//printf("codifyCharacter %c , %d = %c \n",c,step,c+step);
	return (c+step);
}

char CesarCipher::forceToBeALetter(char c){
	if(c>getMaxChar()) return (getMinChar()-1) + (c - getMaxChar());
	if(c<getMinChar()) return getMaxChar() - ((getMinChar()-1) - c);
	return c;
}


char* CesarCipher::codify(char * phrase, int step){
	char* codedphrase = (char*)malloc(sizeof(char) * strlen(phrase));
	for(int i=0; i<strlen(phrase); i++){
		codedphrase[i] = phrase[i];
		if(isAlphabetic(phrase[i])){

			codedphrase[i] = forceToBeALetter(codifyCharacter(phrase[i], step));


		}

	}
codedphrase[strlen(phrase)]='\0';
	return codedphrase;
}