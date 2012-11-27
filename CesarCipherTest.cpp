
#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>

#include "CesarCipher.h"
#include "gtest/gtest.h"

namespace{
	class CesarCipherTest : public ::testing::Test{
	protected:
			CesarCipher *cesarcipher;

			CesarCipherTest()
    	{
        	// You can do set-up work for each test here.
    	}

		virtual void SetUp()
    	{

        	cesarcipher = new CesarCipher();

    	}
	};

	TEST_F(CesarCipherTest, ACharacterisCapital){
		bool result = cesarcipher->isCapital('G');
		ASSERT_TRUE(result);
	}

	TEST_F(CesarCipherTest, ACharacterisNotCapital){
		bool result = cesarcipher->isCapital('j');
		ASSERT_FALSE(result);
	}

	TEST_F(CesarCipherTest, ACharacterisMinor){
		bool result = cesarcipher->isMinor('j');
		ASSERT_TRUE(result);
	}

	TEST_F(CesarCipherTest, ACharacterisNotMinor){
		bool result = cesarcipher->isMinor('G');
		ASSERT_FALSE(result);
	}

	TEST_F(CesarCipherTest, ACharacterisAlphabetic){
		bool result = cesarcipher->isAlphabetic('j');
		ASSERT_TRUE(result);
	}

	TEST_F(CesarCipherTest, ACharacterisNotAlphabetic){
		bool result = cesarcipher->isAlphabetic('*');
		ASSERT_FALSE(result);
	}


	TEST_F(CesarCipherTest, NumberAreNotProcessed){
		char *phrasecoded = cesarcipher->codify("ABC 34.,D E*", 2);

		ASSERT_TRUE(strcmp("CDE 34.,F G*",
			phrasecoded) == 0);
	}
	TEST_F(CesarCipherTest, BlankSpaceAndSimbolsAreNoProcessed){
		char *phrasecoded = cesarcipher->codify("23ABC¿? =DEF$G", 3);

		ASSERT_TRUE(strcmp("23DEF¿? =GHI$J",
			phrasecoded) == 0);
	}

	TEST_F(CesarCipherTest, CodedCharBiggerThanLimit){
		char *phrasecoded = cesarcipher->codify("y", 3);
		printf("%s\n",phrasecoded );
		ASSERT_TRUE(strcmp("b",
			phrasecoded) == 0);
	}


	TEST_F(CesarCipherTest, CodedCharSmallerThanLimit){
	char *phrasecoded = cesarcipher->codify("c", -3);

		ASSERT_TRUE(strcmp("z",
			phrasecoded) == 0);
	}

	TEST_F(CesarCipherTest, LongSentenceTest){
		char *phrasecoded =
		cesarcipher->codify("Todo lo que se preguntaba eran las mismas respuestas que buscamos el resto de nosotros. ¿De dónde vengo? ¿A dónde voy? ¿Cuánto tiempo tengo? Todo lo que pude hacer fue sentarme y ver como moría.", 3);
		printf("%s\n",phrasecoded );
		ASSERT_TRUE(strcmp("Wrgr or txh vh suhjxqwded hudq odv plvpdv uhvsxhvwdv txh exvfdprv ho uhvwr gh qrvrwurv. ¿Gh góqgh yhqjr? ¿D góqgh yrb? ¿Fxáqwr wlhpsr whqjr? Wrgr or txh sxgh kdfhu ixh vhqwduph b yhu frpr pruíd.",
			phrasecoded) == 0);
	}
}
