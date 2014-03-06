#pragma once
#include "BaseStrategy.h"
#include "..\Objects\Ants\Queen.h"
class BaseQueenStrategy : public BaseStrategy
{
protected:
	Queen * queen;
public:
	BaseQueenStrategy(Queen * _queen);
	~BaseQueenStrategy();
};

