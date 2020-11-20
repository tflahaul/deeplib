#ifndef __SGD_CLASS_HPP__
#define __SGD_CLASS_HPP__

#include "../core/optimizer.class.hpp"

class			SGD : public Optimizer {
private:
	unsigned int	_epochs = 500;
	float		_learning_rate;
public:
	SGD(float const);
	SGD(unsigned int const, float const);
	~SGD();
};

SGD::SGD(float const learning_rate) : _learning_rate(learning_rate) {}
SGD::SGD(unsigned int const epochs, float const lr) : _epochs(epochs), _learning_rate(lr) {}
SGD::~SGD() {}

#endif /* __SGD_CLASS_HPP__ */
