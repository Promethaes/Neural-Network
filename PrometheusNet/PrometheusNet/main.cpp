#include "Neuron.h"
#include "Matrix.h"
#include "NeuralNetwork.h"

bool check(std::vector<Layer*>& l1, std::vector<Layer*>&l2);
int main() {
	//Neuron* n = new Neuron(1.5f);
	//
	//std::cout << "Value: " << n->getValue() << "\n";
	//std::cout << "Activated Value: " << n->getActivatedValue() << "\n";
	//std::cout << "DerivedValue: " << n->getDerivedValue() << "\n";

	//Matrix* m = new Matrix(3, 2, yes);
	//m->print();
	//
	//Matrix* mT = m->transpose();
	//mT->print();

	std::vector<int>topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(3);

	std::vector<float> input;
	input.push_back(1.0f);
	input.push_back(0.0f);
	input.push_back(1.0f);




	NeuralNetwork network = NeuralNetwork(topology);
	network.setCurrentInput(input);
	network.setCurrentTarget(input);

	float lastError = 0;
	//training proccess
	for (int i = 0; i < 1000000; i++) {
		std::cout << "Training Counter: " << i << "\n";
		network.feedForward();

		network.setErrors();
		if (i > 0 && network.getTotalError() - lastError < 0)
			std::cout << "???\n";
		//	network.print();
		std::cout << "Total Error: " << network.getTotalError() << "\n";
		network.backPropagation();
		lastError = network.getTotalError();
	}













	system("pause");
	return 0;
}

bool check(std::vector<Layer*>& l1, std::vector<Layer*>& l2)
{
	//for (int i = 0; i < l1.size(); i++) {
	//	for (int j = 0; j < l2.size(); j++) {
	//		if(l1[i]->getNeurons()[0])
	//	}
	//}
	//
	return false;
}
