#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <fstream>

class Neuron {
public:
    std::vector<double> weights;
    double bias;
    double output;
    double delta;

    Neuron(int inputSize);
    double feedForward(const std::vector<double>& inputs);
    void save(std::ofstream& out);
    void load(std::ifstream& in);
};

#endif