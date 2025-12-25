#include "DualityRollStrategy.h"

namespace Criticli {

  DualityRollStrategy::DualityRollStrategy(int hope, int fear) 
    : m_hope(hope), m_fear(fear) {}

  bool DualityRollStrategy::isCrit(int h, int f) {
    return h == f;
  }

  std::expected<RollResult, std::string_view> DualityRollStrategy::roll(int difficulty, int modifier) const {
    // 1. Capture state using designated initializers (C++20/23)
    RollResult result {
      .hope_die = m_hope,
      .fear_die = m_fear,
      .modifier = modifier
    };  // closes aggregate initialization for result

    // 2. Calculate total and store it in the result object
    result.total = (result.fear_die + result.hope_die) + result.modifier;

    // 3. Check for crit
    if (isCrit(m_hope, m_fear)) {
      result.outcome = RollOutcome::CriticalSuccess;
      return result;  // crit means immediate success in Daggerheart. No need to continue.
    }  // Closes crit check

    // 4. Calculate outcome
    if (result.total >= difficulty) {
      result.outcome = (m_hope > m_fear) ? RollOutcome::SuccessWithHope : RollOutcome::SuccessWithFear;
    } else {
      result.outcome = (m_hope > m_fear) ? RollOutcome::FailureWithHope : RollOutcome::FailureWithFear;
    }  // Closes outcome resolution logic    

    return result;
  }  // closes roll method

}  // closes NS