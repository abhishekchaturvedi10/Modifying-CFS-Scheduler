# Modifying-CFS-Scheduler
You would thus need to modify the scheduler in such a way that when
everytime a process is selected through the RB-tree, you you need to compare
to all other process with soft-realtime requirements and see which one of those
require the CPU more urgently than the one selected through the regular RB-
tree. The one that urgently requires CPU time need to be scheduled before the
one selected through CFS.
You would additionally require a system call to modify the tasks soft-realtime
requirements { say rtnice, which takes argument the PID and the realtime
guarantees needed. rtnice can have a corresponding user program with the
same name which should actually do the system call rtnice to perform the said
operation with the supplied PID.
