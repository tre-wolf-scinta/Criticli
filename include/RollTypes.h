#pragma once
#include <expected>
#include <string_view>
#include <string>

namespace Criticli {

  /*
   * Represents the distinct terminal states of the Daggerheart Duality system.
   * scoped enumeration for type safety and preventing namespace pollution.
  */
  enum class RollOutcome {
    SuccessWithHope,
    SuccessWithFear,
    FailureWithHope,
    FailureWithFear,
    CriticalSuccess
  };  // closes RollOutcome

  /*
   * Passive data structure designed to transport roll metadata across system boundaries.
   * Encapsulates raw dice results and computed outcome.
  */
  struct RollResult {
    int hope_die{};
    int fear_die{};
    int modifier{};
    int total{};
    RollOutcome outcome {RollOutcome::FailureWithFear};
  };  // closes RollResult

  /*
   * Abstract base class defining the contract for various roll resolution algorithms.
   * Facilitates Strategy pattern by allowing context to remain agnostic of
   * specific mechanics like duality, advantage, group roll, etc.
  */
  class IRollStrategy {
  public:
    virtual ~IRollStrategy() = default;
    
    /*
     * Executes resolution logic. Returns std::expected to enforce
     * error handling and avoid exceptions overhead
    */
    [[nodiscard]] virtual std::expected<RollResult, std::string_view> roll(
      int difficulty,
      int modifier
      ) const = 0;
  };  // closes IRollStrategy 
} // closes namespace