#pragma once
#include <string>
#include "StatelessFeatureFunction.h"

namespace Moses
{

// the only thing this FF does is set TargetPhrase::m_ruleSource so that other FF can use it in Evaluate(Search).
class SetSourcePhrase : public StatelessFeatureFunction
{
public:
  SetSourcePhrase(const std::string &line);

  virtual bool IsUseable(const FactorMask &mask) const
  { return true; }

  virtual void EvaluateInIsolation(const Phrase &source
						, const TargetPhrase &targetPhrase
						, ScoreComponentCollection &scoreBreakdown
						, ScoreComponentCollection &estimatedFutureScore) const;

  virtual void EvaluateWithSourceContext(const InputType &input
                         , const InputPath &inputPath
                         , const TargetPhrase &targetPhrase
                         , const StackVec *stackVec
                         , ScoreComponentCollection &scoreBreakdown
                         , ScoreComponentCollection *estimatedFutureScore = NULL) const
  {}

  virtual void EvaluateWhenApplied(const Hypothesis& hypo,
                        ScoreComponentCollection* accumulator) const
  {}

  virtual void EvaluateWhenApplied(const ChartHypothesis &hypo,
                             ScoreComponentCollection* accumulator) const
  {}

  std::vector<float> DefaultWeights() const
  { return std::vector<float>(); }

};

}

