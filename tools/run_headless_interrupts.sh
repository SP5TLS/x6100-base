#!/usr/bin/env bash
set -euo pipefail

: "${GHIDRA_INSTALL:?set GHIDRA_INSTALL to the Ghidra directory}"
: "${JAVA_HOME:?set JAVA_HOME to the JDK directory}"
PROJECT_DIR="${PROJECT_DIR:-/tmp/x6100-ghidra-project}"
PROJECT_NAME="${PROJECT_NAME:-x6100_import}"
GHIDRA_CONFIG_DIR="${GHIDRA_CONFIG_DIR:-/tmp/x6100-ghidra-config}"
OUTPUT_DIR="${OUTPUT_DIR:-analysis/interrupts}"
PROGRAM_NAME="X6100_BBFW_V1.1.9_251127001.bin"

mkdir -p "$GHIDRA_CONFIG_DIR" "$OUTPUT_DIR"

XDG_CONFIG_HOME="$GHIDRA_CONFIG_DIR" \
"$GHIDRA_INSTALL/support/analyzeHeadless" \
	"$PROJECT_DIR" "$PROJECT_NAME" \
	-process "$PROGRAM_NAME" \
	-readOnly \
	-scriptPath "$(pwd)/ghidra_scripts" \
	-postScript ExportInterruptEvidence.java "$(pwd)/$OUTPUT_DIR"
