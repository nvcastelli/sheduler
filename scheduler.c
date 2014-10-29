#include <linux/time.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>


#define CHILD 1
#define ADULT 2
#define ADULT_LUGGAGE 4

enum status = {PARKED, MOVING, DEACTIVATING, OFFLINE};

struct shuttle{
	#define SHUTTLECAPACITY 50
	int startTerminal = 3;
	int currentPassengers = 0;
	int status = 3;//false = parked true = moving
} theShuttle;

struct passenger{
	int passengerTyper;
	int startTerminal;
	int destinationTerminal;
} person;


MODULE_LICENSE("GPL");

static int start_shuttle(struct seq_file *m, void *v) {
	

	if(theShuttle.status == 1 || theShuttle.status == 0)
		return 1;

seq_printf(m, "The shuttle is starting at terminal %d", theShuttle.startTerminal);

return 0;
}
static int hello_proc_open(struct inode *inode, struct file *file) {
return single_open(file, start_shuttle, NULL);
}
static const struct file_operations hello_proc_fops = {
.owner = THIS_MODULE,
.open = hello_proc_open,
.read = seq_read,
.release = single_release,
};
static int __init hello_proc_init(void) {
proc_create("terminal", 0, NULL, &hello_proc_fops);
return 0;
}
static void __exit hello_proc_exit(void) {
remove_proc_entry("terminal", NULL);
}
module_init(hello_proc_init);
module_exit(hello_proc_exit);
