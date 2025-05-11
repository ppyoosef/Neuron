
#include "src/core/Neuron.h"
#include <iostream>
using namespace std;

int main() {
    Neuron nn;

    // XOR dataset
    double data[4][2] = {{0,0},{0,1},{1,0},{1,1}};
    double labels[4] = {0, 1, 1, 0};

    // Train
    for (int epoch = 0; epoch < 10000; ++epoch) {
        double loss = 0;
        for (int i = 0; i < 4; ++i) {
            loss += nn.train(data[i], labels[i]);
        }
        if (epoch % 500 == 0) {
            cout << "Epoch " << epoch << ", Loss: " << loss << endl;
        }
    }

    // Test
    for (int i = 0; i < 4; ++i) {
        double pred = nn.predict(data[i]);
        cout << "Input: " << data[i][0] << ", " << data[i][1] << " => Predicted: " << pred << endl;
    }

    return 0;
}