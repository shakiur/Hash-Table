#ifndef HASHMAP_H
#define HASHMAP_H

#include "hashentry.h"

class HashMap{

	int TABLE_SIZE;
	HashEntry** table;

	public:
		HashMap();

		int getHash(int);
		int getValue(int);

		void insertEntry(int, int);

		void display();
};

#endif