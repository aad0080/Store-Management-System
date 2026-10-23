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
	

	//add to store and other variables
Store store1;
    Person people[100];
    int people_count = 0;
	
	//print store info after you finish importing info
	  std::ifstream people_file("people.txt");
    std::ifstream card_file("credit_card.txt");
	
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
if (!people_file || !card_file)
    {
        std::cerr << "Error opening customer data files.\n";
        return 1;
    }
	//make random number of random transactions

	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
}
