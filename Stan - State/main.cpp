#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <unistd.h>

using namespace std;

class Computer;
class ConcreteStateOFF;
class ConcreteStateON;
class ConcretestateHIBER;
class State {
public:
    virtual void on(Computer* computer) { cout << "Computer is ON" << endl; };
    virtual void off(Computer* computer) { cout << "Computer is OFF" << endl; };
    virtual void hiber(Computer* computer) { cout << "Computer is SLEEPING (Hibernation Mode)" << endl; };
};

class Computer {
public:
    void on();
    void off();
    void hiber();
    void setState(State* state);
private:
    State* state;
};


void Computer::on() {
    state->on(this);
}

void Computer::off() {
    state->off(this);
}

void Computer::hiber() {
    state->hiber(this);
}

void Computer::setState(State* state) {
    this->state = state;
}

class ConcreteStateON : public State {
public:
    void off(Computer* computer);
    void hiber(Computer* computer);
};

void ConcreteStateON::off(Computer* computer) {
    cout << "Computer is turning OFF" << endl;
    delete this;
}

void ConcreteStateON::hiber(Computer* computer) {
    cout << "Computer is SLEEPING (Hibernation Mode)" << endl;
    //for(int i = 0; i<10; i++) cout << "sleeping " << i << endl;
    do{
        cout << "Podaj nowa wartosc aby kontynuowac..." << endl;
    } while (cin.get() != '\n');
}

class ConcreteStateOFF : public State {
public:
    void on(Computer* computer);
    void hiber(Computer* computer);
};

void ConcreteStateOFF::on(Computer* computer) {
    cout << "Computer is turning ON" << endl;
    computer->setState(new ConcreteStateON());
}

void ConcreteStateOFF::hiber(Computer* computer) {
    cout << "Computer is SLEEPING (Hibernation Mode)" << endl;
    //for(int i = 0; i<10; i++) cout << "sleeping " << i << endl;
    do{
        cout  << "Podaj nowa wartosc aby kontynuowac..." << endl;
    } while (cin.get() != '\n');
}

class ConcreteStateHIBER : public State {
public:
    void on(Computer* computer);
    void off(Computer* computer);
};

void ConcreteStateHIBER::on(Computer* computer) {
    cout << "Computer is turning ON" << endl;
    computer->setState(new ConcreteStateON());
}

void ConcreteStateHIBER::off(Computer* computer) {
    cout << "Computer is turning OFF" << endl;
    delete this;
}

int main() {
    Computer* computer;
    computer->setState(new ConcreteStateOFF());
    int state = 0;
    cout << "prosze podac stan OFF(0), HIBER(2), cokolwiek innego - ON" << endl;

    for(int i = 0; i < 10000; i++){
        cin >> state;
        if(state == 0) computer->off();
        if(state == 2) computer->hiber();
        else computer->on();
    }
    return 0;
}