#ifndef NN_H
#define NN_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Sigmoid activation and derivative
double sigmoid(double x);
double sigmoid_derivative(double x);

class Neuron {
private:
    double input[2];
    double hidden[2];
    double output;

    double weights_input_hidden[2][2];
    double weights_hidden_output[2];
    double bias_hidden[2];
    double bias_output;

    double learning_rate = 0.5;

public:
    Neuron();
    static double rand_weight();

    double train(const double in[2], double target);
    double predict(const double in[2]);
};

#endif // NN_H
