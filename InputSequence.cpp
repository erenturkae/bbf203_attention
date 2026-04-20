    #include "InputSequence.h"
    #include <iostream>

    using namespace std;

    InputSequence::InputSequence(const string& seqName)
        : name{ seqName } {
        // Hardcoded dummy input embeddings (2 tokens, 4 dimensions each)
        double initData[SEQ_LEN][D_EMB] {
            {1.0, 0.5, -0.1, 0.2},
            {-0.2, 1.2, 0.4, -0.5}
        };

        //TODO: Initialize the data array with the hardcoded values
        for (int i = 0; i < SEQ_LEN; i++) {
            for (int j = 0; j < D_EMB; j++) {
                data[i][j] = initData[i][j];
            }
        }
    }

    //TODO: Implement Destructor and getValue method
    InputSequence::~InputSequence() {}

    double InputSequence::getValue(int row, int col) const {
        return data[row][col];
    }
