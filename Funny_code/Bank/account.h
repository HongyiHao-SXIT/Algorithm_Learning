#ifndef _ _ACCOUNT_H_ _
#define _ _ACCOUNT_H_ _
class SavingsAccount{
    private:
    int id;
    double balance;
    double rate;
    int lastDate;
    double accumulation;

    static double total;

    void record(int date, double amount);

    double accumulate(int date) const{
        return accumulation + balance * (date - lastDate);
    }

    public:
    SavingsAccount(int date, int id, double rate);
    int getId() const{return id;}
    double getBalance() const{return balance;}
    static double getTotal(){return total;}
    void deposit(int date, double amount);
    void withdraw(int date, double amount);

    void settle(int date);

    void show() const;

};

#endif _ _ACCOUNT_H_ _
