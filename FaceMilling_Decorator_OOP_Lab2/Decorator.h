#pragma once

#include "IFaceMilling.h"

class Decorator : public IFaceMilling {
	IFaceMilling* faceMill;
public:
	Decorator(IFaceMilling* faceMill) : faceMill(faceMill) {};

	virtual void mill() = 0;
};