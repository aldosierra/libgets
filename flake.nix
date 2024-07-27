{
  description = "A simple C library that mimics cs50 gets";

  inputs.nixpkgs.url = "nixpkgs/nixos-24.05";

  outputs = { flake-parts, ... }@inputs:
  flake-parts.lib.mkFlake { inherit inputs; } {
    systems = [ "x86_64-linux" "aarch64-linux" "aarch64-darwin" "x86_64-darwin" ];

    perSystem = { pkgs, system, ... }: {
      packages = {
        default = pkgs.stdenv.mkDerivation {
          pname = "gets-lib";
          version = "1.0";
          src = ./src;
          nativeBuildInputs = with pkgs; [ autoconf automake libtool ];

          unpackPhase = "cp -r $src/* .";

          buildPhase = ''
            gcc -c gets.c -o gets.o
            ar rcs libgets.a gets.o
            ranlib libgets.a
          '';

          installPhase = ''
            mkdir -p $out/{lib,include}
            cp libgets.a $out/lib
            cp gets.h $out/include
          '';

          meta = with pkgs.lib; {
            description = "A simple c library that mimics cs50 gets functions";
            license = licenses.mit;
            maintainers = [ maintainers.aldosierra ];
          };
        };
      };
    };
  };
}
