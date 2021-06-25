#include <iostream>
using namespace std;

class Resourse{
public:
    virtual void useResourse() = 0;
};

class RealResourse : public  Resourse{
private:
public:
    explicit RealResourse(const string &resourseName);
    void useResourse() override;

private:
    string resourseName{};
    void loadResourseFromDisc();
};
RealResourse::RealResourse(const string &resourseName) : resourseName(resourseName) {
    this->loadResourseFromDisc();
}
void RealResourse::loadResourseFromDisc() {
    cout << "zaladowanie zasobu " + this->resourseName + "\n";
}
void RealResourse::useResourse() {
    cout << "uzycie zasobu " + this->resourseName + "\n";
}

class Proxy : public Resourse{
public:
    explicit Proxy(string resourseName);
    void useResourse() override;
private:
    string resourseName{};
    RealResourse * realResourse{};
};
Proxy::Proxy(string resourseName) : resourseName(std::move(resourseName)) {}
void Proxy::useResourse() {
    if (this->realResourse == nullptr){
        cout << "stworzono obiekt RealSourse\n";
        this->realResourse = new RealResourse(this->resourseName);
    }
    this->realResourse->useResourse();
}




int main() {
    Resourse * resourse = new Proxy("plik.txt");
    resourse->useResourse();
    resourse->useResourse();
    return 0;
}
