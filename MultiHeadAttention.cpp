#include "MultiHeadAttention.h"
#include "AttentionHead.h"
#include "InputSequence.h"
#include <iostream>

using namespace std;

//TODO: Implement Constructor, Copy Constructor, Destructor and execute() method
MultiHeadAttention::MultiHeadAttention(int n_heads, const InputSequence* inputTensor)
	: numHeads(n_heads), x(inputTensor)
{
	heads = new AttentionHead * [numHeads];
	for (int i = 0; i < numHeads; i++) {
		heads[i] = new AttentionHead(i, i, x);
	}
}

MultiHeadAttention::MultiHeadAttention(const MultiHeadAttention& other)
	: numHeads(other.numHeads), x(other.x)
{
	heads = new AttentionHead*[numHeads];
	for (int i = 0; i < numHeads; i++) {
		heads[i] = new AttentionHead(*other.heads[i]);
	}
}

MultiHeadAttention::~MultiHeadAttention() {
	for (int i = 0; i < numHeads; i++) {
		delete heads[i];
	}
	delete[] heads;
}

void MultiHeadAttention::execute() const {
	for (int i = 0; i < numHeads; i++) {
		heads[i]->forwardPass();
	}
}
