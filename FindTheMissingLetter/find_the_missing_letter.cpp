#include <cassert>

char findMissingLetter(char array[], int arrayLength)
{
    char letter = array[0];
    int i = 0;

    while (letter == array[i])
    {
        i++;
        letter++;
    };

    return letter;
}

int main()
{
    // Test cases from Codewars
    char arr1[] = { 'a','b','c','d','f' };
    char arr2[] = { 'O','Q','R','S' };
    
    assert(findMissingLetter(arr1, 5) == 'e');
    assert(findMissingLetter(arr2, 4) == 'P');

    return 0;
}