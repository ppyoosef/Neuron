#include "src/core/NeuralNetwork.h"
#include <iostream>

int main() {
    NeuralNetwork nn;
    std::vector<std::vector<double>> inputs = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    std::vector<std::vector<double>> targets = {{0}, {1}, {1}, {0}};

    std::cout << "Select option: \n1. Train and Save Model\n2. Load and Predict\n> ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        nn.train(inputs, targets, 100000, 0.5);
        nn.saveModel("xor_model.bin");
        std::cout << "Model trained and saved.\n";
    } else if (choice == 2) {
        nn.loadModel("xor_model.bin");
        for (auto& input : inputs) {
            auto output = nn.feedForward(input);
            std::cout << input[0] << " XOR " << input[1] << " = " << output[0] << std::endl;
        }
    }

    return 0;
}