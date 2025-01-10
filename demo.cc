#include <print>
#include <vector>

#include "nm_pairs.hh"

// Expected output:
//   [1, 2]  [1, 3]  [1, 4]  [2, 3]  [2, 4]  [3, 4]

auto main() -> int {
  const auto numbers = std::vector<int>{1, 2, 3, 4};

  for (const auto& [a, b] : numbers | views::nm_pairs)
    std::print("[{}, {}]  ", a, b);

  std::println("");
}
