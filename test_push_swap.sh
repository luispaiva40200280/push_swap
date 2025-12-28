#!/bin/bash
# Usage: ./test_push_swap.sh [stack size] [max value]

SIZE=${1:-100}       # default 100 elements
MAX=${2:-1000}       # default max number

# Generate random stack
ARG=$(shuf -i 0-$MAX -n $SIZE | tr '\n' ' ')

echo "Testing push_swap with $SIZE numbers..."
echo "Stack: $ARG"

# Run push_swap and capture operations
OPS=$(./push_swap $ARG)

# Count operations
OP_COUNT=$(echo "$OPS" | wc -l)
echo "Operations executed: $OP_COUNT"

# Optionally, print each operation for debugging
# echo "$OPS"

# Run checker
CHECK=$(echo "$OPS" | ./checker_linux $ARG)
echo "Checker result: $CHECK"

# Benchmark check for 100% (bonus thresholds)
if [[ $SIZE -eq 100 ]]; then
    if [[ $OP_COUNT -lt 700 ]]; then
        echo "✅ 100 numbers: passes 100% benchmark"
    else
        echo "⚠ 100 numbers: does NOT pass 100% benchmark"
    fi
elif [[ $SIZE -eq 500 ]]; then
    if [[ $OP_COUNT -le 5500 ]]; then
        echo "✅ 500 numbers: passes 100% benchmark"
    else
        echo "⚠ 500 numbers: does NOT pass 100% benchmark"
    fi
fi
