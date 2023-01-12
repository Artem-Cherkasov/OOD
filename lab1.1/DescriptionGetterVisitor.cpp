#include "DescriptionGetterVisitor.h"

DescriptionGetterVisitor::DescriptionGetterVisitor(std::ofstream& output)
    :m_ofstream(output)
{
}

void DescriptionGetterVisitor::Visit(CShapeDecorator* shape)const
{
    m_ofstream << shape->GetDescription() << std::endl;
}