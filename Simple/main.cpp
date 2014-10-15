#include <iostream>

using namespace std;

const int TABLE_SIZE = 128;

class HashEntry {

	public:
		HashEntry(int k, int v) : key(k), value(v) {}
		int getKey() {return key;}
		int getValue() {return value;}

	private:
		int key;
		int value;
};

class HashMap {

	public:
		HashMap() {	
			table = new HashEntry*[TABLE_SIZE];

			// Set all values to NULL
			for(int i = 0; i < TABLE_SIZE; i++) {
				table[i] = 0;
			}
		}

		~HashMap() {
			for(int i = 0; i < TABLE_SIZE; i++)
				delete table[i];
			delete[] table;
		}

		void put(int key, int value) {
			int hash = key % TABLE_SIZE;

			while(table[hash] != NULL && table[hash]->getKey() != key)
				hash = (hash + 1) % TABLE_SIZE;

			table[hash] = new HashEntry(key, value);
		}

		int get(int key) {
			int hash = key % TABLE_SIZE;

			while(table[hash] != NULL && table[hash]->getKey() != key)
				hash = (hash + 1) % TABLE_SIZE;

			if(table[hash] == NULL)
				return -1;
			else
				return table[hash]->getValue();
		}

	private:
		HashEntry ** table;
};

int main(){

	const int TABLE_SIZE = 128;

	int num = 4;

	cout << ((num % TABLE_SIZE)+1) % TABLE_SIZE << endl;


}