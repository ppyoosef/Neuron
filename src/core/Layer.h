#ifndef LAYER_H
#define LAYER_H

#include "Neuron.h"
#include <vector>

class Layer {
public:
    std::vector<Neuron> neurons;

    Layer(int size, int inputSizePerNeuron);
    std::vector<double> feedForward(const std::vector<double>& inputs);
    void save(std::ofstream& out);
    void load(std::ifstream& in);
};

#endif
