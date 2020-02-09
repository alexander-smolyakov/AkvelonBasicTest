// Link on task -> https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1/

#include <vector>
#include <iostream>
using namespace std;

vector<int> snail(vector<vector<int>> snail_map) 
{
    if (snail_map[0].size() <= 0) 
        return {};

    size_t n = snail_map.size();
    vector<int> path(n*n, 0);

    int x = 0, y = 0;
    int x_step = 1, y_step = 0;

    for (int i = 0; i < path.size(); ++i)
    {
        path[i] = snail_map[y][x];
        snail_map[y][x] = -1;
        
        x += x_step;
        y += y_step;

        if (x_step != 0 && (x < 0 || x >= n || snail_map[y][x] == -1))
        {
            x += -x_step;
            y += x_step;
            y_step = x_step;
            x_step = 0;
        }
        else if (y_step != 0 && (y < 0 || y >= n || snail_map[y][x] == -1))
        {
            x += -y_step; 
            y += -y_step;
            x_step = -y_step; 
            y_step = 0;
        }
    }

    return path;
}


int main()
{
    vector<vector<int>> input; 
    vector<int> expected_result;
    vector<int> result;

    // Test cases from Codewars
    input = { {} };
    expected_result = {};
    result = snail(input);
    cout << boolalpha << "Test 1 -> " << ((equal(result.begin(), result.end(), expected_result.begin(), expected_result.end())) ? "passed" : "error") << endl;

    input = { {1} };
    expected_result = { 1 };
    result = snail(input);
    cout << boolalpha << "Test 2 -> " << ((equal(result.begin(), result.end(), expected_result.begin(), expected_result.end())) ? "passed" : "error") << endl;
    
    input = { {1,2}, {4,3} };
    expected_result = { 1,2,3,4 };
    result = snail(input);
    cout << boolalpha << "Test 3 -> " << ((equal(result.begin(), result.end(), expected_result.begin(), expected_result.end())) ? "passed" : "error") << endl;

    input = { {1,2,3}, {8,9,4}, {7,6,5} };
    expected_result = { 1,2,3,4,5,6,7,8,9 };
    result = snail(input);
    cout << boolalpha << "Test 4 -> " << ((equal(result.begin(), result.end(), expected_result.begin(), expected_result.end())) ? "passed" : "error") << endl;

    input = { {1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7} };
    expected_result = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    result = snail(input);
    cout << boolalpha << "Test 5 -> " << ((equal(result.begin(), result.end(), expected_result.begin(), expected_result.end())) ? "passed" : "error") << endl;

	return 0;
}