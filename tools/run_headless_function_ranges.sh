#!/usr/bin/env bash
set -euo pipefail

if (($# != 1)); then
	echo "usage: $0 <output-csv>" >&2
	exit 2
fi

GHIDRA_INSTALL="${GHIDRA_INSTALL:-/home/master/opt/ghidra}"
GHIDRA_JDK="${GHIDRA_JDK:-/home/master/opt/jdk-21.0.5+11}"
PROJECT_DIR="${PROJECT_DIR:-/tmp/x6100-ghidra-project}"
PROJECT_NAME="${PROJECT_NAME:-x6100_import}"
GHIDRA_CONFIG_DIR="${GHIDRA_CONFIG_DIR:-/tmp/x6100-ghidra-config}"
PROGRAM_NAME="X6100_BBFW_V1.1.9_251127001.bin"
OUTPUT_CSV="$1"

mkdir -p "$GHIDRA_CONFIG_DIR" "$(dirname "$OUTPUT_CSV")"

XDG_CONFIG_HOME="$GHIDRA_CONFIG_DIR" \
JAVA_HOME="$GHIDRA_JDK" \
"$GHIDRA_INSTALL/support/analyzeHeadless" \
	"$PROJECT_DIR" "$PROJECT_NAME" \
	-process "$PROGRAM_NAME" \
	-readOnly \
	-scriptPath "$(pwd)/ghidra_scripts" \
	-preScript MapSTM32F427Memory.java \
	-postScript ExportFunctionRanges.java "$(pwd)/$OUTPUT_CSV"
