// Link on task -> https://www.codewars.com/kata/576757b1df89ecf5bd00073b/cpp

#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> towerBuilder(int nFloors)
{
    vector<string>tower;
    
    int lengthOfStage = 1 + ((nFloors - 1) * 2);
    string floor(lengthOfStage, '*');
    string stage = floor;
    tower.emplace_back(floor);

    for (int i = 0; i < nFloors - 1; i++) {
        stage = stage;
        stage[i] = ' ';
        stage[(lengthOfStage-1) - i] = ' ';
        tower.emplace_back(stage);
    }

    std::reverse(tower.begin(), tower.end());
    return tower;
}


int main()
{
    // For tests 
    auto result = towerBuilder(7);

    for (auto x : result)
        cout << x << endl;
    return 0;
}