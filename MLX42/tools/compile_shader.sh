#!/bin/sh
# -----------------------------------------------------------------------------
# Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
# See README in the root project for more information.
# -----------------------------------------------------------------------------

# If no arguments have been given
if [ "$#" -ne 2 ]; then
    echo "ERROR: missing arguments, use as follows: $0 <ShaderFile> <Mode>" 1>&2
    exit 1
fi

# If file cannot be found
if [ ! -f "$1" ]; then
    echo "ERROR: shader file not found: $1" 1>&2
    exit 2
fi

SHADERTYPE="${1##*.}"

printf '%s\n' "// -----------------------------------------------------------------------------"
printf '%s\n' "// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard."
printf '%s\n' "// See README in the root project for more information."
printf '%s\n' "// -----------------------------------------------------------------------------"
printf '\n'
printf '%s\n' "// If you wish to modify this file edit the .vert or .frag file!"
printf '\n'
printf '%s\n' "#include \"MLX42/MLX42_Int.h\""
printf '\n'

if [ "$2" -eq 1 ]; then
	printf 'const char* %s_shader = "#version 300 es\\n"\n' "${SHADERTYPE}"
	printf '%s\n' '	"precision mediump float;"'
else
	IFS= read -r FIRST_LINE < "$1"
	printf 'const char* %s_shader = "%s\\n"\n' "${SHADERTYPE}" "${FIRST_LINE}"
fi

tail -n +2 "$1" | while IFS= read -r LINE; do
	if [ -n "${LINE}" ]; then
		if [ "${LINE}" = "}" ]; then
			printf '	"%s";\n' "${LINE}"
		else
			printf '	"%s"\n' "${LINE}"
		fi
	fi
done

exit 0
