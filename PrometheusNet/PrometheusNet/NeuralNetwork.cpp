#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(std::vector<int> TOPOLOGY)
{
	topology = TOPOLOGY;
	for (int i = 0; i < TOPOLOGY.size(); i++) 
		layers.push_back(new Layer(TOPOLOGY[i]));

	for (int i = 0; i < TOPOLOGY.size() - 1; i++)
		weightMatrices.push_back(new Matrix(TOPOLOGY[i],TOPOLOGY[i]+1,yes));
}

void NeuralNetwork::setCurrentInput(std::vector<float> input)
{
	this->input = input;
	for (int i = 0; i < input.size(); i++)
		layers[0]->setValue(i, input[i]);
}

void NeuralNetwork::print()
{
	for (int i = 0; i < layers.size(); i++) {
		if (not i) {
			Matrix* m = layers[i]->toMatrixValue();
			m->print();
		}
		else {
			Matrix* m = layers[i]->toMatrixActivatedValue();
			m->print();
		}
		
	}
}
