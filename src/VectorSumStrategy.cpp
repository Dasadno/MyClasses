#include "../hd/VectorSumStrategy.hpp"

void VectorSumStrategy::process(Vector& v1, Vector& v2) const {
    Vector result = v1 + v2;
    std::cout << "Vector sum: " << result;
}