#pragma once
#include "ÑShapeDecorator.h"

class CShapeFactory
{
public:
    virtual ~CShapeFactory() {};
    virtual CShapeDecorator* createDecorator() const = 0;
};