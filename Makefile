
TEST = CesarCipherTest
CC=g++
CFLAGS=
INCLUDES=
LFLAGS=
SRCS =  main.cpp CesarCipher.cpp CesarCipherTest.cpp

CFLAGS += -I/Users/antoniomartinez/Software/gtest-1.6.0/include
LFLAGS += -L/opt/local/lib -L. -lgtest_main

COMMONOBJS = CesarCipher.o

MAINOBJ = main.o
TESTOBJ = CesarCipherTest.o

all: $(MAIN) $(TEST) executeTest

$(MAIN):  $(MAINOBJ) $(COMMONOBJS)
	$(CC) $(MAINOBJ) $(COMMONOBJS) -o $(MAIN) $(LFLAGS)

$(TEST):  $(TESTOBJ) $(COMMONOBJS)
	$(CC) $(TESTOBJ) $(COMMONOBJS) -o $(TEST) $(LFLAGS)
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

clean:
	rm -f *.o *~ $(MAIN)

executeTest:
	./CesarCipherTest