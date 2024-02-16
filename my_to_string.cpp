#include <iostream>
#include <cmath>
#include <set>
#include <string>
#define ll long long
#define el '\n'
using namespace std;

long long my_str_to_num(string s) {
    long long res = 0;

    for (int i = 0; i < s.size(); i++) {
        res += (s[i] - '0') * pow(10, s.size() - i - 1);
    }

    return res;
}

ll count_digits(ll num) { // there is a better way using log
    ll digits = 1; // at least 1

    for (ll i = 1, j = 1; i <= num; i *=  10) {
        //cnt++;

        if (i / pow(10, j) >= 1) { // reach 10 -> 2 digits, 100 -> 3 digits
            digits++;
            j++;
        }
    }

    return digits;
}

string my_to_string(ll num) {
    string res = "";
    ll play = num;
    if (num == 0) {
        return "0";
    }

    if (num < 0) {
        num *= -1;
        res.push_back('-');
    }

    ll digits = (ll)log10(num) + 1LL; // using log to count digits
    for (int i = digits; i >= 1; i--) {
        res.push_back('0' + num % (int)pow(10, i) / pow(10, i - 1));
    }

    return res;
}

int main() {
    ll num;
    cin >> num;
    cout << my_to_string(num) << '\n' << my_to_string(num).size();
    //cout << (ll)log10(num) + 1LL;

    return 0;
}