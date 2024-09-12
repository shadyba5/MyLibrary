#include <iostream>
#include <math.h>
#include <vector>



using namespace std;



bool isPrime(int x) {
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}


vector<vector<int>> function(int n) {
    vector<int> arr1;
    vector<int> arr2;

    vector<vector<int>> res;


    for (int i = 0; i <= n; i++) {
        if (isPrime(i)) {
            arr1.push_back(i);
        }
    }

    int pow = 2;
    while (pow <= n) {
        arr2.push_back(pow);
        pow *= 2;
    }

    res.push_back(arr1);
    res.push_back(arr2);


    return res;
}


int main()
{
    int n=20;
    vector<vector<int>> res = function(n);
    

    for (int i = 0; i < res[0].size(); i++) {
        cout << res[0][i] << ",";
    }
    cout << endl;
    for (int i = 0; i < res[1].size(); i++) {
        cout << res[1][i] << ",";
    }

    return 0;
}





