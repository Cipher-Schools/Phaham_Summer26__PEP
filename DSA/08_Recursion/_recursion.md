```
A function that calls itself is recursive. Each call creates a new "stack frame" in memory — a box holding local variables and the return address. Frames stack up as calls go deeper, then unwind (pop) as each returns. The call stack is the engine of recursion.
Analogy: a stack of plates in a cafeteria. Each recursive call adds a new plate on top. When a call returns (hits the base case), that plate is removed. You can only work on the top plate. The base case is what stops you from adding plates forever — without it, the stack overflows and crashes.

Every recursive function needs exactly two things
Base case -
The condition that stops recursion. No recursive call made. Must be reachable for all valid inputs — missing this causes infinite recursion and stack overflow.

Recursive call - 
Calls itself with a simpler/smaller input - making progress toward the base case. Must guarantee the input shrinks every call, or you loop forever.
```