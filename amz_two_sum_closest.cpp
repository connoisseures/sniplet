#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
using namespace std;

vector<double> two_sum_closest_small_than_target(vector<double> num, double target) {
    sort(num.begin(), num.end());
    int left = 0, right = num.size() - 1;
    vector<double> res = {num[left], num[right]};
    while (left < right) {
        if (target > num[left] + num[right]) {
            left++;
        } else {
            right--;
        }
        if (num[left] + num[right] <= target && res[0] + res[1] < num[left] + num[right]) {
            res[0] = num[left];
            res[1] = num[right];
        }
    }
    return res;
}

double two_sum_closest(vector<double> num, double target) {
    sort(num.begin(), num.end());
    int left = 0, right = num.size() - 1;
    double diff = target - num[left] - num[right];
    while (left < right) {
        diff = min(diff, target - num[left] - num[right]);
        if (target > num[left] + num[right]) {
            //diff = min(diff, target - num[left] - num[right]);
            left++;
        } else {
            //diff = min(diff, target - num[left] - num[right]);
            right--;
        }
    } 
    return diff;
}

void show_arr(vector<double> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
}

int main(int argc, char *argv[]) {
    vector<double> num = {-1.1, 2.1, 1.1, -4.1};
    double target = 4.1;
    double diff = two_sum_closest(num, target);
    cout << "smallest diff: " << diff << endl;
    vector<double> num1 = {-1.1, 2.1, 3.0, 1.1, -4.1};
    vector<double> res = two_sum_closest_small_than_target(num1, target);
    cout << "closet pair: ";  
    show_arr(res);
    

}
