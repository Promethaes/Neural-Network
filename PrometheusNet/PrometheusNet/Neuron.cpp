#include "Neuron.h"

Neuron::Neuron(float VALUE)
{
	setValue(VALUE);
}

void Neuron::setValue(float VALUE)
{
	value = VALUE;
	activate();
	derive();
}

void Neuron::activate()
{
	activatedValue = value / (1 + ((value < 0) ? value * -1 : value));
}

void Neuron::derive()
{
	derivedValue = activatedValue * (1 - activatedValue);
}
