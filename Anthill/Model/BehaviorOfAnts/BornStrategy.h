#pragma once
#include "BaseQueenStrategy.h"

class BornStrategy : public BaseQueenStrategy
{
public:
	BornStrategy(Queen * _queen);
	~BornStrategy();
	void Update(float _deltaTime);
};

