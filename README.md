# Semi-Fudded Keylogger

---
> ⚠️ **DISCLAIMER:** This code is for educational use only. Unauthorized use is strictly prohibited and may be illegal.

---


## Overview

This keylogger is designed to **bypass heuristic detections** by:

- Dynamically resolving Windows APIs at runtime
- Injecting junk code to confuse antivirus heuristic engines
- Employing various obfuscation techniques to avoid triggering detection signatures

The goal is to showcase methods to evade antivirus scanners *without accidentally triggering alerts.*


## Technical Details

- Uses **dynamic API resolution** (`LoadLibraryA`, `GetProcAddress`) instead of static imports
- Implements **stack strings** and concatenation to hide suspicious strings
- Incorporates **junk instructions** to obfuscate program behavior
- Avoids common heuristics that cause antivirus flags

---

## Important Notes

- This repository is intended for learning, research, and defensive purposes only.
- Ensure you have permission before running or analyzing this code.
- Always run in isolated and controlled environments.
