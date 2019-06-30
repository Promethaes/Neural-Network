#include "NeuralNetwork.h"
#include <algorithm>
NeuralNetwork::NeuralNetwork(const std::vector<int>& TOPOLOGY)
{
	topology = TOPOLOGY;
	for (int i = 0; i < TOPOLOGY.size(); i++) 
		layers.push_back(new Layer(TOPOLOGY[i]));
	

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
		Matrix* m1;
		if (i > 0)
			m1 = layers[i]->toMatrixActivatedValue();
		else
			m1 = layers[i]->toMatrixValue();

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

void NeuralNetwork::backPropagation()
{
	//output layer to hidden layer
	auto derivedValuesYtoZ = *layers.back()->toMatrixDerivedValue();
	auto gradientsYtoZ = Matrix(1, layers.back()->getNeurons().size(), no);

	for (int i = 0; i < errors.size(); i++)
		gradientsYtoZ.setValue(0, i, derivedValuesYtoZ.getValue(0, i)*errors[i]);

	Layer lastHiddenlayer = *layers[layers.size() - 2];



	//create and transpose a matrix
	Matrix deltaOutputToHidden = gradientsYtoZ.transpose() *= *lastHiddenlayer.toMatrixActivatedValue();
	deltaOutputToHidden = deltaOutputToHidden.transpose();


	std::vector<Matrix*> newWeights;
	newWeights.push_back(new Matrix((*weightMatrices[layers.size() - 2] - deltaOutputToHidden).transpose()));
	auto gradient = gradientsYtoZ;

	//std::cout << "Output to Hiden New Weights\n";
	//newWeights.back()->print();

	//-----------------------------------------//
	//-----------------------------------------//
	//-----------------------------------------//
	//-----------------------------------------//
	//-----------------------------------------//
	//-----------------------------------------//
	//-----------------------------------------//



	//from last hidden layer down to hidden layer
	for (int i = layers.size() - 2; i > 0; i--) {
		auto derivedGradients = Matrix(1, layers[i]->getNeurons().size(), false);

		for (int j = 0; j < weightMatrices[i]->getRowsorColumns(0); j++) {
			float sum = 0;
			for (int k = 0; k < weightMatrices[i]->getRowsorColumns(1); k++) {
				auto p = gradient.getValue(0, k) * weightMatrices[i]->getValue(j, k);
				sum += p;
			}
			derivedGradients.setValue(0, j, sum*layers[i]->toMatrixActivatedValue()->getValue(0, j));
		}
		auto leftNeurons = (i - 1) ? *layers[0]->toMatrixValue() : *layers[i - 1]->toMatrixActivatedValue();

		gradient = derivedGradients;

		//(new Matrix(*weightMatrices[i - 1] - (derivedGradients.transpose()*leftNeurons)->transpose()))
		//(new Matrix(*weightMatrices[i - 1] - (derivedGradients.transpose()*leftNeurons)->transpose()))
		auto s = Matrix(*weightMatrices[i - 1] - (derivedGradients.transpose()*leftNeurons)->transpose());
		newWeights.push_back(new Matrix(s.transpose()));
	}



	//std::reverse(newWeights.begin(), newWeights.end());
	weightMatrices = newWeights;






}
