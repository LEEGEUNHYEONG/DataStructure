#include "base.h"
#include "Stack.h"

using namespace std;

int main()
{
	cout << "main" << endl;	

	AStack *aStack = new AStack();
	//aStack->StackMain();

	LStack *lStack = new LStack();
	lStack->LStackMain();
	
}