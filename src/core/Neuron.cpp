#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Neuron.h"

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x) {
    return x * (1.0 - x);  // x is already sigmoid(x)
}

Neuron::Neuron() {
    srand(time(0));
    for (int i = 0; i < 2; ++i) {
        bias_hidden[i] = rand_weight();
        weights_hidden_output[i] = rand_weight();
        for (int j = 0; j < 2; ++j) {
            weights_input_hidden[j][i] = rand_weight();
        }
    }
    bias_output = rand_weight();
}

double Neuron::rand_weight() {
    return ((double) rand() / RAND_MAX) * 2 - 1;
}

double Neuron::train(const double in[2], double target) {
    for (int i = 0; i < 2; ++i) {
        hidden[i] = 0;
        for (int j = 0; j < 2; ++j) {
            hidden[i] += in[j] * weights_input_hidden[j][i];
        }
        hidden[i] += bias_hidden[i];
        hidden[i] = sigmoid(hidden[i]);
    }

    output = 0;
    for (int i = 0; i < 2; ++i) {
        output += hidden[i] * weights_hidden_output[i];
    }
    output += bias_output;
    output = sigmoid(output);

    double error = target - output;
    double d_output = error * sigmoid_derivative(output);

    for (int i = 0; i < 2; ++i) {
        double d_hidden = d_output * weights_hidden_output[i] * sigmoid_derivative(hidden[i]);

        weights_hidden_output[i] += learning_rate * d_output * hidden[i];
        for (int j = 0; j < 2; ++j) {
            weights_input_hidden[j][i] += learning_rate * d_hidden * in[j];
        }
        bias_hidden[i] += learning_rate * d_hidden;
    }

    bias_output += learning_rate * d_output;

    return error * error;
}

double Neuron::predict(const double in[2]) {
    for (int i = 0; i < 2; ++i) {
        hidden[i] = 0;
        for (int j = 0; j < 2; ++j) {
            hidden[i] += in[j] * weights_input_hidden[j][i];
        }
        hidden[i] += bias_hidden[i];
        hidden[i] = sigmoid(hidden[i]);
    }

    output = 0;
    for (int i = 0; i < 2; ++i) {
        output += hidden[i] * weights_hidden_output[i];
    }
    output += bias_output;
    return sigmoid(output);
}

