# Libgets

Libgets is a CS50-like C library with Nix flakes, designed for learning C and Nix flakes.

---

## Table of Contents.
1. [How to use it in your devShell.](#how-to-use-it-in-your-devshell)
2. [To do List.](#to-do-list)


## How to use it in your devShell.

1. Add it to inputs in your flake.nix file.
```nix
inputs = {
    nixpkgs.url = "nixpkgs/nixos-24.05";
    libgets = {
        url = "github:aldosierra/libgets";
        inputs.nixpkgs.follows = "nixpkgs";
    };
};
```

2. Add it to the devShell buildInputs.
```nix
devShells = {
    default = pkgs.mkShell {
        name = "sample-env";
        buildInputs = with pkgs; [ gcc libgets.packages."x86_64-linux".default ];
    };
};
```

3. Import it on your c file.
```c
#include "libgets.h"

int main(void) {
    char *name = GetString("What is your name? ");
    printf("Hi, %s\n", name);

    return 0;
}
```

## To do List.

- [ ] Add a list of functions include it on this library.
- [ ] Add options parameters for format messages.
- [ ] Check for missing functions on the og cs50 library.
