#include "../src/fpga.h"

int main() {
    TMP::FpgaSet::ptr fs(new TMP::FpgaSet());
    TMP::Fpga::ptr vc707(new TMP::Fpga("vc707"));
    TMP::Fpga::ptr vc707_1(new TMP::Fpga("vc707"));
    // vc707->info();
    fs->addToFpgaSet(vc707);
    fs->addToFpgaSet(vc707_1);
    fs->info();

    return 0;
}
