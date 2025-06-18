#ifndef VECTOR_SUM_STRATEGY_HPP
#define VECTOR_SUM_STRATEGY_HPP
#include "VectorProcessingStrategy.hpp"

class VectorSumStrategy : public VectorProcessingStrategy {
public:
    void process(Vector& v1, Vector& v2) const override;
};

#endif // !VECTOR_SUM_STRATEGY_HPP
