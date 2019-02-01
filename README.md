# Qt5-STD-Vector-benchmarking

## Overview

If you are working with Qt and std libraries in the same time, you might consider the container performance of these two libraries.
Different scenarios for adding AND accessing elements is considered. Note that only the primitive type int is tested and the results for other types/object might differ.


## Summary
Please consider the results might vary (not valid) if we change the type to others rather than int!
Here is my conclusion:

- Try to use std variants rather than Qt (at least vectors!)
- Try to access QVector using at()
- Try to access std::vector by <i>iterator</i> or <i>subscription</i>
- Try to use emplace_back whenever possible (huge difference!)
- <b>What about using C++17 std::variant and std::any instead of QVariant?!?!</b>
