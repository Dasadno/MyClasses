#ifndef VECTOR_PROCESSING_STRATEGY_HPP
#define VECTOR_PROCESSING_STRATEGY_HPP
#include "Vector.hpp"

class VectorProcessingStrategy {
public:
    virtual ~VectorProcessingStrategy() = default;

    virtual void process(Vector& v1, Vector& v2) const = 0;

};



#endif // !VECTOR_PROCESSING_STRATEGY_HPP