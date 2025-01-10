# nm_pair_view - A simple C++23 "bubble" range iterator

This repository contains a the nm_pair_view, a simple range iterator
that provide "n \* m" pairs of a given range,
from (range[0], range[1]) until (range[last-1], range[last]) inclusive.

It matches the following loop syntax:

```C++
for (auto n = 0; n != range.size() - 1; ++n) {
    for (auto m = n + 1, m != range.size(); ++m) {
        auto pair = std::make_pair(range[n], range[m])
        // ...
    }
}
```

## Example usage

Pairwise "bubble" view over a given range:

```C++
// Expected output:
//   [1, 2]  [1, 3]  [1, 4]  [2, 3]  [2, 4]  [3, 4]
const auto numbers = std::vector<int>{1, 2, 3, 4};
for (const auto& [a, b] : numbers | views::nm_pairs)
    std::print("[{}, {}]  ", a, b);
std::println("");
```

A completely "rangified" version of bubble sort:

```C++
auto less = [](const auto& pair) { return pair.second < pair.first; };
auto swap = [](auto pair) { std::swap(pair.first, pair.second); };
std::ranges::for_each(
    range | views::nm_pairs | std::views::filter(less),  swap);
```

## Compiling

To build using **make**:

    make

To build using **ninja-build**:

    ninja

Binaries are created in the **build/** folder
