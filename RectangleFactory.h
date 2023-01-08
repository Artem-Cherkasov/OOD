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
    CShapeDecorator* createCertainDecorator(int a_x, int a_y, int b_x, int b_y);
    ~CRectangleFactory() { std::cout << "abc"; };

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