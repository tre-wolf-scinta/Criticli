// static_assert(__cplusplus  >=202302L, "Build must use C++23 or later");
#include <iostream>
#include <iomanip>
#include "DualityRollStrategy.h"

void print_result(const std::string& test_name, const Criticli::RollResult& res) {
  std::cout << "--- Test: " << test_name << " ---\n";
  std::cout << "Dice: [" << res.hope_die << " Hope] [" << res.fear_die << " Fear]\n";
  std::cout << "Total: " << res.total << " | Outcome: ";
  
  // A simple way to visualize the enum results
  switch(res.outcome) {
    case Criticli::RollOutcome::CriticalSuccess: std::cout << "CRITICAL SUCCESS!\n"; break;
    case Criticli::RollOutcome::SuccessWithHope: std::cout << "Success with Hope\n"; break;
    case Criticli::RollOutcome::SuccessWithFear: std::cout << "Success with Fear\n"; break;
    case Criticli::RollOutcome::FailureWithHope: std::cout << "Failure with Hope\n"; break;
    case Criticli::RollOutcome::FailureWithFear: std::cout << "Failure with Fear\n"; break;
  }
  std::cout << std::endl;
}

int main() {
  // Test 1: Critical Success (Match) vs high DC
  // Even though 10 < 15, the 5/5 match should trigger CriticalSuccess
  Criticli::DualityRollStrategy crit_test(5, 5);
  auto res1 = crit_test.roll(15, 0);
  if (res1) print_result("Critical Match (5,5) vs DC 15", *res1);

  // Test 2: Success with Fear
  // 8 + 4 + 2 = 14. 14 >= 12 (Success). Fear (4) > Hope (8)? No.
  // Let's swap: 4 Hope, 8 Fear. 4 + 8 + 2 = 14. 14 >= 12. Fear is higher.
  Criticli::DualityRollStrategy fear_test(4, 8);
  auto res2 = fear_test.roll(12, 2);
  if (res2) print_result("Success with Fear (4,8) +2 vs DC 12", *res2);

  // Test 3: Failure with Hope
  // 3 Hope, 1 Fear. 3 + 1 + 0 = 4. 4 < 10 (Failure). Hope is higher.
  Criticli::DualityRollStrategy hope_test(3, 1);
  auto res3 = hope_test.roll(10, 0);
  if (res3) print_result("Failure with Hope (3,1) vs DC 10", *res3);

  return 0;
}