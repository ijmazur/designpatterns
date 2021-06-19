#include <iostream>
using namespace std;

class Strategy {
public:
    virtual void AlgorithmInterface() = 0;
protected:
    double interest;
    double credit;
};

class Frank : public Strategy {
public:
    Frank(double interest, double credit);
    void AlgorithmInterface();
private:
    double convert;
    double final;
};

Frank::Frank(double interest, double credit) {
    this->interest = interest;
    this->credit = credit;
    this->convert = 4.09;   // 8/6/21
    this->final = (this->credit + (this->credit * (this->interest/100)));
}

void Frank::AlgorithmInterface() {
    cout << "Dzisiejszy kurs 1CHF = " << this->convert << "PLN" << endl;
    cout << "Kredyt: " << this->credit << "CHF, po naliczeniu uprocenotwania, wynosi: " << this->final << "CHF, po przewalutowaniu " << this->final * this->convert << "PLN";
}

class Euro : public Strategy {
public:
    Euro(double interest, double credit);
    void AlgorithmInterface();
private:
    double convert;
    double final;
};

Euro::Euro(double interest, double credit) {
    this->interest = interest;
    this->credit = credit;
    this->convert = 4.47;   // 8/6/21
    this->final = (this->credit + (this->credit * (this->interest/100)));
}

void Euro::AlgorithmInterface() {
    cout << "Dzisiejszy kurs 1EUR = " << this->convert << "PLN" << endl;
    cout << "Kredyt: " << this->credit << "EUR, po naliczeniu uprocenotwania, wynosi: " << this->final << "EUR, po przewalutowaniu " << this->final * this->convert << "PLN";
}

class Zloty : public Strategy {
public:
    Zloty(double interest, double credit);
    void AlgorithmInterface();
private:
    double convert;
    double final;
};

Zloty::Zloty(double interest, double credit) {
    this->interest = interest;
    this->credit = credit;
    this->convert = 1.0;
    this->final = (this->credit + (this->credit * (this->interest/100)));
}

void Zloty::AlgorithmInterface() {
    cout << "Kredyt: " << this->credit << "PLN, po naliczeniu oprocentowania, wynosi: " << this->final << "PLN";
}

class Dolar : public Strategy {
public:
    Dolar(double interest, double credit);
    void AlgorithmInterface();
private:
    double convert;
    double final;
};

Dolar::Dolar(double interest, double credit) {
    this->interest = interest;
    this->credit = credit;
    this->convert = 3.67;   // 8/6/21
    this->final = (this->credit + (this->credit * (this->interest/100)));
}

void Dolar::AlgorithmInterface() {
    cout << "Dzisiejszy kurs 1USD = " << this->convert << "PLN" << endl;
    cout << "Kredyt: " << this->credit << "USD, po naliczeniu uprocenotwania, wynosi: " << this->final << "USD, po przewalutowaniu " << this->final * this->convert << "PLN";
}

class NaliczanieOprocentowania {
public:
    void ContextInterface();
    void setStrategy(int option, double interest, double amount);
    Strategy *strategy;
};

void NaliczanieOprocentowania::ContextInterface() {
    this->strategy->AlgorithmInterface();
}

void NaliczanieOprocentowania::setStrategy(int option, double interest, double credit) {
    if(option == 1) this->strategy = new Frank(interest, credit);
    else if (option == 2) this->strategy = new Euro(interest, credit);
    else if (option == 3) this->strategy = new Zloty(interest, credit);
    else if (option == 4) this->strategy = new Dolar(interest, credit);
    else cout << "bad input, try again" << endl;
}

int main() {
    double interest, credit;
    int option;
    cout << "Prosze podac kwote kredytu: " << endl;
    cin >> credit;
    cout << "Prosze podac kwote oprocentowania do obliczenia kredytu" << endl;
    cin >> interest;
    cout << "W jakiej walucie jest brany kredyt? Frank(1), Euro(2), Zloty(3), Dolar(4): " << endl;
    cin >> option;

    NaliczanieOprocentowania *oprocentowanie = new NaliczanieOprocentowania;
    oprocentowanie->setStrategy(option, interest, credit);
    oprocentowanie->ContextInterface();
    return 0;
}
