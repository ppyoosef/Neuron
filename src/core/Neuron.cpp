#include "Neuron.h"
#include <random>
#include <cmath>

static double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

Neuron::Neuron(int inputSize) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);
    for (int i = 0; i < inputSize; ++i) weights.push_back(dis(gen));
    bias = dis(gen);
}

double Neuron::feedForward(const std::vector<double>& inputs) {
    double sum = bias;
    for (size_t i = 0; i < weights.size(); ++i) sum += weights[i] * inputs[i];
    output = sigmoid(sum);
    return output;
}

void Neuron::save(std::ofstream& out) {
    int size = weights.size();
    out.write((char*)&size, sizeof(int));
    out.write((char*)weights.data(), sizeof(double) * size);
    out.write((char*)&bias, sizeof(double));
}

void Neuron::load(std::ifstream& in) {
    int size;
    in.read((char*)&size, sizeof(int));
    weights.resize(size);
    in.read((char*)weights.data(), sizeof(double) * size);
    in.read((char*)&bias, sizeof(double));
}