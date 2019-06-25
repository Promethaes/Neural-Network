#include "Layer.h"

Layer::Layer(unsigned SIZE)
{
	for (int i = 0; i < SIZE; i++)
		neurons.push_back(new Neuron(0.00f));
	size = SIZE;
}

Matrix * Layer::toMatrixValue()
{
	Matrix* m = new Matrix(1, neurons.size(), false);
	for (int i = 0; i < neurons.size(); i++)
		m->setValue(0, i, neurons[i]->getValue());

	return m;
}

Matrix * Layer::toMatrixActivatedValue()
{
	Matrix* m = new Matrix(1, neurons.size(), false);
	for (int i = 0; i < neurons.size(); i++)
		m->setValue(0, i, neurons[i]->getActivatedValue());

	return m;
}

Matrix * Layer::toMatrixDerivedValue()
{
	Matrix* m = new Matrix(1, neurons.size(), false);
	for (int i = 0; i < neurons.size(); i++) 
		m->setValue(0, i, neurons[i]->getDerivedValue());
	
	return m;
}
