#ifndef __LOSS_CLASS_HPP__
#define __LOSS_CLASS_HPP__

#include <vector>

using namespace std;

namespace loss {

struct				loss {
	virtual float		error(vector<float> const &, vector<float> const &) const = 0;
	virtual vector<float>	gradient(vector<float> const &, vector<float> const &) const = 0;
};

} /* namespace loss */

#endif /* __LOSS_CLASS_HPP__ */
