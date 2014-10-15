#include <iostream>
#include "headers/hashentry.h"
#include "headers/hashmap.h"

using namespace std;

HashMap::HashMap() {

	TABLE_SIZE = 128;
	table = new HashEntry*[TABLE_SIZE];

	for(int i = 0; i < TABLE_SIZE; i++){
		table[i] = NULL;
	}
}

int HashMap::getHash(int key) {
	return key % TABLE_SIZE;
}

int HashMap::getValue(int key) {

	int hash = getHash(key);

	if(table[hash]){
		HashEntry * temp = table[hash];

		while(temp){
			if(temp->getKey() == key)
				return temp->getValue();
			else
				temp = temp->getNext();
		}


	}

	// If no entry or key never found
	return -1;

}

void HashMap::insertEntry(int key, int value){

	int hash = getHash(key);

	HashEntry * new_entry = new HashEntry(key, value);

	// If entry is taken, iterate to last and append
	if(table[hash]){

		HashEntry * temp = table[hash];

		while(temp->getNext()){
			temp = temp->getNext();
		}

		// If key matches, just update entry
		// Otherwise attach new entry
		if(temp->getKey() == key){
			temp->setValue(value);
			delete new_entry;
		}
		else{
			temp->setNext(new_entry);
		}

	}
	else{
		table[hash] = new_entry;
	}

}

void HashMap::display(){
	for(int i = 0; i < TABLE_SIZE; i++){
		cout << "Hash: " << i << " | ";

		HashEntry * temp = table[i];

		if(temp){
			while(temp){
				cout << "[" << temp->getKey()
					 << "," << temp->getValue()
					 << "]->";
				
				temp = temp->getNext();
			}
		}
		
		cout << "NULL" << endl;
		
	}
}