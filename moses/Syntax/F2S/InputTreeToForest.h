#pragma once

#include "moses/Syntax/T2S/InputTree.h"

#include "InputForest.h"

namespace Moses
{
namespace Syntax
{
namespace F2S
{

// Constructs a F2S::InputForest given a T2S::InputTree.  This is a stopgap
// until support for actual forest input is added.
void InputTreeToForest(const T2S::InputTree &, InputForest &);

}  // F2S
}  // Syntax
}  // Moses
