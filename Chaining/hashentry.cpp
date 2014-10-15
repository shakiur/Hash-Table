#include <iostream>
#include "headers/hashentry.h"

using namespace std;

HashEntry::HashEntry() {}
HashEntry::HashEntry(int k, int v) : key(k), value(v), next(NULL) {}

int HashEntry::getKey() { return key; }

int HashEntry::getValue() { return value; }

HashEntry * HashEntry::getNext() { return next; }

void HashEntry::setNext(HashEntry* n) { next = n; }

void HashEntry::setValue(int v) { value = v; }