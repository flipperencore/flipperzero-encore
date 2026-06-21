#!/usr/bin/env python3
import pathlib
import string

KEY_LENGTH = 12
DICT_PATH = "applications/main/nfc/resources/nfc/assets/mf_classic_dict.nfc"

file = pathlib.Path(__file__).parent.parent / DICT_PATH
lines = file.read_text().split("\n")

total = 0
for i, line in reversed(list(enumerate(lines))):
    if line.startswith("#"):
        continue
    if not line:
        continue
    if len(line) != KEY_LENGTH or any(char not in string.hexdigits for char in line):
        print(f"{DICT_PATH}:{i + 1}: incorrect format: {line}")
    for check in lines[:i]:
        if check.startswith("#"):
            continue
        if check.upper() == line.upper():
            print(f"{DICT_PATH}:{i + 1}: removed duplicate line: {line}")
            del lines[i]
            break
    else:  # Didn't break
        total += 1


file.write_text("\n".join(lines))
print(f"Total keys: {total}")
