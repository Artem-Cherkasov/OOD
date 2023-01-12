#pragma once
#include "stdafx.h"
#include "ShapeFactory.h"
#include "ÑShapeDecorator.h"
#include "CCircleDecorator.h"

class CCircleFactory : public CShapeFactory
{
public:

    static CCircleFactory& GetInstance();
    CShapeDecorator* createDecorator() const override;
    CShapeDecorator* createCertainDecorator(int x, int y, int r);

private:
    int m_x = 0;
    int m_y = 0;
    int m_r= 0;
    CCircleFactory(const int x, const int y, const int r);
    CCircleFactory() {};
    CCircleFactory(const CCircleFactory&) {};
    CCircleFactory& operator=(CCircleFactory&) {};
};