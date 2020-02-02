// Link on task -> https://www.codewars.com/kata/517abf86da9663f1d2000003/cpp

#include <iostream>
#include <string>
using namespace std;

string to_camel_case(string text) {
	string convertedText;
	bool isNeedToUpper = false;
	char converted_letter;

	for (auto letter : text) {
		converted_letter = letter;
		if (letter == '-' || letter == '_') {
			isNeedToUpper = true;
		} else {
			if (isNeedToUpper) {
				converted_letter = toupper(converted_letter);
				isNeedToUpper = false;
			} 
			convertedText.push_back(converted_letter);
		}
	}

	return convertedText;
}

int main()
{
	// Test cases from Codewars
	string expected_result = "theStealthWarrior";
	string result = to_camel_case("the-stealth-warrior");
	cout << "Case 1 -> " << (expected_result._Equal(result) ? "passed" : "error") << endl;


	expected_result = "TheStealthWarrior";
	result = to_camel_case("The_Stealth_Warrior");
	cout << "Case 2 -> " << (expected_result._Equal(result) ? "passed" : "error") << endl;
	
	return 0;
}