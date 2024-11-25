#ifndef SPINLOCK_H
#define SPINLOCK_H

// Definición de struct spinlock
struct spinlock {
    uint locked;       // Is the lock held?
    char *name;        // Name of lock
    struct cpu *cpu;   // The cpu holding the lock
};

// Funciones para spinlock
void initlock(struct spinlock *lk, char *name);
void acquire(struct spinlock *lk);
void release(struct spinlock *lk);

#endif // SPINLOCK_H
