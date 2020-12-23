#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;



int main() {
    vector<string> list2 {
        "16",
        "32",
        "40",
        "48",
        "56",
        "72",
        "80",
        "96"
    };
    vector<string> list8 {
    "112",
    "128",
    "136",
    "144",
    "152",
    "168",
    "176",
    "184",
    "192",
    "216",
    "224",
    "232",
    "248",
    "256",
    "264",
    "272",
    "288",
    "296",
    "312",
    "328",
    "336",
    "344",
    "352",
    "368",
    "376",
    "384",
    "392",
    "416",
    "424",
    "432",
    "448",
    "456",
    "464",
    "472",
    "480",
    "488",
    "496",
    "512",
    "528",
    "536",
    "544",
    "552",
    "568",
    "576",
    "584",
    "592",
    "616",
    "624",
    "632",
    "648",
    "656",
    "664",
    "672",
    "688",
    "696",
    "712",
    "728",
    "736",
    "744",
    "752",
    "768",
    "776",
    "784",
    "792",
    "816",
    "824",
    "832",
    "848",
    "856",
    "864",
    "872",
    "888",
    "896",
    "912",
    "928",
    "936",
    "944",
    "952",
    "968",
    "976",
    "984",
    "992"
    };
    for (auto& v : list8) {
        sort(v.begin(), v.end());
    }
    sort(list8.begin(), list8.end());
    list8.erase(unique(list8.begin(), list8.end()), list8.end());
    string S;
    cin >> S;
    if (S.size() == 1) {
        if (S == "8"){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (S.size() == 2) {
        for (const auto& v : list2) {
            auto ss = S;
            int find = ss.find(v[0]);
            if (find != std::string::npos) {
                ss.erase(find,1);
                find = ss.find(v[1]);
                if (find != std::string::npos) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    for (const auto& v : list8) {
        auto ss = S;
        int find = ss.find(v[0]);
        if (find != std::string::npos) {
            ss.erase(find,1);
            find = ss.find(v[1]);
            if (find != std::string::npos) {
                ss.erase(find,1);
                find = ss.find(v[2]);
                if (find != std::string::npos) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}