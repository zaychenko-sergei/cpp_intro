#include <iostream>

struct Node
{
	int value;
	Node * pNext;
};

struct LinkedList
{
	Node * pFirst;
	Node * pLast;
};

void addToList ( LinkedList * pList, int value )
{
	Node * pNode = new Node;
	pNode->value = value;
	pNode->pNext = nullptr;

	if ( pList->pLast )
	{
		pList->pLast->pNext = pNode;
		pList->pLast = pNode;
	}
	else
		pList->pFirst = pList->pLast = pNode;
}

void printList ( const LinkedList * pList )
{
	const Node * pCurrent = pList->pFirst;
	while ( pCurrent != pList->pLast )
	{
		printf( "%d ", pCurrent->value );
		pCurrent = pCurrent->pNext;
	}

	putchar( '\n' );
}

void destroyList ( LinkedList * pList )
{
	Node * pCurrent = pList->pFirst;
	while ( pCurrent )
	{
		Node * pTemp = pCurrent;
		pCurrent = pCurrent->pNext;
		delete pTemp;
	}
}

int main ()
{
	LinkedList l;
	l.pFirst = l.pLast = nullptr;

	while ( ! feof( stdin ) )
	{
		int value;
		if ( scanf( "%d", & value ) )
			addToList( & l, value );
	}

	printList( & l );

	destroyList( & l );
}