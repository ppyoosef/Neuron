#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "Layer.h"
#include <string>

class NeuralNetwork {
public:
    Layer hidden;
    Layer output;

    NeuralNetwork();
    std::vector<double> feedForward(const std::vector<double>& inputs);
    void train(const std::vector<std::vector<double>>& inputs,
               const std::vector<std::vector<double>>& targets,
               int epochs, double lr);
    void saveModel(const std::string& filename);
    void loadModel(const std::string& filename);
};

#endif