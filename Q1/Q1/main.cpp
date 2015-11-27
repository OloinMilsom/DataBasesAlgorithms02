// I declare that the work I am submitting for assessing by the Institute examiner(s) is entirely my own
// work, save for any portion(s) thereof where the author or source has been duly referenced and
// attributed.
// Signed: Niall Milsom (C00179300)

#include <vector>
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>
void printVector(vector<T> vec);

template<typename T>
void checkPalindrome(vector<T> vec);

int main() {
	// empty vector of ints
	vector<int> emptyVecInt;
	printVector(emptyVecInt);

	// vector with three random ints
	vector<int> randVecInt;
	srand(time(0));
	for (int i = 0; i < 3; i++)
	{
		randVecInt.push_back(rand() % 100);
	}
	printVector(randVecInt);

	// vector with 3 empty strings
	vector<string> emptyVecString(3,"");
	printVector(emptyVecString);

	// vector with three specified values
	vector<int> specificVecInt;
	specificVecInt.push_back(23);
	specificVecInt.push_back(42);
	specificVecInt.push_back(76);
	printVector(specificVecInt);

	// copy of a vector
	vector<int> copyVecInt;
	copyVecInt = specificVecInt;
	printVector(copyVecInt);

	// vector with its first and last elements changed
	vector<int>::iterator first = copyVecInt.begin();
	vector<int>::iterator last = copyVecInt.end();
	*first = 76;
	*(last - 1) = 23;
	printVector(copyVecInt);

	// vector with reduced size
	copyVecInt.resize(2);
	printVector(copyVecInt);

	// vector with increased size
	copyVecInt.resize(3);
	printVector(copyVecInt);

	// vector with back element added
	copyVecInt.push_back(12);
	printVector(copyVecInt);

	// vector with back element removed
	copyVecInt.pop_back();
	printVector(copyVecInt);

	// vector with all its elements removed
	copyVecInt.clear();
	printVector(copyVecInt);

	// maximum size of a specified vector
	cout << copyVecInt.max_size() << endl;

	// vectors with their contents swapped
	copyVecInt.swap(specificVecInt);
	printVector(copyVecInt);

	// test if contents of a vector are a palindrome
	checkPalindrome(copyVecInt);
	vector<int> palindrome;
	for (int i = 0; i < 5; i++)
	{
		palindrome.push_back(1 - (i % 2));
	}
	checkPalindrome(palindrome);

	system("PAUSE");
}

template<typename T>
void printVector(vector<T> vec){
	cout << "{ ";
	for (vector<T>::iterator curr = vec.begin(); curr < vec.end(); curr++)
	{
		cout << *curr;
		if (curr < vec.end() - 1){
			cout << ", ";
		}
	}
	cout << " }" << endl;
}

template<typename T>
void checkPalindrome(vector<T> vec){
	vector<T> temp = vec;
	reverse(temp.begin(), temp.end());
	if (vec == temp)
	{
		cout << "Is a Palindrome: ";
	}
	else
	{
		cout << "Not a Palindrome: ";
	}
	printVector(vec);
}