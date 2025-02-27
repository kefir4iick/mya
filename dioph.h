#ifndef DIOPH_H
#define DIOPH_H

#include <iostream>
#include <vector>
#include <utility> 

std::pair<int, std::vector<int>> gcd_function(int a, int b);
std::pair<int, int> bezu(std::vector<int> coef);
void print(int a, int b, int c, int gcd, int u, int v);

#endif
