#include <iostream>
#include "List.h"

using namespace std;

int main()
{

 List L1, L2;

 //Do some stuff with L1, L2, ...
 // ...
 
 cout << L1.size() << endl;
 for (int i = 0; i < 10; i++)
	 L1.insert((i+5), (i+1));

 cout << L1.getNode(5) << endl;
 L1.insert(21, 3);
 cout << L1.size() << "\n" << endl;

 for (int i = 1; i <= L1.size(); i++)
	 cout << "L1 - " << L1.getNode(i) << endl;

 cout << "Copy L1 into L2 then clear L1" << endl;

 int prevSize = L1.size();
 for (int i = 1; i <= prevSize; i++)
	 L2.insert(L1.getNode(i), i);

 cout << endl;
 L1.clear();
 cout << "L1.size() - " << L1.size() << endl;
 for (int i = 1; i <= L2.size(); i++)
	 cout << "L2 - " << L2.getNode(i) << endl;
}
