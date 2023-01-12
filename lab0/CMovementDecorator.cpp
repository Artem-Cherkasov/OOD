#include "CMovementDecorator.h"

void CMovementDecorator::SetMoved(bool isMoved) {
	m_isMoved = isMoved;
}

bool CMovementDecorator::GetMoved() const {
	return m_isMoved;
}