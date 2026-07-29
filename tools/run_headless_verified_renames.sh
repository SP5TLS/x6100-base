#!/usr/bin/env bash
set -euo pipefail

if (($# != 1)); then
	echo "usage: $0 <verified-renames.csv>" >&2
	exit 2
fi

: "${GHIDRA_INSTALL:?set GHIDRA_INSTALL to the Ghidra directory}"
: "${JAVA_HOME:?set JAVA_HOME to the JDK directory}"
: "${PROJECT_DIR:?set PROJECT_DIR to the persistent Ghidra project directory}"
: "${PROJECT_NAME:?set PROJECT_NAME to the persistent Ghidra project name}"
GHIDRA_CONFIG_DIR="${GHIDRA_CONFIG_DIR:-/tmp/x6100-ghidra-config}"
PROGRAM_NAME="X6100_BBFW_V1.1.9_251127001.bin"

mkdir -p "$GHIDRA_CONFIG_DIR"

XDG_CONFIG_HOME="$GHIDRA_CONFIG_DIR" \
"$GHIDRA_INSTALL/support/analyzeHeadless" \
	"$PROJECT_DIR" "$PROJECT_NAME" \
	-process "$PROGRAM_NAME" \
	-noanalysis \
	-scriptPath "$(pwd)/ghidra_scripts" \
	-postScript RenameVerifiedFromCsv.java "$(pwd)/$1"
