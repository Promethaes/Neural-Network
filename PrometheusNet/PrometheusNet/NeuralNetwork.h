#pragma once
#include <vector>
#include "Matrix.h"
#include "Layer.h"
class NeuralNetwork {
public:
	NeuralNetwork(const std::vector<int>& TOPOLOGY);
	void setCurrentInput(const std::vector<float>& input);
	void setNeuronValue(int indexLayer, int indexNeutron, float v);
	void print();
	void feedForward();
private:
	std::vector<int> topology;
	std::vector<float> input;
	std::vector<Layer*>layers;
	std::vector<Matrix*> weightMatrices;

};