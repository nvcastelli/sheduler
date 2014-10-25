#include <linux/time.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

const double child = 0.5;
const double adult = 1;
const double adultLuggage = 2;
//const int shuttleCapacity = 25;

struct shuttle{
  const int shuttleCapacity;
  bool status;
};

MODULE_LICENSE("GPL");

/*int start_shuttle(void) 
A shuttle begins at Terminal C with no passenger onboard
 and no passenger waiting at all terminals,
 and with a shuttle status of either PARKED or MOVING.  
 The call returns 1 if the service has already been started 
 and 0 if it was started successfully.*/

static int start_shuttle(struct seq_file *m, void *v) {

  seq_printf(m, "namaste");

  return 0;
}

static int hello_proc_open(struct inode *inode, struct  file *file) {
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
