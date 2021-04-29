#!/usr/bin/env python3
import sys
import json
import lzma
import os.path

def main():
    if len(sys.argv) < 3:
        print("Usage: vial_generate_defition.py path-to-vial.json path-to-output.h")
        return 1

    # Last argument is output
    outputPath = sys.argv[len(sys.argv) - 1]

    # Second to last folder is top level folder.
    # If no vial.json is found, move a folder down to look for more central configuration
    vialFolder = len(sys.argv) - 2

    # Get most specific folder that contains vial.json
    # Priorities:
    # 1: Keymap folder
    # 2: Keyboard folder
    # 3: Parent keyboard folder
    # 4: Etc....
    for i in range(vialFolder, 1, -1):
        # Check if vial.json is in directory
        if os.path.isfile(sys.argv[i] + "/vial.json"):
            vialFolder = i
            break

    with open(sys.argv[vialFolder] + "/vial.json", "r") as inf:
        data = inf.read()

    # minify json
    data = json.dumps(json.loads(data), separators=(',', ':')).strip()

    # compress
    data = lzma.compress(data.encode("utf-8"))

    with open(outputPath, "w") as outf:
        outf.write("#pragma once\n")
        outf.write("static const unsigned char keyboard_definition[] PROGMEM = {")
        arr = ["0x{:02X}".format(b) for b in data]
        outf.write(", ".join(arr))
        outf.write("};\n")

    return 0

if __name__ == "__main__":
    sys.exit(main())
