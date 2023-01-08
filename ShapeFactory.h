#pragma once
#include "�ShapeDecorator.h"

class CShapeFactory
{
public:
    virtual ~CShapeFactory() {};
    virtual CShapeDecorator* createDecorator() const = 0;
};