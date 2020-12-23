#include <bits/stdc++.h>
using namespace std;

class Coord {
public:
    Coord(double x, double y) : _x(x), _y(y) {}
    Coord(const Coord& other) = default;
    Coord(Coord&& other) = default;
    Coord& operator=(const Coord& other) {
        if (this == &other) {
            return *this;
        }
        _x = other._x;
        _y = other._y;
        return *this;
    }
    bool operator==(const Coord& other) const {
        return _x == other._x && _y == other._y;
    }

    double _x;
    double _y;
};

Coord operator+(const Coord& p, const Coord& q) {
    return Coord(p._x + q._x, p._y + q._y);
}
Coord operator-(const Coord& p, const Coord& q) {
    return Coord(p._x - q._x, p._y - q._y);
}
double operator*(const Coord& p, const Coord& q) {
    return p._x * q._x + p._y * q._y;
}
Coord operator*(double k, const Coord& p) {
    return Coord(k * p._x, k * p._y);
}
double norm(const Coord& p) {
    return sqrt(p * p);
}
bool compare(const Coord& p, const Coord& q) {
    return p._x < q._x;
}

void koch(
    const Coord& p1,
    const Coord& p2,
    vector<Coord>& result,
    int current, int last) 
{
    result.push_back(p1);
    result.push_back(p2);
    if (current == last) {
        return;
    }
    Coord p12 = p2 - p1;
    Coord p3 = p1 + 1./3 * p12;
    koch(p1, p3, result, current+1, last);
    Coord p4 = p1 + 2./3 * p12;
    koch(p4, p2, result, current+1, last);
    Coord vertical = Coord(-p12._y, p12._x);
    double x = norm(vertical);
    vertical = (1./x) * vertical;
    x = norm(vertical);
    Coord p5 = 0.5 * (p1 + p2) + norm(p12)/6.0 * sqrt(3.0) * vertical;
    koch(p3, p5, result, current+1, last);
    koch(p5, p4, result, current+1, last);
}

int main() {
    int n;
    cin >> n;

    size_t max_size = pow(5, n);
    vector<Coord> result;
    result.reserve(max_size);
    Coord p1(0,0);
    Coord p2(100, 0);
    koch(p1, p2, result, 0, n);
    sort(result.begin(), result.end(), compare);
    auto last = unique(result.begin(), result.end());
    result.erase(last, result.end());
    for (const auto& v : result) {
        cout << setprecision(11) << v._x << " " << v._y << endl;
    }
}