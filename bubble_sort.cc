#include <algorithm>
#include <print>
#include <ranges>
#include <vector>

#include "nm_pairs.hh"

// NOTE:
// The bubble_sort_* functions create copies of the incoming numbers.
// This is for demonstration purposes only.

// clang-format off

auto bubble_sort_simple(auto range) {
  for (auto [a, b] : range | views::nm_pairs) {
    if (std::ranges::less{}(b, a))
      std::ranges::swap(a, b);
  }

  return range;
}

auto bubble_sort_rangified(auto range) {
  auto less = [](const auto& pair) { return pair.second < pair.first; };
  auto swap = [](auto pair) { std::swap(pair.first, pair.second); };

  std::ranges::for_each(
        range | views::nm_pairs | std::views::filter(less),  swap);

  return range;
}

// clang-format on

// Expected output:
//   Simple    | Sorted: true
//   Rangified | Sorted: true
auto main() -> int {
  const auto unsorted = std::vector<int>{10, 2, 8, 7, 1, 6, 5, 3, 9, 4};

  const auto simple = bubble_sort_simple(unsorted);
  std::println("Simple    | Sorted: {}",
               std::is_sorted(std::begin(simple), std::end(simple)));

  const auto rangified = bubble_sort_rangified(unsorted);
  std::println("Rangified | Sorted: {}",
               std::is_sorted(std::begin(rangified), std::end(rangified)));
}
