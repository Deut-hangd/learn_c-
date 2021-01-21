#include "head1.h"

int main(int arg, char **args)
{
    // Person p;
    // VFPTR *vTableP = (VFPTR *)(*(int *)&p);
    // PrintVTable(vTableP);
    // Student s;
    // VFPTR *vTableS = (VFPTR *)(*(int *)&s);
    // PrintVTable(vTableS);
    Child c;
    VFPTR *vTableC = (VFPTR *)(*(int *)&c);
    PrintVTable(vTableC);

    return 0;
}