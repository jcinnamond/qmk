{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    qmk_firmware = {
      url = "git+https://github.com/qmk/qmk_firmware?submodules=1";
      flake = false;
    };
  };

  outputs =
    {
      nixpkgs,
      qmk_firmware,
      ...
    }:
    let
      pkgs = nixpkgs.legacyPackages.x86_64-linux;
    in
    {
      devShells.x86_64-linux.default = pkgs.mkShell {
        packages = with pkgs; [
          dos2unix
          gnumake
          qmk
          rsync
        ];

        shellHook = ''
          rsync -a --delete "${qmk_firmware}/" "$PWD/qmk_firmware/"
          chmod -R u+w "$PWD/qmk_firmware"
          export QMK_HOME="$(pwd -P)/qmk_firmware"
          export QMK_USERSPACE="$(pwd -P)/userspace"
        '';
      };
    };
}
