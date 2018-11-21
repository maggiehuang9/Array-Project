#include <iostream>
#include <string>
#include <cassert>
	using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);
int main()
{
	string a[6] = { "Maggie", "Esther", "Katherine", "Jasmine", "Lise", "Katherine" };
	assert(lookup(a, 5, "Esther") == 1); //when target is in array
	assert(lookup(a, -1, "Esther") == -1); //negative array size
	assert(lookup(a, 5, "Katherine") == 2); //there is more than one string
	assert(lookup(a, 2, "Katherine") == -1); //when target is not in the array
	assert(lookup(a, 2, "katherine") == -1); //case is different
	assert(lookup(a, 0, "katherine") == -1); //array is size 0

	string b[5] = { "cat", "dog", "rabbit", "mouse", "rabbit" };
	assert(appendToAll(b, 4, "?") == 4 && b[0] == "cat?" && b[3] == "mouse?");//check to see if question mark is appended
	assert(appendToAll(b, -4, "?") == -1); //negative array size
	assert(positionOfMax(b, 4) == 2); //check positionOfMax works
	assert(positionOfMax(b, -4) == -1); //negative array size
	assert(positionOfMax(b, 5) == 2); //more than one string that's max string
	assert(positionOfMax(b, 1) == 0); //one string only
	assert(positionOfMax(b, 0) == -1); //array with no interesting elements
	string c[5] = { };

	string d[4] = { "one", "two", "three", "four" };
	assert(rotateLeft(d, 4, 1) == 1 && d[1] == "three" && d[2] == "four" && d[3] == "two"); //check rotateLeft works
	assert(rotateLeft(d, -4, 1) == -1); //negative array size
	assert(rotateLeft(d, 4, -1) == -1); //negative position size
	string m[2] = { "cat", "dog" };
	assert(rotateLeft(m, 2, 1) == 1 && m[0] == "cat" && m[1] == "dog"); //when there's only two elements
	assert(rotateLeft(d, 0, 1) == -1); //when n is less than pos
	assert(rotateLeft(d, 0, 0) == -1); //when n is equal to pos

	assert(countRuns(d, 4) == 4); //countRuns when every element is different
	string e[4] = { "one", "one", "two", "three" };
	assert(countRuns(e, 4) == 3); //countRuns when there is multiple of the same item
	assert(countRuns(e, -4) == -1); //negative array size
	assert(countRuns(c, 0) == 0); //when there's no elements
	assert(countRuns(c, 5) == 1); //when there's an empty string

	assert(flip(e, 4) == 4 && e[0] == "three" && e[3] == "one"); //flip with even amount of elements
	assert(flip(b, 5) == 5 && b[0] == "rabbit" && b[2] == "rabbit?" && b[4] == "cat?"); //flip with odd amount of elements
	assert(flip(e, 1) == 1 && e[0] == "three"); //only one element
	assert(flip(e, -4) == -1); //negative array size
	assert(flip(e, 0) == 0); //array size is 0

	string f[4] = { "hello", "hi", "hola", "hey" };
	string g[5] = { "hello", "hi", "wassup", "hola", "hey" };
	assert(differ(f, 4, g, 5) == 2); //an element in first array is not equal to an element in second array
	assert(differ(f, -4, g, 5) == -1); //negative array size
	string h[5] = { "hello", "hi", "hola", "hey", "wassup" };
	assert(differ(f, 4, h, 5) == 4);//elements are equal until one runs out
	assert(differ(f, 4, h, 4) == 4);//elements are equal until both run out
	assert(differ(f, 0, h, 4) == 0);//one array is of size 0
	assert(differ(f, 0, h, 0) == 0);//both arrays are of size 0

	assert(subsequence(f, 4, g, 2) == 0);//all n2 elements of a2 are in a1
	assert(subsequence(f, 4, g, 4) == -1);//not all n2 elements of a2 are in a1
	assert(subsequence(f, 4, g, -2) == -1);//negative array size
	assert(subsequence(f, 4, g, 5) == -1);//n2 is bigger than n1
	assert(subsequence(f, 4, g, 0) == 0);//a2 is a sequence of 0 elements
	assert(subsequence(f, 0, g, 0) == 0);//a2 and a1 are sequences of 0 elements
	assert(subsequence(f, 0, g, 5) == -1);//a1 is a sequence of 0 elements
	string i[2] = { "hi", "hello" };
	assert(subsequence(f, 4, i, 2) == -1);//all n2 elements of a2 are in a1 but in different order

	string j[8] = { "hello", "there", "i", "am", "maggie", "huang", "maggie" };
	string k[3] = { "abc", "def", "maggie" };
	assert(lookupAny(j, 6, k, 3) == 4);//element in a2 is in a1
	assert(lookupAny(j, 8, k, 3) == 4);//multiple elements in a2 are in a1
	assert(lookupAny(j, -6, k, 3) == -1);//negative array size
	assert(lookupAny(j, 6, k, 2) == -1);//element in a2 is not in a1
	k[2] = "Maggie";
	assert(lookupAny(j, 6, k, 3) == -1); //case is different
	assert(lookupAny(j, 0, k, 3) == -1); //there's an array of size 0
	assert(lookupAny(j, 0, k, 0) == -1); //both arrays of size 0


	string l[8] = { "a", "h", "c", "i", "f", "e", "d", "b" };
	string z[10] = { "1", "2", "7", "8", "6", "4", "3", "6", "4", "5" };
	assert(divide(l, 8, "d") == 3);//divider is in array
	assert(divide(l, -8, "d") == -1);//negative array size
	assert(divide(l, 8, "x") == 8);//no element is greater than divider
	assert(divide(l, 8, "h") == 6);//check divider works
	assert(divide(z, 10, "6") == 6 && z[6] == "6");
	assert(divide(l, 0, "h") == 0); //array of size 0

	cerr << "All tests succeeded" << endl;
}

