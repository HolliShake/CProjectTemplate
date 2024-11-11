#include "core.h"

int main(int argc, char* argv[]) {
    GC_INIT();
    int status = start(argc, argv);
    printf("Program exited with status %d\n", status);
    GC_gcollect();
    return status;
}
