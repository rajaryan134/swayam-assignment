#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

pair<int, int> findmissingnumbers(vector<int>& arr, int n) { //function declare....
    int totalsum = (n + 2) * (n + 3) / 2;
    int totalsqsum = (n + 2) * (n + 3) * (2 * (n + 2) + 1) / 6;//total sum and sq of nt no...

    int arrsum = 0, arrsqsum = 0;
    for (int num : arr) {
        arrsum += num;
        arrsqsum += num * num; //actual sum and sum of sq...
    }

    int sumdiff = totalsum - arrsum;      
    int sqsumdiff = totalsqsum - arrsqsum; //diffference ...

    int product = (sumdiff * sumdiff - sqsumdiff) / 2; //product....

    int discriminant = sqrt(sumdiff * sumdiff - 4 * product);

    int x = (sumdiff + discriminant) / 2; //solve quadratic eq....
    int y = (sumdiff - discriminant) / 2;

    return {x, y};
}

int main() {
    vector<int> arr = {1, 2, 4, 6, 3, 8};
    int n = arr.size();

    pair<int, int> result = findmissingnumbers(arr, n);
    cout << result.first << " " << result.second << endl;

    return 0;
}
