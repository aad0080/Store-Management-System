CC = g++

all: main.o address.o credit_card.o person.o product.o store.o transaction.o
	$(CC) main.o address.o credit_card.o person.o product.o store.o transaction.o -o all

main.o: main.cpp
	$(CC) -c main.cpp -o main

address.o: address.cpp
	$(CC) -c address.cpp -o address

credit_card.o: credit_card.cpp
	$(CC) -c credit_card.cpp -o credit

person.o: person.cpp
	$(CC) -c person.cpp -o person

product.o: product.cpp
	$(CC) -c product.cpp -o product

store.o: store.cpp
	$(CC) -c store.cpp -o store

transaction.o: transaction.cpp
	$(CC) -c transaction.cpp -o transaction

clean:
	rm -f *.o all


// Amy