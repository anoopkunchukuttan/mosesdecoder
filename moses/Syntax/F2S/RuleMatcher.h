#pragma once

#include "InputForest.h"

namespace Moses
{
namespace Syntax
{
namespace F2S
{

// Base class for rule matchers.
template<typename Callback>
class RuleMatcher
{
 public:
  virtual ~RuleMatcher() {}

  virtual void EnumerateHyperedges(const InputForest::Vertex &, Callback &) = 0;
};

}  // F2S
}  // Syntax
}  // Moses
