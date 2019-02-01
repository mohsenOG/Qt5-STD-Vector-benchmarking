# Benchmarking: Qt5 vs. STD Vector

## Overview

If you are working with Qt and std libraries at the same time, you might want to know the container performance of these two libraries.
Different scenarios for <i>adding</i> AND <i>accessing</i> elements is considered. Note that only the primitive type <b>int</b> is tested.


## Summary
Please consider the results might vary (or not valid) if we change the type to others rather than int!
Here is my conclusion:

- Try to use std variants rather than Qt (at least vectors!)
- Try to access QVector using at()
- Try to access std::vector by <i>iterator</i> or <i>subscription</i>
- Try to use emplace_back whenever possible (huge difference!)
- <b>What about using C++17 std::variant and std::any instead of QVariant?!?!</b>
