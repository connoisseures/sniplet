#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int refill_count(int cap1, int cap2, vector<int>& plants) {
    if (plants.size() == 0) return 0;
    if (plants.size() == 1 && plants[0] <= max(cap1, cap2)) return 1;
    int cnt = 0;
    int i = 0, j = plants.size() - 1;
    int can1 = 0, can2 = 0;
    while (i < j) {
        cout << i << ";" << j << endl;
        //the gardener1 refill the watering can
        if (plants[i] > can1) {
            can1 = cap1;
            cnt++;
        }
        can1 -= plants[i];
        
        //the gardener2 refill the watering can
        if (plants[j] > can2) {
            can2 = cap2;
            cnt++;
        }
        can2 -= plants[j];
        i++;
        j--;
    }
    //when gardener1 and gardener2 meet in the middle
    if (i == j && can1 + can2 < plants[i]) {
        if (max(cap1, cap2) >= plants[i]) {
            cnt++;
        } else if (cap1 + cap2 >= plants[i]) {
            cnt += 2;
        }
    }
    cout << "cnt=" << cnt << endl;
    return cnt;
}

int main() {
    vector<int> plants0 = {5};
    assert(1 == refill_count(5, 7, plants0));
    vector<int> plants = {2,4,5,1,2};
    assert(3 == refill_count(5, 7, plants));
    vector<int> plants2 = {3,7,9,5,1,4,2};
    assert(5 == refill_count(9, 8, plants2));
    vector<int> plants3 = {1,3,5,4,6,5,4,5};
    assert(7 == refill_count(5, 7, plants3)); 
    vector<int> plants4 = {1,3,6,7,6,5,4,5};
    assert(7 == refill_count(5, 7, plants4));
    vector<int> plants5 = {1,1,1,1,1,1,1};
    assert(2 == refill_count(5, 7, plants5)); 
    vector<int> plants6 = {1,1,1,2,2,2};
    assert(2 == refill_count(3, 6, plants6)); 
    vector<int> plants7 = {5,5,5,7,7,7,7};
    assert(7 == refill_count(5, 7, plants7)); 
    vector<int> plants8;
    assert(0 == refill_count(5, 7, plants8)); 
}
