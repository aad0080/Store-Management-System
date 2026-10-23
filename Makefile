# Run with ./a.out

CC = g++ -std=c++14

all: main.o address.o credit_card.o person.o product.o store.o transaction.o
	$(CC) main.o address.o credit_card.o person.o product.o store.o transaction.o

main.o: main.cpp address.h credit_card.h person.h product.h store.h transaction.h
	$(CC) -c main.cpp

address.o: address.cpp address.h
	$(CC) -c address.cpp

credit_card.o: credit_card.cpp credit_card.h
	$(CC) -c credit_card.cpp

person.o: person.cpp person.h address.h credit_card.h
	$(CC) -c person.cpp

product.o: product.cpp product.h
	$(CC) -c product.cpp

store.o: store.cpp store.h person.h product.h transaction.h address.h credit_card.h
	$(CC) -c store.cpp

transaction.o: transaction.cpp transaction.h person.h product.h address.h credit_card.h
	$(CC) -c transaction.cpp

clean:
	rm -f *.o a.out
