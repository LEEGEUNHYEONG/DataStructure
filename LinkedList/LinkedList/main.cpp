#include <iostream>
#include <stdio.h>
#include <Windows.h>

#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "CircularLinkedList.h"

int main()
{	
	system("mode con:cols=50 lines=30");

	//SingleLinkedListMain();

	//DoubleLinkedList d;
	//d.DoubleLinkedListMain();
	
	CircularDoubleLinkedList cdl;
	cdl.CircularDoubleLinkedListMain();
	
}