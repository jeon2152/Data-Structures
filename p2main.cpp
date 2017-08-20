#include <iostream>
#include "HashingTable.h"
using namespace std;

// A sample main program
void main()
{
	HashingTable<char*>* myHashTable;
	char* Names[25] = { "Andy B", "Amy Dean", "Antonio G", "Andy Roberts",
		"Brian W","Bob Macy", "Brent James", "Buck Muck",
		"Cannon James", "Cart Wright", "Catherine Zeta", "Carl Lewis",
		"David Johnson", "Dowd Peter", "Daniel Fauchier", "Dawn Smith",
		"Yarda Varda", "Yami Jacob", "Yester Louis", "Yukon Oklahoma",
		"Zandi Rich", "Zea John", "Zelby Leon", "Ziert Paul", "Zanola Helen" };
	int i;
	myHashTable = new HashingTable<char*>(26);
	for (i = 0; i < 25; i++)
		(*myHashTable).insert(Names[i]);
	cout << "// --- Original hash table --- //" << endl;
	cout << "Printing the hash table after inserting...." << endl;
	//cout << myHashTable << endl;
	cout << *myHashTable << endl;
	cout << "// --- Find Zandi Rich --- //" << endl;
	if ((*myHashTable).find("Zandi Rich"))
		cout << "Zandi Rich is in the list" << endl;
	else
		cout << "Zandi Rich is not in the list" << endl;
	cout << endl;
	cout << "// --- Remove and check Zea John --- //" << endl;
	(*myHashTable).remove("Zea John");
	if ((*myHashTable).find("Zea John"))
		cout << "Zea John is in the list" << endl;
	else
		cout << "Zea John is not in the list" << endl;
	for (i = 0; i < 26; i++)
		(*myHashTable).split(i, 2);
	cout << endl;
	cout << "// --- Splitted hash table --- //" << endl;
	cout << "Printing the hash table after splitting...." << endl;
	//cout << myHashTable << endl;
	cout << *myHashTable << endl;
	cout << "// --- Find Ziert Paul --- //" << endl;
	if ((*myHashTable).find("Ziert Paul"))
		cout << "Ziert Paul is in the list" << endl;
	else
		cout << "Ziert Paul is not in the list" << endl;
	cout << endl;
	cout << "// --- Insert and check Zea John --- //" << endl;
	(*myHashTable).insert("Zea John");
	if ((*myHashTable).find("Zea John"))
		cout << "Zea John is in the list" << endl;
	else
		cout << "Zea John is not in the list" << endl;
	cout << endl;
	cout << "// --- HashingTable Destructor --- //" << endl;
	delete myHashTable;
	}
