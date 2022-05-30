// C++ code to demonstrate the calculation 
// in parent and its 3 child processes using fork() 
#include <iostream> 
#include <unistd.h> 

using namespace std; 

int main() 
{ 

	int a[10] = { 2, 4, 6, 7, 9, 0, 1, 5, 8, 3 }; 
	int n1, n2, i, j, key, c, temp; 
	n1 = fork(); 
	n2 = fork(); 

	// if n1 is greater than zero 
	// and n2 is greater than zero 
	// then parent process executes 
	if (n1 > 0 && n2 > 0) { 

		int c = 0; 
		cout << "Parent process :" << endl; 

		// key to be searched is 7 
		key = 7; 
		cout << "the key to be searched is " << key << endl; 

		for (i = 0; i < 10; i++) { 

			if (a[i] == key) 
				// frequency of key 
				c++; 
		} 

		cout << "the frequency of " << key << " is " << c << endl; 
	} 

	// else if n1 is zero 
	// and n2 is greater than zero 
	// then 1st child process executes 
	else if (n1 == 0 && n2 > 0) { 

		cout << "1st child process :" << endl; 

		for (i = 0; i < 10; i++) { 

			for (j = 0; j < 9; j++) { 

				if (a[j] > a[j + 1]) { 

					temp = a[j]; 
					a[j] = a[j + 1]; 
					a[j + 1] = temp; 
				} 
			} 
		} 

		cout << "the sorted array is" << endl; 

		for (i = 0; i < 10; i++) { 

			cout << a[i] << " "; 
		} 

		cout << endl; 
	} 

	// else if n1 is greater than zero 
	// and n2 is zero 
	// then 2nd child process executes 
	else if (n1 > 0 && n2 == 0) { 

		int f = 0; 
		cout << "2nd child process :" << endl; 

		for (i = 0; i < 10; i++) { 

			// counting total even numbers 
			if (a[i] % 2 == 0) { 

				f++; 
			} 
		} 

		cout << " Total even no are: " << f << " "; 
		cout << endl; 
	} 

	// else if n1 is zero 
	// and n2 is zero 
	// then 3rd child process executes 
	else if (n1 == 0 && n2 == 0) { 

		cout << "3rd child process :" << endl; 

		int sum = 0; 
		// summing all given keys 
		for (i = 0; i < 10; i++) { 

			sum = sum + a[i]; 
		} 

		cout << "the sum is :" << sum << endl; 
	} 

	return 0; 
} 

