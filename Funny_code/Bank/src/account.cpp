#include "account.h"

#include <cmath>
#include <iostream>
using namespace std;

double Account::total = 0.0;

Account::Account(int date, int id, double rate)
    : id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
  cout << date << "\t#" << id << " is created" << endl;
}

void Account::record(int date, double amount) {
  accumulation = accumulate(date);
  lastDate = date;
  amount = floor(amount * 100 + 0.5) / 100;
  balance += amount;
  total += amount;
  cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}

void Account::deposit(int date, double amount) { record(date, amount); }

void Account::withdraw(int date, double amount) {
  if (amount > balance) {
    cout << "Error: insufficient funds" << endl;
  } else {
    record(date, -amount);
  }
}

void Account::settle(int date) {
  double interest = accumulate(date) * rate / 365;
  if (interest != 0) {
    record(date, interest);
  }
  accumulation = 0;
  lastDate = date;
}

void Account::show() const {
  cout << "#" << id << "\tBalance: " << balance << endl;
}
