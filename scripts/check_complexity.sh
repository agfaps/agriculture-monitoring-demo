#!/bin/bash

THRESHOLD=10  # Set your cyclomatic complexity limit
REPORT="complexity_report.txt"

# Run Lizard and save output
lizard src/ > "$REPORT"

EXCEEDS=0  # Flag for complexity violations

# Parse Lizard output
while IFS= read -r line; do
    if [[ $line =~ ([0-9]+)[[:space:]]+([0-9]+)[[:space:]]+[0-9]+[[:space:]]+[0-9]+[[:space:]]+[0-9]+[[:space:]]+../src/ ]]; then
        COMPLEXITY="${BASH_REMATCH[2]}"
        if [ "$COMPLEXITY" -gt "$THRESHOLD" ]; then
            echo "🚨 Function exceeds complexity threshold: $line"
            EXCEEDS=1
        fi
    fi
done < "$REPORT"

if (( EXCEEDS )); then
    echo "❌ Complexity check failed!"
    exit 1  # Exit with error if threshold is exceeded
else
    echo "✅ Complexity check passed!"
fi
