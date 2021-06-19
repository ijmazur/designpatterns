#include <iostream>
#include <vector>

using namespace std;

class Strategy {
public:
    virtual void AlgorithmInterface() = 0;
protected:
    vector<int> numbers;
    int n;
};

class SortowanieA : public Strategy {
public:
    SortowanieA(vector<int> numbers, int n);
    void bubblesort(vector<int> &numbers, int n);
    void AlgorithmInterface();
private:
    vector<int> numbers;
};

SortowanieA::SortowanieA(vector<int> numbers, int n) {
    this->numbers = numbers;
    this->n = n;
}

void SortowanieA::bubblesort(vector<int> &numbers, int n) {
    int tmp;
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (numbers[j] > numbers[j+1]) {
                tmp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = tmp;
            }
}

void SortowanieA::AlgorithmInterface() {
    bubblesort(numbers, n);
    for (int i = 0; i < 7; i++){
        cout << numbers[i] << " ";
    }
    cout << endl;
}

class SortowanieB : public Strategy {
public:
    SortowanieB(vector<int> numbers, int n);
    void insertionsort(vector<int> &numbers, int n);
    void AlgorithmInterface();
private:
    vector<int> numbers;
};

SortowanieB::SortowanieB(vector<int> numbers, int n) {
    this->numbers = numbers;
    this->n = n;
}

void SortowanieB::insertionsort(vector<int> &numbers, int n) {
    int i, key, j;
    for (i = 1; i < n; i++){
        key = numbers[i];
        j = i - 1;
        while (j >= 0 && numbers[j] > key){
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }
}

void SortowanieB::AlgorithmInterface() {
    insertionsort(numbers, n);
    for (int i = 0; i < 7; i++){
        cout << numbers[i] << " ";
    }
    cout << endl;
}

class Context {
public:
    void ContextInterface();
    void setStrategy(int option, vector<int> numbers, int n);
private:
    Strategy *strategy;
};

void Context::ContextInterface() {
    this->strategy->AlgorithmInterface();
}

void Context::setStrategy(int option, vector<int> numbers, int n) {
    if(option == 1) this->strategy = new SortowanieA(numbers, n);
    else if (option == 2) this->strategy = new SortowanieB(numbers, n);
}

int main() {
    vector<int> numbers = vector<int>({2, 5, 1, 3, 6, 9, 8, 7});
    int n = 7;
    int option;
    cout << "Jakiego sortowania chcesz uzyc? babelkowe(1), insertsort(2): " << endl;
    cin >> option;

    Context *sortowanie = new Context;
    sortowanie->setStrategy(option, numbers, n);
    sortowanie->ContextInterface();
    return 0;
}
