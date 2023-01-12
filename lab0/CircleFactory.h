#pragma once
#include "stdafx.h"
#include "ShapeFactory.h"
#include "ÑShapeDecorator.h"
#include "CCircleDecorator.h"

class CCircleFactory : public CShapeFactory
{
public:
    CCircleFactory(const int x, const int y, const int r);

    CShapeDecorator* createDecorator() const override;

private:
    int m_x = 0;
    int m_y = 0;
    int m_r= 0;
};