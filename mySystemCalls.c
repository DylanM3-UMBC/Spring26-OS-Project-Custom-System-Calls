#include <linux/kernel.h>
#include <linux/syscalls.h>

// Syscall for printing hello world, takes 0 arguments
SYSCALL_DEFINE0(hello) {
    printk("Hello World!\n");
    return 0;
}

// Syscall for memcpy that takes 3 arguments (void* dest, void* source, size_t size);
SYSCALL_DEFINE3(custom_memcpy, unsigned char __user *, dest, unsigned char __user *, source, int, size){
    char* copy; 
    if (access_ok(source, size) == 0) {
        return 1;
    }

    copy = kmalloc(size, GFP_KERNEL);
    if (copy_from_user(copy, source, size) == 0) {
        if (copy_to_user(dest, copy, size) != 0) {
            kfree(copy);
            copy = NULL;
            return 1;
        }
    }
    else{
        kfree(copy);
        copy = NULL;
        return 1;
    }
    
    kfree(copy);
    copy = NULL;    
    
    return 0;
}