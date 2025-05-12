#include "Layer.h"

Layer::Layer(int size, int inputSizePerNeuron) {
    for (int i = 0; i < size; ++i)
        neurons.emplace_back(inputSizePerNeuron);
}

std::vector<double> Layer::feedForward(const std::vector<double>& inputs) {
    std::vector<double> outputs;
    for (auto& neuron : neurons) outputs.push_back(neuron.feedForward(inputs));
    return outputs;
}

void Layer::save(std::ofstream& out) {
    for (auto& neuron : neurons) neuron.save(out);
}

void Layer::load(std::ifstream& in) {
    for (auto& neuron : neurons) neuron.load(in);
}
