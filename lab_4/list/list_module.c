#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/random.h>
#include <linux/slab.h>
#include <linux/types.h>

MODULE_AUTHOR("Serhii Panchenko");
MODULE_DESCRIPTION("Lab4_list_module");
MODULE_LICENSE("GPL3");

#define LIST_LEN 12
#define MSG_PREF "LAB_4: "

#define print_msg(msg, ...) printk(KERN_ERR MSG_PREF msg, ##__VA_ARGS__);

typedef struct {
	struct list_head lnode;
	uint64_t val;
} int_node_t;

// https://elixir.bootlin.com/linux/latest/source/include/linux/list.h#L714
static struct list_head int_list = LIST_HEAD_INIT(int_list);

static void dealloc_list(struct list_head* head) {
    int_node_t *__ptr, *__tmp;
    list_for_each_entry_safe(__ptr, __tmp, (head), lnode) {
        kfree(__ptr);
    }       
}

static void print_list(struct list_head* head) {
	int_node_t *ptr;
	print_msg("List: {");
	list_for_each_entry(ptr, head, lnode) {
		printk(KERN_ERR "\t%llu ", ptr->val);
	}
	printk(KERN_ERR "}\n");  
}

// функция которая побитово сдвигает значение каждого элемента списка на 1 влево
static uint64_t plus(void) {
	int is_first = 0;
	uint64_t res;
	int_node_t *ptr;
	list_for_each_entry(ptr, &int_list, lnode) {
		if(is_first == 0) {
			is_first = 1;
			res = ptr->val;
		} else {
			res += ptr->val;
		}
	}
	return res;
}

static uint64_t conjuction(void) {
	int is_first = 0;
	uint64_t res;
	int_node_t *ptr;
	list_for_each_entry(ptr, &int_list, lnode) {
		if(is_first == 0) {
			is_first = 1;
			res = ptr->val;
		} else {
			res &= ptr->val;
		}
	}
	return res;
}

static int __init list_module_init(void) {
	print_msg("List allocation start...\n");
	for(int i = 0; i < LIST_LEN; ++i) {
		int_node_t *ptr = (int_node_t *)kmalloc(sizeof(*ptr), GFP_KERNEL);
		if (!ptr) {
			print_msg("Can't alloc memory\n");
            dealloc_list(&int_list);
			return -ENOMEM;
		}
		get_random_bytes(&ptr->val, sizeof(ptr->val));
		list_add_tail(&ptr->lnode, &int_list);
	}
	print_msg("List allocation finish\n");
	print_list(&int_list);
	uint64_t p = plus();
	print_msg("Plus result: %llu\n", p);
	uint64_t c = conjuction();
	print_msg("Conjuction result: %llu\n", c);
    dealloc_list(&int_list);
	return 0;
}

static void __exit list_module_exit(void) {
	dealloc_list(&int_list);
	print_msg("Yippee ki-yay, Kernel!\n");
}

module_init(list_module_init);
module_exit(list_module_exit);