#pragma once
#include <vector>
#include "Matrix.h"
#include "Layer.h"
class NeuralNetwork {
public:
	NeuralNetwork(const std::vector<int>& TOPOLOGY);
	void setCurrentInput(const std::vector<float>& input);
	void setCurrentTarget(const std::vector<float>& TARGET) { target = TARGET; }
	void setNeuronValue(int indexLayer, int indexNeutron, float v);
	void print();
	void feedForward();
	void setErrors();
	void backPropagation();

	std::vector<Layer*> getLayers() const { return layers; }
	float getTotalError() const { return error; }
private:
	std::vector<int> topology;
	std::vector<float> input;
	std::vector<Layer*>layers;
	std::vector<Matrix*> weightMatrices;
	std::vector<Matrix*> gradientMatrices; 
	float error;
	std::vector<float> errors;
	std::vector<float> historicalErrors;
	std::vector<float> target;
};