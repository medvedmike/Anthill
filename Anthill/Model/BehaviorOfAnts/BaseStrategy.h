#pragma once
class BaseStrategy
{
public:
	virtual void Update(float _deltaTime) = 0;
	BaseStrategy();
	virtual ~BaseStrategy();
};

