#pragma once
#include "ÑShapeDecorator.h"
#include "stdafx.h"

class DescriptionGetterVisitor : public Visitor
{
public:
    DescriptionGetterVisitor(std::ofstream& output);

    void Visit(CShapeDecorator* shape)const override;

private:
    std::ofstream& m_ofstream;
};