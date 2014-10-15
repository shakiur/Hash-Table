#include <iostream>
#include "headers/hashentry.h"
#include "headers/hashmap.h"

using namespace std;

int main(){
	HashEntry * h = new HashEntry(5,5);
	HashMap * hm = new HashMap();

	hm->insertEntry(120,5);
	hm->display();

	cout << hm->getValue(121) << endl;
}