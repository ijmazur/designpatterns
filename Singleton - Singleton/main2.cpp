#include <iostream>
#include <fstream>
using namespace std;

class Backlogs {
public:
    Backlogs(const Backlogs &) = delete;
    void save(string message);
    static Backlogs &get(){
        return logs;
    };
private:
    Backlogs logs;
    ofstream file;
    Backlogs();
    ~Backlogs();
    Backlogs *instance;
};

void Backlogs::save(string message) {
    file << message;
}

Backlogs::Backlogs() {
    file.open("logs.txt");
}

Backlogs::~Backlogs() {
    file.close();
}

Backlogs Backlogs::instance;

class Binance {
public:
    float btc_price;
    float doge_price;
    void buy_btc(float amount);
    void buy_doge(float amount);
    void sell_doge(float amount);
    void sell_btc(float amount);
};

void Binance::buy_btc(float amount) {
    Backlogs::get().save("User bought ");
    Backlogs::get().save(to_string(amount));
    Backlogs::get().save(" BTC at ");
    Backlogs::get().save(to_string(btc_price));
    Backlogs::get().save("\n");
}

void Binance::buy_doge(float amount) {
    Backlogs::get().save("User bought ");
    Backlogs::get().save(to_string(amount));
    Backlogs::get().save(" DOGE at ");
    Backlogs::get().save(to_string(doge_price));
    Backlogs::get().save("\n");
}

void Binance::sell_doge(float amount) {
    Backlogs::get().save("User sold ");
    Backlogs::get().save(to_string(amount));
    Backlogs::get().save(" DOGE at ");
    Backlogs::get().save(to_string(doge_price));
    Backlogs::get().save("\n");
}

void Binance::sell_btc(float amount) {
    Backlogs::get().save("User sold ");
    Backlogs::get().save(to_string(amount));
    Backlogs::get().save(" DOGE at ");
    Backlogs::get().save(to_string(doge_price));
    Backlogs::get().save("\n");
}

int main(){
    Binance user;
    user.doge_price = 0.2948;
    user.btc_price = 36331.53;
    user.buy_btc(2);
    user.buy_doge(13042);
    user.sell_btc(0.5);
    return 0;
}