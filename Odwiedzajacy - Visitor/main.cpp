#include <iostream>
#include <vector>
using namespace std;

class Bmw;
class Volvo;
class Driver {
public:
    virtual void visit(Bmw* bmw) = 0;
    virtual void visit(Volvo* volvo) = 0;
};

class Car {
public:
    virtual void accept(Driver* driver) = 0;
};

class Bmw : public Car {
public:
    void lutututu();
    void accept(Driver* driver);
};

void Bmw::lutututu() {
    cout << "Wsiadam do fury lututut, stawiam bokiem. A ze psy sie patrza z boku na fure to mam ich tam gdzie prokurature" << endl;
}

void Bmw::accept(Driver* driver) {
    driver->visit(this);
}

class Volvo : public Car {
public:
    void prostokatBokiem();
    void accept(Driver* driver);
};

void Volvo::prostokatBokiem() {
    cout << "tutaj noga w podlodze i to nie pierwszy raz kiedy stawiam prostokat bokiem" << endl;
}

void Volvo::accept(Driver* driver) {
    driver->visit(this);
}

class Visitator : public Driver {
public:
    void visit(Bmw* bmw);
    void visit(Volvo* volvo);
};

void Visitator::visit(Bmw* bmw) {
    bmw->lutututu();
}

void Visitator::visit(Volvo* volvo) {
    volvo->prostokatBokiem();
}

int main() {
    Driver* austin = new Visitator();
    vector<Car*> cars = {new Bmw(), new Volvo(), new Bmw(), new Volvo()};
    for(int i = 0; i < cars.size(); i++) cars[i]->accept(austin);
    return 0;
}



//asd