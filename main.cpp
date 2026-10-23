#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;

int main()
{

	//import from text files
	Store store1;
    Person people[100];
	product products[100];
    int people_count = 0;

			//PEOPLE	
	string name, number;
	ifstream personFile("people.txt");
	while (getline(personFile, name))
	{
		if (name == "") break;
		address address;
		getline(personFile, number);
		getline(personFile, address.address_line1);
		getline(personFile, address.address_line2);
		getline(personFile, address.city);
		getline(personFile, address.state);
		getline(personFile, address.zip);

		people[people_count].name(name);
		people[people_count].phone(number);
		people[people_count].person_address(address);
		people_count++;
	}
	personFile.close();

		//CREDIT CARD

	string cc_number_txt, limit_txt, balance_txt;
	ifstream ccFile("credit_card.txt");
	while (getline(ccFile, name))
	{
		if (name == "") break;
		credit_card cc;
		getline(ccFile, cc_number_txt);
		cc.cc_number = stoi(cc_number_txt); //comvert to integer
		getline(ccFile, limit_txt);
		cc.limit = stod(limit_txt); //convert to double
		getline(ccFile, balance_txt);
		cc.current_balance = stod(balance_txt); //convert to double

		for (int i = 0; i < people_count; i++) //check array to assign the card to the right person
		{
			if (people[i].name() == name) 
			{
				people[i].person_credit_card(cc);
				break;
			}
		}
	}
	ccFile.close();

		//PRODUCTS
	
	string price_txt;
	product item;
	ifstream productFile("products.txt");
	while (getline(productFile, item.name))
	{
		if (item.name == "") break;
		getline(productFile, item.description);
		getline(productFile, price_txt);
		item.price = stod(price_txt);
		store1.add_product(item);
	}
	productFile.close();

	//add to store and other variables

	for (int i = 0; i < people_count; i++) {
		store1.add_customer(people[i]);
	}
	
	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	//make random number of random transactions

	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
}
