#ifndef __BCE_CLASS_HPP__
#define __BCE_CLASS_HPP__

#include "../core/loss.class.hpp"
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

namespace loss {

/*!
 * \brief Binary cross entropy loss function
 */
struct			BCE : public loss {
	float		error(vector<float> const &, vector<float> const &) const;
	vector<float>	gradient(vector<float> const &, vector<float> const &) const;
};

float			BCE::error(vector<float> const & out, vector<float> const & target) const {
	assert(out.size() == 1 && target.size() == 1);
	return (-((target[0] * logf(out[0])) + ((1.0 - target[0]) * logf(1.0 - out[0]))));
}

vector<float>		BCE::gradient(vector<float> const & out, vector<float> const & target) const {
	assert(out.size() == 1 && target.size() == 1);
	return (target);
}

} /* namespace loss */

#endif /* __BCE_CLASS_HPP__ */