int appendToAll(string a[], int n, string value)
{
	if (n < 0)//if n is negative
		return -1;
	else
	{
		for (int i = 0; i != n; i++)//appends value to all the elements up to n in the array
		{

			a[i] += value;
		}
		return n;
	}

}

int lookup(const string a[], int n, string target)
{
	if (n < 0)//if n is negative
		return -1;
	for (int i = 0; i != n; i++)//finds the first element that is equal to target
	{
		if (a[i] == target)
			return i;
	}
	return -1;//no element found
}

int positionOfMax(const string a[], int n)
{
	if (n <= 0)//if n is negative or has no interesting elements
		return -1;
	string max = a[0];
	int position = 0;  // initialize to zero
	for (int i = 1; i != n; i++)
	{
		if (a[i] > max)//the current element is larger than the previous maximum
		{
			max = a[i];//set maximum to current element
			position = i;//set position to position number of current greatest element
		}
	}
	return position;
}

int rotateLeft(string a[], int n, int pos)
{
	if (n < 0 || pos < 0 || n <= pos)//if n or pos is negative
		return -1;
	string temp = a[pos];//save element in pos into temp
	for (int i = pos; i != n - 1; i++)
	{
		a[i] = a[i + 1];//moves every element to the left
	}
	a[n - 1] = temp;//switches element at pos with last element
	return pos;//return position
}

int countRuns(const string a[], int n)
{
	if (n < 0) //if n is negative
		return -1;
	else if (n == 0) // check n==0
		return 0;

	int count = 1;
	for (int i = 0; i != n - 1; i++)
	{
		if (a[i] != a[i + 1])//if the element is not the same as the element after it, it's the end of that sequence
			count++;
	}
	return count;
}

int flip(string a[], int n)
{
	if (n < 0) //if n is negative
		return -1;
	string temp;
	for (int i = 0; i != n / 2; i++)
	{
		temp = a[i]; //save element in temp
		a[i] = a[n - i - 1]; //save last half of string into corresponding first half of string
		a[n - i - 1] = temp;//save first half of string into corresponding last half of string
	}
	return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0) //if n1 or n2 is negative
		return -1;
	int size;
	//find size of bigger array
	if (n1 < n2)
		size = n1;
	else if (n2 < n1)
		size = n2;
	else
		size = n1; //sizes are the same so just save it to n1
	for (int i = 0; i != size; i++)
	{
		if (a1[i] != a2[i])//corresponding elements are not equal
			return i;
	}
	return size;
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0) //if n1 or n2 is negative
		return -1;
	if (n2 == 0) //sequence of zero elements
		return 0;
	int count = 0;
	int j = 0;
	for (int i = 0; i != n1; i++)
	{
		while (j != n2)
		{
			if (a1[i] != a2[j])//element of a2 not equal to element of a1
			{
				count = 0;
				j = 0;
				break;//break to go to next element of a1
			}

			else
			{
				count++;
				j++;//check the next element of a2 to element of a1
				break;
			}
		}
		if (count == n2) //all elements of a2 were found in a1 in the correct order
			return i - n2 + 1; //position in a1 where subsequence begins
	}
	return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0) //if n1 or n2 is negative
		return -1;
	for (int i = 0; i != n1; i++)//check elements of a1
	{
		for (int j = 0; j != n2; j++)//check all the elements of a2 to the element of a1
		{
			if (a1[i] == a2[j])//element of a1 is equal to element of a2
				return i;
		}
	}
	return -1;
}

int divide(string a[], int n, string divider)
{
	if (n < 0)//if n is negative
		return -1;

	// move all the elements < divider to the front
	for (int i = 0; i != n; i++) {
		if (a[i] >= divider) //elements greater than or equal to divider, move to the end
		{
			for (int j = i + 1; j < n; j++) {
				if (a[j] < divider) {
					string temp = a[j];
					a[j] = a[i];
					a[i] = temp;
					break;
				}
			}
		}
	}

	int pos = n;  // initialize the position n first

	for (int i = 0; i != n; i++)
	{
		if (a[i] >= divider)
		{
			pos = i;
			break;
		}
	}

	// now move all the elements > divider to the back
	for (int i = pos; i < n; i++) {
		if (a[i] > divider) //elements greater than divider, move to the back
		{
			for (int j = i + 1; j < n; j++) {
				if (a[j] == divider) {
					string temp = a[j];
					a[j] = a[i];
					a[i] = temp;
					break;
				}
			}
		}
	}

	return pos;
}
