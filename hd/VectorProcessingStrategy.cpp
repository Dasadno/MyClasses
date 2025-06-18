#ifndef VECTOR_PROCESSING_STRATEGY_HPP
#define VECTOR_PROCESSING_STRATEGY_HPP
#include "Vector2D.hpp"

class VectorProcessingStrategy {
public:
    virtual ~VectorProcessingStrategy() = default;

    virtual void process(Vector2D& v1, Vector2D& v2) const = 0;

};



#endif // !VECTOR_PROCESSING_STRATEGY_HPP