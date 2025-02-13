#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v(4,3);
    cout << v.capacity() << endl;
    cout << v.size() << endl;
    cout << v[2] << endl;
    return 0;
}