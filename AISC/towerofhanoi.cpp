#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char helper, char destination) {
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, source, destination, helper);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, helper, source, destination);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}

 // A -> source rod
 // B -> helper rod
// C -> destination rod