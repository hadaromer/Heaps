#include <iostream>
#include <string>
using namespace std;

#include "Heaps.h"

int main() {

	int numOfActions;
	cin >> numOfActions;
	if (numOfActions <= 0) {
		cout << "wrong input" << endl;
		exit(1);
	}
	char curr;
	cin >> curr;
	if (curr != 'e') {
		cout << "wrong input" << endl;
		exit(1);
	}
	numOfActions--;
	Heaps res;
	for (int i = 0; i < numOfActions; i++) {
		cin >> curr;
		if (curr == 'a') {
			res.Max();
		}
		else if (curr == 'b') {
			res.DeleteMax();		}
		else if (curr == 'c') {
			res.Min();
		}
		else if (curr == 'd') {
			res.DeleteMin();
		}
		else if (curr == 'f') {
			int priority;
			string str;
			cin >> priority;
            if(cin.fail()){
                cout << "wrong input" << endl;
                exit(1);
            }
			getline(cin, str);
			Item* a = new Item(priority, str);
			res.Insert(a);
		}
		else if (curr == 'g') {
			res.Median();
		}
		else {
			cout << "wrong input" << endl;
			exit(1);
		}
	}
    cin >> curr; // for enter
    string str;
    getline(cin, str); // check if input is too long
    if(!str.empty()){
        cout << "wrong input" << endl;
        exit(1);
    }
	return 0;
}

