#ifndef __LOSS_CLASS_HPP__
#define __LOSS_CLASS_HPP__

#include <vector>

using namespace std;

struct				Loss {
	virtual float		loss(vector<float> const &, vector<float> const &) const;
	virtual vector<float>	gradient(vector<float> const &, vector<float> const &) const;
};

#endif /* __LOSS_CLASS_HPP__ */
