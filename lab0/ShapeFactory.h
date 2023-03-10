#pragma once
#include "ŃShapeDecorator.h"

class CShapeFactory
{
public:
    virtual ~CShapeFactory() {};
    virtual CShapeDecorator* createDecorator() const = 0;
};