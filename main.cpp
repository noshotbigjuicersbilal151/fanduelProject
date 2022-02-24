#include <iostream>
#include <string>
#include <Team.h>
using namespace std;
string enterDate(){
	string date;
	cout << "Please enter date in MMDDYYYY format: " << endl;
	cin >> date;
	
return date;
}

int main(int argc, char* argv[])
{
cout << "Welcome to our Daily Fantasy Best Lineup Retriever Tool" << endl;

String date = enterDate();

return 0;
}
