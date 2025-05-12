#include "NeuralNetwork.h"
#include <fstream>
#include <cmath>

static double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

static double sigmoid_derivative(double x) {
    double s = sigmoid(x);
    return s * (1 - s);
}

NeuralNetwork::NeuralNetwork() : hidden(2, 2), output(1, 2) {}

std::vector<double> NeuralNetwork::feedForward(const std::vector<double>& inputs) {
    auto hiddenOut = hidden.feedForward(inputs);
    return output.feedForward(hiddenOut);
}

void NeuralNetwork::train(const std::vector<std::vector<double>>& inputs,
                          const std::vector<std::vector<double>>& targets,
                          int epochs, double lr) {
    for (int epoch = 0; epoch < epochs; ++epoch) {
        for (size_t i = 0; i < inputs.size(); ++i) {
            auto hiddenOut = hidden.feedForward(inputs[i]);
            auto finalOut = output.feedForward(hiddenOut);

            for (size_t j = 0; j < output.neurons.size(); ++j) {
                double error = targets[i][j] - finalOut[j];
                // output.neurons[j].delta = error * sigmoid_derivative(finalOut[j]);
                output.neurons[j].delta = error * finalOut[j] * (1 - finalOut[j]);
            }

            for (size_t j = 0; j < hidden.neurons.size(); ++j) {
                double error = 0.0;
                for (auto& outNeuron : output.neurons)
                    error += outNeuron.delta * outNeuron.weights[j];
                // hidden.neurons[j].delta = error * sigmoid_derivative(hiddenOut[j]);
                hidden.neurons[j].delta = error * hiddenOut[j] * (1 - hiddenOut[j]);

            }

            for (auto& neuron : output.neurons) {
                for (size_t k = 0; k < neuron.weights.size(); ++k)
                    neuron.weights[k] += lr * neuron.delta * hiddenOut[k];
                neuron.bias += lr * neuron.delta;
            }

            for (auto& neuron : hidden.neurons) {
                for (size_t k = 0; k < neuron.weights.size(); ++k)
                    neuron.weights[k] += lr * neuron.delta * inputs[i][k];
                neuron.bias += lr * neuron.delta;
            }
        }
    }
}

void NeuralNetwork::saveModel(const std::string& filename) {
    std::ofstream out(filename, std::ios::binary);
    hidden.save(out);
    output.save(out);
    out.close();
}

void NeuralNetwork::loadModel(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    hidden.load(in);
    output.load(in);
    in.close();
}
