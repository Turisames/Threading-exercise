#ifndef SOLARIANTUTORIAL_HH
#define SOLARIANTUTORIAL_HH

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void helloWorld();
void launchedFromThread( int i );
void dot_product_nonparallel(const std::vector<int> &v1,
                             const std::vector<int> &v2,
                             int &result, int L, int R);
void dot_product(const std::vector<int> &v1,
                 const std::vector<int> &v2,
                 int &result, int L, int R);
void program_itself();

#endif // SOLARIANTUTORIAL_HH
