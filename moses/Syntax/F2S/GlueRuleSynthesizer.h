#pragma once

#include "moses/Phrase.h"
#include "moses/TargetPhrase.h"

#include "HyperTree.h"
#include "HyperTreeCreator.h"
#include "InputForest.h"

namespace Moses
{
namespace Syntax
{
namespace F2S
{

class GlueRuleSynthesizer : public HyperTreeCreator
{
 public:
  GlueRuleSynthesizer(HyperTree &);

  // Synthesize the minimal, monotone rule that can be applied to the given
  // hyperedge and add it to the rule trie.
  void SynthesizeRule(const InputForest::Hyperedge &);

 private:
  void SynthesizeHyperPath(const InputForest::Hyperedge &, HyperPath &);

  TargetPhrase *SynthesizeTargetPhrase(const InputForest::Hyperedge &);

  HyperTree &m_hyperTree;
  Phrase m_dummySourcePhrase;
};

}  // F2S
}  // Syntax
}  // Moses
