#include "../src/task.h"

void test() {
    TMP::TaskSet::ptr ts(new TMP::TaskSet);
    ts->addTaskFromJson("/mnt/hgfs/xilinxtoolsshared/TMP/input/task.json");
    return;
}

int main() {
    test();
    return 0;
}
