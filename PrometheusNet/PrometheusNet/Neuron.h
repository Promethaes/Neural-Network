#pragma once
#include <iostream>
class Neuron {
public:


	Neuron(float VALUE);

	void setValue(float VALUE);

	//fast sigmoid function
	//f(x) = x/1 +(1 + |x|)
	void activate();
	//derivative of this function is
	//f'(x)= f(x) * (1-f(x))
	void derive();

	float getValue() const { return value; }
	float getActivatedValue() const{ return activatedValue; }
	float getDerivedValue() const { return derivedValue; }


private:
	float value;
	float activatedValue;
	float derivedValue;

};