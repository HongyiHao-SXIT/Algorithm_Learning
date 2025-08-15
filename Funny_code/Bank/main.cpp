#include "account.h"
#include <iostream>
using namespace std;

int main() {
    SavingsAccount sa0(1, 21325302, 0.015);
    SavingsAccount sa1(1, 58310212, 0.015);

    sa0.deposit(5, 5000);
    sa1.deposit(10, 10000);
    sa0.withdraw(20, 2000);
    sa1.withdraw(25, 500);

    sa0.settle(365);
    sa1.settle(365);

    sa0.show();
    sa1.show();

    cout << "Total: " << SavingsAccount::getTotal() << endl;

    return 0;
}
