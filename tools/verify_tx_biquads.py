#!/usr/bin/env python3
"""Evaluate the independently exported BASE TX audio biquad cascade."""

import cmath
import csv
import math
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent
SAMPLE_RATE = 12_500.0
FREQUENCIES = (0, 100, 200, 300, 500, 1000, 2000, 3000, 4000, 5000, 6250)


def read_entry(name):
    path = ROOT / "analysis" / "tx_filters" / name
    with path.open(newline="") as source:
        return [float(row["float_value"]) for row in csv.DictReader(source)]


def response(entry, frequency):
    z1 = cmath.exp(-2j * math.pi * frequency / SAMPLE_RATE)
    z2 = z1 * z1
    result = entry[30]
    for stage in range(5):
        b0, b1, b2, _unused, a1, a2 = entry[stage * 6 : stage * 6 + 6]
        result *= (b0 + b1 * z1 + b2 * z2) / (1.0 + a1 * z1 + a2 * z2)
    return result


def main():
    lower = read_entry("biquad_300hz_table_entry.csv")
    upper = read_entry("biquad_3000hz_table_entry.csv")
    print("frequency_hz,magnitude,db")
    for frequency in FREQUENCIES:
        magnitude = abs(response(lower, frequency) * response(upper, frequency))
        decibels = 20.0 * math.log10(magnitude) if magnitude else float("-inf")
        print(f"{frequency},{magnitude:.9g},{decibels:.6f}")


if __name__ == "__main__":
    main()
