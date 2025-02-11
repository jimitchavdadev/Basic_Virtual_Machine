# StackVM

StackVM is a simple stack-based virtual machine that executes basic arithmetic operations. It consists of a compiler (`sasm`) that converts assembly-like syntax into binary instructions and a virtual machine (`stack-vm`) that executes them.

## Features
- Stack-based execution model
- Supports basic arithmetic operations: addition, subtraction, multiplication, and division
- Simple instruction encoding with 2-bit headers and 30-bit data
- Custom assembler (`sasm`) to convert human-readable instructions into binary
- Written in C++ with a minimal and efficient design

## Project Structure
```
├── stack-vm/
│   ├── main.cpp        # Entry point for the VM
│   ├── stack-vm.h      # VM header file
│   ├── stack-vm.cpp    # VM implementation
│   ├── Makefile        # Build script for the VM
├── sasm/
│   ├── lexer.h         # Lexer header file
│   ├── lexer.cpp       # Lexical analyzer for parsing
│   ├── sasm.cpp        # Compiler implementation
│   ├── Makefile        # Build script for the assembler
│   ├── test.sasm       # Example assembly file
└── README.md
```

## Installation & Build
### Requirements
- A C++ compiler (GCC, Clang, or MSVC)
- `make` (for Unix-based systems)

### Building the Project
```sh
# Build the assembler
cd sasm
make

# Build the virtual machine
cd ../stack-vm
make
```

## Usage
### Compiling an Assembly Program
Write an assembly-like program in `.sasm` format, e.g., `test.sasm`:
```
3 4 + 2 * 2 + 4 /
```
Compile it into binary instructions:
```sh
./sasm test.sasm
```
This generates `out.bin`, which can be executed by the VM.

### Running the Virtual Machine
Run the compiled binary with the VM:
```sh
./stack-vm out.bin
```

### Expected Output
```
add: 3 4
tos: 7
mul: 7 2
tos: 14
add: 14 2
tos: 16
div: 16 4
tos: 4
halt
```

## Instruction Encoding
Each instruction consists of:
- **2-bit header**: Defines instruction type
  - `0`: Positive integer
  - `1`: Primitive operation
  - `2`: Negative integer
- **30-bit data**: Stores numbers or operation codes

### Supported Operations
| Symbol | Description |
|--------|-------------|
| `+`    | Addition    |
| `-`    | Subtraction |
| `*`    | Multiplication |
| `/`    | Division |

## License
This project is open-source and licensed under the MIT License.


