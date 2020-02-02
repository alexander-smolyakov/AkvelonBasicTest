// Link on task -> https://www.codewars.com/kata/54b42f9314d9229fd6000d9c/cpp

#include <string>
#include <unordered_set>
#include <cassert>
using namespace std;

string duplicate_encoder(const string& word) {
    unordered_set<char> singleLetters;
    unordered_set<char> repeatedLetters;
    string encodedWord;

    for (auto letter : word)
    {
        auto letterLowerCase = tolower(letter);

        if (singleLetters.find(letterLowerCase) == singleLetters.end()) {
            singleLetters.insert(letterLowerCase);
        }
        else {
            repeatedLetters.insert(letterLowerCase);
        }
    }

    for (auto letter : word)
    {
        auto letterLowerCase = tolower(letter);

        if (repeatedLetters.find(letterLowerCase) == repeatedLetters.end()) {
            encodedWord.push_back('(');
        }
        else {
            encodedWord.push_back(')');
        }
    }

    return encodedWord;
}

int main()
{
    // Test case from Codewars
    assert(duplicate_encoder("din") == "(((");
    assert(duplicate_encoder("recede") == "()()()");
    assert(duplicate_encoder("Supralapsarian") == ")()))()))))()(");

    return 0;
}