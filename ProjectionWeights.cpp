#include "ProjectionWeights.h"
#include "InputSequence.h"
#include <iostream>

using namespace std;

//TODO: Implement Constructor, Copy Constructor, Destructor
ProjectionWeights::ProjectionWeights(double seed) {
    for (int i = 0; i < D_EMB; i++) {
        for (int j = 0; j < D_K; j++) {
            W_q[i][j] = seed * 0.1 + (i * 0.05) - (j * 0.02);
            W_k[i][j] = seed * -0.1 + (j * 0.05);
            W_v[i][j] = seed * 0.2 - (i * 0.01) + (j * 0.03);
        }
    }
}

ProjectionWeights::ProjectionWeights(const ProjectionWeights& other) {
    for (int i = 0; i < D_EMB; i++) {
        for (int j = 0; j < D_K; j++) {
            W_q[i][j] = other.W_q[i][j];
            W_k[i][j] = other.W_k[i][j];
            W_v[i][j] = other.W_v[i][j];
        }
    }
}

ProjectionWeights::~ProjectionWeights() {}


//TODO Implement getQ(), getK(), getV() methods using the project() method
void ProjectionWeights::getQ(const InputSequence* input, double Q[SEQ_LEN][D_K]) const {
    project(input, W_q, Q);
}

void ProjectionWeights::getK(const InputSequence* input, double K[SEQ_LEN][D_K]) const {
    project(input, W_k, K);
}

void ProjectionWeights::getV(const InputSequence* input, double V[SEQ_LEN][D_K]) const {
    project(input, W_v, V);
}

void ProjectionWeights::project(const InputSequence* input, const double W[D_EMB][D_K], double out[SEQ_LEN][D_K]) const {
    //TODO Implement the projection logic: out = input * W
    for (int i = 0; i < SEQ_LEN; i++) {
        for (int j = 0; j < D_K; j++) {
            out[i][j] = 0.0;

            for (int k = 0; k < D_EMB; k++) {
                out[i][j] += input->getValue(i, k) * W[k][j];
            }
        }
    }
}
