// Link on task -> https://www.codewars.com/kata/5541f58a944b85ce6d00006a
#include <vector>
#include <iostream>
using namespace std;

typedef unsigned long long ull;

static vector<ull> productFib(ull prod)
{
    ull prev = 0;
    ull curr = 1;
    ull multiplied = prev * curr;

    while (multiplied < prod) {
        ull temp = curr;
        curr += prev;
        prev = temp;
        multiplied = prev * curr;
    }

    vector<ull> result;
    result = { prev, curr, ull(multiplied == prod ? 1 : 0)};

    return result;
}

int main()
{
    vector<ull> result;
    vector<ull> expected_result;

    // Test cases from Codewars
    result = productFib(4895);
    expected_result = { 55, 89, true };
    cout << "Test 1 -> " << boolalpha  << equal(result.begin(), result.end(), expected_result.begin(), expected_result.end()) << endl;

    result = productFib(5895);
    expected_result = { 89, 144, false };
    cout << "Test 2 -> " << boolalpha << equal(result.begin(), result.end(), expected_result.begin(), expected_result.end()) << endl;

    result = productFib(74049690);
    expected_result = { 6765, 10946, 1ULL };
    cout << "Test 3 -> " << boolalpha << equal(result.begin(), result.end(), expected_result.begin(), expected_result.end()) << endl;

    result = productFib(84049690);
    expected_result = { 10946, 17711, 0ULL };
    cout << "Test 4 -> " << boolalpha << equal(result.begin(), result.end(), expected_result.begin(), expected_result.end()) << endl;

    return 0;
}

