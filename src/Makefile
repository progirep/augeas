HEADERS = config.h  fa.h  hash.h  internal.h  list.h  memory.h  ref.h

default: regextodfa

main.o: main.cpp $(HEADERS)
		g++ -c main.cpp -O -o main.o -I .

%.o: %.c $(HEADERS)
		gcc -c $< -O -o $@ -I .

regextodfa : main.o fa.o memory.o hash.o ref.o
		g++ -static main.o fa.o memory.o hash.o ref.o -o regextodfa

clean:
		-rm -f *.o
		-rm -f regextodfa
