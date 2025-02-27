#include "dioph.h"
#include <iostream>
#include <vector>

using namespace std;

pair<int, vector<int>> gcd_function(int a, int b) {
    vector<int> coef;
    int m, gcd, l;

    if (a > b) {
        m = a;
        gcd = b;
    } else {
        m = b;
        gcd = a;
    }

    int i = 1;
    while (true) {
        l = m % gcd;
        if (l == 0) {
            break;
        } else {
            coef.push_back((m - l) / gcd);
            cout << m << " = " << gcd << " * " << (m - l) / gcd << " + " << l
                 << " q" << i << " = " << (m - l) / gcd << endl;
            m = gcd;
            gcd = l;
            i++;
        }
    }
    cout << m << " = " << gcd << " * " << (m - l) / gcd << " q" << i
         << " = " << (m - l) / gcd << endl;
    cout << "gcd = " << gcd << endl;
    
    return {gcd, coef};
}

pair<int, int> bezu(vector<int> coef) {
    int n = static_cast<int>(coef.size());
    vector<int> u_vec(n + 2, 0), v_vec(n + 2, 0);

    u_vec[0] = 1;
    v_vec[0] = 0;
    u_vec[1] = 0;
    v_vec[1] = 1;

    for (int j = 0; j < n; j++) {
        u_vec[j + 2] = u_vec[j] - coef[j] * u_vec[j + 1];
        v_vec[j + 2] = v_vec[j] - coef[j] * v_vec[j + 1];
    }

    return {u_vec[n + 1], v_vec[n + 1]};
}

void print(int a, int b, int c, int gcd, int u, int v) {
    if (c % gcd == 0) {
        cout << a / gcd << "x + " << b / gcd << "y = " << c / gcd << endl;

        int x0 = (c / gcd) * u;
        int y0 = (c / gcd) * v;

        if (a > b) {
            cout << "gcd = " << a << "*" << u << " + " << b << "*" << v << endl;
            cout << "x0 = " << x0 << endl;
            cout << "y0 = " << y0 << endl;
            cout << "x = " << x0 << " + " << b / gcd << "t" << endl;
            cout << "y = " << y0 << " - " << a / gcd << "t" << endl;
        } else {
            cout << "gcd = " << a << "*" << v << " + " << b << "*" << u << endl;
            cout << "x0 = " << (c / gcd) * v << endl;
            cout << "y0 = " << (c / gcd) * u << endl;
            cout << "x = " << (c / gcd) * v << " + " << b / gcd << "t" << endl;
            cout << "y = " << (c / gcd) * u << " - " << a / gcd << "t" << endl;
        }
    } else {
        cout << c << "!⋮" << gcd << " => No solution exists" << endl;
    }
}

