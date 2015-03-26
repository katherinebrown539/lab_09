/*
	lab_09
	CSC 2111 Lab 09
	Katherine (Katie) Brown and Amber Patterson
	Note: A second makefile is used in build.bat to create an executable to test the quicksort individually
	https://github.com/kebrown46/lab_09
*/

#include "Sort.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
	
   }

   delete iter;
}


int main()
{
	
   ListArray<CD>* list = CD::readCDs("cds.txt");

   CD** cds = list->toArray();
   int size = list->size();
   CD** sorted = Sort<CD>::quickSort(cds, size, &CD::compare_items);
   for (int i = 0; i < size; i++)
   {
      CD* cd = sorted[i];
      String* key = cd->getKey();
	  key->displayString();
	  cout << endl;
	  
   }

   deleteCDs(list);
   delete list;
}
