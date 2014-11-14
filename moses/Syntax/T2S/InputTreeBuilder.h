#pragma once

#include <vector>

#include "moses/TreeInput.h"
#include "moses/TypeDef.h"

#include "InputTree.h"

namespace Moses
{
namespace Syntax
{
namespace T2S
{

class InputTreeBuilder
{
 public:
  InputTreeBuilder();

  // Constructs a Moses::T2S::InputTree given a Moses::TreeInput and a label
  // for the top-level node (which covers <s> and </s>).
  void Build(const TreeInput &, const std::string &, InputTree &);

 private:
  void CreateNodes(const TreeInput &, const std::string &, InputTree &);
  void ConnectNodes(InputTree &);

  const std::vector<FactorType> &m_outputFactorOrder;
};

}  // T2S
}  // Syntax
}  // Moses
