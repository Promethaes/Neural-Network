#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(const std::vector<int>& TOPOLOGY)
{
	topology = TOPOLOGY;
	for (int i = 0; i < TOPOLOGY.size(); i++) {
		layers.push_back(new Layer(TOPOLOGY[i]));
		errors.push_back(0);
	}

	for (int i = 0; i < TOPOLOGY.size() - 1; i++)
		weightMatrices.push_back(new Matrix(TOPOLOGY[i], TOPOLOGY[i + 1], yes));

}

void NeuralNetwork::setCurrentInput(const std::vector<float>& input)
{
	this->input = input;
	for (int i = 0; i < input.size(); i++)
		layers[0]->setValue(i, input[i]);
}

void NeuralNetwork::setNeuronValue(int indexLayer, int indexNeutron, float v)
{
	layers[indexLayer]->setValue(indexNeutron, v);
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
		std::cout << "================\n";
		if (i < layers.size() - 1) {
			std::cout << "weigh matrix at " << i << "\n";
			weightMatrices[i]->print();
		}
		std::cout << "================\n";
	}
}

void NeuralNetwork::feedForward()
{
	for (int i = 0; i < layers.size() - 1; i++) {
		auto m1 = layers[i]->toMatrixValue();
		if (i > 0)
			m1 = layers[i]->toMatrixActivatedValue();

		auto m2 = weightMatrices[i];
		auto m3 = *m1 * *m2;


		//for (int q = 0; q < layers[i + 1]->getNeurons().size(); q++)
		//	std::cout << q << "\n";
		for (int j = 0; j < m3->columns; j++)
			setNeuronValue(i + 1, j, m3->getValue(0, j));


	}
}

void NeuralNetwork::setErrors()
{
	if (target.empty())
		exit(0);
	if (target.size() != layers.back()->getNeurons().size())
		exit(0);
	error = 0.00f;

	std::vector<Neuron*> outputNeurons = layers.back()->getNeurons();
	for (int i = 0; i < target.size(); i++) {
		float tempError = outputNeurons[i]->getActivatedValue() - target[i];
		errors[i] = tempError;
		error += tempError;
	}
	historicalErrors.push_back(error); 
}
