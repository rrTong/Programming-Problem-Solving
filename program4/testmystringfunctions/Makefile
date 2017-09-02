a.out: testmystringfunctions.o mystringfunctions.o
	gcc -Wall -g testmystringfunctions.o mystringfunctions.o -o a.out
testmystringfunctions.o: testmystringfunctions.c mystringfunctions.h
	gcc -Wall -c -g testmystringfunctions.c -o testmystringfunctions.o
mystringfunctions.o: mystringfunctions.h mystringfunctions.c
	gcc -Wall -c -g mystringfunctions.c -o mystringfunctions.o
clean:
	rm -rf *.o *.out
