#ifndef __SGD_CLASS_HPP__
#define __SGD_CLASS_HPP__

#include "../core/optimizer.class.hpp"

class			SGD : public Optimizer {
private:
	unsigned int	_epochs = 500;
	float		_patience = 0.1;
	float		_learning_rate;
public:
	SGD(float const);
	SGD(unsigned int const, float const, float const);
	~SGD();
};

SGD::SGD(float const learning_rate) : _learning_rate(learning_rate) {}

SGD::SGD(unsigned int const epochs, float const patience, float const learning_rate) :
	_epochs(epochs), _patience(patience), _learning_rate(learning_rate) {}

SGD::~SGD() {}

#endif /* __SGD_CLASS_HPP__ */
