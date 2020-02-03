// Link on task -> https://www.codewars.com/kata/5254ca2719453dcc0b00027d/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> permutations(string str) 
{
    vector<string> Permutations;
    sort(str.begin(), str.end());

    do {
        Permutations.emplace_back(str);
    } while (next_permutation(str.begin(), str.end()));

    return Permutations;
}


int main() 
{
    // Test case from Codewars
    auto result = permutations("abcd");

    cout << result.size() << endl;

    for (auto permutation : result)
    {
        cout << permutation << endl;
    }

    return 0;
}