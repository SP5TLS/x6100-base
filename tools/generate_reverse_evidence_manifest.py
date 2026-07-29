#!/usr/bin/env python3
"""Create a deterministic hash manifest for decompile/disassembly evidence."""

from __future__ import annotations

import csv
import hashlib
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent
ANALYSIS = ROOT / "analysis"
OUTPUT = ANALYSIS / "decompile_disassembly_manifest.csv"
PATTERNS = (
    "*decompile*",
    "*decompilation*",
    "*disassembly*",
)


def evidence_files() -> list[Path]:
    files: set[Path] = set()
    for pattern in PATTERNS:
        files.update(path for path in ANALYSIS.rglob(pattern) if path.is_file())
    files.discard(OUTPUT)
    return sorted(files)


def evidence_type(path: Path) -> str:
    name = path.name.lower()
    if "disassembly" in name:
        return "disassembly"
    return "decompile"


def main() -> None:
    rows = []
    for path in evidence_files():
        data = path.read_bytes()
        rows.append(
            (
                path.relative_to(ROOT).as_posix(),
                evidence_type(path),
                len(data),
                hashlib.sha256(data).hexdigest(),
            )
        )

    with OUTPUT.open("w", newline="", encoding="utf-8") as stream:
        writer = csv.writer(stream, lineterminator="\n")
        writer.writerow(("path", "type", "bytes", "sha256"))
        writer.writerows(rows)


if __name__ == "__main__":
    main()
