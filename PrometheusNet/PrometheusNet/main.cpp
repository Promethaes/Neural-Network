#include "Neuron.h"
#include "Matrix.h"
#include "NeuralNetwork.h"
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
		   
	network.print();

	//Matrix m1(3, 2, yes);
	//Matrix m2(2, 3, yes);
	//
	//auto m3 = m1 * m2;

	system("pause");
	return 0;
}