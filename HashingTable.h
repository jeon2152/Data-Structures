#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;


template <class DT>
class HashingTable {

//protected:

public:
	vector<list<DT>> v;			// vector of linked lists
	
	HashingTable();				// empty constructor
	HashingTable(int z);		// non-empty constructor
	virtual ~HashingTable();	// destructor of HashingTable class

	int hashFunction(DT name);	// hashFunction method
	void insert(DT name);		// insert method
	bool find(DT name);			// find method
	void remove(DT name);		// remove method
	void split(int i, int p);	// split method


	// overloaded ostream operator<<
	friend ostream& operator<< (ostream& s, HashingTable<DT>& ht){
		for (int i = 0; i < (ht.v).size(); ++i) {
			cout << "V""[" << i << "]: ";
			list<DT>::iterator lItr = (ht.v[i]).begin();
			const list<DT>::iterator lItrEnd = (ht.v[i]).end();
			for (; lItrEnd != lItr; ++lItr) {
				s << *lItr << "|";
			}
			cout << endl;
		}
		return s;
	}

};

// HashingTable empty constructor
template <class DT>
HashingTable<DT>::HashingTable() {}

// HashingTable non-empty constructor
template <class DT>
HashingTable<DT>::HashingTable(int z) {

	std::list<DT> * vectorList;
	vectorList = new list<DT>(0);
	for (int i = 0; i < z; ++i) {
		v.push_back(*vectorList);
	}

}

// HashingTable destructor 
template <class DT>
HashingTable<DT>::~HashingTable() {

	v.clear();
	cout << "Mission completed. We're destroying the hashtable!!" << endl;
	cout << "The size of the vector becomes " << v.size() << "." << endl;

}

// HashingTable methods

template <class DT>
int HashingTable<DT>::hashFunction(DT name) {
	return (name[0] - 'A');
}

template <class DT>
void HashingTable<DT>::insert(DT name) {

	int index = hashFunction(name);
	v.at(index).push_back(name);

}

template <class DT>
bool HashingTable<DT>::find(DT name) {

	bool found = false;
	int i = hashFunction(name);
	for (; i < v.size(); ++i) {
		for (auto element : (v.at(i))) {
			if (element == name) {
				found = true;
				break;
			}
			else continue;
		}
	}
	return found;

	//int i = hashFunction(name);
	//std::list<DT> * str;
	//str = new list<DT>(i);
	//list<DT>::iterator lItr = (v[i]).begin();
	//const list<DT>::iterator lItrEnd = (v[i]).end();
	//for (; lItrEnd != lItr; ++lItr) {
		//if ((*lItr).str == name) {
			//return true;
		//}
	//}

}

template <class DT>
void HashingTable<DT>::remove(DT name) {

	int i = hashFunction(name);
	for (i; i < v.size(); ++i) {
		for (auto element : (v.at(i))) {
			if (element == name) {
				(v.at(i)).remove(element);
				break;
			}
			else continue;
		}
	}
	
	//DT info = find(name);
	//DT str = NULL;
	//for (int i = 0; i < v.size(); ++i) {
		//list<DT>::iterator lItr = (v[i]).begin();
		//const list<DT>::iterator lItrEnd = (v[i]).end();
		//for (; lItrEnd != lItr; ++lItr) {
		//	(v[i]).remove(info);
			//if (name == str) { (v[i]).remove(find(name); }
		//}
	//}

}


template <class DT>
void HashingTable<DT>::split(int i, int p) {

	list<DT> l;								// linked list (of each vector index)

	if (v.at(i).size() > p) {					// split and pass the input data to next vector index
		int delta = (v.at(i)).size() - p;
		for (int m = 0; m < delta; m++) {
			l.push_back(v.at(i).back());
			v.at(i).pop_back();
		}
		int j = i;
		j++;
		for (j; ; j++) {
			if (v.size() < j + 1 )
				v.resize(v.size() + 1);

			while (v.at(j).size() < p) {
				v.at(j).push_back(l.back());
				l.pop_back();
				if (l.size() == 0) {
					return;
				}
			}
		}
	}

}


