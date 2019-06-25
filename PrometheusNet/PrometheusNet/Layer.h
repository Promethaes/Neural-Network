#pragma once
#include "Neuron.h"
#include "Matrix.h"
#include <vector>
class Layer {
public:


	Layer(unsigned SIZE);
	void setValue(unsigned i, float v) { neurons[i]->setValue(v); }
	Matrix* toMatrixValue();
	Matrix* toMatrixActivatedValue();
	Matrix* toMatrixDerivedValue();

private:

	std::vector<Neuron*> neurons;
	unsigned size;

};