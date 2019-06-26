#pragma once
#include <vector>
#include "Matrix.h"
#include "Layer.h"
class NeuralNetwork {
public:
	NeuralNetwork(std::vector<int> TOPOLOGY);
	void setCurrentInput(std::vector<float> input);
	void print();
private:
	std::vector<int> topology;
	std::vector<float> input;
	std::vector<Layer>layers;
	std::vector<Matrix> weightMatrices;

};