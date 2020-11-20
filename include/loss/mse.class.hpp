#ifndef __MSE_CLASS_HPP__
#define __MSE_CLASS_HPP__

#include "../core/loss.class.hpp"
#include <vector>
#include <cmath>

using namespace std;

struct			mean_squared_error : public Loss {
	float		loss(vector<float> const &, vector<float> const &) const;
	vector<float>	gradient(vector<float> const &, vector<float> const &) const;
};

float			mean_squared_error::loss(vector<float> const & out, vector<float> const & target) const {
	assert(out.size() == target.size());

	float loss = 0.0;
	for (uint_least32_t idx = 0; idx < out.size(); ++idx)
		loss += powf(out[idx] - target[idx], 2);
	return (loss);
}

vector<float>		mean_squared_error::gradient(vector<float> const & out, vector<float> const & target) const {
	assert(out.size() == target.size());

	vector<float>	gradients(out.size());
	for (uint_fast32_t idx = 0; idx < out.size(); ++idx)
		gradients[idx] = (out[idx] - target[idx]) * 2;
	return (gradients);
}

#endif /* __MSE_CLASS_HPP__ */
