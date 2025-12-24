#pragma once
#include "RollTypes.h"

namespace Criticli {

  /*
   * Concrete implementation of IRollStrategy.
   * Daggerheart Duality Die mechanic = (1 D12 Hope + 1 D12 Fear).
  */
  class DualityRollStrategy : public IRollStrategy {
  public:
    /*
     *Constructor for dependency injection of dice values.
     * Enables deterministic testing and decoupled roll generation.
    */
    DualityRollStrategy(int hope, int fear);

    /*
     * Executes the core Daggerheart roll resolution algorithm.
     * Provides a success or failure outcome with hope or fear side effects.
    */
    [[nodiscard]] std::expected<RollResult, std::string_view> roll(
      int difficulty,
      int modifier
    ) const override;

  private:
    int m_hope{};
    int m_fear{};

    /*
     * Internal helper to determine if duality dice meet the 'Match' rule 
     * Centralizes critical success logic per the core ruleset.
    */
    static bool isCrit(int h, int f);
  };  // Closes DualityRollStrategy class

}  // closes NS