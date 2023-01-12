#pragma once

class CShapeDecorator;

class Visitor
{
public:
    virtual void Visit(CShapeDecorator* shape)const = 0;
};