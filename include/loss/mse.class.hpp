#ifndef __MSE_CLASS_HPP__
#define __MSE_CLASS_HPP__

#include "../core/loss.class.hpp"
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

namespace loss {

struct			MSE : public loss {
	float		error(vector<float> const &, vector<float> const &) const;
	vector<float>	gradient(vector<float> const &, vector<float> const &) const;
};

float			MSE::error(vector<float> const & out, vector<float> const & target) const {
	float		loss = 0.0;
	assert(out.size() == target.size());
	for (uint_least32_t idx = 0; idx < out.size(); ++idx)
		loss += powf(out[idx] - target[idx], 2);
	return (loss);
}

vector<float>		MSE::gradient(vector<float> const & out, vector<float> const & target) const {
	vector<float>	gradients(out.size());
	for (uint_fast32_t idx = 0; idx < out.size(); ++idx)
		gradients[idx] = (out[idx] - target[idx]) * 2;
	return (gradients);
}

} /* namespace loss */

#endif /* __MSE_CLASS_HPP__ */
