#pragma once
#include <expected>
#include <string_view>
#include <string>

namespace Criticli {

// scoped enum RollOutcome
  enum class RollOutcome {
    SuccessWithHope,
    SuccessWithFear,
    FailureWithHope,
    FailureWithFear,
    CriticalSuccess
  };  // closes RollOutcome

// RollResult object
  struct RollResult {
    // Data Members
    int hope_die{};
        int fear_die{};
    int modifier{};
    int total{};
    RollOutcome outcome {RollOutcome::FailureWithFear};
  };  // closes RollResult

// interface 
  class IRollStrategy {
  public:
    virtual ~IRollStrategy() = default;
    [[nodiscard]] virtual std::expected<RollResult, std::string_view> roll(int difficulty, int modifier) const = 0;
  };  // closes IRollStrategy 
} // closes namespace