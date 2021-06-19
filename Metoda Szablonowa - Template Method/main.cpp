#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Sorting {
public:
    void sorting(vector <int> &vec);
    virtual int compare(int a, int b) = 0;
};

void Sorting::sorting(vector <int> &vec) {
    for (int i = 0; i < vec.size() - 1; i++){
       int min = i;
       for(int j = i + 1; j < vec.size(); j++){
           if (compare(vec[j], vec[min])) min = j;
       }
       swap(vec[min], vec[i]);
    }
}

class Smallest : public Sorting {
public:
    int compare(int a, int b);
};

int Smallest::compare(int a, int b) {
    return b>a;
}

class Biggest : public Sorting {
public:
    int compare(int a, int b);
};

int Biggest::compare(int a, int b) {
    return b < a;
}

int main() {
    vector<int> vec = {24, 7, 13, 37, 69, 42, 0, 11, 15, 9, 2, 3};
    cout << "Wektor wyjsciowy:" << endl;
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << '\t';

    Smallest* smallest = new Smallest();
    smallest->sorting(vec);
    cout << '\n' << "Posortowany rosnaco:" << endl;
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << '\t';

    Biggest* biggest = new Biggest();
    biggest->sorting(vec);
    cout << '\n' << "Posortowany malejaco:" << endl;
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << '\t';
    return 0;
}
