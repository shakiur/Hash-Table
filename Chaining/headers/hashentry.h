#ifndef HASHENTRY_H
#define HASHENTRY_H

class HashEntry{
	int key;
	int value;
	HashEntry * next;

	public:
		HashEntry();
		HashEntry(int, int);

		int getKey();
		int getValue();
		HashEntry * getNext();

		void setNext(HashEntry*);
		void setValue(int);
};

#endif