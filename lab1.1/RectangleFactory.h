#pragma once
#include "stdafx.h"
#include "ShapeFactory.h"
#include "ÑShapeDecorator.h"
#include "CRectangleDecorator.h"

class CRectangleFactory : public CShapeFactory
{
public:    
    static CRectangleFactory& GetInstance();
    CShapeDecorator* createDecorator() const override;
    CShapeDecorator* createCertainDecorator(int x1, int y1, int x2, int y2);

private:
    int m_pointA_x = 0;
    int m_pointA_y = 0;
    int m_pointB_x = 0;
    int m_pointB_y = 0;
    CRectangleFactory(const int pointA_x, const int pointA_y, const int pointB_x, const int pointB_y);
    CRectangleFactory() {};
    CRectangleFactory(const CRectangleFactory&) {};
    CRectangleFactory& operator=(CRectangleFactory&) {};
};